// Kết nối tới WebSocket server
var socket = io.connect('http://' + document.domain + ':' + location.port);

socket.on('connect', function() {
    console.log('WebSocket connected successfully!');
});
socket.on('disconnect', function() {
    console.error('WebSocket disconnected!');
});


// Tự động tải dữ liệu từ cơ sở dữ liệu khi tải trang
window.onload = function () {
    showClientData();
    showConfirmHistory();

    // Đặt bản đồ mặc định
    document.getElementById("map-frame").src = "https://maps.google.com/maps?q=0,0&z=2&output=embed";
    const today = new Date().toISOString().split('T')[0];
    document.getElementById('filter-date').value = today;

    filterConfirmHistoryByDate();
    fetchRequestedData(); // Hiển thị dữ liệu phần Receive the requested
    fetchConfirmHistory(); // Hiển thị dữ liệu lịch sử xác nhận

    // Khởi tạo biểu đồ thống kê
    initializeStatChart();

    // Cập nhật dữ liệu biểu đồ cho ngày hiện tại
    document.getElementById('chart-filter-date').value = today; // Đặt ngày mặc định cho bộ lọc biểu đồ
    updateChartData(); // Lấy dữ liệu biểu đồ
};

socket.on('update', function (data) {
    console.log("Received data from server:", data);

    // Cập nhật thông tin giao diện
    document.getElementById("vin_id").innerText = data.vin_id || "No VIN_ID received yet";
    document.getElementById("ip-address").innerText = data.ip || "No IP received yet";
    document.getElementById("latitude").innerText = data.latitude || "Latitude not available";
    document.getElementById("longitude").innerText = data.longitude || "Longitude not available";

    // Cập nhật Google Maps iframe
    if (data.latitude !== undefined && data.longitude !== undefined) {
        const mapUrl = `https://www.google.com/maps?q=${data.latitude},${data.longitude}&z=15&output=embed`;
        document.getElementById("map-frame").src = mapUrl;
        document.getElementById("map-frame").style.display = "block";
    } else {
        // Hiển thị bản đồ mặc định khi không có dữ liệu
        document.getElementById("map-frame").src = "https://maps.google.com/maps?q=0,0&z=2&output=embed";
        document.getElementById("map-frame").style.display = "block";
    }
    
    // Cập nhật biểu đồ eCall
    const currentHour = new Date().getHours(); // Lấy giờ hiện tại
    statChart.data.datasets[0].data[currentHour]++; // Tăng số lượng eCall tại giờ hiện tại
    statChart.update();
    
    // Kiểm tra xem dữ liệu đã tồn tại trong CSDL (requestedData) hay chưa
    const existingIndex = requestedData.findIndex(entry => entry[0] === data.vin_id);
    let newEntryClass = '';

    if (existingIndex !== -1) {
        // Đã tồn tại trong CSDL, cập nhật và gắn trạng thái hiệu ứng màu vàng
        requestedData.splice(existingIndex, 1); // Xóa dữ liệu cũ
        requestedData.unshift([data.vin_id, data.ip, data.latitude, data.longitude, new Date().toUTCString()]); // Thêm lên đầu
        newEntryClass = 'highlight'; // Gắn trạng thái màu vàng
    } else {
        // Chưa tồn tại, thêm mới và gắn trạng thái hiệu ứng màu đỏ
        requestedData.unshift([data.vin_id, data.ip, data.latitude, data.longitude, new Date().toUTCString()]);
        newEntryClass = 'new-entry'; // Gắn trạng thái màu đỏ
    }

    // Hiển thị lại dữ liệu và áp dụng hiệu ứng
    displayRequestedPage(newEntryClass);
    document.getElementById('client-data-table').style.display = 'table';
});

socket.on('confirm_update', function (data) {
    console.log("Confirmation update received:", data);

    // Lấy giờ từ dữ liệu nhận được
    const confirmedHour = data.hour;

    // Cập nhật biểu đồ "Đã xác nhận cứu hộ"
    if (statChart.data.datasets[1].data[confirmedHour] !== undefined) {
        statChart.data.datasets[1].data[confirmedHour]++;
    } else {
        statChart.data.datasets[1].data[confirmedHour] = 1; // Trường hợp dữ liệu ban đầu trống
    }
    statChart.update(); // Cập nhật biểu đồ

    // Kiểm tra xem VIN ID đã tồn tại trong confirmHistoryData chưa
    const existingIndex = confirmHistoryData.findIndex(entry => entry[0] === data.vin_id);
    if (existingIndex === -1) {
        // Nếu chưa tồn tại, thêm mới vào confirmHistoryData
        confirmHistoryData.unshift([data.vin_id, data.timestamp]);
        displayPage(); // Hiển thị lại bảng với phân trang
    } else {
        console.log(`VIN ID ${data.vin_id} đã tồn tại trong lịch sử, không thêm trùng lặp.`);
    }
});



socket.on('disconnect', function() {
    console.error("Disconnected from WebSocket server");
});

// Hàm để hiển thị toàn bộ dữ liệu từ cơ sở dữ liệu
function showClientData() {
    fetch('/data')
        .then(response => response.json())
        .then(data => {
            console.log('Received data from /data endpoint:', data);

            if (data.error) {
                alert('Error: ' + data.error);
                return;
            }

            // Xóa dữ liệu cũ trong bảng
            var tableBody = document.getElementById('client-data-body');
            tableBody.innerHTML = '';

            // Thêm dữ liệu mới từ cơ sở dữ liệu
            data.forEach(client => {
                var row = document.createElement('tr');
                row.innerHTML = `
                    <td>${client[0]}</td>
                    <td>${client[1]}</td>
                    <td>${client[2]}</td>
                    <td>${client[3]}</td>
                    <td>${client[4]}</td>
                    <td><a href="https://www.google.com/maps?q=${client[2]},${client[3]}" target="_blank">View on Map</a></td>
                    <td><button class="confirm-btn" onclick="confirmAction('${client[0]}')">Confirm</button></td>
                `;
                tableBody.appendChild(row);
            });

            // Hiển thị bảng
            document.getElementById('client-data-table').style.display = 'table';
        })
        .catch(error => {
            console.error('Error fetching client data:', error);
            alert('Error fetching client data');
        });
}

function confirmAction(vin_id) {
    fetch('/confirm', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ vin_id: vin_id })
    })
    .then(response => response.json())
    .then(data => {
        if (data.message) {
            alert(data.message);

            // Kiểm tra trùng lặp trong confirmHistoryData trước khi thêm
            const existingIndex = confirmHistoryData.findIndex(entry => entry[0] === vin_id);
            if (existingIndex === -1) {
                confirmHistoryData.unshift([vin_id, new Date().toISOString()]);
                displayPage(); // Hiển thị lại dữ liệu với phân trang
            } else {
                console.log(`VIN ID ${vin_id} đã tồn tại trong lịch sử, không thêm trùng lặp.`);
            }

            // Cập nhật biểu đồ "Đã xác nhận cứu hộ"
            const currentHour = new Date().getHours(); // Lấy giờ hiện tại
            statChart.data.datasets[1].data[currentHour]++; // Tăng số lượng xác nhận tại giờ hiện tại
            statChart.update(); // Cập nhật biểu đồ
        } else {
            console.error('Error:', data.error);
        }
    })
    .catch(error => console.error('Error confirming action:', error));
}


function showConfirmHistory() {
    fetch('/confirm-history')
        .then(response => response.json())
        .then(data => {
            console.log('Received data from /confirm-history endpoint:', data);

            var tableBody = document.getElementById('confirm-history-body');
            tableBody.innerHTML = '';

            data.forEach(entry => {
                var row = document.createElement('tr');
                row.innerHTML = `
                    <td>${entry[0]}</td>
                    <td>${new Date(entry[1]).toUTCString()}</td>
                `;
                tableBody.appendChild(row);
            });
        })
        .catch(error => {
            console.error('Error fetching confirm history:', error);
            alert('Error fetching confirm history');
        });
}

let isFilterMode = false; // Cờ kiểm tra xem có đang ở chế độ lọc hay không

// Biến lưu trữ dữ liệu lịch sử và số trang
let confirmHistoryData = [];
let currentPage = 1;
const rowsPerPage = 5; // Số hàng hiển thị trên mỗi trang

// Hàm lấy dữ liệu từ server
function fetchConfirmHistory() {
    fetch('/confirm-history')
        .then(response => response.json())
        .then(data => {
            confirmHistoryData = data;
            currentPage = 1; // Reset về trang đầu tiên
            displayPage(); // Hiển thị trang đầu tiên
        })
        .catch(error => {
            console.error('Error fetching confirm history:', error);
            alert('Error fetching confirm history');
        });
}

// Cập nhật trạng thái nút phân trang
function updatePaginationControls() {
    const totalPages = Math.ceil(confirmHistoryData.length / rowsPerPage);
    document.getElementById('page-info').innerText = `Page ${currentPage} of ${totalPages}`;
    document.getElementById('prev-page').disabled = currentPage === 1;
    document.getElementById('next-page').disabled = currentPage === totalPages;
}

// Xử lý khi nhấn nút Previous
function prevPage() {
    if (currentPage > 1) {
        currentPage--;
        displayPage();
    }
}

// Xử lý khi nhấn nút Next
function nextPage() {
    if (currentPage < Math.ceil(confirmHistoryData.length / rowsPerPage)) {
        currentPage++;
        displayPage();
    }
}

// Hàm gọi khi nhấn Confirm
function confirmAction(vin_id) {
    fetch('/confirm', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ vin_id: vin_id })
    })
        .then(response => response.json())
        .then(data => {
            if (data.message) {
                alert(data.message);

                // Thêm dữ liệu mới vào danh sách confirmHistoryData
                confirmHistoryData.unshift([vin_id, new Date().toISOString()]);
                displayPage(); // Hiển thị lại bảng
            } else {
                console.error('Error:', data.error);
            }
        })
        .catch(error => console.error('Error confirming action:', error));
}

let requestedData = []; // Dữ liệu toàn bộ cho phần Receive the requested
let requestedCurrentPage = 1; // Trang hiện tại
const requestedRowsPerPage = 3; // Số hàng trên mỗi trang

// Hàm lấy dữ liệu và hiển thị
function fetchRequestedData() {
    fetch('/data') // Endpoint lấy dữ liệu
        .then(response => response.json())
        .then(data => {
            requestedData = data;
            requestedCurrentPage = 1; // Reset về trang đầu tiên
            displayRequestedPage(); // Hiển thị trang đầu tiên
        })
        .catch(error => {
            console.error('Error fetching requested data:', error);
            alert('Error fetching requested data');
        });
}

// Hiển thị dữ liệu của trang hiện tại
function displayRequestedPage(newEntryClass = '') {
    const startIndex = (requestedCurrentPage - 1) * requestedRowsPerPage;
    const endIndex = startIndex + requestedRowsPerPage;
    const pageData = requestedData.slice(startIndex, endIndex);

    const tableBody = document.getElementById('client-data-body');
    tableBody.innerHTML = ''; // Xóa dữ liệu cũ

    pageData.forEach((entry, index) => {
        const row = document.createElement('tr');
        row.innerHTML = `
            <td>${entry[0]}</td>
            <td>${entry[1]}</td>
            <td>${entry[2]}</td>
            <td>${entry[3]}</td>
            <td>${entry[4]}</td>
            <td><a href="https://www.google.com/maps?q=${entry[2]},${entry[3]}" target="_blank">View on Map</a></td>
            <td><button class="confirm-btn" onclick="confirmAction('${entry[0]}')">Confirm</button></td>
        `;
        tableBody.appendChild(row);

        // Chỉ áp dụng hiệu ứng cho dòng đầu tiên (mới nhận được)
        if (index === 0 && newEntryClass) {
            row.classList.add(newEntryClass);
            setTimeout(() => row.classList.remove(newEntryClass), 3000); // Hiệu ứng 3 giây
        }
    });

    // Cập nhật phân trang
    updateRequestedPaginationControls();
}

// Cập nhật trạng thái nút phân trang
function updateRequestedPaginationControls() {
    const totalPages = Math.ceil(requestedData.length / requestedRowsPerPage);
    document.getElementById('requested-page-info').innerText = `Page ${requestedCurrentPage} of ${totalPages}`;
    document.getElementById('requested-prev-page').disabled = requestedCurrentPage === 1;
    document.getElementById('requested-next-page').disabled = requestedCurrentPage === totalPages;
}

// Xử lý khi nhấn nút Previous
function prevRequestedPage() {
    if (requestedCurrentPage > 1) {
        requestedCurrentPage--;
        displayRequestedPage();
    }
}

// Xử lý khi nhấn nút Next
function nextRequestedPage() {
    if (requestedCurrentPage < Math.ceil(requestedData.length / requestedRowsPerPage)) {
        requestedCurrentPage++;
        displayRequestedPage();
    }
}


// Lọc Confirm History theo ngày
function filterConfirmHistoryByDate() {
    const selectedDate = document.getElementById('filter-date').value;

    if (!selectedDate) {
        // Nếu không có ngày được chọn (giá trị bị xóa), hiển thị lại tất cả dữ liệu
        displayPage();
        return;
    }

    // Lọc dữ liệu theo ngày đã chọn
    const filteredData = confirmHistoryData.filter(entry => {
        const entryDate = new Date(entry[1]).toISOString().split('T')[0]; // Chuyển Timestamp thành YYYY-MM-DD
        return entryDate === selectedDate; // So sánh với ngày được chọn
    });

    displayFilteredHistory(filteredData);
}

// Hiển thị dữ liệu đã lọc
function displayFilteredHistory(filteredData) {
    const tableBody = document.getElementById('confirm-history-body');
    const paginationControls = document.getElementById('pagination-controls');

    tableBody.innerHTML = ''; // Xóa dữ liệu cũ

    if (filteredData.length === 0) {
        tableBody.innerHTML = '<tr><td colspan="2">No records found for the selected date.</td></tr>';
        paginationControls.style.display = 'none'; // Ẩn phân trang khi không có dữ liệu
        return;
    }

    paginationControls.style.display = 'none'; // Ẩn phân trang khi lọc theo ngày

    filteredData.forEach(entry => {
        const row = document.createElement('tr');
        row.innerHTML = `
            <td>${entry[0]}</td>
            <td>${new Date(entry[1]).toUTCString()}</td>
        `;
        tableBody.appendChild(row);
    });
}

// Hàm hiển thị tất cả dữ liệu và bật lại phân trang
function displayPage() {
    const startIndex = (currentPage - 1) * rowsPerPage;
    const endIndex = startIndex + rowsPerPage;
    const pageData = confirmHistoryData.slice(startIndex, endIndex);

    const tableBody = document.getElementById('confirm-history-body');
    const paginationControls = document.getElementById('pagination-controls');

    tableBody.innerHTML = ''; // Xóa dữ liệu cũ

    pageData.forEach(entry => {
        const row = document.createElement('tr');
        row.innerHTML = `
            <td>${entry[0]}</td>
            <td>${new Date(entry[1]).toUTCString()}</td>
        `;
        tableBody.appendChild(row);
    });

    paginationControls.style.display = 'block'; // Hiển thị phân trang
    updatePaginationControls();
}

let statChart;
function initializeStatChart() {
    const ctx = document.getElementById('statChart').getContext('2d');
    statChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: Array.from({ length: 24 }, (_, i) => `${i}:00`), // 24 giờ
            datasets: [
                {
                    label: 'Total number of eCalls',
                    data: Array(24).fill(0), // Khởi tạo dữ liệu rỗng
                    borderColor: 'rgb(255, 0, 0)',
                    borderWidth: 2,
                    tension: 0.4
                },
                {
                    label: 'Rescue confirmed',
                    data: Array(24).fill(0), // Khởi tạo dữ liệu rỗng
                    borderColor: 'rgb(0, 182, 0)',
                    borderWidth: 2,
                    tension: 0.4
                }
            ]
        },
        options: {
            responsive: true,
            scales: {
                x: {
                    title: {
                        display: true,
                        text: 'Time'
                    }
                },
                y: {
                    title: {
                        display: true,
                        text: 'Number'
                    },
                    beginAtZero: true
                }
            }
        }
    });
}

function updateChartData() {
    const selectedDate = document.getElementById('chart-filter-date').value;

    if (!selectedDate) {
        alert('Please select a valid date!');
        return;
    }

    fetch(`/chart-data?date=${selectedDate}`)
        .then(response => response.json())
        .then(data => {
            if (data.error) {
                console.error('Error fetching chart data:', data.error);
                return;
            }

            // Cập nhật dữ liệu từ API
            statChart.data.labels = data.timestamps.map(hour => `${hour}:00`);
            statChart.data.datasets[0].data = data.totalECalls;
            statChart.data.datasets[1].data = data.confirmed;
            statChart.update(); // Cập nhật biểu đồ
        })
        .catch(error => console.error('Error fetching chart data:', error));
}
