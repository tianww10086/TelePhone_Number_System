#include "Phone.h"

void show(const phone one) {
	cout << "ID编号：" << one.id << endl;
	cout << "姓名：" << one.name << endl;
	cout << "电话号码：" << one.tele_num << endl;
	cout << "---------------------------"<<endl;
}
void init(book *one) {
    one->arr[0] = { 1, "John Smith", "12345678901" };
    one->arr[1] = { 2, "Jane Doe", "12345678902" };
    one->arr[2] = { 3, "Alex Johnson", "12345678903" };
    one->arr[3] = { 4, "Emily Davis", "12345678904" };
    one->arr[4] = { 5, "Chris Brown", "12345678905" };
    one->arr[5] = { 6, "Katie Wilson", "12345678906" };
    one->size = 6;
}

void show_all(const phone* arr, int size) {
    if (size <= 0) {
        cout << "该通讯录中没有联系人！" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0;i<size; i++) {
        show(arr[i]);
    }
}
//计算当前数据大小

void menu() {
    cout << "\t通讯录管理系统\t" << endl;
    cout << "1.增加联系人\t 2.删除联系人" << endl;
    cout << "3.修改联系人\t 4.查找联系人" << endl;
    cout << "5.查看所有联系人 q.退出" << endl;

}

int add_book(book *second) {

    phone peo;
    addPhone(&peo);
    //首先检查数组是否已满
    if (second->size == 200) {
        cout << "该通讯录已满" << endl;
        return ERROR;
    }

    //添加联系人到最后一位
    second->arr[second->size] = peo;
    second->size++; //数量+1
    second->arr[second->size - 1].id = second->size;
    cout << "添加成功" << endl;
    return OK;
}

//录入联系人信息
void addPhone(phone* peo) {
    cout << "请输入姓名：" << endl;
    cin >> peo->name;
    cout << "请输入电话号码: " << endl;
    cin >> peo->tele_num;
}

int delete_phone(book* ar, int id) {
    if (id < 0 || id > ar->size) {
        cout << "该id不合法" << endl;
        return ERROR;
    }
    //首先判断通讯录中有没有联系人
    if (ar->size <= 0) {
        cout << "该通讯录中没有联系人" << endl;
        return ERROR;
    }

    //删除该联系人
    /* 步骤
        1.根据id找到联系人位置，如果id是3，则位置是id-1 =2
        2.从该位置一种循环到结尾，如果数组的数量是size ,则结尾位置则为size-1
        3.判断条件应该是i小于size
        4.让后一位直接覆盖前一位
    */
    for (int i = id-1; i <ar->size; i++) {
        //但是该位置的id不变。
      
        ar->arr[i] = ar->arr[i + 1];
        ar->arr[i].id = ar->arr[i + 1].id - 1;
    }
    ar->size--; //数量减1;
    cout << "删除成功" << endl;
    return OK;
}

int revise_phone(book* ar, int id) {
    //更改他的姓名和电话号码等。
    if (id < 0 || id > ar->size) {
        cout << "该id不合法" << endl;
        return ERROR;
    }
    cout << "输入更改后的姓名:" << endl;
    getline(cin,ar->arr[id - 1].name);
    cout << "输入更改后的电话号码:" << endl;
    getline(cin, ar->arr[id - 1].tele_num);

    cout << "更改完成"<<endl;
    return OK;
}


int find_phone(const book* ar, int id) {
    if (id < 0 || id > ar->size) {
        cout << "该id不合法" << endl;
        return ERROR;
    }
    show(ar->arr[id - 1]);
    cout << "查找完成" << endl;
    return OK;
}