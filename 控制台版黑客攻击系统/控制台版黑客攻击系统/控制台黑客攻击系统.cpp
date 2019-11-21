#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
/*
	1.网站404攻击
	2.网站篡改攻击
	3.网站攻击记录
	4.DNS攻击
	5.服务器重启攻击
*/

//功能菜单函数
void Menu(void) {
	system("cls");//控制台清理
	std::cout << "1.网站404攻击" << std::endl;
	std::cout << "2.网站篡改攻击" << std::endl;
	std::cout << "3.查看攻击记录" << std::endl;
	std::cout << "4.网站攻击修复" << std::endl;
	std::cout << "5.退出" << std::endl;
}

//登陆函数
void Landing() {
	//char name;
	//int Password;
	string  name;//优化,string 字符串的账号和密码;
	string  Password;
	while (1) {
		cout << "请输入账号" << endl;
		cin >> name;//让用户输入账号保存到name中

		cout << "请输入密码" << endl;
		cin >> Password;//让用户输入密码保存到Password中


			//优化权限判断
		if (name == "54hk" && Password == "123456") {
			Menu();
			break;
		}
		else {
			cout << "用户名或密码输入错误!\n";
			//system("pause");
		}
	}
}

//输入功能编号的函数
int Enter_function_number() {
	int Serial_number = 0;//编号
	while (1) {
		Menu();
		cout << "请输入功能编号:";
		cin >> Serial_number;//用户输入编号
		if (cin.fail()) {
			cin.clear();//清掉错误标记
			cin.sync();//清空缓冲区
			cout << "无效输入,请重新输入\n";
			system("pause");
		}
		else {
			break;
		}
	}
	return Serial_number;//返回数值
}

//1.网站404攻击,实现
void attack404() {
	system("cls");
	cout << "网站404攻击\n";
	system("pause");
}

//2.网站篡改攻击,实现
void Tampering_attack() {
	system("cls");
	cout << "网站篡改攻击\n";
	system("pause");
}

//3.网站攻击记录
void Website_attack_record() {
	system("cls");
	cout << "查看攻击记录\n";
	system("pause");
}

//4.网站攻击修复
void Website_attack_repair() {
	system("cls");
	cout << "网站攻击修复\n";
	system("pause");
}


int main(void) {
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
			cout << "无效输入,请重新输入.\n";
			system("pause");
			break;
		}
	}

	system("pause");
	return 0;
}
