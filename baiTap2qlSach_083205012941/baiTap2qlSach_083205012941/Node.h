#pragma once
#include "Book.h"
class Node
{
public:
	Node* next;
	Book book;

	Node(Book b);
};

