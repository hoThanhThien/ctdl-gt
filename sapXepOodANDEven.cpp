#include <iostream>
using namespace std;

// Hàm sắp xếp mảng theo thứ tự tăng dần sử dụng thuật toán sắp xếp nổi bọt (bubble sort)
void bubbleSortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int a[100];
    int n;
    cin >> n; // Nhập số lượng phần tử của mảng
    
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Nhập từng phần tử của mảng
    }
    
    // Bước 1: Sắp xếp toàn bộ mảng theo thứ tự tăng dần
    bubbleSortAscending(a, n);
    
    // Bước 2: Tìm vị trí bắt đầu của các số lẻ
    int startOdd = 0;
    while (startOdd < n && a[startOdd] % 2 == 0) {
        startOdd++; // Tăng chỉ số cho đến khi gặp số lẻ đầu tiên
    }
    
    // Bước 3: Sắp xếp lại các số lẻ theo thứ tự giảm dần
    for (int i = startOdd; i < n - 1; i++) {
        for (int j = startOdd; j < n - i + startOdd - 1; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
    // In ra mảng đã được sắp xếp
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}
