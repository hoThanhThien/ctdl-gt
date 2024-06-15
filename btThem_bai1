#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Hàm hoán đổi giá trị của hai phần tử
void hoanDoi(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Thuật toán Selection Sort
void selectionSort(vector<int>& arr, int& soSanh, int& gan) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            soSanh++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        hoanDoi(arr[min_idx], arr[i]);
        gan += 3; // 1 lần hoán đổi = 3 lần gán (a = b, b = a, a = b)
    }
}

// Hàm utility cho Heap Sort
void taoHeap(vector<int>& arr, int n, int i, int& soSanh, int& gan) {
    int lonNhat = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    soSanh += 3; // So sánh l, r và lonNhat

    if (l < n && arr[l] > arr[lonNhat]) {
        lonNhat = l;
    }
    if (r < n && arr[r] > arr[lonNhat]) {
        lonNhat = r;
    }

    if (lonNhat != i) {
        hoanDoi(arr[i], arr[lonNhat]);
        gan += 3; // 1 lần hoán đổi = 3 lần gán (a = b, b = a, a = b)
        taoHeap(arr, n, lonNhat, soSanh, gan);
    }
}

// Thuật toán Heap Sort
void heapSort(vector<int>& arr, int& soSanh, int& gan) {
    int n = arr.size();

    // Xây dựng Heap (sắp xếp lại mảng)
    for (int i = n / 2 - 1; i >= 0; i--) {
        taoHeap(arr, n, i, soSanh, gan);
    }

    // Trích xuất từng phần tử từ Heap
    for (int i = n - 1; i >= 0; i--) {
        hoanDoi(arr[0], arr[i]);
        gan += 3; // 1 lần hoán đổi = 3 lần gán (a = b, b = a, a = b)
        taoHeap(arr, i, 0, soSanh, gan);
    }
}

// Hàm utility cho Quick Sort
int phanDoan(vector<int>& arr, int thap, int cao, int& soSanh, int& gan) {
    int moc = arr[cao];
    int i = (thap - 1);

    for (int j = thap; j <= cao - 1; j++) {
        soSanh++;
        if (arr[j] < moc) {
            i++;
            hoanDoi(arr[i], arr[j]);
            gan += 3; // 1 lần hoán đổi = 3 lần gán (a = b, b = a, a = b)
        }
    }
    hoanDoi(arr[i + 1], arr[cao]);
    gan += 3; // 1 lần hoán đổi = 3 lần gán (a = b, b = a, a = b)
    return (i + 1);
}

// Thuật toán Quick Sort
void quickSort(vector<int>& arr, int thap, int cao, int& soSanh, int& gan) {
    if (thap < cao) {
        int moc = phanDoan(arr, thap, cao, soSanh, gan);

        quickSort(arr, thap, moc - 1, soSanh, gan);
        quickSort(arr, moc + 1, cao, soSanh, gan);
    }
}

// Hàm utility cho Merge Sort
void tron(vector<int>& arr, int thap, int giua, int cao, int& soSanh, int& gan) {
    int n1 = giua - thap + 1;
    int n2 = cao - giua;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[thap + i];
        gan++;
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[giua + 1 + j];
        gan++;
    }

    int i = 0, j = 0, k = thap;
    while (i < n1 && j < n2) {
        soSanh++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            gan++;
        } else {
            arr[k] = R[j];
            j++;
            gan++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        gan++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        gan++;
    }
}

// Thuật toán Merge Sort
void mergeSort(vector<int>& arr, int thap, int cao, int& soSanh, int& gan) {
    if (thap < cao) {
        int giua = thap + (cao - thap) / 2;

        mergeSort(arr, thap, giua, soSanh, gan);
        mergeSort(arr, giua + 1, cao, soSanh, gan);

        tron(arr, thap, giua, cao, soSanh, gan);
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan tu mang: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Nhap " << n << " phan tu cua mang:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Copy mảng ban đầu để sử dụng cho các thuật toán sắp xếp
    vector<int> arrSelection = arr;
    vector<int> arrHeap = arr;
    vector<int> arrQuick = arr;
    vector<int> arrMerge = arr;

    // Biến để lưu số phép so sánh và gán của từng thuật toán
    int soSanhSelection = 0, ganSelection = 0;
    int soSanhHeap = 0, ganHeap = 0;
    int soSanhQuick = 0, ganQuick = 0;
    int soSanhMerge = 0, ganMerge = 0;

    // Selection Sort
    selectionSort(arrSelection, soSanhSelection, ganSelection);
    cout << "Selection Sort: So sanh = " << soSanhSelection << ", Gan = " << ganSelection << endl;

    // Heap Sort
    heapSort(arrHeap, soSanhHeap, ganHeap);
    cout << "Heap Sort: So sanh = " << soSanhHeap << ", Gan = " << ganHeap << endl;

    // Quick Sort
    quickSort(arrQuick, 0, n - 1, soSanhQuick, ganQuick);
    cout << "Quick Sort: So sanh = " << soSanhQuick << ", Gan = " << ganQuick << endl;

    // Merge Sort
    mergeSort(arrMerge, 0, n - 1, soSanhMerge, ganMerge);
    cout << "Merge Sort: So sanh = " << soSanhMerge << ", Gan = " << ganMerge << endl;

    return 0;
}
