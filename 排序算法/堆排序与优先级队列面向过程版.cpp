/*struct + priority_queue + HeapSort*/
/*结构体+优先级队列的实现+堆排序*/
#include<iostream> 
using namespace std;
const int MAX=100;
const int inf=0x7fffffff;

typedef struct Heap* MaxHeap;
typedef int ElementType;
struct Heap{
	ElementType* Elememts;
	int heapSize,Capacity;
};

MaxHeap create_maxheap(int maxSize)
{
	MaxHeap H = new struct Heap;
	H->Elememts = new ElementType[maxSize];
	H->Capacity = maxSize;
	H->heapSize = 0;
	H->Elememts[0] = inf;
	return H;
}

void Heapify(MaxHeap a,int position)//维护 
{
	int n = a->heapSize;
	int i=position,large=position;
	while(1){
		int left = i<<1;
		int right = left|1;
		if(left<=n&&a->Elememts[left]>a->Elememts[large])
			large = left;
		if(right<=n&&a->Elememts[right]>a->Elememts[large])
			large = right;
		if(i==large) break;
		int temp=a->Elememts[large];
		a->Elememts[large] = a->Elememts[i];
		a->Elememts[i] = temp;
		i = large;
	} 
}

void Heapify2(MaxHeap a,int position)//维护2 
{
	int parent=position,child=position;
	int tmp=a->Elememts[position];
	for(;parent<<1 <= a->heapSize;parent=child){
		child = parent<<1;
		if((child|1) <= a->heapSize && a->Elememts[child|1] > a->Elememts[child]) child |= 1;
		if(a->Elememts[child] <= tmp) break;
		a->Elememts[parent] = a->Elememts[child];
	}
	a->Elememts[parent] = tmp;
}//注意运算符优先级 

void build_max_heap(MaxHeap a)//建立最大堆 
{
	for(int i=a->heapSize>>1;i>=1;--i)
		Heapify(a,i);
}

void Insert(MaxHeap a,int element)
{
	int i = ++a->heapSize;
	for(;a->Elememts[i>>1]<element;i >>= 1){
		a->Elememts[i] = a->Elememts[i>>1];
	}
	a->Elememts[i] = element;
}

int extract_max_element(MaxHeap a)
{
	int max = a->Elememts[1];
	a->Elememts[1] = a->Elememts[a->heapSize--];
	int tmp = a->Elememts[1];
	int parent=1,child=1;
	for(;parent<<1 <= a->heapSize;parent=child){
		child = parent<<1;
		if((child|1) <= a->heapSize && a->Elememts[child|1] > a->Elememts[child]) child |= 1;
		if(a->Elememts[child] <= tmp) break;
		a->Elememts[parent] = a->Elememts[child];
	}
	a->Elememts[parent] = tmp;
	return max;
}

int increase_key(MaxHeap a,int initial_position,int now_element)
{
	if(now_element < a->Elememts[initial_position]) cerr<<"new element is smaller!"<<endl;
	int i=initial_position;
	for(;now_element > a->Elememts[i>>1];i >>= 1)
		a->Elememts[i] = a->Elememts[i>>1];
	a->Elememts[i] = now_element;
} 

void HeapSort(MaxHeap a,int n)//桶排序 
{
	build_max_heap(a);
	for(int i=a->heapSize;i>=2;--i){
		int temp = a->Elememts[1];
		a->Elememts[1] = a->Elememts[a->heapSize];
		a->Elememts[a->heapSize--] = temp;
		Heapify(a,1);
	}
	a->heapSize = n;
}

int main()
{
	MaxHeap a = create_maxheap(MAX);
	int n;cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a->Elememts[i];
	a->heapSize = n;
	HeapSort(a,n); 
	for(int i=1;i<=n;++i)
		cout<<a->Elememts[i]<<" ";
	cout<<endl;
    return 0;
}
