#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>//getch();函数的头文件

using namespace std;

#define COLS  40    //终端宽度
#define LINES  15   //终端高度

/*
	1.网站404攻击
	2.网站篡改攻击
	3.网站攻击记录
	4.DNS攻击
	5.服务器重启攻击
*/

//初始化界面函数
void Initialization() {
	//设置控制台终端大小
	char tmd[128];
	sprintf(tmd, "mode con cols=%d lines=%d", COLS, LINES);
	system(tmd);
}

//居中显示(string 标题),功能是传一个字符串,让字符串居中显示
void Center_display(string Title) {
	int Left_space_number = (COLS - Title.length()) / 2;//如(40-10)/2=15空格
	//循环打印menu[]数组,i表示下标,i++,将字符串一组一组打印出来
		//循环打印空格
		for (int i = 0; i < Left_space_number; i++) {
			cout << " ";
		}
		cout << Title << endl;//输出字符串
}

//隐藏密码的函数(传的密码,密码的长度)
void Hide_password(char Password[],int size) {
	char c;
	int i = 0;
	while (1) {
		c=_getch();//不显示,如果读到回车符,返回'\r'
		if (c == '\r') { 
			Password[i] = 0;//把Password数组当字符串,遇回车,保存一个结束符;
			break; }//跳出循环;
		Password[i++] = c; cout << "*";
	}
	cout << "\n";
}

//登陆函数
void Landing() {
	//char name;
	//int Password;
	string  name;//优化,string 字符串的账号和密码;
	char  Password[32];
	while (1) {
		cout << "请输入账号" << endl;
		cin >> name;//让用户输入账号保存到name中

		cout << "请输入密码" << endl;
		//cin >> Password;//让用户输入密码保存到Password中
		Hide_password(Password, sizeof(Password));
		

			//优化权限判断  //strcmp(Password,"123456")一样的话就==0;
		if (name == "54hk" && !strcmp(Password,"123456")) {
			//Menu();
			//break;
			return;
		}
		else {
			cout << "用户名或密码输入错误!\n";
			//system("pause");
		}
	}
}

//功能菜单函数,菜单居中显示
void Menu(void) {
	/*
	system("cls");//控制台清理
	std::cout << "1.网站404攻击" << std::endl;
	std::cout << "2.网站篡改攻击" << std::endl;
	std::cout << "3.查看攻击记录" << std::endl;
	std::cout << "4.网站攻击修复" << std::endl;
	std::cout << "5.退出" << std::endl;
	*/
	string menu[]{
	"1.网站404攻击",
	"2.网站篡改攻击",
	"3.查看攻击记录",
	"4.网站攻击修复",
	"5.退出"
	};
	//计算菜单项的最大长度
	int max = 0;
	//菜单个数=menu的总空间/一个元素的空间
	int menu_number = sizeof(menu) / sizeof(menu[0]);
	for (int i = 0; i < menu_number; i++) {//比较字符串的长度,长的一方赋值给max
		if (menu[i].length() > max) {
			//max=menu中最长字符串的长度
			max = menu[i].length();
		}
	}
	//左空格数=(终端宽度-memu中字符串最长长度)/2
	int Left_space_number = (COLS - max )/ 2;//如(40-10)/2=15空格

	system("cls");
	Center_display("-----黑客攻击系统-----");

	//循环打印menu[]数组,i表示下标,i++,将字符串一组一组打印出来
	for (int i = 0; i < menu_number; i++) {
		//循环打印空格
		for (int i = 0; i < Left_space_number; i++) {
			cout << " ";
		}
		cout << menu[i] << endl;//输出字符串
	}

}

//输入功能编号的函数
int Enter_function_number() {
	int Serial_number = 0;//编号
	while (1) {
		//system("cls");
		Menu();
		//cout << "请输入功能编号:";
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
	Center_display("-----网站404攻击-----");
	cout << "请输入准备攻击的id:";
	

	//int hk_404(char *id, char *response) ;
	//cout << "网站404攻击\n";


	//攻击结果转换为GBK编码
	//string Returned_string = UTF8ToGBK(Response_result);
	//cout << Returned_string;
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
			cout << "无效输入,请重新输入.\n";
			system("pause");
			break;
		}
	}

	system("pause");
	return 0;
}
