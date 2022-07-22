#include<iostream>
#include"randomarry.h"
using namespace std;
void Heapify(int* a, int n, int position)//Î¬»¤ 
{
	int i=position,large=position;
	while(1){
		int left = i<<1;
		int right = left|1;
		if(left<=n&&a[left]>a[large])
			large = left;
		if(right<=n&&a[right]>a[large])
			large = right;
		if(i==large) break;
		int temp=a[large];
		a[large] = a[i];
		a[i] = temp;
		i = large;
	} 
}
void build_max_heap(int* a,int n)
{
	int heap_size = n;
	for(int i=heap_size/2;i>=1;--i){
		Heapify(a, heap_size, i);
	}
}
void HeapSort(int* a,int n)
{
	int heap_size = n;
	build_max_heap(a,heap_size);
	for(int i=heap_size;i>=2;--i){
		int temp = a[1];
		a[1] = a[heap_size];
		a[heap_size--] = temp;
		Heapify(a, heap_size, 1);
	}
}
int main()
{
	int num = arrySize();//50
	int*a = CreateRandArry();
	OutputArry(a);
	HeapSort(a,num); 
	OutputArry(a); 
    return 0;
}
