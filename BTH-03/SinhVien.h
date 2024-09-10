#include<iostream>
#include<string>
using namespace std; 

struct SinhVien // node
{
	string HoTen; 
	string MSSV; 
	double diemTB;
	SinhVien* next; 
	SinhVien() {
		HoTen = "";
		MSSV = "";
		diemTB = 0; 
		next = NULL;
	}
	SinhVien(string name, string id, double GPA, SinhVien* ptr = NULL) {
		HoTen = name; 
		MSSV = id;
		diemTB = GPA; 
		next = ptr;
	}
};

struct DS_SLL // head
{
	SinhVien* DS_SinhVien; 
	DS_SLL() {
		DS_SinhVien = NULL; 
	}
	// ktra danh sach co rong hay kh
	bool isEmpty() const {
		return (DS_SinhVien == NULL);
	}

	// ham chen dau 
	void Chen_Dau(SinhVien& sv) {
		DS_SinhVien = new SinhVien(sv.HoTen,sv.MSSV,sv.diemTB, DS_SinhVien);

	}
	// ham chen cuoi, kiem tra neu ham rong thi chen dau
	void Chen_Cuoi(SinhVien& sv) {
		if (isEmpty()) {
			DS_SinhVien = new SinhVien(sv.HoTen, sv.MSSV, sv.diemTB, DS_SinhVien);
		}
		else {
			SinhVien* tmp = DS_SinhVien; 
			while (tmp->next != NULL) {
				tmp = tmp->next; 
			}
			tmp->next = new SinhVien(sv.HoTen, sv.MSSV, sv.diemTB);
		}
		
	}
	// ham xoa sinh vien o dau danh sach
	void Xoa_Dau() {
		if (DS_SinhVien == NULL) {
			cout << "Danh sach rong!\n";
		}
		else {
			SinhVien* tmp = DS_SinhVien; 
			DS_SinhVien = DS_SinhVien->next; 
			delete tmp;
		}
		
	}
	// ham xoa sinh vien o cuoi danh sach
	void Xoa_Cuoi() { 
		if (isEmpty()) {
			cout << "Danh sach rong!\n";
		}
		if (DS_SinhVien->next == NULL) {
			delete DS_SinhVien; 
			DS_SinhVien = NULL; 
		}
		else {
			SinhVien* tmp = DS_SinhVien;
			SinhVien* truoc = NULL;
			while (tmp->next != NULL) {
				truoc = tmp; 
				tmp = tmp->next; 
			}
			if (tmp == DS_SinhVien) {
				DS_SinhVien = NULL; 
			}
			else {
				truoc->next = NULL; 
			}
			delete tmp; 
		}
		
	}
	// ham xuat danh sach 
	void Xuat_DS() const {
		if (isEmpty()) {
			cout << "Danh sach rong!\n";
		}
		else {
			SinhVien* sv_Hien_Tai = DS_SinhVien; 
			while (sv_Hien_Tai != NULL) {
				cout << "Ho ten: " << sv_Hien_Tai->HoTen << endl;
				cout << "MSSV: " << sv_Hien_Tai->MSSV << endl;
				cout << "Diem trung binh: " << sv_Hien_Tai->diemTB << endl;
				cout << "--------------------" << endl;
				sv_Hien_Tai = sv_Hien_Tai->next; 
			}
		}
	}

	void Nhap_SinhVien(SinhVien& sv) {
		cout << "Nhap ho ten: ";
		cin.ignore(); 
		getline(cin, sv.HoTen);
		cout << "Nhap MSSV: ";
		getline(cin, sv.MSSV);
		cout << "Nhap diem trung binh: ";
		cin >> sv.diemTB;
	}
};

