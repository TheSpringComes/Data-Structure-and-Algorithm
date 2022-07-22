#include<iostream> 
using namespace std;
const int negative_inf=0xc0c0c0c0;
const int MAX=1000;
struct Node{
	int left,right;
	int sum;
};
typedef struct Node node;
node fing_max_crossing_subarry(int* a,int left,int right,int mid)
{
	int left_sum=negative_inf,right_sum=negative_inf;
	int left_max=mid,right_max=mid+1;
	int sum=0;
	int i=mid,j=mid+1;
	while(i>=left){
		sum+=a[i--];
		if(sum>left_sum){
			left_sum=sum;
			left_max=i+1;
		}
	}
	sum=0;
	while(j<=right){
		sum+=a[j++];
		if(sum>right_sum){
			right_sum=sum;
			right_max=j-1;
		}
	}
	node tempnode;
	tempnode.left=left_max;
	tempnode.right=right_max;
	tempnode.sum=left_sum+right_sum;
	return tempnode;
}
node find_max_subarry(int* a,int left,int right)
{
	node temp;
	if(left>=right){
		temp.left=left;
		temp.right=right;
		temp.sum=a[left];
		return temp;
	}
	else{
		int mid=(left+right)/2;
		node t1,t2,t3;
		t1=find_max_subarry(a,left,mid);
		t2=find_max_subarry(a,mid+1,right);
		t3=fing_max_crossing_subarry(a,left,right,mid);
		if(t1.sum>=t2.sum&&t1.sum>=t3.sum) return t1;
		else if(t2.sum>=t1.sum&&t2.sum>=t3.sum) return t2;
		else if(t3.sum>=t1.sum&&t3.sum>=t2.sum) return t3;
	}
}
int main()
{
	int n;
	int a[MAX];
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	node A;
	A=find_max_subarry(a,1,n);
	cout<<"From "<<A.left<<" to "<<A.right;
	cout<<" the sum of the max subarry is "<<A.sum<<"."<<endl;
    return 0;
}
//可以用于计算股票价格增长的最大值,差分数列 
//eg:16
//13 -3 -25 20 -3 -16 -23 18 20 -7 12 -5 -22 15 -4 7
//output:From 8 to 11 the sum of the max subarry is 43.
