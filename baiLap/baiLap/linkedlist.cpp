/// File: linkedlist.cpp

#include "linkedlist.h"
#include <iostream>
using namespace std;
linkedlist::linkedlist()
{
    //ctor
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}

linkedlist::~linkedlist()
{
    //dtor
}
void linkedlist::InsertFirst(element* e) {
    if (this->head == nullptr)
        this->head = this->tail = e;
    else {
        e->Setpointer(this->head); //step 1
        this->head = e;  // step 2
    }
    this->nNum++;

}
void linkedlist::InsertTail(element* e) {
    if (this->head == nullptr)
        this->head = this->tail = e;
    else {
        this->tail->Setpointer(e);// step 1// lấy giá trị pt cuối gán cho pt mới
        this->tail = e;    // step 2
    }
    this->nNum++;
}
void linkedlist::Travel() {// xuất data ra 
    element* p = this->head;
    while (p != nullptr) {
        cout << p->Getdata() << "\t";
        p = p->Getpointer();
    }
}


int linkedlist::count(int x)
{
    int count = 0;
    element* p = this->head;// địa chỉ đầu
    while (p != nullptr)// địa chỉ đầu =null dừng
    {
        if (p->Getdata() == x)
        {
            count++;
        }
        p = p->Getpointer();
    }
    return count;
}

void linkedlist::InsertAfter(element* p, element* newElement)
{
    if (p != nullptr) {
        newElement->Setpointer(p->Getpointer());
        p->Setpointer(newElement);
        if (this->tail == p) {
            this->tail = newElement;
        }
        this->nNum++;
    }
    else {
        InsertFirst(newElement);
    }
}
bool linkedlist::DeleteFirst() {
    if (this->tail == nullptr) return false;
    else {
        element* p = this->tail;
        this->tail = this->tail->Getpointer();
        delete p;
        return true;
    }
}
