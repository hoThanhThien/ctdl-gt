#include <iostream>
using namespace std;

// Hàm hoán đổi hai phần tử trong mảng
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm sắp xếp dãy số nguyên theo thứ tự tăng dần (Bubble Sort)
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// Hàm tìm số lớn thứ 3 trong dãy sau khi đã sắp xếp
int timSoLonThuBa(int a[], int n) {
    if (n < 3) {
        return 0; // Không đủ 3 số để tìm max3
    }

    int max1 = a[n-1], max2 = a[n-2], max3 = a[n-3];

    for (int i = n - 4; i >= 0; i--) {
        if (a[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2) {
            max3 = max2;
            max2 = a[i];
        } else if (a[i] > max3) {
            max3 = a[i];
        }
    }

    return max3;
}

// Hàm đếm số lượng phần tử có giá trị lớn nhất trong dãy
int demSoLuongMax(int a[], int n) {
    if (n == 0) {
        return 0;
    }

    int maxElement = a[n - 1];
    int count = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == maxElement) {
            count++;
        } else {
            break; // Vì đã sắp xếp tăng dần nên có thể dừng khi không bằng maxElement nữa
        }
    }

    return count;
}

// Hàm sắp xếp dãy theo giá trị tuyệt đối tăng dần
void sapXepTheoGiaTriTuyetDoiTang(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (abs(a[j]) > abs(a[j + 1])) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// Hàm sắp xếp dãy sao cho số dương đầu mảng giảm dần và số âm cuối mảng tăng dần
void sapXepSoDuongGiamSoAmTang(int a[], int n) {
    // Sắp xếp mảng theo giá trị tuyệt đối giảm dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (abs(a[j]) < abs(a[j + 1])) {
                swap(a[j], a[j + 1]);
            }
        }
    }

    // Tìm vị trí đầu tiên của số âm (nếu có)
    int viTriAmDauTien = n;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            viTriAmDauTien = i;
            break;
        }
    }

    // Sắp xếp số âm (nếu có) tăng dần từ vị trí viTriAmDauTien
    for (int i = viTriAmDauTien; i < n - 1; i++) {
        for (int j = viTriAmDauTien; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// Hàm sắp xếp dãy số sao cho số chẵn đầu mảng tăng dần và số lẻ cuối mảng giảm dần
void sapXepChanTangLeGiam(int a[], int n) {
    // Biến chỉ số để duyệt từ đầu và từ cuối mảng
    int left = 0, right = n - 1;

    // Duyệt mảng và đổi chỗ để đưa số lẻ về cuối mảng và số chẵn về đầu mảng
    while (left < right) {
        // Tìm số lẻ từ đầu mảng và đưa về cuối mảng
        while (left < right && a[left] % 2 == 0) {
            left++;
        }

        // Tìm số chẵn từ cuối mảng và đưa về đầu mảng
        while (left < right && a[right] % 2 != 0) {
            right--;
        }

        // Hoán đổi hai phần tử nếu left < right
        if (left < right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }

    // Sau khi hoàn thành vòng lặp, sắp xếp số chẵn đầu mảng tăng dần và số lẻ cuối mảng giảm dần
    // Phần sắp xếp số chẵn đầu mảng tăng dần đã được thực hiện bởi bubbleSort
    // Duyệt và sắp xếp số lẻ cuối mảng giảm dần
    for (int i = left; i < n; i++) {
        for (int j = left; j < n - 1; j++) {
            if (a[j] < a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}


// Hàm in mảng
void inMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15};
    int n = sizeof(a) / sizeof(a[0]);

    // 1. Sắp xếp dãy số nguyên theo thứ tự tăng dần
    bubbleSort(a, n);
    cout << "1. Dãy sau khi sắp xếp tăng dần: ";
    inMang(a, n);

    // 2. Tìm số lớn thứ 3 trong dãy sau khi đã sắp xếp
    int soLonThuBa = timSoLonThuBa(a, n);
    cout << "2. Số lớn thứ 3 trong dãy là: " << soLonThuBa << endl;

    // 3. Đếm số lượng phần tử có giá trị lớn nhất trong dãy
    int demMax = demSoLuongMax(a, n);
    cout << "3. Số lượng phần tử lớn nhất trong dãy là: " << demMax << endl;

    // 4. Sắp xếp dãy theo giá trị tuyệt đối tăng dần
    sapXepTheoGiaTriTuyetDoiTang(a, n);
    cout << "4. Dãy sau khi sắp xếp theo giá trị tuyệt đối tăng dần: ";
    inMang(a, n);

    // 5. Sắp xếp dãy sao cho số dương đầu mảng giảm dần và số âm cuối mảng tăng dần
    sapXepSoDuongGiamSoAmTang(a, n);
    cout << "5. Dãy sau khi sắp xếp theo yêu cầu của câu 5: ";
    inMang(a,n);
    // 6. Sắp xếp dãy sao cho số chẵn đầu mảng tăng dần và số lẻ cuối mảng giảm dần
    sapXepChanTangLeGiam(a, n);
    cout << "6. Dãy sau khi sắp xếp theo yêu cầu của câu 6: ";
     inMang(a, n);

}
