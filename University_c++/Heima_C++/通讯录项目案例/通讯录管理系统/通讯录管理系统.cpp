#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

//菜单界面
void showMenu() {
	cout << "***********************" << endl;
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出通讯录" << endl;
	cout << "***********************" << endl;

};

//联系人结构体
struct Person {
	string m_name;//姓名
	int m_age;//年龄
	int m_sex;//性别 1男 2女
	string m_phone;//电话号码
	string m_addr;//家庭住址
};

//通讯录结构体
struct AddressBooks {
	Person personArray[MAX];//通讯录中保存的联系人数组,最多保存1000个联系人
	int m_Size;//通讯录中当前联系人数量
};

//1、添加联系人
void addPerson(AddressBooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else {
		//添加联系人
		string name;
		cout << "请输入姓名：";
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;
		
		int age;
		cout << "请输入年龄：";
		cin >> age;
		abs->personArray[abs->m_Size].m_age = age;

		cout << "请输入性别：" << endl;
		int sex;
		cout << "1-----男" << endl;
		cout << "2-----女" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_sex = sex;
				break;
			}
			else {
				cout << "请输入有效值！" << endl;
			};
		}
		
		cout << "请输入电话号码；";
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_phone = phone;

		string addr;
		cout << "请输入家庭住址：";
		cin >> addr;
		abs->personArray[abs->m_Size].m_addr = addr;

		// 增加已存人数，保证下一次添加不会覆盖当前记录
		abs->m_Size++;

		cout << "添加成功！" << endl;
		system("pause");
		//按任意键继续
		system("cls");
		//清屏操作

	}

};

//2、显示联系人
void showPersonArray(AddressBooks * abs) {
	if (abs->m_Size <= 0) {
		cout << "当前通讯录中没有联系人！" << endl;
		return;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "年龄：" << abs->personArray[i].m_age << "\t";
			cout << "性别：" << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
			if (abs->personArray[i].m_sex == 1) {
				cout << "性别：男" << "\t";
			}
			else {
				cout << "性别：女" << "\t";
			}
			cout << "电话号码：" << abs->personArray[i].m_phone << "\t";
			cout << "家庭住址：" << abs->personArray[i].m_addr<< endl;
			
		}
		
	}
	system("pause");
	system("cls");
	
};

//3、删除联系人
//3、1.检测联系人是否存在
int isExit(AddressBooks* abs, string name) {
	for (int i = 0; i <= abs->m_Size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;
		}
		//找到返回位置
	}
	return -1;
	//没找到返回-1
}

//3、.2删除联系人
void deletePerson(AddressBooks * abs) {
	cout << "请输入删除联系人的姓名：" << endl;;

	while (true) {
		string ming;
		cin >> ming;
		
		if (isExit(abs, ming) == -1) {
			cout << "没有该联系人！请重新输入：" << endl;

		}
		else {
			for (int i = isExit(abs, ming); i < abs->m_Size; i++) {
				//数据前移
				abs->personArray[i].m_name = abs->personArray[i + 1].m_name;
			}
			abs->m_Size--;
			cout << "已删除该联系人！" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

//4、查找联系人
void findPerson(AddressBooks* abs) {
	cout << "请输入要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret =isExit(abs, name);
	if (ret != -1) {
		cout << "姓名：" << abs->personArray[ret].m_name << "\t";
		cout << "年龄：" << abs->personArray[ret].m_age << "\t";
		cout << "性别：" << (abs->personArray[ret].m_phone = 1 ? "男" : "女") << "\t";
		cout << "电话号码：" << abs->personArray[ret].m_phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_addr << "\t";
			

	}
	else {
		cout << "查无此人!" << endl;
	}
	system("pause");
	system("cls");
}

//5.修改联系人
void modifyPerson(AddressBooks* abs) {
	cout << "请输入要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret != -1) {
		string newName;
		cout << "请输入新的姓名：";
		cin >> newName;
		abs->personArray[ret].m_name = newName;
		int newAge;
		cout << "请输入新的年龄：";
		cin >> newAge;
		abs->personArray[ret].m_age = newAge;
		int newSex;
		cout << "请输入新的性别：" << endl;
		cout << "1-----男" << endl;
		cout << "2-----女" << endl;
		cin >> newSex;
		abs->personArray[ret].m_sex = newSex;
		string newPhone;
		cout << "请输入新的电话号码：";
		cin >> newPhone;
		abs->personArray[ret].m_phone = newPhone;
		string newAddr;
		cout << "请输入新的家庭住址：";
		cin >> newAddr;
		abs->personArray[ret].m_addr = newAddr;
		cout << "修改完成！" << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

//6.清空联系人
void cleanPerson(AddressBooks* abs) {
	abs->m_Size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}
int main() {

	//创建通讯录结构体变量
	AddressBooks abs;
	//初始化通讯录中人数
	abs.m_Size = 0;
	

	while(true) {
		showMenu();
		int select = 0;
		cout << "请选择操作：";
		cin >> select;
		switch (select) {
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPersonArray(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
		default:
			cout << "输入有误，请重新输入！" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}
