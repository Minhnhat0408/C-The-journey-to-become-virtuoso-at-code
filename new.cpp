#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

struct Quanly{
	int maHS;
	double uutien,toan,van,tdiem;
	string KV;
	char xeploai;
	
	void init(){
		if(KV == "KV1")
			uutien = 0.75;
		if(KV == "KV2-NT")
			uutien = 0.5;
		if(KV == "KV2")
			uutien = 0.25;
		if(KV == "KV3")
			uutien = 0;
		tdiem = toan+van+uutien;
		
	}

};
void print(Quanly x,int stt)
{
	cout <<setw(3) << stt << "|" << setw(8) << x.maHS << "|" << setw(7) << x.KV << "|" << setw(4) <<
	 x.toan << "|" <<setw(4) << x.van << "|" << setw(12) << x.uutien << "|" <<setw(9) << x.tdiem << "|" << endl;
}
bool cmp(Quanly x,Quanly y)
{
	return x.tdiem > y.tdiem;
}

void Menu() {
	int opt,n;
	vector <Quanly> save;
	do{
		cout << "\n=================MENU================\n";
		cout << "1. Nhap danh sach hoc sinh\n";
		cout << "2. Tong diem hoc sinh\n";
		cout << "3. Hien thi danh sach hoc sinh\n";
		cout << "4. Sap xep danh sach\n";
		cout << "5. Hoc sinh duoc diem Toan Van tren 8\n";
		cout << "6. Them hoc sinh vao danh sach\n";
		cout << "7. Xoa sinh vien uu tien\n";
		cout << "8. Luu danh sach hoc sinh\n";
		cout << "9. In ra danh sach tu tep\n";
		cout << "0. Thoat!!!\n";
		cout << "=====================================\n";
		cout << ">> ";
		cin >> opt;
		switch (opt){
			case 0: 
				break;
			case 1:{
				int n;
				cout << "Nhap so hoc sinh: "; cin >> n;
		
	 			for(int i =0;i < n;i++)
	 			{   
	 				Quanly s;
	 				cout << "Hoc sinh " << i+1<< ": " << endl;
	 				cout << "Ma HS : ";cin >> s.maHS;
	 				cout << "Khu vuc : ";cin >> s.KV;
	 				cout << "Diem Toan : ";cin >> s.toan;
	 				cout << "Diem Van : ";cin >> s.van;
	 				save.push_back(s);
	 				//cout << s[i].uutien<< endl;
	 			}
				break;
			}
			case 2:
				for(int i = 0; i < (int)save.size();i++)
				{
					save[i].init();
				}
				//for(int)
				break;
			case 3:
				cout << "\nSTT|" << setw(9) << "Ma HS|" << setw(8) << "Khu vuc|"<< setw(5) <<
	 "Toan|" <<setw(5) << "Van|" << setw(13) << "Diem uu tien|" <<setw(10) << "Tong Diem|" << endl;
	 			cout << "======================================================"<<endl;
	 			for(int i =0; i < save.size();i++)
	 			{
	 				print(save[i],i+1);
	 			}
				break;
			case 4:
				sort(save.begin(),save.end(),cmp);
				break;
			case 5:
				cout << "\nSTT|" << setw(9) << "Ma HS|" << setw(8) << "Khu vuc|"<< setw(5) <<
	 "Toan|" <<setw(5) << "Van|" << setw(13) << "Diem uu tien|" <<setw(10) << "Tong Diem|" << endl;
	 			cout << "======================================================"<<endl;
	 			for(int i =0; i < save.size();i++)
	 			{
	 				if(save[i].toan >= 8 && save[i].van >=8)
	 				{
	 					print(save[i],i+1);
	 				}
	 			}
				break;
			case 6:
				{
					Quanly a;
		 			cout << "Ma HS : ";cin >> a.maHS;
		 			cout << "Khu vuc : ";cin >> a.KV;
		 			cout << "Diem Toan : ";cin >> a.toan;
		 			cout << "Diem Van : ";cin >> a.van;
		 			a.init();
		 			save.push_back(a);
		 			sort(save.begin(),save.end(),cmp);
					break;
				}
			case 7:
				double diem;
				cout << "Nhap diem : "; cin >> diem;
				for(int i=0; i < save.size();i++)
				{
					
					if(save[i].uutien>diem)
					{
						save.erase(save.begin()+i);
						i--;
					}
				}
				break;
			case 8:{
				ofstream file("hs1.dat");
				file << "\nSTT|" << setw(9) << "Ma HS|" << setw(8) << "Khu vuc|"<< setw(5) <<
	 "Toan|" <<setw(5) << "Van|" << setw(13) << "Diem uu tien|" <<setw(10) << "Tong Diem|" << endl;
	 			cout << "======================================================"<<endl;
				for(int i=0; i < save.size();i++)
				{	
					file <<setw(3) << i+1 << "|" << setw(8) << save[i].maHS << "|" << setw(7) << save[i].KV << "|" << setw(4) <<
	 save[i].toan << "|" <<setw(4) << save[i].van << "|" << setw(12) << save[i].uutien << "|" <<setw(9) << save[i].tdiem << "|" << endl;
				} 
				break;
			}
				
			case 9:
				{
					ifstream file("hs1.dat");
					while(!file.eof())
					{
						string line;
						getline(file,line);
						cout << line << endl;
					}
					break;
				}
		}
	}while(opt != 0);
	
}

int main()
{	
	
	Menu();
	return 0;
}