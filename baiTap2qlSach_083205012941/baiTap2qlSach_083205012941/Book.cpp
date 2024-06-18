#include "Book.h"


Book::Book(const string& tenSach, const vector<string>& tacGia, const string& nhaXuatBan, int NamXuatBan)
    : tenSach(tenSach), tacGia(tacGia), nhaXuatBan(nhaXuatBan), NamXuatBan(NamXuatBan)
{
}

string Book::gettenSach()
{
    return tenSach;
}

vector<string> Book::gettacGia()
{
    return tacGia;
}

string Book::getnhaXuatBan()
{
    return nhaXuatBan;
}

int Book::getNamXuatBan()
{
    return NamXuatBan;
}

void Book::settenSach(string tenSach)
{
    this->tenSach = tenSach;
}

void Book::settacGia(vector<string> tacGia)
{
    this->tacGia = tacGia;
}

void Book::setnhaXuatBan(string nhaXuatBan)
{
    this->nhaXuatBan = nhaXuatBan;
}

void Book::setNamXuatBan(int NamXuatBan)
{
    this->NamXuatBan = NamXuatBan;
}


