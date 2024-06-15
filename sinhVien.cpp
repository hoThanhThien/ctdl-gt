#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Định nghĩa cấu trúc SinhVien
struct Student {
    int student_id;     // Mã số sinh viên
    string name;        // Họ và tên sinh viên
    int birth_year;     // Năm sinh
};

// Hàm nhập thông tin sinh viên
void inputStudents(vector<Student>& students, int n) {
    for (int i = 0; i < n; ++i) {
        Student s;  // Tạo một biến SinhVien mới để lưu thông tin sinh viên
        cout << "Nhap ma so sinh vien: ";
        cin >> s.student_id;    // Nhập mã số sinh viên từ bàn phím
        cin.ignore();           // Xóa bộ nhớ đệm để đọc chuỗi kế tiếp (dùng khi kết hợp getline sau cin)
        cout << "Nhap ho va ten sinh vien: ";
        getline(cin, s.name);   // Nhập họ và tên sinh viên (dùng getline để nhập cả chuỗi có dấu cách)
        cout << "Nhap nam sinh: ";
        cin >> s.birth_year;    // Nhập năm sinh từ bàn phím
        students.push_back(s);  // Thêm đối tượng SinhVien s vào vector students
    }
}

// Hàm in thông tin sinh viên
void printStudents(const vector<Student>& students) {
    for (const auto& s : students) {
        cout << s.student_id << "\t" << s.name << "\t" << s.birth_year << endl;
        // In ra mã số sinh viên, họ tên và năm sinh của mỗi sinh viên trong vector students
    }
}

// Hàm sắp xếp danh sách sinh viên theo mã số sinh viên tăng dần
void sortById(vector<Student>& students) {
    for (size_t i = 0; i < students.size() - 1; ++i) {
        for (size_t j = i + 1; j < students.size(); ++j) {
            if (students[i].student_id > students[j].student_id) {
                swap(students[i], students[j]); // Hoán đổi vị trí hai sinh viên nếu cần thiết
            }
        }
    }
}

// Hàm sắp xếp danh sách sinh viên theo tên và năm sinh tăng dần
void sortByNameAndYear(vector<Student>& students) {
    for (size_t i = 0; i < students.size() - 1; ++i) {
        for (size_t j = i + 1; j < students.size(); ++j) {
            // So sánh tên sinh viên, nếu trùng tên thì so sánh theo năm sinh
            if (students[i].name > students[j].name || 
                (students[i].name == students[j].name && students[i].birth_year > students[j].birth_year)) {
                swap(students[i], students[j]); // Hoán đổi vị trí hai sinh viên nếu cần thiết
            }
        }
    }
}

// Hàm main là hàm chính của chương trình
int main() {
    vector<Student> students;    // Khai báo vector chứa các đối tượng SinhVien
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;   // Nhập số lượng sinh viên từ bàn phím

    inputStudents(students, n); // Gọi hàm để nhập thông tin sinh viên

    cout << "\nDanh sach sinh vien sau khi nhap:\n";
    printStudents(students);   // In ra danh sách sinh viên sau khi nhập

    sortById(students); // Sắp xếp danh sách sinh viên theo mã số tăng dần
    cout << "\nDanh sach sinh vien sap xep theo ma so tang dan:\n";
    printStudents(students);   // In ra danh sách sinh viên sau khi sắp xếp theo mã số

    sortByNameAndYear(students);    // Sắp xếp danh sách sinh viên theo tên và năm sinh tăng dần
    cout << "\nDanh sach sinh vien sap xep theo ten va nam sinh tang dan:\n";
    printStudents(students);   // In ra danh sách sinh viên sau khi sắp xếp theo tên và năm sinh

    return 0;   // Kết thúc chương trình
}
