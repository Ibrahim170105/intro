#include <iostream>
using namespace std;
const int N = 10;

int array[N] = {12,34,67,34,1,8,7,56,9,6};

void swap(int x,int y)
{
	int temp = array[x];
	array[x] = array[y];
	array[y] = temp;
}

void bubble_sort(int arr[])
{
	for(int i = 0;i < N;i++)
	{
		int n = N;
		int swapped = 0;
		for(int j = 1;j < n;j++)
		{
			if(arr[j] < arr[j - 1])
			{
				swap(j - 1,j);
				swapped = 1;
			}
		}
		n--;
		if(swapped == 0)
		{
			break;
		}
	}
}

int main()
{
	cout<<"\n-------BUBBLE SORT-----------\n";
	cout<<"\nBEFORE SORTING:"<<endl;
	for(int i = 0;i < N;i++)
	{
		cout<<array[i]<<",";
	}
	bubble_sort(array);
	cout<<"\nAFTER SORTING:"<<endl;
	for(int i = 0;i < N;i++)
	{
		cout<<array[i]<<",";
	}
}