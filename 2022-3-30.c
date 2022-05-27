#define _CRT_SECURE_NO_WARNINGS 1
//1.在一个有序数组中查找具体的某个数字n。编写int binsearch(int x,int v[],int n);功能：在v[0]<=v[1]<=[v2]……<=v[n-1]的数组中查找x
#include<stdio.h>
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};//此为有序的数组
	int k=7;//写一个代码，在arr数组中找到7
	int i=0;
	int sz=sizeof(arr)/sizeof(arr[0]);//计算数组中的字符个数
	for(i=0;i<sz;i++)
	{
		if(k==arr[i])
		{
			printf("找到了，下标是：%d\n",i);
			break;//找到的话就跳出去
		}
	}
	if(i==sz)
		printf("找不到\n");
	
	
	return 0;
}

//二分法
#define _CRT_SECURE_NO_WARNINGS 1
//2.在一个有序数组中查找具体的某个数字n。编写int binsearch(int x,int v[],int n);功能：在v[0]<=v[1]<=[v2]……<=v[n-1]的数组中查找x
#include<stdio.h>
int main()//利用二分法解决有序数组查找问题
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};//此为有序的数组
	int k=7;
	int sz=sizeof(arr)/sizeof(arr[0]);//计算元素个数
	int left=0;//表示左下标
	int right=sz-1;//右下标
	while(left<=right)
	{
		int mid=(left+right)/2;//数组中间的下标数字是最左和最右下标的和的一半
		if(arr[mid]>k)//如果中间下标对应的数大于我要找的数，则根据二分法查找原则，进一步二分的话，往左边查找，之后的右下标在这个中间下标的左边，所以要减一
		{
			right=mid-1;
		}
		else if(arr[mid]<k)
		{
			left=mid+1;//如果中间下标对应的数小于我要找的数，则根据二分法查找原则，进一步二分的话，往右边查找，之后的右下标在这个中间下标的左边，所以要减一
		}
		else
		{
			printf("找到了，下标是：%d\n",mid);	
			break;
		}
	}
	if(left>right)
	{
		printf("找不到\n");
	}
	return 0;
}
//二分法：若一个有序数组中含有n个数字，则需要查找的系数为log2(n),即以2为底的log n次；例如：如果n=2^32，则需要查找32次

#define _CRT_SECURE_NO_WARNINGS 1
//3.编写代码，延时多个字符从两端移动，向中间汇聚
#include<stdio.h>
#include<string.h>
#include<windows.h>//使用Sleep函数时用的头文件
#include<stdlib.h>
int main()
{
	char arr1[]="welcome to NJUST!!!";
	char arr2[]="###################";
	int left=0;
	//int right=sizeof(arr1)/sizeof(arr1[0])-2;//此处不是减一，因为arr1对应的是字符串，不是数组，所以其结尾会有“\0”，也是占字符的。
	//上面计算right也可以用下面的来代替
	int right=strlen(arr1)-2;//strlen是计算字符串长度的，到了"\0"就回停止，计数中不包括“\0”
	while(left<=right)
	{
		arr2[left]=arr1[left];
		arr2[right]=arr1[right];
		printf("%s\n",arr2);
		//打印一次休息1秒
		Sleep(1000);//休息1000毫秒，即休息1秒
		system("cls");
		left++;
		right--;
	}
	return 0;
}
//例如：char arr[]="abc";字符串
//相当于数组[a b c \0];下标对应为0 1 2 3；多出1个数

#define _CRT_SECURE_NO_WARNINGS 1
//4.编写代码实现，模拟用户登录情景，并且只能登录三次（只允许输入三次密码，如果密码正确则提示成功，如果三次均错误，则退出登录）
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
int main()
{
	int i=0;
	char password[20]={0};
	for(i=0;i<3;i++)
	{
		printf("请输入密码：>");
		scanf("%s",password);
		if(strcmp(password,"123456")==0)//等号==不能直接用来判断两个字符串是否相等，应该使用一个“库函数”-strcmp
		{
			printf("登录成功\n");
			break;
		}
		else
		{
			printf("密码错误\n");
		}
	}
	if(i==3)
		printf("三次密码均错误，退出输入\n");
	return 0;
}

