#include<iostream>
#include<string>
#include"showMenu.h"
#define MAX1 1000
using namespace std;

void showMenu02();
void addperson(struct Addressbooks* abs);
void showMenu(struct Addressbooks* abs);
int isExist(Addressbooks* abs, string name);
void deletperson(Addressbooks* abs);
void findperson(Addressbooks* abs);
void modifyperson(Addressbooks* abs);
void cleanperson(Addressbooks* abs);

struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};

//通訊錄結構體
struct Addressbooks
{
	//通訊錄中保存的聯繫人數組
	struct Person array[MAX1];
	//當前聯繫人個數
	int m_Size;
};




int main()
{
	
	Addressbooks abs;	//創建通訊錄結構體
	abs.m_Size = 0;		//初始化通訊錄人員個數



	int slect = 0;
	while (true)
	{
		showMenu02();
		cin >> slect;
		switch (slect)
		{
		case 1:		//添加聯繫人
			addperson(&abs);  //地址傳遞可以修改實參
			break;
		case 2:		//顯示聯繫人
			showMenu(&abs);
			break;
		case 3:		//刪除聯繫人
			deletperson(&abs);
			break;
		case 4:		//查找聯繫人
			findperson(&abs);
			break;
		case 5:		//
			modifyperson(&abs);
			break;
		case 6:		//
			cleanperson(&abs);
			break;
		case 0:
			cout << "歡迎下次再來" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	

	system("pause");
	return 0;
}



void showMenu02()
{
	cout << "*************" << endl;
	cout << "1.添加聯繫人" << endl;
	cout << "2.顯示聯繫人" << endl;
	cout << "3.刪除聯繫人" << endl;
	cout << "4.查找聯繫人" << endl;
	cout << "5.修改聯繫人" << endl;
	cout << "6.清空聯繫人" << endl;
	cout << "0.退出通訊錄" << endl;
	cout << "*************" << endl;
}

//1.添加聯繫人
void addperson(struct Addressbooks* abs)
{
	//判斷通訊錄是否已滿
	if (abs->m_Size == MAX1)
	{
		cout << "通訊錄已滿" << endl;
		return;
	}
	else
	{
		string name;
		cout << "請輸入姓名: " << endl;
		cin >> name;
		abs->array[abs->m_Size].m_name = name;

		int sex;
		cout << "請輸入姓別: " << endl;
		cout << "1---男: " << endl;
		cout << "2---女: " << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->array[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "輸入錯誤請從新輸入" << endl;
		}
	
		int age;
		cout << "請輸入年紀: " << endl;
		cin >> age;
		abs->array[abs->m_Size].m_age = age;

		string phone;
		cout << "請輸入電話:　" << endl;
		cin >> phone;
		abs->array[abs->m_Size].m_phone = phone;

		string addr;
		cout << "請輸入地址: " << endl;
		cin >> addr;
		abs->array[abs->m_Size].m_addr = addr;

		abs->m_Size++;
		cout << "添加成功" << endl;

	}

	system("pause");
	system("cls");
}

//2.顯示所有聯繫人
void showMenu(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "當前紀錄為空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名: " << abs->array[i].m_name << "\t"
				<< "性別: "<<(abs->array[i].m_sex == 1 ? "男" : "女") << "\t"
				<< "年齡: " << abs->array[i].m_age << "\t\t"
				<< "電話: " << abs->array[i].m_phone << "\t\t"
				<< "住址: " << abs->array[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//檢測聯繫人是否存在,存在則回傳通訊人位置，不存在回傳-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->array[i].m_name == name)
		{
			return i;   //找到後回傳數組下標
		}
		return -1;
	}
}

//3.刪除聯繫人
void deletperson(Addressbooks *abs)
{
	cout << "輸入要刪除的聯繫人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if ( ret == -1)
	{
		cout << "查無此人" << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->array[i] = abs->array[i + 1];
		}
		abs->m_Size--;	//更新通訊錄中人數
	}
	system("pause");
	system("cls");
}
//4.查找聯繫人
void findperson(Addressbooks* abs)
{
	cout << "輸入要查詢的聯繫人" << endl;
	string name;
	cin >> name;
	int i = isExist(abs, name);
	if (i == -1)
	{
		cout << "查無此人" << endl;
	}
	else
	{
		cout << "姓名: " << abs->array[i].m_name << "\t"
			<< "性別: " << (abs->array[i].m_sex == 1 ? "男" : "女") << "\t"
			<< "年齡: " << abs->array[i].m_age << "\t\t"
			<< "電話: " << abs->array[i].m_phone << "\t\t"
			<< "住址: " << abs->array[i].m_addr << endl;
	}
	system("pause");
	system("cls");
}
//5.修改聯繫人
void modifyperson(Addressbooks* abs)
{
	cout << "輸入你要修改的聯繫人" << endl;
	string name;
	cin >> name;
	int i = isExist(abs, name);
	if (i == -1)
	{
		cout << "查無此人" << endl;
	}
	else
	{
		int sex;
		cout << "請輸入姓別: " << endl;
		cout << "1---男: " << endl;
		cout << "2---女: " << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->array[i].m_sex = sex;
				break;
			}
			cout << "輸入錯誤請從新輸入" << endl;
		}

		int age;
		cout << "請輸入年紀: " << endl;
		cin >> age;
		abs->array[i].m_age = age;

		string phone;
		cout << "請輸入電話:　" << endl;
		cin >> phone;
		abs->array[i].m_phone = phone;

		string addr;
		cout << "請輸入地址: " << endl;
		cin >> addr;
		abs->array[i].m_addr = addr;

		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");

}

//6.清空聯繫人
void cleanperson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通訊錄已清空" << endl;
	system("pause");
	system("cls");
}