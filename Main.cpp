#include "Phone.h"
using namespace std;
int main() {
	book one;
	int flag = 0;
	init(&one);
	show_all(one.arr, one.size);
	menu();
	cout << "���������ѡ���ܣ�";
	while (cin >>flag ) {
		switch (flag) {
		case 1:
			add_book(&one);
			break;
		case 2:
		{
			restart1:
			int n;
			cout << "���������ϵ�˵ı�ţ�����ɾ��:";
			cin >> n;
			cin.get();
			int flag = delete_phone(&one, n);
			if (flag == 0) {
				goto restart1;
			}
			break;
		}
		case 3:
		{
			restart2:
			int n;
			cout << "���������ϵ�˵ı�ţ����ɸ���:" << endl;
			cin >> n;
			cin.get();
			int flag = revise_phone(&one, n);
			if (flag == 0) {
				goto restart2;
			}
			break;
		}
		case 4:
		{
			restart3:
			int n;
			cout << "���������ϵ�˵ı�ţ����ɲ��ң�";
			cin >> n;
			cin.get();
			int flag = find_phone(&one, n);
			if (flag == 0) {
				goto restart3;
			}
			break;
		}
			
		case 5:
			show_all(one.arr, one.size);
			break;
		default:
			cout << "��������ȷ�Ĵ���!" << endl;
		}
		menu();
		cout << "����������룺";
	}
}