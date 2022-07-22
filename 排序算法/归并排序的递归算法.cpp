#include<iostream>
using namespace std;
const int inf=0x7fffffff;
const int MAX=1000;

void Merge(int*a,int left,int right,int mid)
{
	int n1=mid-left+1;
	int n2=right-mid;
	//int l[n1+1],r[n2+1]; 
	//it is supposed to use a dynamic arry 
	//typename* pointer_name = new typename [num_elememts]; 
	int* l=new int [n1+1];
	int* r=new int [n2+1]; 
	for(int i=0;i<n1;++i)
		l[i]=a[left+i];
	for(int i=0;i<n2;++i)
		r[i]=a[mid+1+i];
	l[n1]=inf,r[n2]=inf;
	int i=0,j=0;
	for(int k=left;k<=right;++k){
		if(l[i]<r[j])
			a[k]=l[i++];
		else a[k]=r[j++];
	}
	delete [] l;
	delete [] r;
}
void mergeSort(int*a,int left,int right)
{
	if(left<right){
		int mid=(left+right)/2;
		mergeSort(a,left,mid);
		mergeSort(a,mid+1,right);
		Merge(a,left,right,mid);
	}
}

int main()
{
	int a[MAX],n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	mergeSort(a,1,n); 
	for(int i=1;i<=n;++i)
		cout<<a[i]<<" ";
	cout<<endl;
    return 0;
}

