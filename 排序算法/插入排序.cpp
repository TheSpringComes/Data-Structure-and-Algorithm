#include<iostream>
using namespace std;
const int MAX=1000;
void insertion_Sort(int *a,int n)//API˵��:����a�±��1��ʼ,a[0]=0;n������Ԫ�صĸ��� 
{
	for(int j=1;j<=n;++j){
		int key=a[j];
		int i=j-1;
		while(i>=1&&a[i]>key){//ʹ��a[i]>key�����Ǵ��ڵ��ڱ�֤��������ȶ��� 
			a[i+1]=a[i--];
		}
		a[i+1]=key;
	}
} 
int main()
{
	int a[MAX],n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	insertion_Sort(a,n); 
	for(int i=1;i<=n;++i)
		cout<<a[i]<<" ";
	cout<<endl;
    return 0;
}
