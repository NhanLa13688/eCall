#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <unistd.h>
#include <chrono>


#define PORT 1234

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Tạo socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Thiết lập socket để tái sử dụng địa chỉ và cổng
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Gán địa chỉ và cổng cho socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Lắng nghe tất cả địa chỉ IP
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
while(1)
{
    // Lắng nghe kết nối
    if (listen(server_fd, 3) < 0) {
        perror("Listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    std::cout << "Server đang chạy trên cổng " << PORT << "..." << std::endl;

    // Chờ client kết nối
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("Accept");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    std::cout << "Client đã kết nối!" << std::endl;

    // Gửi thông báo tới client
    const char *message = "Kết nối thành công!";
    send(client_socket, message, strlen(message), 0);
    std::cout << "Đã gửi: " << message << std::endl;


    // Gửi dữ liệu tốc độ định kỳ
    int speed = 0; // Giá trị tốc độ khởi đầu
    while (true) {
        // Tạo giá trị tốc độ giả lập
        speed = (speed + 1) % 135; // Tăng tốc độ, quay vòng từ 0 đến 120

        // Chuyển đổi giá trị tốc độ thành chuỗi
        std::string speedMessage = std::to_string(speed);

        // Gửi tốc độ tới client
        send(client_socket, speedMessage.c_str(), speedMessage.size(), 0);
        std::cout << "Đã gửi tốc độ: " << speed << " km/h" << std::endl;


        // Chờ 2 giây trước khi gửi giá trị tiếp theo
        usleep(200000);
  //std::this_thread::sleep_for(std::chrono::seconds(2));

  }
}
    // Đóng kết nối
    close(client_socket);
    close(server_fd);

    return 0;
}
