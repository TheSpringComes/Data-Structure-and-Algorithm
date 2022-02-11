#include<iostream>
#include<queue> 
using namespace std;
const int INF = 0x7fffffff;
const int MaxVertexNum = 1e5+10;

int n,m,s;
int dist[MaxVertexNum];
bool collected[MaxVertexNum];
typedef int ElementType;
typedef struct AdjVNode * PAdjVNode;
struct AdjVNode{
	int AdjV;
	int Weight;
	PAdjVNode next;
};
typedef struct GraphNode* PtrNode;
struct GraphNode{
	int NV,NE;
	PAdjVNode G[MaxVertexNum];
};//Adjacency List
typedef int Vertex;
PtrNode CreateGraph(int VertexNum)
{
	PtrNode Graph = new struct GraphNode;
	Graph->NV = VertexNum;
	Graph->NE = 0;
	for(Vertex V = 0;V<MaxVertexNum;++V)
		Graph->G[V]=NULL; 
	return Graph;
}
inline void InsertEdge(PtrNode Graph,int m)
{
	Vertex V1,V2;
	ElementType mWeight;
	for(int i=0;i<m;++i){
		cin>>V1>>V2>>mWeight;
		PAdjVNode NewNode = new struct AdjVNode;
		NewNode->AdjV = V2;
		NewNode->Weight=mWeight;
		NewNode->next=Graph->G[V1];
		Graph->G[V1]=NewNode;
	}
}

struct Node{
	int dis;
	int vertex;
	
	bool operator < (const Node& node) const{
		return dis > node.dis;
	}
};
void Dijkstra(Vertex s,PtrNode Graph)
{
	priority_queue<Node> Q;
	Q.push((Node){0,s});
	while(!Q.empty()){
		struct Node node = Q.top();Q.pop();
		int V = node.vertex;
		if(dist[V]!=node.dis)continue;
		collected[V]=true;
		PAdjVNode pv=Graph->G[V];
		while(pv){
			if(!collected[pv->AdjV] && ((dist[V]+pv->Weight) < dist[pv->AdjV])){
				dist[pv->AdjV] = dist[V]+pv->Weight;
				Q.push((Node){dist[pv->AdjV],pv->AdjV});
			}
			pv=pv->next;
		}
	}
	for(int i=1;i<=Graph->NV;++i)
		cout<<dist[i]<<" ";
	cout<<endl;
}
int main()
{
	cin>>n>>m>>s;
	for(int i=0;i<=n;++i){
		dist[i] = INF;
		collected[i] = false;
	}dist[s] = 0;
	
	PtrNode Graph = CreateGraph(n);
	InsertEdge(Graph,m);
	Dijkstra(s,Graph);
	return 0;
} 
