﻿/// File: linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "element.h"

class linkedlist
{
private:
    element* head;// tp đầu
    element* tail;// cuối
    int nNum;// phần tử dãy
public:
    linkedlist();
    virtual ~linkedlist();
    element* Gethead() { return head; }
    void Sethead(element* val) { head = val; }
    element* Gettail() { return tail; }
    void Settail(element* val) { tail = val; }
    void InsertFirst(element*);
    void InsertTail(element*);
    bool DeleteFirst();// xóa phần tử đầu tiên
    void Travel();

protected:


};

#endif // LINKEDLIST_H