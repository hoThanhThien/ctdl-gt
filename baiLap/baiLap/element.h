/// File: element.h 
#ifndef ELEMENT_H
#define ELEMENT_H
// tham https://stackoverflow.com/questions/37016031/how-to-fix-access-violation-reading-location-error

class element//node link kết 
{
private:
    int data;//kiểu int
    element* pointer;// con trỏ chứa địa chỉ node kế tiếp

public:
    element();// hàm tạo
    element(int);// hàm tạo
    virtual ~element();// dì trắc tơ = hàm hủy

    int Getdata() { return data; }// phương thức get truy cập private:
    void Setdata(int val) { data = val; }
    element* Getpointer() { return pointer; }
    void Setpointer(element* val) { pointer = val; }

protected:

};

#endif // ELEMENT_H