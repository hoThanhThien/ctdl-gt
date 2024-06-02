#include "SapXep.h"
void SapXep::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SapXep::readFromFile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Không thể mở file " << filename << "\n";
        return;
    }
    int value;
    while (file >> value) {
        pt.push_back(value);
    }
    file.close();
}

void SapXep::selectionSort()
{
    int N = pt.size();
    int min;
    for (int i = 0; i < N - 1; i++) {
        min = i;
        for (int j = i + 1; j < N; j++) {
            if (pt[j] < pt[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(pt[min], pt[i]);
        }
    }
}

void SapXep::printData() const
{
    for (int i = 0; i < pt.size(); i++) {
        cout << pt[i] << " ";
    }
        cout << endl;
}
