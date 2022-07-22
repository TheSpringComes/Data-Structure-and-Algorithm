#ifndef _randomarry_h_
#define _randomarry_h_

#include<cstdio>
#include<cstdlib>
#include<ctime>
const int arrySIZE = 50; 
const int BASE = 1e3;
int randarry[arrySIZE+1];
int* CreateRandArry()
{	
	srand(time(0));
	for(int i=1;i<=arrySIZE;++i)
		randarry[i]=rand()%BASE;//32767
    return randarry;
}
void OutputArry(int* arry)
{
	for(int i=1;i<=arrySIZE;++i)
		printf("%d ",arry[i]);
	printf("\n");
}
int arrySize()
{
	return int(arrySIZE);
}

#endif
