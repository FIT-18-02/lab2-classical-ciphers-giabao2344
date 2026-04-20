#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Q7: Kiểm tra đầu vào chỉ cho phép chữ cái và khoảng trắng
bool is_valid_message(const string &text) {
    if (text.empty()) return false;
    for (char c : text) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ') {
            return false;
        }
    }
    return true;
}

// Q6: Giữ nguyên dấu cách (Logic trong vòng lặp for đã thực hiện việc này)
string rail_fence_encrypt(const string &plaintext, int rails) {
    if (rails <= 1 || plaintext.empty()) return plaintext;

    vector<string> fence(rails, "");
    int rail = 0;
    int direction = 1;

    for (char c : plaintext) {
        fence[rail] += c;
        rail += direction;
        if (rail == rails - 1 || rail == 0) direction = -direction;
    }

    string ciphertext;
    for (const string &row : fence) ciphertext += row;
    return ciphertext;
}

// Q5: Viết hàm giải mã
string rail_fence_decrypt(const string &ciphertext, int rails) {
    if (rails <= 1 || ciphertext.empty()) return ciphertext;

    // Bước 1: Tạo ma trận để đánh dấu vị trí zigzag
    vector<vector<char>> fence(rails, vector<char>(ciphertext.length(), '\n'));
    
    int rail = 0;
    int direction = 1;
    for (int i = 0; i < ciphertext.length(); i++) {
        fence[rail][i] = '*'; // Đánh dấu vị trí sẽ có ký tự
        rail += direction;
        if (rail == rails - 1 || rail == 0) direction = -direction;
    }

    // Bước 2: Điền các ký tự từ bản mã vào các vị trí đã đánh dấu
    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < ciphertext.length(); j++) {
            if (fence[i][j] == '*' && index < ciphertext.length()) {
                fence[i][j] = ciphertext[index++];
            }
        }
    }

    // Bước 3: Đọc lại ma trận theo hình zigzag để lấy bản rõ
    string plaintext = "";
    rail = 0;
    direction = 1;
    for (int i = 0; i < ciphertext.length(); i++) {
        plaintext += fence[rail][i];
        rail += direction;
        if (rail == rails - 1 || rail == 0) direction = -direction;
    }
    return plaintext;
}

// Q8: Đọc thông điệp từ file
string read_message_from_file(const string &path) {
    ifstream fin(path);
    if (!fin.is_open()) {
        return ""; // Trả về rỗng nếu không mở được file
    }
    string line;
    getline(fin, line);
    return line;
}

int main() {
    cout << "=== Rail Fence Cipher Demo ===\n";
    cout << "1. Encrypt\n2. Decrypt\n3. Read from file and encrypt\nChoose: ";

    int choice;
    cin >> choice;
    cin.ignore();

    string message;
    int rails;

    if (choice == 3) {
        message = read_message_from_file("data/input.txt");
        if (message.empty()) {
            cout << "Could not read file or file is empty.\n";
            return 0;
        }
        cout << "Message from file: " << message << "\n";
    } else {
        cout << "Enter message: ";
        getline(cin, message);
    }

    cout << "Enter rails: ";
    cin >> rails;

    if (!is_valid_message(message)) {
        cout << "Invalid input. Only letters and spaces are allowed.\n";
        return 0;
    }

    if (choice == 1 || choice == 3) {
        cout << "Ciphertext: " << rail_fence_encrypt(message, rails) << "\n";
    } else if (choice == 2) {
        cout << "Plaintext: " << rail_fence_decrypt(message, rails) << "\n";
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}