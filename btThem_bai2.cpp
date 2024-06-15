#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Hàm hoán đổi giá trị của hai phần tử
void hoanDoi(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm phân đoạn mảng và trả về vị trí của pivot
int phanDoan(vector<int>& arr, int thap, int cao) {
    int moc = arr[thap]; // Chọn phần tử đầu dãy làm pivot
    int i = thap - 1;

    for (int j = thap; j <= cao; j++) {
        if (arr[j] < moc) {
            i++;
            hoanDoi(arr[i], arr[j]);
        }
    }
    hoanDoi(arr[i + 1], arr[thap]);
    return (i + 1);
}

// Hàm QuickSort chọn pivot là phần tử đầu dãy
void quickSortPivotDau(vector<int>& arr, int thap, int cao) {
    if (thap < cao) {
        int moc = phanDoan(arr, thap, cao);

        quickSortPivotDau(arr, thap, moc - 1);
        quickSortPivotDau(arr, moc + 1, cao);
    }
}

// Hàm phân đoạn mảng với pivot là phần tử ở giữa dãy
int phanDoanPivotGiua(vector<int>& arr, int thap, int cao) {
    int moc = arr[(thap + cao) / 2]; // Chọn phần tử ở giữa dãy làm pivot
    int i = thap;
    int j = cao;

    while (true) {
        while (arr[i] < moc) i++;
        while (arr[j] > moc) j--;

        if (i >= j) return j;

        hoanDoi(arr[i], arr[j]);
        i++;
        j--;
    }
}

// Hàm QuickSort chọn pivot là phần tử ở giữa dãy
void quickSortPivotGiua(vector<int>& arr, int thap, int cao) {
    if (thap < cao) {
        int moc = phanDoanPivotGiua(arr, thap, cao);

        quickSortPivotGiua(arr, thap, moc);
        quickSortPivotGiua(arr, moc + 1, cao);
    }
}

// Hàm tạo mảng ngẫu nhiên
vector<int> taoMangNgauNhien(int n) {
    vector<int> arr(n);
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 1000;
    }
    return arr;
}

// Hàm hiển thị mảng
void hienThiMang(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu mang: ";
    cin >> n;

    // Tạo mảng ngẫu nhiên
    vector<int> arrDau = taoMangNgauNhien(n);
    vector<int> arrGiua = arrDau; // Sao chép mảng ngẫu nhiên để sử dụng cho pivot giữa

    // Hiển thị mảng nếu cần
    // cout << "Mang ngau nhien: ";
    // hienThiMang(arrDau);

    // Đo thời gian chạy và sắp xếp với pivot là phần tử đầu dãy
    clock_t startDau = clock();
    quickSortPivotDau(arrDau, 0, n - 1);
    clock_t finishDau = clock();
    double durationDau = (double)(finishDau - startDau) / CLOCKS_PER_SEC;

    // Đo thời gian chạy và sắp xếp với pivot là phần tử ở giữa dãy
    clock_t startGiua = clock();
    quickSortPivotGiua(arrGiua, 0, n - 1);
    clock_t finishGiua = clock();
    double durationGiua = (double)(finishGiua - startGiua) / CLOCKS_PER_SEC;

    // Hiển thị thời gian chạy
    cout << "Thoi gian chay QuickSort voi pivot la phan tu dau day: " << durationDau << " giay" << endl;
    cout << "Thoi gian chay QuickSort voi pivot la phan tu o giua day: " << durationGiua << " giay" << endl;

    return 0;
}
