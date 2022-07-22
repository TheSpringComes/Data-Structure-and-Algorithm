#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int MAX=1000;
int RandomPartition(int* a,int left,int right)
{
	int rand_index = rand()%(right-left+1)+left;
	int tmp = a[rand_index];
	a[rand_index] = a[right];
	a[right] = tmp;
	int x = a[right];
	int i = left-1;
	for(int j = left;j<right;++j){
		if(a[j]<x){
			tmp = a[j];
			a[j] = a[++i];
			a[i] = tmp;
		}
	}
	a[right] = a[++i];
	a[i] = x;
	return i;
}
void QuickSort(int* a,int left,int right)
{
	if(left<right){
		int mid = RandomPartition(a,left,right);
		QuickSort(a,left,mid-1);
		QuickSort(a,mid+1,right);
	} 
}
int main()
{
	srand(time(0));
	int a[MAX],n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	QuickSort(a,1,n); 
	for(int i=1;i<=n;++i)
		cout<<a[i]<<" ";
	cout<<endl;
    return 0;
}

