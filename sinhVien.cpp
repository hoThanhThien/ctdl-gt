#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int student_id;
    string name;
    int birth_year;
};

void inputStudents(vector<Student>& students, int n) {
    for (int i = 0; i < n; ++i) {
        Student s;
        cout << "Nhap ma so sinh vien: ";
        cin >> s.student_id;
        cin.ignore();  // Xoa bo nho dem
        cout << "Nhap ho va ten sinh vien: ";
        getline(cin, s.name);
        cout << "Nhap nam sinh: ";
        cin >> s.birth_year;
        students.push_back(s);
    }
}

void printStudents(const vector<Student>& students) {
    for (const auto& s : students) {
        cout << s.student_id << "\t" << s.name << "\t" << s.birth_year << endl;
    }
}

void sortById(vector<Student>& students) {
    for (size_t i = 0; i < students.size() - 1; ++i) {
        for (size_t j = i + 1; j < students.size(); ++j) {
            if (students[i].student_id > students[j].student_id) {
                swap(students[i], students[j]);
            }
        }
    }
}

void sortByNameAndYear(vector<Student>& students) {
    for (size_t i = 0; i < students.size() - 1; ++i) {
        for (size_t j = i + 1; j < students.size(); ++j) {
            if (students[i].name > students[j].name || 
                (students[i].name == students[j].name && students[i].birth_year > students[j].birth_year)) {
                swap(students[i], students[j]);
            }
        }
    }
}

int main() {
    vector<Student> students;
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    inputStudents(students, n);

    cout << "\nDanh sach sinh vien sau khi nhap:\n";
    printStudents(students);

    sortById(students);
    cout << "\nDanh sach sinh vien sap xep theo ma so tang dan:\n";
    printStudents(students);

    sortByNameAndYear(students);
    cout << "\nDanh sach sinh vien sap xep theo ten va nam sinh tang dan:\n";
    printStudents(students);

    return 0;
}
