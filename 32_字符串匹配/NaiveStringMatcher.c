#include <stdio.h>
#include <string.h>

#define    TURE    1
#define    FALSE  -1

void naiveStringMatcher(const char *str,const char *p);
int stringMatch(const char *left,const char *right,int len);

int main()
{
	char *str = "aabcdabcdeabcabc";
	char *p = "abc";
	naiveStringMatcher(str,p);
	return 0;
}

//�����ַ���ƥ���㷨
// param   str ������
// param   p ģʽ��
// ��ʾƫ��ֵ
void naiveStringMatcher(const char *str,const char *p)
{
	int strLen = strlen(str);
	int pLen = strlen(p);
	int i;
	int end = strLen - pLen + 1;
	for(i = 0;i < end; i++)
	{
		if(stringMatch(str+i,p,pLen) == TURE)
		{
			printf("s = %d \n",i);
		}
	}//end for i
}

//����left right len�����ַ��Ƿ����
//
int stringMatch(const char *left,const char *right,int len)
{
	int i;
	for(i = 0;i < len; i++)
	{
		if(left[i] != right[i]) 
			return FALSE;
	}//end for i
	return TURE;
}
