#include "Phone.h"
using namespace std;
int main() {
	book one;
	int flag = 0;
	init(&one);
	show_all(one.arr, one.size);
	menu();
	cout << "请输入代码选择功能：";
	while (cin >>flag ) {
		switch (flag) {
		case 1:
			add_book(&one);
			break;
		case 2:
		{
			restart1:
			int n;
			cout << "请输入该联系人的编号，即可删除:";
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
			cout << "请输入该联系人的编号，即可更改:" << endl;
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
			cout << "请输入该联系人的编号，即可查找：";
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
			cout << "请输入正确的代码!" << endl;
		}
		menu();
		cout << "继续输入代码：";
	}
}