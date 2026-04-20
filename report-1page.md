# Report 1 Page – FIT4012 Lab 2

## 1. Mục tiêu
Tóm tắt ngắn gọn mục tiêu của bài lab.

## 2. Cách làm
- Hoàn thiện Caesar Cipher cho chữ thường, dấu cách và giải mã.
- Hoàn thiện Rail Fence Cipher cho giải mã, giữ dấu cách, kiểm tra đầu vào và đọc file.
- Chạy thử trên nhiều test case.

## 3. Kết quả chính
### 3.1 Caesar Cipher
| Input | Key | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 3 | L ORYH BRX  |Đúng, giữ khoảng trắng  |
| hello world | 5 |mjqqt btwqi | Đúng, xử lý chữ thường |
| LORYH BRX | 3 | I LOVE YOU   | Đúng, giải mã chính xác |

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 2 |ILV O OEYU | Đúng, zigzag 2 dòng |
| I LOVE YOU | 4 |IY LOEOVU  | Đúng, phân bổ theo 4 rails  |
| IOEOLVYU | 2 |I LOVE YOU |  Đúng, giải mã chính xác |

### 3.3 Input validation / file input
- Trường hợp đầu vào không hợp lệ:
 - Ký tự đặc biệt → bị từ chối
  - Số → bị từ chối
- Kết quả đọc từ `data/input.txt`:
Message from file: I LOVE YOU
Enter rails: 2
Ciphertext: ILV O OEYU

## 4. Kết luận
Qua bài lab này, em đã hiểu rõ nguyên lý hoạt động của các thuật toán mã hóa cổ điển như Caesar Cipher và Rail Fence Cipher. Cụ thể, em nắm được cách dịch chuyển ký tự theo khóa trong Caesar Cipher và cách sắp xếp ký tự theo dạng zigzag trong Rail Fence Cipher để tạo ra bản mã.

Khó khăn lớn nhất của em là xử lý input/output trong C++ (đặc biệt là kết hợp cin và getline) và hiểu cách hoạt động của Rail Fence khi số lượng rails tăng lên. Ngoài ra, việc kiểm tra tính đúng đắn của kết quả cũng cần làm cẩn thận để tránh sai sót về thứ tự ký tự và khoảng trắng.

Thông qua việc tự cài đặt, chạy thử nhiều test case và sửa lỗi, em đã hiểu sâu hơn về cách các thuật toán mã hóa hoạt động, cũng như nhận ra điểm mạnh (đơn giản, dễ triển khai) và điểm yếu (dễ bị phá) của các phương pháp này.
