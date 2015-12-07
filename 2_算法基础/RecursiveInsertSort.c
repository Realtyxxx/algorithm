// �������� 
// �ݹ���ʽ�Ĳ�������

#include <stdio.h>
#include "Tool.h"

void insertItem(int *data,int start,int end,int insertItem);

int recursiveInsertSort(int *data,int start,int end);

int main()
{
	int data[] = {9,3,1,0,4,10,3,2,8,7};
	int len = sizeof(data)/sizeof(data[0]);
	showArray(data, len);
	recursiveInsertSort(data,0,len - 1);
	showArray(data, len);
	return 0;
}

//�ݹ�״̬�Ĳ�������
int recursiveInsertSort(int *data,int start,int end)
{
	if(end > start)
	{
		recursiveInsertSort(data,start,end - 1);
		//do insert
		insertItem(data,start,end - 1,data[end]);
	}
	return 0;
}

//����Ԫ�ص�����������
void insertItem(int *data,int start,int end,int insertItem)
{
	int index = end;
	while(index >= start && insertItem < data[index])
	{
		data[index + 1] = data[index];
		index--;
	}//end while index
	data[index + 1] = insertItem;
}
