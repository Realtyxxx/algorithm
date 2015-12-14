// 
// Ѱ�����������������

// findMaxSubarrayOrigin ��ٷ�����  O(n*n)
// findMaxSubarrayDivideConquer  ���η� ���縴�Ӷ�O(nlgn)
#include <stdio.h>

#define MIN_VALUE  -999999999

void findMaxSubarrayOrigin(int *data,int start,int end,int *pMaxSubarray,int *pLeft,int *pRight);
void printResult(int *data,int left,int right,int maxSubarray);
int addAll(int *data,int start,int end);
void findMaxSubarrayDivideConquer(int *data,int start,int end,int *pMaxSubarray,int *pLeft,int *pRight);
int findSubarrayCrossMid(int *data,int start,int mid,int end,int *midValue,int *pLeft,int *pRight);//�ҵ���Խ�е�mid�����������

int main()
{
	int data[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	//int data[]={3,2,-1};
	int len = sizeof(data)/sizeof(data[0]);
	
	int maxValue = 0;
	int left,right;

	findMaxSubarrayOrigin(data,0,len -1, &maxValue,&left,&right);
	printResult(data,left,right,maxValue);

	findMaxSubarrayDivideConquer(data,0,len - 1,&maxValue,&left,&right);
	printResult(data,left,right,maxValue);

	return 0;
}

//���
void findMaxSubarrayOrigin(int *data,int start,int end,int *pMaxSubarray,int *pLeft,int *pRight)
{
	int i , j;
	int left,right;
	int max = MIN_VALUE;

	for(i = start; i <= end ; i++)
	{
		for(j = i;j <= end;j++)
		{
			int sum = addAll(data,i,j);					
			if(sum > max)
			{
				max = sum;
				left = i;
				right = j;
			}	
		}//end for j
	}//end for i

	*pMaxSubarray = max;
	*pLeft = left;
	*pRight = right;
}

//���η�  ������������
//���η� ���縴�Ӷ�O(nlgn)
void findMaxSubarrayDivideConquer(int *data,int start,int end,int *pMaxSubarray,int *pLeft,int *pRight)
{
	if(start == end)//�������
	{
		*pMaxSubarray = data[end];
		*pLeft = end;
		*pRight = end;
	}else{//�ɵݹ����
		int leftL,leftR,leftSubValue;
		int rightL,rightR,rightSubValue;
		int midL,midR,midSubValue;
		int mid = (start + end) / 2;

		findMaxSubarrayDivideConquer(data,start,mid,&leftSubValue,&leftL,&leftR);
		findMaxSubarrayDivideConquer(data,mid + 1,end,&rightSubValue,&rightL,&rightR);
		findSubarrayCrossMid(data,start,mid,end,&midSubValue,&midL,&midR);

		if(leftSubValue >= rightSubValue && leftSubValue >= midSubValue)//������
		{
			*pMaxSubarray = leftSubValue;
			*pLeft = leftL;
			*pRight = leftR;
		}
		else if(rightSubValue >= leftSubValue && rightSubValue >= midSubValue)//�Ҳ����
		{
			*pMaxSubarray = rightSubValue;
			*pLeft = rightL;
			*pRight = rightR;
		}
		else if(midSubValue >= leftSubValue && midSubValue >= rightSubValue)//�м�ֵ���
		{
			*pMaxSubarray = midSubValue;
			*pLeft = midL;
			*pRight = midR;
		}//end if
		printf("%d  ,left = %d   ,right = %d\n",*pMaxSubarray,*pLeft,*pRight);
	}//end if
}

int findSubarrayCrossMid(int *data,int start,int mid,int end,int *pMidValue,int *pLeft,int *pRight)
{
	int i;
	int left = mid;
	int right = mid+1;
	int leftSum = MIN_VALUE;
	int rightSum = MIN_VALUE;
	int sum = 0;
	
	for(i = mid; i >= start ; i--)
	{
		sum += data[i];
		if(sum > leftSum)
		{
			leftSum = sum;
			left = i;
		}
	}//end for i
	
	sum = 0;
	for(i = mid+1;i <= end; i++)
	{
		sum += data[i];
		if(sum > rightSum)
		{
			rightSum  = sum;
			right = i;
		}
	}//end for i

	*pMidValue = leftSum + rightSum;
	*pLeft = left;
	*pRight = right;

	return 0;
}

void printResult(int *data,int left,int right,int maxSubarray)
{
	int i;
	printf("max sub array is: ");
	for(i = left; i<=right;i++)
	{
		printf("%d  ",data[i]);
	}//end for i
	printf("\n");
	printf("max sub array value is: %d\n",maxSubarray);
}

int addAll(int *data,int start,int end)
{
	int sum = 0;
	int i;
	for(i = start; i<= end;i++)
	{
		sum += data[i];
	}//end for i
	return sum;
}


