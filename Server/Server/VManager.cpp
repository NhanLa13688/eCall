// Note hardware
// Day cam la chan 10
// Day vang la chan 9


#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>

#include <bits/stdc++.h>

class SerialPort
{
    public:
    SerialPort(const std::string &port, speed_t baudRate);
    ~SerialPort();
    bool writeData(const std::vector<uint8_t> &data);
    bool readData(std::vector<uint8_t> &buffer, size_t size);
  
    private:
    int serial_port;
    void configurePort(speed_t baudRate);
};

SerialPort::SerialPort(const std::string &port, speed_t baudRate) {
    serial_port = open(port.c_str(), O_RDWR);
    if (serial_port < 0) {
        throw std::runtime_error("Error opening serial port");
    }
    configurePort(baudRate);
}

SerialPort::~SerialPort() {
    if (serial_port >= 0) {
        close(serial_port);
    }
}

void SerialPort::configurePort(speed_t baudRate) {
    struct termios tty;
    memset(&tty, 0, sizeof(tty));

    if (tcgetattr(serial_port, &tty) != 0) {
        close(serial_port);
        throw std::runtime_error("Error getting port attributes");
    }

    cfsetispeed(&tty, baudRate);
    cfsetospeed(&tty, baudRate);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;
    tty.c_iflag &= ~IGNBRK;
    tty.c_lflag = 0;
    tty.c_oflag = 0;
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 1;

    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~(PARENB | PARODD);
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
        close(serial_port);
        throw std::runtime_error("Error setting port attributes");
    }

}

bool SerialPort::writeData(const std::vector<uint8_t> &data) {
    if (serial_port < 0) {
        std::cerr << "Serial port not open" << std::endl;
        return false;
    }

    ssize_t bytesWritten = write(serial_port, data.data(), data.size());
    if (bytesWritten < 0) {
        perror("Error writing to serial port");
        return false;
    }

    return true;
}

bool SerialPort::readData(std::vector<uint8_t> &buffer, size_t size) {
    if (serial_port < 0) {
        std::cerr << "Serial port not open" << std::endl;
        return false;
    }

    buffer.resize(size);
    ssize_t bytesRead = read(serial_port, buffer.data(), size);
    if (bytesRead < 0) {
        perror("Error reading from serial port");
        buffer.clear();
        return false;
    }

    buffer.resize(bytesRead);
    return true;
}

class NFrame
{
    public:
    bool parse();
    uint8_t getFrameID();
    std::vector<uint8_t> getData();
    NFrame(std::vector<uint8_t> frame)
    {
        mFrame = frame;
    };
    private:
    uint8_t calculateBCC();
    std::vector<uint8_t> mFrame;
    bool mIsValidFrame;
    const static int HEADER = 0xAA;
    
    const static int ID_INDEX = 2;
    const static int LENGTH_INDEX = 2;
    const static int DATA_INDEX = 3;
};
 
 
uint8_t NFrame::calculateBCC()
{
    uint8_t bcc = 0;
    for(int i = 0; i < mFrame.size() - 1; i++)
    {
        bcc ^= mFrame[i];
    }
    return bcc;
}
 
bool NFrame::parse()
{
    bool ret = false;
    if(mFrame.size() > 4)
    {
        uint8_t bcc = calculateBCC();
        uint8_t frameBcc = mFrame[mFrame.size() - 1];
        if(bcc == frameBcc)
        {
            mIsValidFrame = true;
            ret = true;
        }
    }
    return ret;
}
 
uint8_t NFrame::getFrameID()
{
    if(mIsValidFrame)
    {
        return mFrame[1];
    }
    return 0;
}
 
std::vector<uint8_t> NFrame::getData()
{
    std::vector<uint8_t> ret = {};
    if(mIsValidFrame)
    {
        for(int i = 0; i < mFrame[LENGTH_INDEX]; i++)
        {
            ret.push_back(mFrame[DATA_INDEX + i]);
        }
    }
    return ret;
}
 
void printVector(std::vector<uint8_t> vec)
{
    for(auto it : vec)
    {
        printf("%.2X", it);
    }
    std::cout << std::endl;
}

std::vector<uint8_t> createCustomFrame(uint8_t id, const std::vector<uint8_t> &data)
{
    const uint8_t HEADER = 0xAA;
    std::vector<uint8_t> frame;

    // Header
    frame.push_back(HEADER);
    // ID
    frame.push_back(id);
    // Length
    frame.push_back(static_cast<uint8_t>(data.size()));
    // Data
    frame.insert(frame.end(), data.begin(), data.end());
    // BCC
    uint8_t bcc = 0;
    for (size_t i = 0; i < frame.size(); ++i)
    {
        bcc ^= frame[i];
    }
    frame.push_back(bcc);

    return frame;
}


 
int main(int argc, char *argv[])
{
    SerialPort serial("/dev/serial0", B115200);
    std::cout << "UART connection established." << std::endl;


    // while(1)
    // {
    //  // Tạo frame tùy ý
    // uint8_t customID = 0x01; // ID của frame
    // std::vector<uint8_t> customData = {0x10, 0x20, 0x30, 0x40}; // Data
    // std::vector<uint8_t> customFrame = createCustomFrame(customID, customData);

    // // Gửi frame qua UART
    // if (serial.writeData(customFrame))
    // {
    //     std::cout << "Custom frame sent successfully." << std::endl;
    // }
    // else7
    // {
    //     std::cerr << "Failed to send custom frame." << std::endl;
    // }

    // }

    while(1)
    {
        std::vector<uint8_t> buffer;
        if (serial.readData(buffer, 256))
        { 
            NFrame frame(buffer);
            if( frame.parse())
            {
                uint8_t id = frame.getFrameID();
                std::vector<uint8_t> data = frame.getData();
                std::cout << "ID: " << (int) id << std::endl;
                std::cout << "DATA: " ;
                printVector(data);
                std::cout << std::endl;
            }
        } 
        else 
        {
            std::cerr << "Failed to read data from serial." << std::endl;
        }
     }
        
    
}

