# 一、数据结构设计
	通讯录管理系统，通常需要以下几个数据：
		3.id
		1.姓名
		2.电话号码
	可以使用struct来定义这种数据，由于通讯录最多的操作是查和增加，所以我们使用顺序表来存储这些数据。
	struct phone{
		int id;
		string name;
		long int; //电话号码11位
	}
	使用一个struct数组，来表示通讯录，最多200个联系人，即 struct arr[200];
# 二、功能实现：
	使用一个menu（）函数，输出可以执行的操作，根据用户选择的编号执行对应的操作：
	
	##1 增加用户
		找出数组最后一个位置，在这个位置的后面增加用户信息
		
	##2 删除用户
		找到要删除的用户的位置，依次执行以下操作：
			
			arr[i+1] = arr[i];  用后一位覆盖前一位。
	##3更改用户信息:
		根据ID编号，查找到该用户，ID编号从1开始。然后让其修改他的信息
		
	## 4 根据ID查找用户
		并输出该用户信息