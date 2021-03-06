#include <stdio.h>


#define NEXT_PORT_OF_2(x) ((((x) & (~(0x01))) << 1) ? (((x) & (~(0x01))) << 1) : 1)
int binary_search(int arr[], int n, int num)
{
	int i, pos = 0;
	
	for(i = pos = n/2/*NEXT_PORT_OF_2(n) / 2*/; ; i >>= 1)
	{
		printf("%d, %d\n", i, pos);
		if(pos < 0)
			pos += i;
		else if(pos >= n)
			pos -= i;
		else 
		{
			if(arr[pos] > num)
			{
				pos -= i;
			}
			else if(arr[pos] < num)
			{
				pos += i;
			}
			else
				return pos;
		}
		if(i == 0)
			break;
	}
	return pos;
}

int main()
{
#if 0
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		printf("i = %d, NEXT_PORT_OF_2(%d) = %d\n", i, i, NEXT_PORT_OF_2(i));
	}
#endif
	int arr[10000];
	int i = 0;
	for(i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		arr[i] = i;
	}
	printf("%d\n", binary_search(arr, sizeof(arr) / sizeof(int), 9));
	return 0;
}
