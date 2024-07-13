#include "Phone.h"

void show(const phone one) {
	cout << "ID��ţ�" << one.id << endl;
	cout << "������" << one.name << endl;
	cout << "�绰���룺" << one.tele_num << endl;
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
        cout << "��ͨѶ¼��û����ϵ�ˣ�" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0;i<size; i++) {
        show(arr[i]);
    }
}
//���㵱ǰ���ݴ�С

void menu() {
    cout << "\tͨѶ¼����ϵͳ\t" << endl;
    cout << "1.������ϵ��\t 2.ɾ����ϵ��" << endl;
    cout << "3.�޸���ϵ��\t 4.������ϵ��" << endl;
    cout << "5.�鿴������ϵ�� q.�˳�" << endl;

}

int add_book(book *second) {

    phone peo;
    addPhone(&peo);
    //���ȼ�������Ƿ�����
    if (second->size == 200) {
        cout << "��ͨѶ¼����" << endl;
        return ERROR;
    }

    //�����ϵ�˵����һλ
    second->arr[second->size] = peo;
    second->size++; //����+1
    second->arr[second->size - 1].id = second->size;
    cout << "��ӳɹ�" << endl;
    return OK;
}

//¼����ϵ����Ϣ
void addPhone(phone* peo) {
    cout << "������������" << endl;
    cin >> peo->name;
    cout << "������绰����: " << endl;
    cin >> peo->tele_num;
}

int delete_phone(book* ar, int id) {
    if (id < 0 || id > ar->size) {
        cout << "��id���Ϸ�" << endl;
        return ERROR;
    }
    //�����ж�ͨѶ¼����û����ϵ��
    if (ar->size <= 0) {
        cout << "��ͨѶ¼��û����ϵ��" << endl;
        return ERROR;
    }

    //ɾ������ϵ��
    /* ����
        1.����id�ҵ���ϵ��λ�ã����id��3����λ����id-1 =2
        2.�Ӹ�λ��һ��ѭ������β����������������size ,���βλ����Ϊsize-1
        3.�ж�����Ӧ����iС��size
        4.�ú�һλֱ�Ӹ���ǰһλ
    */
    for (int i = id-1; i <ar->size; i++) {
        //���Ǹ�λ�õ�id���䡣
      
        ar->arr[i] = ar->arr[i + 1];
        ar->arr[i].id = ar->arr[i + 1].id - 1;
    }
    ar->size--; //������1;
    cout << "ɾ���ɹ�" << endl;
    return OK;
}

int revise_phone(book* ar, int id) {
    //�������������͵绰����ȡ�
    if (id < 0 || id > ar->size) {
        cout << "��id���Ϸ�" << endl;
        return ERROR;
    }
    cout << "������ĺ������:" << endl;
    getline(cin,ar->arr[id - 1].name);
    cout << "������ĺ�ĵ绰����:" << endl;
    getline(cin, ar->arr[id - 1].tele_num);

    cout << "�������"<<endl;
    return OK;
}


int find_phone(const book* ar, int id) {
    if (id < 0 || id > ar->size) {
        cout << "��id���Ϸ�" << endl;
        return ERROR;
    }
    show(ar->arr[id - 1]);
    cout << "�������" << endl;
    return OK;
}