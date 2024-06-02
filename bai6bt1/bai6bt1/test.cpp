/*#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
// Hàm để hoán đổi hai số nguyên
void Swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}

// Hàm Selection Sort
void SelectionSort( vector<int>& a)
{
    int N = a.size();
    int min; // Chỉ số phần tử nhỏ nhất trong dãy hiện hành 
    for (int i = 0; i < N - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < N; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            Swap(a[min], a[i]);
        }
    }
}

int main()
{
     ifstream file("input.txt");
    if (!file.is_open())
    {
         cerr << "Khong the mo file input.txt\n";
        return 1;
    }

     vector<int> a;
    int n;

    // Đọc các số nguyên từ file và lưu vào vector
    while (file >> n)
    {
        a.push_back(n);
    }
    file.close();

    // Gọi hàm SelectionSort để sắp xếp dãy số
    SelectionSort(a);

    // In ra dãy số đã được sắp xếp
    for (int i = 0; i < a.size(); i++)
    {
         cout << a[i] << " ";
    }
     cout <<  endl;

    return 0;
}
*/