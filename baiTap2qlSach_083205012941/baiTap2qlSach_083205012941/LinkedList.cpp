#include "LinkedList.h"

LinkedList::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;

}

void LinkedList::themDau(Book b)
{
	Node* newNode = new Node(b);
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
}



int LinkedList::demSachCuaTG(string Tacgia)
{
	int count=0;
	Node* hienTai = head;
	while (hienTai!=nullptr)
	{
		vector<string> TacGias = hienTai->book.gettacGia();
		for(const string& item: TacGias )
		{ 
			if (item == Tacgia)
			{
				count++;
		}
		}
		hienTai = hienTai->next;
	}
	return count;

}

void LinkedList::timSach(string NhaXuatBan, int NamXuatBan)
{
	Node* hienTai = head;
	while (hienTai!=nullptr)
	{
		if (hienTai->book.getnhaXuatBan() == NhaXuatBan && hienTai->book.getNamXuatBan() == NamXuatBan)
		{
			cout << "Ten sach: " << hienTai->book.gettenSach() << endl;
		}

		hienTai = hienTai->next;
	}

}

