#include "polynomial.h"
#include <iostream>
#include <cmath> // Bao gồm thư viện để sử dụng hàm pow

// Hàm khởi tạo: Khởi tạo đa thức với danh sách liên kết rỗng
Polynomial::Polynomial() : head(nullptr) {}

// Hàm hủy: Giải phóng bộ nhớ đã cấp phát cho các hạng tử trong đa thức
Polynomial::~Polynomial() {
    while (head) {
        Term* temp = head;
        head = head->next;
        delete temp;
    }
}

// Phương thức để thêm một hạng tử vào đa thức
void Polynomial::addTerm(int coef, int exp) {
    if (coef == 0) return; // Bỏ qua các hệ số bằng 0

    Term* newTerm = new Term(coef, exp); // Tạo hạng tử mới
    if (!head || head->exponent < exp) { // Nếu danh sách rỗng hoặc hạng tử đầu tiên có số mũ nhỏ hơn
        newTerm->next = head;
        head = newTerm;
    }
    else {
        Term* current = head;
        while (current->next && current->next->exponent > exp) { // Tìm vị trí thích hợp để chèn
            current = current->next;
        }
        if (current->exponent == exp) { // Nếu đã có hạng tử với số mũ này, cộng hệ số
            current->coefficient += coef;
            delete newTerm; // Không cần hạng tử mới nữa
        }
        else {
            newTerm->next = current->next;
            current->next = newTerm;
        }
    }
}

// Phương thức để in đa thức
void Polynomial::printPolynomial() const {
    if (!head) { // Nếu đa thức rỗng
        std::cout << "0";
        return;
    }
    Term* current = head;
    while (current) {
        if (current != head && current->coefficient > 0) { // In dấu cộng nếu cần
            std::cout << " + ";
        }
        if (current->exponent == 0) { // Nếu số mũ là 0, chỉ in hệ số
            std::cout << current->coefficient;
        }
        else if (current->exponent == 1) { // Nếu số mũ là 1, in hệ số và x
            std::cout << current->coefficient << "x";
        }
        else { // Nếu số mũ lớn hơn 1, in hệ số và x^số mũ
            std::cout << current->coefficient << "x^" << current->exponent;
        }
        current = current->next;
    }
    std::cout << std::endl;
}

// Phương thức để tính giá trị của đa thức tại giá trị x cho trước
int Polynomial::evaluate(int x) const {
    int result = 0;
    Term* current = head;
    while (current) {
        result += current->coefficient * std::pow(x, current->exponent); // Tính giá trị của từng hạng tử
        current = current->next;
    }
    return result;
}

// Phương thức để cộng hai đa thức
Polynomial Polynomial::add(const Polynomial& other) const {
    Polynomial result;
    Term* term1 = head;
    Term* term2 = other.head;

    while (term1 && term2) {
        if (term1->exponent == term2->exponent) { // Nếu số mũ bằng nhau, cộng hệ số
            result.addTerm(term1->coefficient + term2->coefficient, term1->exponent);
            term1 = term1->next;
            term2 = term2->next;
        }
        else if (term1->exponent > term2->exponent) { // Nếu số mũ của term1 lớn hơn, thêm term1 vào kết quả
            result.addTerm(term1->coefficient, term1->exponent);
            term1 = term1->next;
        }
        else { // Nếu số mũ của term2 lớn hơn, thêm term2 vào kết quả
            result.addTerm(term2->coefficient, term2->exponent);
            term2 = term2->next;
        }
    }

    while (term1) { // Thêm các hạng tử còn lại của term1
        result.addTerm(term1->coefficient, term1->exponent);
        term1 = term1->next;
    }

    while (term2) { // Thêm các hạng tử còn lại của term2
        result.addTerm(term2->coefficient, term2->exponent);
        term2 = term2->next;
    }

    return result;
}

// Phương thức để nhân hai đa thức
Polynomial Polynomial::multiply(const Polynomial& other) const {
    Polynomial result;
    for (Term* term1 = head; term1 != nullptr; term1 = term1->next) { // Lặp qua từng hạng tử của term1
        Polynomial temp;
        for (Term* term2 = other.head; term2 != nullptr; term2 = term2->next) { // Lặp qua từng hạng tử của term2
            temp.addTerm(term1->coefficient * term2->coefficient, term1->exponent + term2->exponent); // Nhân các hạng tử và thêm vào đa thức tạm thời
        }
        result = result.add(temp); // Cộng đa thức tạm thời vào kết quả
    }
    return result;
}
