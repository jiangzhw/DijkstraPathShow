// NodeObject.cpp: implementation of the CNodeObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "dijshow.h"
#include "NodeObject.h"
#define radius 10

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CNodeObject::CNodeObject()
{
}

CNodeObject::CNodeObject(int ser,CPoint point)
{
	sernum=ser;
	centre=point;
	rect.SetRect(centre.x-radius,centre.y-radius,centre.x+radius,centre.y+radius);
}

CNodeObject::~CNodeObject()
{

}

void CNodeObject::Draw(CDC *pDC){
	CPen pen(PS_SOLID,2,COLORREF(RGB(255,0,0)));
	CPen *pOldPen=NULL;
	pOldPen=pDC->SelectObject(&pen);
	pDC->Ellipse(centre.x-radius,centre.y-radius,centre.x+radius,centre.y+radius);
	char buf[20];
	sprintf(buf,"%d",sernum);
	pDC->TextOut( centre.x-4, centre.y-8 ,buf );	
	pDC->SelectObject(pOldPen);
}

bool CNodeObject::hittest(CPoint point)
{
	if(rect.PtInRect(point))
		return true;
	return false;
}
