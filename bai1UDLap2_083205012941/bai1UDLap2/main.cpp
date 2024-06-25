#include <iostream>
#include "polynomial.h"

int main() {
    Polynomial poly1, poly2;

    // Thêm các hạng tử vào đa thức đầu tiên
    poly1.addTerm(5, 2);
    poly1.addTerm(3, 1);
    poly1.addTerm(2, 0);

    // Thêm các hạng tử vào đa thức thứ hai
    poly2.addTerm(4, 1);
    poly2.addTerm(1, 0);

    // Hiển thị cả hai đa thức
    std::cout << "Da thuc 1: ";
    poly1.printPolynomial();

    std::cout << "Da thuc 2: ";
    poly2.printPolynomial();

    // Cộng hai đa thức
    Polynomial sum = poly1.add(poly2);
    std::cout << "Tong: ";
    sum.printPolynomial();

    // Nhân hai đa thức
    Polynomial product = poly1.multiply(poly2);
    std::cout << "Tich: ";
    product.printPolynomial();

    return 0;
}
