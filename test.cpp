#include <iostream>
using namespace std;

int main() {
   int choice1, choice2;

   do {
      cout << "===== MENU CHINH =====\n";
      cout << "1. Lua chon 1\n";
      cout << "2. Lua chon 2\n";
      cout << "3. Hien thi menu con\n";
      cout << "0. Thoat\n";
      cout << "Nhap lua chon cua ban: ";
      cin >> choice1;

      switch (choice1) {
         case 1:
            cout << "Ban da chon lua chon 1.\n";
            break;
         case 2:
            cout << "Ban da chon lua chon 2.\n";
            break;
         case 3:
            do {
               cout << "===== MENU CON =====\n";
               cout << "1. Lua chon 1\n";
               cout << "2. Lua chon 2\n";
               cout << "0. Quay lai menu chinh\n";
               cout << "Nhap lua chon cua ban: ";
               cin >> choice2;

               switch (choice2) {
                  case 1:
                     cout << "Ban da chon lua chon 1 trong menu con.\n";
                     break;
                  case 2:
                     cout << "Ban da chon lua chon 2 trong menu con.\n";
                     break;
                  case 0:
                     cout << "Quay lai menu chinh.\n";
                     break;
                  default:
                     cout << "Lua chon khong hop le. Vui long nhap lai.\n";
                     break;
               }
            } while (choice2 != 0);
            break;
         case 0:
            cout << "Ban da chon thoat chuong trinh.\n";
            break;
         default:
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
            break;
      }
   } while (choice1 != 0);

   return 0;
}