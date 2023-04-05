#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// Đối tượng ngày-tháng-năm
struct Date
{
     int day, month, year;

     string toString()
     {
          return to_string(day) + "-" + to_string(month) + "-" + to_string(year);
     }
};

// Đối tượng sinh viên
struct User
{
     int id = rand();
     char fullName[100];
     char address[125];
     double salary;
     Date birthday;
     char placeOfBirth[125];
     Date createdAt;

     bool isValid()
     {
          if (fullName == "")
          {
               system("cls");
               cout << "\n      Thông tin không đúng !!!!! \n\n"
                    << endl;
               system("pause");
               return false;
          }
          if (address == "")
          {
               system("cls");
               cout << "\n      Thông tin không đúng !!!!! \n\n"
                    << endl;
               system("pause");
               return false;
          }
          if (salary < 10000)
          {
               system("cls");
               cout << "\n      Thông tin không đúng !!!!! \n\n"
                    << endl;
               system("pause");
               return false;
          }

          if (birthday.day < 1 || birthday.month < 1 || birthday.year < 1980)
          {
               system("cls");
               cout << "\n      Thông tin không đúng !!!!! \n\n"
                    << endl;
               system("pause");
               return false;
          }
          if (createdAt.day < 1 || createdAt.month < 1 || createdAt.year > 2023 || createdAt.year < 2015)
          {
               system("cls");
               cout << "\n      Thông tin không đúng !!!!! \n\n"
                    << endl;
               system("pause");
               return false;
          }
          if (placeOfBirth == "")
          {
               system("cls");
               cout << "\n      Thông tin không đúng !!!!! \n\n"
                    << endl;
               system("pause");
               return false;
          }
          return true;
     }

     void toString()
     {
          cout << setw(25) << id;
          cout << setw(22) << fullName;
          cout << setw(22) << address;
          cout << fixed << setprecision(0) << setw(22) << salary;
          cout << setw(22) << birthday.toString();
          cout << setw(22) << placeOfBirth;
          cout << setw(22) << createdAt.toString() << "\n"
               << endl;
     }
};

// header table
void headerTable()
{
     cout << "============================================================================================================================================================================" << endl;
     cout << setw(25) << "Mã";
     cout << setw(25) << "Họ tên";
     cout << setw(25) << "Địa chỉ";
     cout << setw(25) << "Lương";
     cout << setw(25) << "Ngày sinh";
     cout << setw(25) << "Nơi sinh";
     cout << setw(30) << "Ngày vào làm" << endl;
     cout << "============================================================================================================================================================================" << endl;
}

// nhập dữ liệu cho 1 user
void setUser(User &user)
{
     // tạo 2 đối tượng cho ngày
     Date ngaySinh;
     Date ngayVaoLam;

     cout << "NHẬP THÔNG TIN NHÂN VIÊN :\n\n"
          << endl;
     // nhập tên
     cout << "Họ và tên        :";
     cin.getline(user.fullName, 100);

     // nhập địa chỉ
     cout << "Địa chỉ          :";
     cin.getline(user.address, 125);

     // nhập lương
     cout << "Lương cơ bản     :";
     cin >> user.salary;
     fflush(stdin); // sau khi nhập số thì tự động bỏ qua các hàm phía sau :(

     // nhập ngày tháng năm sinh
     cout << "Sinh ngày        :";
     cin >> ngaySinh.day;
     fflush(stdin);
     cout << "tháng            :";
     cin >> ngaySinh.month;
     fflush(stdin);
     cout << "năm sinh         :";
     cin >> ngaySinh.year;
     fflush(stdin);
     // set ngày sinh
     user.birthday = ngaySinh;

     // nhập nơi sinh
     cout << "Nơi sinh         :";
     cin >> user.placeOfBirth;
     fflush(stdin);

     // nhập ngày vào làm
     cout << "Vào làm ngày     :";
     cin >> ngayVaoLam.day;
     fflush(stdin);
     cout << "tháng            :";
     cin >> ngayVaoLam.month;
     cout << "năm sinh         :";
     cin >> ngayVaoLam.year;
     fflush(stdin);
     // set ngày vào làm
     user.createdAt = ngayVaoLam;
     system("cls"); // clear screen
     if (user.isValid() == false)
     {
          system("cls");
          setUser(user);
     }
}

// Sắp xếp theo lương
void sortBySalary(vector<User> &list, string option)
{
     // sử dụng bumber sort
     if (option == "up")
     {

          for (int i = 0; i < list.size(); i++)
          {
               for (int j = i + 1; j < list.size(); j++)
               {
                    if (list[j].salary > list[i].salary)
                    {
                         swap(list[j], list[i]);
                    }
               }
          }
     }
     else
     {
          for (int i = 0; i < list.size(); i++)
          {
               for (int j = i + 1; j < list.size(); j++)
               {
                    if (list[j].salary < list[i].salary)
                    {
                         swap(list[j], list[i]);
                    }
               }
          }
     }
}

// duyệt danh sách user
void showAllUser(vector<User> list)
{
     headerTable();
     if (list.size() > 0)
     {

          for (User user : list)
          {
               user.toString();
          }
          cout << "\n\n\n\n";
     }
     else
     {
          cout << " \n\n\n\n                  ( KHÔNG CÓ USER NÀO TRONG DANH SÁCH )                    \n\n\n\n"
               << endl;
     }

     cout << "====================================================" << endl;
     cout << "=   1. Sắp xếp theo lương giảm dần                 =" << endl;
     cout << "=   2. Sắp xếp theo lương tăng dần                 =" << endl;
     cout << "=   3. Quay lại                                    =" << endl;
     cout << "====================================================" << endl;

     int option;
     cout << "Chọn (*) :";
     cin >> option;
     fflush(stdin);
     system("cls");
     switch (option)
     {
     case 1:
          sortBySalary(list, "up");
          showAllUser(list);
          break;
     case 2:
          sortBySalary(list, "down");
          showAllUser(list);
          break;

     case 3:
          return;
          break;
     }
}

// thêm 1 user vào list
void addUser(vector<User> &list)
{
     User user;
     setUser(user);
     list.push_back(user);
}

// tìm nhân viên theo tên
void findUsersByName(string keyword, vector<User> &list)
{
     bool founded = false;
     headerTable();
     for (User user : list)
     {
          string name = string(user.fullName);
          if (name.find(keyword) != string::npos)
          {
               founded = true;
               user.toString();
          }
     }
     cout << "\n\n\n\n\n";
     if (founded == false)
     {
          cout << "\n\n\n\n\n               KHÔNG TÌM THẤY KẾT QUẢ NÀO \n\n\n\n\n\n " << endl;
     }
     system("pause");
     system("cls");
}

// xóa user theo id
void deleteUser(vector<User> &list, int id)
{
     for (int i = 0; i < list.size(); i++)
     {
          if (list[i].id == id)
          {
               list.erase(list.begin() + i);
               break;
          }
     }
}

// hàm kiểm trả user có *id đã tồn tại hay chưa
bool isPresent(vector<User> &list, int id)
{
     for (User user : list)
     {
          if (user.id == id)
          {
               return true;
               break;
          }
     }
     return false;
}

// Edit user
void editUser(vector<User> &list, int index)
{
     setUser(list[index]);
}

// Chi tiết nhân viên
void detailUser(vector<User> &list, int id)
{
     User tagetUser;
     int option;
     int index;
     for (int i = 0; i < list.size(); i++)
     {
          if (list[i].id == id)
          {
               tagetUser = list[i];
               index = i;
               break;
          }
     }
     headerTable();
     tagetUser.toString();

     cout << "\n\n\n\n\n\n\n\n";
     cout << "=========================================================" << endl;
     cout << "=     1. Xóa        2.Sửa         3.Quay lại Menu       =" << endl;
     cout << "=========================================================" << endl;
     cout << "Chọn (*) : ";
     cin >> option;
     fflush(stdin);
     switch (option)
     {
     case 1: // Xóa user
          deleteUser(list, id);
          system("cls");
          break;
     case 2: // Sửa user
          editUser(list, index);
          break;
     case 3: // Thoát
          system("cls");
          return;
     default:
          break;
     }
}

// menu
void menu()
{
     cout << "==========================================================================" << endl;
     cout << "=           1. THÊM NHÂN VIÊN MỚI                                        =" << endl;
     cout << "=           2. XUẤT DANH SÁCH NHÂN VIÊN                                  =" << endl;
     cout << "=           3. TÌM NHÂN VIÊN THEO MÃ                                     =" << endl;
     cout << "=           4. TÌM NHÂN VIÊN THEO TÊN                                    =" << endl;
     cout << "==========================================================================" << endl;
}

int main()
{
     system("cls");
     // ENV
     vector<User> listUser = {};
     int option;

     // Let dance !!!
     while (true)
     {
          menu();
          cout << "CHỌN CHỨC NĂNG (*) :";
          cin >> option;
          fflush(stdin);
          system("cls");
          switch (option)
          {
          case 1: //  Thêm nhân viên mới
               addUser(listUser);
               system("cls");
               break;
          case 2: // duyệt danh sách
               showAllUser(listUser);
               system("cls");
               break;

          case 3: // tìm nhân viên theo id
               system("cls");
               int id;
               cout << "Nhập đúng ID cần tìm (*) :";
               cin >> id;
               fflush(stdin);

               if (isPresent(listUser, id) == true)
               {
                    detailUser(listUser, id);
               }
               else
               {
                    cout << "Nhân viên " << id << " không tồn tại !\n\n\n\n"
                         << endl;
                    system("pause");
                    system("cls");
               }
               break;
          case 4: // Tìm kiếm theo tên nhân viên ( contains )
               system("cls");
               string keyword;
               cout << "Tìm kiếm : ";
               cin >> keyword;
               findUsersByName(keyword, listUser);
               break;
          }
     }

     return 1;
}
