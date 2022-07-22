#include<iostream>
using namespace std;
const int MAX=1000;
void CountingSort(int* a,int n,int max_value)
{
	int* b = new int [n+1];
	int* c = new int [max_value];
	int k = max_value;
	for(int i=0;i<k;++i) c[i]=0;
	for(int i=1;i<=n;++i) c[a[i]]++;//c[i] contains the number of elements equal to i 
	for(int i=1;i<k;++i) c[i]+=c[i-1];//c[i] contains the number of elements smaller than or equal to i
	for(int i=n;i>=1;--i) b[c[a[i]]--] = a[i];//ensure the sorted arry is stable
	for(int i=1;i<=n;++i) a[i] = b[i];
	delete [] b;
	delete [] c;
} 
int main()
{
	int a[MAX],n,k;
	cout<<"要排序的元素的个数:"; cin>>n;
	cout<<"所有元素都要是大于0的整数\n元素的最大值:"; cin>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	CountingSort(a,n,k); 
	for(int i=1;i<=n;++i) cout<<a[i]<<" ";
	cout<<endl;
    return 0;
}

