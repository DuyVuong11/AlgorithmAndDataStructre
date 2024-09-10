#include"SinhVien.h"

int main() {
    DS_SLL ds;
    int choice;

    do {
        
        cout << "================== MENU ===============\n";
        cout << "1. Them sinh vien vao dau danh sach\n";
        cout << "2. Them sinh vien vao cuoi danh sach\n";
        cout << "3. Xoa sinh vien o dau danh sach\n";
        cout << "4. Xoa sinh vien o cuoi danh sach\n";
        cout << "5. Hien thi danh sach sinh vien\n";
        cout << "0. Thoat\n";
        cout << "=======================================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;
        if (choice != 5 || choice != 0) {
            system("cls");
        }

        SinhVien sv;
        switch (choice) {
        case 1:
            ds.Nhap_SinhVien(sv);
            ds.Chen_Dau(sv);
            cout << "Chen thanh cong\n";
            cout << "--------------------\n";
            break;
        case 2:
            ds.Nhap_SinhVien(sv);
            ds.Chen_Cuoi(sv);
            cout << "Chen thanh cong!\n";
            cout << "--------------------\n";
            break;
        case 3:
            if (ds.DS_SinhVien != NULL) {
                ds.Xoa_Dau();
                cout << "Xoa thanh cong!\n";
                cout << "--------------------\n";
            }
            else cout << "Danh sach rong!\n";
            break;
        case 4:
            if (ds.DS_SinhVien != NULL) {
                ds.Xoa_Cuoi();
                cout << "Xoa thanh cong!\n";
                cout << "--------------------\n";
            }
            else cout << "Danh sach rong!\n";
            break;
        case 5:
            ds.Xuat_DS();
            break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            cout << "--------------------\n";   
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
