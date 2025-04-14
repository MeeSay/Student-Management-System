#include"Header.h"

#define MAX 999
//kiểm tra năm nhuận
bool isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 1;
}

//kiểm tra ngày sinh có hợp lệ hay không
bool isDays(int month, int year, int day) { 
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day > 31 || day < 1) {
			return 0;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day > 30 || day < 1) {
			return 0;
		}
		break;
	case 2:
		int tmp = isLeapYear(year) ? 29 : 28;
		if (day > tmp || day < 1) {
			return 0;
		}
	}
	return 1;
}

//lấy dữ liệu sinh viên
void getStudent(Student& sv) { 
	//Họ và tên
	cin.ignore();
	char name[51];
	cout << "Nhap ten (toi da 50 ky tu): ";
	cin.getline(name,51);
	int h = strlen(name) + 1;
	sv.Name = new char[h];
	strcpy(sv.Name, name);

	//mã số sinh viên
	cout << "Nhap ma so sinh vien (toi da 10 ky tu): ";
	char mssv[11];
	cin.getline(mssv, 11);
	h = strlen(mssv) + 1;
	sv.ID = new char[h];
	strcpy(sv.ID, mssv);

	//chuyên ngành
	cout << "Nhap chuyen nganh (toi da 50 ky tu): ";
	char chuyennganh[50];
	cin.getline(chuyennganh, 50);
	h = strlen(chuyennganh) + 1;
	sv.Major = new char[h];
	strcpy(sv.Major, chuyennganh);

	//ngày tháng năm sinh
	cout << "Nhap ngay thang nam sinh (thang/nam/ngay): " << endl;
	cout << "#Thang: ";
	cin >> sv.BirthDay.month;
	//Kiểm tra tính hợp lệ của tháng sinh
	while (sv.BirthDay.month > 12 || sv.BirthDay.month < 1) {
		//Nhập sai có thể dẫn tới lỗi vòng lặp vô hạn
		cin.clear(); //xóa trạng thái lỗi
		cin.ignore(); //xóa bộ nhớ đệm
		cout << "Khong hop le! Moi nhap lai: ";
		cin >> sv.BirthDay.month;	
	}

	cout << "#Nam: ";
	cin >> sv.BirthDay.year;
	//Kiểm tra tính hợp lệ của năm sinh
	while (sv.BirthDay.month < 1 || sv.BirthDay.year > 2025) {
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Moi nhap lai: ";
		cin >> sv.BirthDay.year;
	}

	cout << "#Ngay: ";
	cin >> sv.BirthDay.day;
	//Kiểm tra tính hợp lệ của ngày sinh
	while (!isDays(sv.BirthDay.month, sv.BirthDay.year, sv.BirthDay.day))
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Moi nhap lai: ";
		cin >> sv.BirthDay.day;
	}	
}

// in ra một sinh viên
void printStudent(Student a) {
	cout << "++++++++++" << endl;
	cout << "Ma so sinh vien: " << a.ID << endl;
	cout << "Ho va ten: " << a.Name << endl;
	cout << "Ngay sinh: " << a.BirthDay.day << "/" << a.BirthDay.month << "/" << a.BirthDay.year << endl;
	cout << "Chuyen nganh: " << a.Major << endl;
}

// in ra danh sách sinh viên
void printStudents(Student a[], int n) {
	if (n == 0) {
		cout << "#Danh sach rong!!!" << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		printStudent(a[i]);
	}
}

// nhập danh sách sinh viên
void getStudents(Student a[], int& n) {
	cout << "#Nhap so luong sinh vien: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "+++++" << endl;
		getStudent(a[i]);
	}
}

// nhập thêm sinh viên vào cuối danh sách
void getNewStudent(Student a[], int& n) {
	int m;
	cout << "#So luong sinh vien nhap them: ";
	cin >> m;
	for (int i = n ; i < n + m; i++) {
		cout << "+++++" << endl;
		getStudent(a[i]);
	}
	n = n + m;
}

// xóa đi 1 sinh viên => xóa đi sinh viên nào thì thay sinh viên cuối vào vị trí đó
void deleteStudent(Student a[], int& n) {
	if (n == 0) {
		cout << "#Danh sach rong!!!" << endl;
		return;
	}
	//lay thong tin cua sinh vien can bi xoa
	cin.ignore();
	cout << "#Nhap ma so sinh vien cua sinh vien can xoa: ";
	char mssv[11];
	cin.getline(mssv, 11);
	
	cout << "#Nhap ten cua sinh vien can xoa: ";
	char name[51];
	cin.getline(name, 51);
	//kiem tra va xoa
	int i = 0;
	for (; i < n; i++) {
		if (strcmp(mssv, a[i].ID) == 0 && strcmp(name, a[i].Name) == 0) {
			a[i].ID = a[n-1].ID;
			a[i].Name = a[n-1].Name;
			a[i].Major = a[n-1].Major;
			a[i].BirthDay.day = a[n - 1].BirthDay.day;
			a[i].BirthDay.month = a[n - 1].BirthDay.month;
			a[i].BirthDay.year = a[n - 1].BirthDay.year;

			a[n - 1].ID = NULL;
			a[n - 1].Name = NULL;
			a[n - 1].Major = NULL;
			a[n - 1].BirthDay.day = NULL;
			a[n - 1].BirthDay.month = NULL;
			a[n - 1].BirthDay.year = NULL;

			i = n + 1;
			break;
		}
	}

	if (i == n + 1) {
		cout << "#Da xoa thanh cong!" << endl;
		n = n - 1;
	}
	else
		cout << "#Khong ton tai sinh vien nay!" << endl;
}

void updateStudent(Student a[], int& n) {
	if (n == 0) {
		cout << "#Danh sach rong!!!" << endl;
		return;
	}
	//lay thong tin cua sinh vien can bi xoa
	cin.ignore();
	cout << "#Nhap ma so sinh vien cua sinh vien can sua: ";
	char mssv[11];
	cin.getline(mssv, 11);

	cout << "#Nhap ten cua sinh vien can sua: ";
	char name[51];
	cin.getline(name, 51);
	//kiem tra va xoa

	Student newSt;
	cout << "#Hay nhap lai thong tin cua sinh vien nay: " << endl;
	getStudent(newSt);

	int i = 0;
	for (; i < n; i++) {
		if (strcmp(mssv, a[i].ID) == 0 && strcmp(name, a[i].Name) == 0) {
			a[i].ID = newSt.ID;
			a[i].Name = newSt.Name;
			a[i].Major = newSt.Major;
			a[i].BirthDay.day = newSt.BirthDay.day;
			a[i].BirthDay.month = newSt.BirthDay.month;
			a[i].BirthDay.year = newSt.BirthDay.year;

			i = n + 1;
			break;
		}
	}

	if (i == n + 1) {
		cout << "#Da chinh sua thanh cong!" << endl;
	}
	else
		cout << "#Khong ton tai sinh vien nay!" << endl;
}

// viết danh sách sinh viên vào file
void writeStudents(Student a[], int n) {
	if (n == 0) {
		cout << "#Danh sach rong!!!" << endl;
		return;
	}
	ofstream file ("output.txt", ios::out);
	if (!file) {
		cout << "#Can not open this file! Exit." << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		file << a[i].ID << "," << a[i].Name << "," << a[i].BirthDay.day << "/" 
			<< a[i].BirthDay.month << "/" << a[i].BirthDay.year << "," << a[i].Major << "\n";
	}
	file.close();
	cout << "#Ghi thanh cong!" << endl;

}

void readStudents(Student a[], int& n) {
	ifstream file("input.txt");
	if (!file) {
		cout << "#Can not open this file! Exit." << endl;
		return;
	}
	n = 0;
	string line;
	while (n < MAX && getline(file, line)) {
		size_t pos = 0;
		try {
			//MSSV
			pos = line.find(',');
			a[n].ID = new char[pos];
			strcpy(a[n].ID,(line.substr(0, pos)).c_str());
			line.erase(0,pos + 1);

			//Ten
			pos = line.find(',');
			a[n].Name = new char[pos - strlen(a[n].ID)];
			strcpy(a[n].Name, (line.substr(0, pos)).c_str());
			line.erase(0, pos + 1);

			//Ngày
			pos = line.find('/');
			a[n].BirthDay.day = stoi((line.substr(0, pos)));
			line.erase(0, pos + 1);

			//Tháng
			pos = line.find('/');
			a[n].BirthDay.month = stoi((line.substr(0, pos)));
			line.erase(0, pos + 1);

			//Năm
			pos = line.find(',');
			a[n].BirthDay.year = stoi((line.substr(0, pos)));
			line.erase(0, pos + 1);

			//Ngành
			a[n].Major = new char[line.size()];
			strcpy(a[n].Major,line.c_str());

			n++;
		}
		catch(...){
			cout << "Error in line: " << line << endl;
			continue;
		}
	}
	file.close();
}

void printMenu(int& choice) {
	cout << "---------------------MENU-----------------------" << endl;
	cout << "1. Nhap danh sach sinh vien" << endl;
	cout << "2. In ra sinh vien" << endl;
	cout << "3. Nhap them sinh vien" << endl;
	cout << "4. Xoa sinh vien" << endl;
	cout << "5. Chinh sua thong tin sinh vien" << endl;
	cout << "6. Ghi vao file" << endl;
	cout << "7. Doc danh sach sinh vien tu file" << endl;
	cout << "Another. Thoat" << endl;
	cout << "Chon cong viec ban muon thuc hien: ";
	cin >> choice;
	system("cls");
}

void menu() {
	int choice;
	Student sv[MAX];
	int n = 0;
	printMenu(choice);
	while (choice != 0) {
		switch (choice) {
		case 0:
			break;
		case 1:
			getStudents(sv, n);
			break;
		case 2:
			printStudents(sv, n);
			break;
		case 3:
			getNewStudent(sv, n);
			break;
		case 4:	
			deleteStudent(sv, n);
			break;
		case 5:
			updateStudent(sv, n);
			break;
		case 6:
			writeStudents(sv, n);
			break;
		case 7:
			readStudents(sv, n);
			break;
		}
		printMenu(choice);
	}
}

