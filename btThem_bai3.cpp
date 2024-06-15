#include <iostream>
#include <vector>

using namespace std;

// Hàm sắp xếp dãy số theo quy luật chỉ dùng một mảng
void sapXepDay(vector<int>& A) {
    vector<int> evenIndices; // Danh sách vị trí của số chẵn
    vector<int> oddIndices;  // Danh sách vị trí của số lẻ

    // Phân loại và lưu trữ vị trí của các số chẵn và lẻ
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] % 2 == 0) {
            evenIndices.push_back(i);
        } else {
            oddIndices.push_back(i);
        }
    }

    // Sắp xếp các số chẵn tăng dần tại các vị trí lưu trong evenIndices
    for (int i = 0; i < evenIndices.size() - 1; ++i) {
        for (int j = 0; j < evenIndices.size() - i - 1; ++j) {
            if (A[evenIndices[j]] > A[evenIndices[j + 1]]) {
                swap(A[evenIndices[j]], A[evenIndices[j + 1]]);
            }
        }
    }

    // Sắp xếp các số lẻ giảm dần tại các vị trí lưu trong oddIndices
    for (int i = 0; i < oddIndices.size() - 1; ++i) {
        for (int j = 0; j < oddIndices.size() - i - 1; ++j) {
            if (A[oddIndices[j]] < A[oddIndices[j + 1]]) {
                swap(A[oddIndices[j]], A[oddIndices[j + 1]]);
            }
        }
    }
}

// Hàm hiển thị dãy số
void hienThiDay(const vector<int>& A) {
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    vector<int> A(n);
    cout << "Nhap " << n << " phan tu cua mang:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    cout << "Dãy ban đầu: ";
    hienThiDay(A);

    sapXepDay(A);

    cout << "Dãy sau khi sắp xếp theo quy luật: ";
    hienThiDay(A);

    return 0;
}
