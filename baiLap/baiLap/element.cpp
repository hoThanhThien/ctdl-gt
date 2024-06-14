/// File: element.cpp
#include "element.h"

element::element()// hàm tạo
{
    //ctor
    this->data = 0;
    this->pointer = nullptr;
}
element::element(int data)
{
    //ctor
    this->data = data;
    this->pointer = nullptr;
}

element::~element()
{
    //dtor
}
