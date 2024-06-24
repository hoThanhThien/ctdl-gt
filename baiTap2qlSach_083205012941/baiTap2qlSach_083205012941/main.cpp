#include"LinkedList.h"
void menu()
{
	cout << "1.Them Sach"<<endl;
	cout << "2.Dem sl" << endl;
	cout << "3.tim Sach" << endl; 
	cout << "4.Thoat" << endl;
}

int main() {
	int luaChon;
	LinkedList thuVien;
	
	
		menu();
		cout << "Nhap lua chon cua ban :\n";
		cin >> luaChon;
		cin.ignore();

		switch (luaChon)

		{
		case 1: {
			int slTacGia, NSX;
			vector<string> TacGia;
			string NXB, tenSach ;
			cout << "Nhap Ten sach cua ban :\n";
			getline(cin, tenSach);
			
				cout << "Nhap sl tac gia cua ban(<=5) :\n";
				cin >> slTacGia;
				cin.ignore();

			 while (slTacGia>5 || slTacGia < 1);
			for (int i = 0; i < slTacGia; i++)
			{
				string tenTacGia;
				cout << "Nhap tac gia thu " << i + 1 << ": ";
				getline(cin, tenTacGia);
				TacGia.push_back(tenTacGia);

			}
			cout << "Nhap nha xuat ban: ";
			getline(cin, NXB);
			cout << "Nhap nam xuat ban: ";
			cin >> NSX;
			cin.ignore();
			Book book(tenSach, TacGia, NXB, NSX);
			thuVien.themDau(book);
			
			break;
		}
		case 2:
		{
			string tenTacGia;
			cout << "Nhap ten tac gia: ";
			getline(cin, tenTacGia);
			int sl = thuVien.demSachCuaTG(tenTacGia);
			cout << "So luong sach cua tac gia la : " << sl;
			break;
		}
		case 3:
		{
			string NXB;
			int NSX;
			cout << " Nhap NXB: \n";
			getline(cin, NXB);
			cout << " Nhap NSX: \n";
			cin >> NSX;
			cin.ignore();
			thuVien.timSach(NXB, NSX);
			break;
		}
		default:
			cout << "lua chon ko hop le\n";
			break;
		
	
	
}