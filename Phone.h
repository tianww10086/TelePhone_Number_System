#pragma once
#include<iostream>
#include<string>
#define OK 1
#define ERROR 0
using namespace std;
struct phone {
	unsigned int id;
	string name;
	string tele_num;
};
struct book {
	phone* arr = new phone[200];
	int size = 0;
};
//执行成功返回1，执行失败返回0
int add_book(book*);  //需要一个联系人 
int delete_phone(book *,int id); //根据id编号删除联系人
int revise_phone(book *,int id); //根据id编号修改联系人
int find_phone(const book *, int id); //根据id编号查找联系人
void menu();
void show_all(const phone* arr, int size); //输出整个通讯录
void show(const phone one); //输出单个
void init(book* one);//执行初始化数据
void addPhone(phone *);