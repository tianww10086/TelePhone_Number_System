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
//ִ�гɹ�����1��ִ��ʧ�ܷ���0
int add_book(book*);  //��Ҫһ����ϵ�� 
int delete_phone(book *,int id); //����id���ɾ����ϵ��
int revise_phone(book *,int id); //����id����޸���ϵ��
int find_phone(const book *, int id); //����id��Ų�����ϵ��
void menu();
void show_all(const phone* arr, int size); //�������ͨѶ¼
void show(const phone one); //�������
void init(book* one);//ִ�г�ʼ������
void addPhone(phone *);