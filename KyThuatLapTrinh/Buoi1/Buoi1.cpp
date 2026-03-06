#include <iostream>
#include <vector>
using namespace std;
struct SinhVien {
	string hoten;
	int tuoi;
	bool gioitinh;
	string diachi;
};
int main() {
	SinhVien b;
	b.hoten = "Nguyen Van A";
	b.tuoi = 20;
	b.gioitinh = true;
	b.diachi = "Tay Ninh";

	SinhVien c;
	c.hoten = "Tran Thi B";
	c.tuoi = 30;

	//SinhVien ds[50]; 
	vector <SinhVien> mang;
	mang.push_back(b);
	mang.push_back(c);
	for (int i = 0; i < mang.size(); i++) {
		cout << "Sinh vien " << (i + 1) << endl;
		cout << "\t+ Ho ten: " << mang[i].hoten << endl;
		cout << "\t+ Tuoi: " << mang[i].tuoi << endl;
	}
	/*int a = 5;
	int* p = &a;
	a += 6;
	a = *p + 2;
	cout << *p;*/

	/*vector <float> diemthi;
	diemthi.push_back(5.5);
	diemthi.push_back(4);
	diemthi.push_back(6);
	diemthi.pop_back();
	for (int i = 0; i < diemthi.size(); i++) {
		cout << diemthi[i] << endl;
	}*/
}
