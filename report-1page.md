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
| I LOVE YOU | 3 | L ORYH BRX |Đúng, giữ khoảng trắng  |
| hello world | 5 |  mjqqt btwqi| Đúng, xử lý chữ thường |
| LORYH BRX | 3 | I LOVE YOU  | Đúng, giải mã chính xác |

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 2 | ILV O OEYU | Đúng, zigzag 2 dòng |
| I LOVE YOU | 4 |EYLVOOU  | Đúng, phân bổ theo 4 rails  |
| IOEOLVYU | 2 | ILOVEYOU |  Đúng, giải mã chính xác |

### 3.3 Input validation / file input
- Trường hợp đầu vào không hợp lệ:
 - Ký tự đặc biệt → bị từ chối
  - Số → bị từ chối
- Kết quả đọc từ `data/input.txt`:
Message from file: I LOVE YOU
Enter rails: 2
Ciphertext: ILV O OEYU

## 4. Kết luận
Nêu ngắn gọn em học được gì từ bài lab, khó khăn lớn nhất là gì, và điều gì giúp em hiểu rõ hơn về Caesar hoặc Rail Fence Cipher.
