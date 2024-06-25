#ifndef TERM_H
#define TERM_H

class Term {
public:
    int coefficient; // Hệ số của hạng tử
    int exponent;    // Số mũ của hạng tử
    Term* next;      // Con trỏ tới hạng tử tiếp theo trong danh sách

    // Hàm khởi tạo để khởi tạo một hạng tử với hệ số và số mũ cho trước
    Term(int coef, int exp) : coefficient(coef), exponent(exp), next(nullptr) {}
};

#endif // TERM_H
