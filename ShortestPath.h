// ShortestPath.h: interface for the CShortestPath class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHORTESTPATH_H__20694803_E4BB_4D89_BA09_23ED6EBB839A__INCLUDED_)
#define AFX_SHORTESTPATH_H__20694803_E4BB_4D89_BA09_23ED6EBB839A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDijshowView;

class CShortestPath  
{
public:
	int ** choosepath;
	int * shortpath;
	int ** route;
	CDijshowView * pView;
	int **pathmatrix;
	CShortestPath(CDijshowView *pView1);
	virtual ~CShortestPath();
	void dij();
};

#endif // !defined(AFX_SHORTESTPATH_H__20694803_E4BB_4D89_BA09_23ED6EBB839A__INCLUDED_)
