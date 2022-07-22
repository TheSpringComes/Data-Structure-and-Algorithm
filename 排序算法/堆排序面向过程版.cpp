#include<iostream>
using namespace std;
const int MAX=1000;
void Heapify(int* a, int n, int position)//维护 
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
void build_max_heap(int* a,int n)//建立最大堆 
{
	int heap_size = n;
	for(int i=heap_size/2;i>=1;--i){
		Heapify(a, heap_size, i);
	}
}
void HeapSort(int* a,int n)//桶排序 
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
	int a[MAX],n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	HeapSort(a,n); 
	for(int i=1;i<=n;++i)
		cout<<a[i]<<" ";
	cout<<endl;
    return 0;
}
