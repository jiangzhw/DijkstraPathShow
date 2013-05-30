// ShortestPath.cpp: implementation of the CShortestPath class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "include.h"
#define INFINITY 100000

#include "ShortestPath.h"
#define	INFINITY 100000
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CShortestPath::CShortestPath(CDijshowView *pView1)
{
	pView=pView1;
}
//
CShortestPath::~CShortestPath()
{
}

void CShortestPath::dij(){
	int vexnum;
	vexnum=pView->nodenum;
	route=new int*[vexnum];

	for(int i=0;i<vexnum;i++)
		route[i]=new int[vexnum];
	for(i=0;i<vexnum;i++)
		for(int j=0;j<vexnum;j++)
			route[i][j]=0;
	int **distance=new int*[vexnum];
	for( i=0;i<vexnum;i++)
		distance[i]=new int[vexnum];//distance[i]=*(distance+i);
	pathmatrix=new int*[vexnum];
	for( i=0;i<vexnum;i++)
		pathmatrix[i]=new int[vexnum];
	for( i=0;i<vexnum;i++)
		for(int j=0;j<vexnum;j++){
			distance[i][j]=INFINITY;
			pathmatrix[i][j]=0;
		}
	choosepath=new int*[vexnum-1];
	for( i=0;i<vexnum-1;i++)
		choosepath[i]=new int[2];
	for( i=0;i<vexnum-1;i++)
		for(int j=0;j<2;j++)
			choosepath[i][j]=0;
	
	POSITION pos = pView->PathList.GetHeadPosition();
	for ( i=0;i < pView->PathList.GetCount();i++)
	{	
	    CPathObject * path=pView->PathList.GetNext(pos);
		int m=path->headnode->sernum-1;
		int n=path->endnode->sernum-1;
		distance[m][n]=path->weight;
	}
	int *final=new int[vexnum];
	shortpath=new int[vexnum];
	for(int v=0;v<vexnum;v++){
		final[v]=false;
		shortpath[v]=distance[0][v];
		if(shortpath[v]<INFINITY){
			pathmatrix[v][0]=1;
			pathmatrix[v][v]=1;
			route[v][0]=1;
			route[v][1]=v+1;
		}
	}
	shortpath[0]=0;
	final[0]=true;
	for(i=1;i<vexnum;i++){
		int min=INFINITY;
		for(int w=0;w<vexnum;w++){
			if(!final[w]&&shortpath[w]<min){
				v=w;
				min=shortpath[w];
			}
			if(i==1)
			route[w][1]=w+1;
		}
		final[v]=true;
//choosepath[i-1][1]=v;
		for(w=0;w<vexnum;w++)
			if(!final[w]&&((min+distance[v][w])<shortpath[w])){
				shortpath[w]=min+distance[v][w];
				for(int m=0;route[v][m]!=0;m++)
					route[w][m]=route[v][m];
				route[w][m]=w+1;
				while(m<(vexnum-1)){
					route[w][m+1]=0;
					m++;
				}
				pathmatrix[w]=pathmatrix[v];
				pathmatrix[w][w]=1;
			}
		choosepath[i-1][1]=v+1;
		for(int mm=0;mm<vexnum;mm++)
		{
			if(route[v][mm]==0)
				break;
		}
		choosepath[i-1][0]=route[v][mm-2];
	}
}
