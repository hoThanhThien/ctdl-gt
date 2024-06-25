#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "term.h"  // Bao gồm lớp Term
#include <iostream> // Bao gồm để thực hiện các thao tác vào/ra

class Polynomial {
private:
    Term* head; // Con trỏ tới hạng tử đầu tiên trong đa thức

public:
    Polynomial();   // Hàm khởi tạo để khởi tạo đa thức
    ~Polynomial();  // Hàm hủy để giải phóng bộ nhớ đã cấp phát
    void addTerm(int coef, int exp); // Phương thức để thêm một hạng tử vào đa thức
    void printPolynomial() const;    // Phương thức để in đa thức
    int evaluate(int x) const;       // Phương thức để tính giá trị của đa thức tại giá trị x cho trước
    Polynomial add(const Polynomial& other) const; // Phương thức để cộng hai đa thức
    Polynomial multiply(const Polynomial& other) const; // Phương thức để nhân hai đa thức
};

#endif // POLYNOMIAL_H
