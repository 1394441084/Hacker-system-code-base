#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>//getch();������ͷ�ļ�

using namespace std;

#define COLS  40    //�ն˿��
#define LINES  15   //�ն˸߶�

/*
	1.��վ404����
	2.��վ�۸Ĺ���
	3.��վ������¼
	4.DNS����
	5.��������������
*/

//��ʼ�����溯��
void Initialization() {
	//���ÿ���̨�ն˴�С
	char tmd[128];
	sprintf(tmd, "mode con cols=%d lines=%d", COLS, LINES);
	system(tmd);
}

//������ʾ(string ����),�����Ǵ�һ���ַ���,���ַ���������ʾ
void Center_display(string Title) {
	int Left_space_number = (COLS - Title.length()) / 2;//��(40-10)/2=15�ո�
	//ѭ����ӡmenu[]����,i��ʾ�±�,i++,���ַ���һ��һ���ӡ����
		//ѭ����ӡ�ո�
		for (int i = 0; i < Left_space_number; i++) {
			cout << " ";
		}
		cout << Title << endl;//����ַ���
}

//��������ĺ���(��������,����ĳ���)
void Hide_password(char Password[],int size) {
	char c;
	int i = 0;
	while (1) {
		c=_getch();//����ʾ,��������س���,����'\r'
		if (c == '\r') { 
			Password[i] = 0;//��Password���鵱�ַ���,���س�,����һ��������;
			break; }//����ѭ��;
		Password[i++] = c; cout << "*";
	}
	cout << "\n";
}

//��½����
void Landing() {
	//char name;
	//int Password;
	string  name;//�Ż�,string �ַ������˺ź�����;
	char  Password[32];
	while (1) {
		cout << "�������˺�" << endl;
		cin >> name;//���û������˺ű��浽name��

		cout << "����������" << endl;
		//cin >> Password;//���û��������뱣�浽Password��
		Hide_password(Password, sizeof(Password));
		

			//�Ż�Ȩ���ж�  //strcmp(Password,"123456")һ���Ļ���==0;
		if (name == "54hk" && !strcmp(Password,"123456")) {
			//Menu();
			//break;
			return;
		}
		else {
			cout << "�û����������������!\n";
			//system("pause");
		}
	}
}

//���ܲ˵�����,�˵�������ʾ
void Menu(void) {
	/*
	system("cls");//����̨����
	std::cout << "1.��վ404����" << std::endl;
	std::cout << "2.��վ�۸Ĺ���" << std::endl;
	std::cout << "3.�鿴������¼" << std::endl;
	std::cout << "4.��վ�����޸�" << std::endl;
	std::cout << "5.�˳�" << std::endl;
	*/
	string menu[]{
	"1.��վ404����",
	"2.��վ�۸Ĺ���",
	"3.�鿴������¼",
	"4.��վ�����޸�",
	"5.�˳�"
	};
	//����˵������󳤶�
	int max = 0;
	//�˵�����=menu���ܿռ�/һ��Ԫ�صĿռ�
	int menu_number = sizeof(menu) / sizeof(menu[0]);
	for (int i = 0; i < menu_number; i++) {//�Ƚ��ַ����ĳ���,����һ����ֵ��max
		if (menu[i].length() > max) {
			//max=menu����ַ����ĳ���
			max = menu[i].length();
		}
	}
	//��ո���=(�ն˿��-memu���ַ��������)/2
	int Left_space_number = (COLS - max )/ 2;//��(40-10)/2=15�ո�

	system("cls");
	Center_display("-----�ڿ͹���ϵͳ-----");

	//ѭ����ӡmenu[]����,i��ʾ�±�,i++,���ַ���һ��һ���ӡ����
	for (int i = 0; i < menu_number; i++) {
		//ѭ����ӡ�ո�
		for (int i = 0; i < Left_space_number; i++) {
			cout << " ";
		}
		cout << menu[i] << endl;//����ַ���
	}

}

//���빦�ܱ�ŵĺ���
int Enter_function_number() {
	int Serial_number = 0;//���
	while (1) {
		//system("cls");
		Menu();
		//cout << "�����빦�ܱ��:";
		cin >> Serial_number;//�û�������
		if (cin.fail()) {
			cin.clear();//���������
			cin.sync();//��ջ�����
			cout << "��Ч����,����������\n";
			system("pause");
		}
		else {
			break;
		}
	}
	return Serial_number;//������ֵ
}

//1.��վ404����,ʵ��
void attack404() {
	

	system("cls");
	Center_display("-----��վ404����-----");
	cout << "������׼��������id:";
	

	//int hk_404(char *id, char *response) ;
	//cout << "��վ404����\n";


	//�������ת��ΪGBK����
	//string Returned_string = UTF8ToGBK(Response_result);
	//cout << Returned_string;
	system("pause");
}

//2.��վ�۸Ĺ���,ʵ��
void Tampering_attack() {
	system("cls");
	cout << "��վ�۸Ĺ���\n";
	system("pause");
}

//3.��վ������¼
void Website_attack_record() {
	system("cls");
	cout << "�鿴������¼\n";
	system("pause");
}

//4.��վ�����޸�
void Website_attack_repair() {
	system("cls");
	cout << "��վ�����޸�\n";
	system("pause");
}

int main(void) {
	Initialization();
	Landing();

	while (1) {
		int Serial_number = Enter_function_number();
		switch (Serial_number) {
		case 1:
			attack404();
			break;
		case 2:
			Tampering_attack();
			break;
		case 3:
			Website_attack_record();
			break;
		case 4:
			Website_attack_repair();
			break;
		case 5:
			return 0;
		default:
			cout << "��Ч����,����������.\n";
			system("pause");
			break;
		}
	}

	system("pause");
	return 0;
}
