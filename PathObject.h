// PathObject.h: interface for the CPathObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PATHOBJECT_H__890443D8_BC8B_4654_A27F_80D18447BA43__INCLUDED_)
#define AFX_PATHOBJECT_H__890443D8_BC8B_4654_A27F_80D18447BA43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "NodeObject.h"
class CPathObject  
{
public:
	void Draw(CDC * pDC);
	int weight;
	CNodeObject * endnode;
	CNodeObject * headnode;
	CPathObject();
	float CalcAngle(float x,float y);
	void GetAnglePoint1(int x,int y,int rx,int ry, int angle,float *x1,float *y1);
	CPoint GetAnglePoint(int x,int y,int rx,int ry, int angle);
	int Round(float f);
	bool IsSelected;
	virtual ~CPathObject();

};

#endif // !defined(AFX_PATHOBJECT_H__890443D8_BC8B_4654_A27F_80D18447BA43__INCLUDED_)
