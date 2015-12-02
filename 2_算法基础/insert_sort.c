// �������� 
// ����������

#include <stdio.h>

#define  SUCCESS    1
#define  ERROR     -1

//print array data
void showArray(int *data,int len)
{
	int i = 0;
	for(;i < len; i++)
	{
		printf("%d    ",data[i]);
	}//end for i
	printf("\n");
}

//insert sort
//��������ʵ��
int insertSort(int *data,int len)
{
	int i = 1;
	for(i = 1; i < len; i++)
	{
		int key = data[i];
		int p = i-1;
		while(p >= 0 && data[p] > key)
		{
			data[p+1] = data[p];
			p--;
		}//end for p
		data[p+1] = key;
	}//end for i
}

int main()
{
	int data[] = {9,3,1,0,4,10,3,2,8,7};
	int len = sizeof(data)/sizeof(data[0]);
	showArray(data, len);
	insertSort(data, len);
	showArray(data, len);
	return SUCCESS;
}