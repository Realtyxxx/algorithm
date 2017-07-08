//��������״̬�Զ������ַ���ƥ���㷨
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE     1
#define FALSE   0
#define MAX_SIZE 1024

//const char CHAR_SET[] = {'a', 'b', 'c'};
const char CHAR_SET[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const int CHAR_SET_SIZE = sizeof(CHAR_SET) / sizeof(char);

struct _AutoMachine
{
	char status[MAX_SIZE];//�Զ���״̬��
	char statusSize;//�Զ���״̬����
	char cur;//�Զ�����ǰ״̬
	char accept;//�ɽ���״̬����ǰ�Զ���ֻ����һ�ֿɽ���״̬
	char transFuc[MAX_SIZE][MAX_SIZE];//��ά���������״̬ת�ƺ���
};
typedef struct _AutoMachine AutoMachine;

int createAutoMachine(char *pattern,int size,AutoMachine *mac);

int autoMachineIndexOf(char *t,int len,char *p,int pLen);

int autoMachineReadChar(AutoMachine *mac,char c);//�Զ��������ַ�  ����״̬

int charToIndex(char c);

int isSuffix(char *str,int strSize,char *suffix,int suffixSize);//judge isSuffix 

void debugMac(AutoMachine *mac);
void showAutoMacTransFunc(AutoMachine *mac);

int main(int argc,char *argv[]){
	char str[]="abcdefghijklmmnopqstuvwxyz122223333333";
	int str_size = sizeof(str) / sizeof(char) - 1;
	char sub[] = "bc";
	int sub_size = sizeof(sub) / sizeof(char)  - 1;
	
	printf("T = %s \nP = %s \n %d , %d \n", str, sub, str_size, sub_size);
	
	int p = autoMachineIndexOf(str,str_size,sub,sub_size);
	printf("index = %d \n",p);
	
	return 0;
}

void debugMac(AutoMachine *mac){
	printf("auto machine status list:\n");

	for(int i = 0; i< mac->statusSize ;i++){
		printf("status_%d\n",mac->status[i]);
	}
	printf("accept status_%d\n",mac->accept);

	printf("test suffix\n");
	char str[]="nihao  shijiehahaha";
	int strSize = strlen(str) - 1;
	char sub[]="ababaca";
	int subSize = strlen(sub) - 1;

	int ret = isSuffix(str , strSize , sub , subSize);
	printf("suffix test result = %d \n", ret);
	
	//showAutoMacTransFunc(mac);
}

int isSuffix(char *str,int strSize,char *suffix,int suffixSize){
	if(suffixSize > strSize)
		return FALSE;
	
	if(suffixSize == 0)//�Ӵ�����Ϊ0 �մ�ʱ   ��ȻΪstr�ĺ�׺
		return TRUE;
	
	// suffixSize <= strSize
	int index = suffixSize - 1;
	int strIndex = strSize -1;
	
	while(index >= 0 ){
		if(suffix[index--] != str[strIndex--]){
			return FALSE;
		}//end if
	}//end while

	return TRUE;
}

//����ƥ�䴮 �����Զ���
int createAutoMachine(char *pattern,int size,AutoMachine *mac){
	//printf(" mac size = %d \n",sizeof(*mac));
	mac->statusSize = size + 1;
	for( int i = 0 ;i < mac->statusSize ; i++){
		mac->status[i] = i;
	}//end for i
	mac->cur = 0;//��ʼ״̬
	mac->accept = size;//��ֹ״̬
	
	//����״̬ת�ƺ���
	memset(mac->transFuc,0,MAX_SIZE * MAX_SIZE);
	
	char tempStr[MAX_SIZE];
	printf("Pattern ->%s\n",pattern);
	
	for(char status = mac->cur ; status <= mac->accept ; status++){ //��������״̬
		for(int i = 0; i < CHAR_SET_SIZE; i++){//���������ַ�
			char ch = CHAR_SET[i];
			memset(tempStr,0,MAX_SIZE);
			//����������
			strncpy(tempStr,pattern,status);
			int len = strlen(tempStr);
			tempStr[len] = ch;
			tempStr[len + 1] = '\0';
			int tempStrSize = status + 1;
			//printf("tempStr ->%s , size = %d\n",tempStr,tempStrSize);
			int maxPValue = mac->statusSize + 1;
			
			while(!isSuffix(tempStr,tempStrSize, pattern, maxPValue)){
					maxPValue--;
			}//end while
			
			//debug
			char buf[1024];
			strncpy(buf, pattern, maxPValue);
			printf("T = %s     , subPattern = %s \n",tempStr, buf);
			//debugend
			
			mac->transFuc[status][i] = maxPValue; 
		}//end for i
	}//end for status
	
	showAutoMacTransFunc(mac);
	
	return -1;
}

void showAutoMacTransFunc(AutoMachine *mac){//״̬ת�ƺ�������ʾsss
	printf("status \t");
	for(int i = 0;i < CHAR_SET_SIZE; i ++){
		printf("%c \t",CHAR_SET[i]);
	}//end for i
	printf("\n");
	
	for(char i = 0; i < mac->statusSize;i++){
		printf("%d",i);
		for(int j = 0;j < CHAR_SET_SIZE; j++){
			printf("\t%d ",mac->transFuc[i][j]);
		}//end for i
		printf("\n");
	}//end for i
}

int autoMachineReadChar(AutoMachine *mac,char c){
	//printf("read char %c\n",c);
	mac->cur = mac->transFuc[mac->cur][charToIndex(c)];
	return mac->cur;
}

int autoMachineIndexOf(char *t,int len,char *p,int pLen) {
	if(!pLen)
		return -1;

	int max = len - pLen;

	if(max < 0)
		return -1;
	
	AutoMachine am;
	createAutoMachine(p,pLen,&am);
	//debugMac(&am);
	
	for(int i = 0;i < len ;i++){
		if(autoMachineReadChar(&am,t[i]) == am.accept){
			printf("pattern match!\n");
			return i - pLen + 1;
		}//end if
	}//end for i
	
	if(am.cur != am.accept){
		printf("pattern Not match!\n");
	}
	
	return -1;
}

int charToIndex(char c){
	for(int i = 0; i < CHAR_SET_SIZE;i++){
		if(c == CHAR_SET[i])
			return i;
	}
	return CHAR_SET_SIZE;
}
