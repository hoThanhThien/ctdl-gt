#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Book
{
private:
	/*Tên sách(chuỗi)
		•	Tác giả(chuỗi, tối đa 5 tác giả)
		•	Nhà xuất bản(chuỗi)
		•	Năm xuất bản(số nguyên)*/
	string tenSach;
	vector<string> tacGia;
	string nhaXuatBan;
	int NamXuatBan;
public:
	

	Book(const string& tenSach, const vector<string>& tacGia, const string& nhaXuatBan, int NamXuatBan);
		
	string gettenSach();
	vector<string> gettacGia();
	string getnhaXuatBan();
	int getNamXuatBan();


	void settenSach(string tenSach);
	void settacGia(vector<string> tacGia);
	void setnhaXuatBan(string nhaXuatBan);
	void setNamXuatBan(int NamXuatBan);

	
};

