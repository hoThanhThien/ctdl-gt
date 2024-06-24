#pragma once
#include<string>
#include "Node.h"
class LinkedList
{
private:
	Node* head;
	Node* tail;
public:
	LinkedList();// constructor

	void themDau(Book b);
	/*void themCuoi(Book b);*/
	
	int demSachCuaTG(string Tacgia);
	void timSach(string NhaXuatBan, int NamXuatBan);
	
};

