// ���������
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Ҫȡ��[a,b)�����������ʹ��(rand() % (b-a))+ a; 
//Ҫȡ��[a,b]�����������ʹ��(rand() % (b-a+1))+ a; 
//Ҫȡ��(a,b]�����������ʹ��(rand() % (b-a))+ a + 1; 
//ͨ�ù�ʽ:a + rand() % n�����е�a����ʼֵ��n�������ķ�Χ�� 
//Ҫȡ��a��b֮��������������һ�ֱ�ʾ��a + (int)b * rand() / (RAND_MAX + 1)�� 
//Ҫȡ��0��1֮��ĸ�����������ʹ��rand() / double(RAND_MAX)��

//ȡ��[a,b]���������
//����֮ǰ�����  srand((unsigned)time(NULL)); ��ʼ��
int randomInt(int min,int max)
{
	return (rand() % (max - min + 1)) + min;
}

int main()
{
	int i;
	for(i = 0; i < 10 ; i++)
	{
		printf("%d \n",randomInt(1,100));
	}//end for i
	return 0;
}