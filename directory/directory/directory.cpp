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

//�q�T�����c��
struct Addressbooks
{
	//�q�T�����O�s���pô�H�Ʋ�
	struct Person array[MAX1];
	//��e�pô�H�Ӽ�
	int m_Size;
};




int main()
{
	
	Addressbooks abs;	//�Ыسq�T�����c��
	abs.m_Size = 0;		//��l�Ƴq�T���H���Ӽ�



	int slect = 0;
	while (true)
	{
		showMenu02();
		cin >> slect;
		switch (slect)
		{
		case 1:		//�K�[�pô�H
			addperson(&abs);  //�a�}�ǻ��i�H�ק���
			break;
		case 2:		//����pô�H
			showMenu(&abs);
			break;
		case 3:		//�R���pô�H
			deletperson(&abs);
			break;
		case 4:		//�d���pô�H
			findperson(&abs);
			break;
		case 5:		//
			modifyperson(&abs);
			break;
		case 6:		//
			cleanperson(&abs);
			break;
		case 0:
			cout << "�w��U���A��" << endl;
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
	cout << "1.�K�[�pô�H" << endl;
	cout << "2.����pô�H" << endl;
	cout << "3.�R���pô�H" << endl;
	cout << "4.�d���pô�H" << endl;
	cout << "5.�ק��pô�H" << endl;
	cout << "6.�M���pô�H" << endl;
	cout << "0.�h�X�q�T��" << endl;
	cout << "*************" << endl;
}

//1.�K�[�pô�H
void addperson(struct Addressbooks* abs)
{
	//�P�_�q�T���O�_�w��
	if (abs->m_Size == MAX1)
	{
		cout << "�q�T���w��" << endl;
		return;
	}
	else
	{
		string name;
		cout << "�п�J�m�W: " << endl;
		cin >> name;
		abs->array[abs->m_Size].m_name = name;

		int sex;
		cout << "�п�J�m�O: " << endl;
		cout << "1---�k: " << endl;
		cout << "2---�k: " << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->array[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "��J���~�бq�s��J" << endl;
		}
	
		int age;
		cout << "�п�J�~��: " << endl;
		cin >> age;
		abs->array[abs->m_Size].m_age = age;

		string phone;
		cout << "�п�J�q��:�@" << endl;
		cin >> phone;
		abs->array[abs->m_Size].m_phone = phone;

		string addr;
		cout << "�п�J�a�}: " << endl;
		cin >> addr;
		abs->array[abs->m_Size].m_addr = addr;

		abs->m_Size++;
		cout << "�K�[���\" << endl;

	}

	system("pause");
	system("cls");
}

//2.��ܩҦ��pô�H
void showMenu(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��e��������" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "�m�W: " << abs->array[i].m_name << "\t"
				<< "�ʧO: "<<(abs->array[i].m_sex == 1 ? "�k" : "�k") << "\t"
				<< "�~��: " << abs->array[i].m_age << "\t\t"
				<< "�q��: " << abs->array[i].m_phone << "\t\t"
				<< "��}: " << abs->array[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//�˴��pô�H�O�_�s�b,�s�b�h�^�ǳq�T�H��m�A���s�b�^��-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->array[i].m_name == name)
		{
			return i;   //����^�ǼƲդU��
		}
		return -1;
	}
}

//3.�R���pô�H
void deletperson(Addressbooks *abs)
{
	cout << "��J�n�R�����pô�H" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if ( ret == -1)
	{
		cout << "�d�L���H" << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->array[i] = abs->array[i + 1];
		}
		abs->m_Size--;	//��s�q�T�����H��
	}
	system("pause");
	system("cls");
}
//4.�d���pô�H
void findperson(Addressbooks* abs)
{
	cout << "��J�n�d�ߪ��pô�H" << endl;
	string name;
	cin >> name;
	int i = isExist(abs, name);
	if (i == -1)
	{
		cout << "�d�L���H" << endl;
	}
	else
	{
		cout << "�m�W: " << abs->array[i].m_name << "\t"
			<< "�ʧO: " << (abs->array[i].m_sex == 1 ? "�k" : "�k") << "\t"
			<< "�~��: " << abs->array[i].m_age << "\t\t"
			<< "�q��: " << abs->array[i].m_phone << "\t\t"
			<< "��}: " << abs->array[i].m_addr << endl;
	}
	system("pause");
	system("cls");
}
//5.�ק��pô�H
void modifyperson(Addressbooks* abs)
{
	cout << "��J�A�n�ק諸�pô�H" << endl;
	string name;
	cin >> name;
	int i = isExist(abs, name);
	if (i == -1)
	{
		cout << "�d�L���H" << endl;
	}
	else
	{
		int sex;
		cout << "�п�J�m�O: " << endl;
		cout << "1---�k: " << endl;
		cout << "2---�k: " << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->array[i].m_sex = sex;
				break;
			}
			cout << "��J���~�бq�s��J" << endl;
		}

		int age;
		cout << "�п�J�~��: " << endl;
		cin >> age;
		abs->array[i].m_age = age;

		string phone;
		cout << "�п�J�q��:�@" << endl;
		cin >> phone;
		abs->array[i].m_phone = phone;

		string addr;
		cout << "�п�J�a�}: " << endl;
		cin >> addr;
		abs->array[i].m_addr = addr;

		cout << "�ק令�\" << endl;
	}
	system("pause");
	system("cls");

}

//6.�M���pô�H
void cleanperson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "�q�T���w�M��" << endl;
	system("pause");
	system("cls");
}