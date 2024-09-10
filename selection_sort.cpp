#include <iostream>
using namespace std;

const int n = 6;
int arr[n] = {12,45,67,4,3,9};

void swap(int &i,int &min)
{
	int temp = arr[i];
	arr[i] = arr[min];
	arr[min] = temp;
}

void sort(int arr[])
{
	for (int i = 0;i < n;i++)
	{
		int min = i;
		for (int j = i+1;j < n;j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		swap(i,min);
	}
}

int main()
{
	cout<<"\nBefore sorting:\n"<<endl;
	
	for(int i = 0;i < n;i++)
	{
		cout<<arr[i]<<",";
	}
	cout<<endl;
	cout<<"\nAfter sorting:\n"<<endl;
	
	sort(arr);
	
	for(int i = 0;i < n;i++)
	{
		cout<<arr[i]<<",";
	}
}