// PathObject.cpp: implementation of the CPathObject class.
//
//////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include "dijshow.h"
#include "PathObject.h"
#include "NodeObject.h"
#include <math.h>
#define PI 3.1415926535
#define arrow 10
#define radius 10
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPathObject::CPathObject()
{
	weight=0;
	IsSelected=false;
}

CPathObject::~CPathObject()
{
}

void CPathObject::Draw(CDC* pDC){
	COLORREF color;
	if(IsSelected)
		color=COLORREF(RGB(255,0,0));
	else
		color=COLORREF(RGB(0,0,0));
	CPen pen(PS_SOLID,2,color);
	CPen *pOldPen=NULL;
	pOldPen=pDC->SelectObject(&pen);

	double	angle=CalcAngle(headnode->centre.x-endnode->centre.x,
		headnode->centre.y-endnode->centre.y);
	CPoint pt1,pt2;
	pt1=GetAnglePoint(headnode->centre.x,headnode->centre.y,radius,radius,(int)(angle+180));
	pt2=GetAnglePoint(endnode->centre.x,endnode->centre.y,radius,radius,(int)(angle));

	pDC->MoveTo(pt1);
	pDC->LineTo(pt2);
	

	CPoint point(endnode->centre.x/3+headnode->centre.x*2/3,
				endnode->centre.y/3+headnode->centre.y*2/3);
	CPoint point1(endnode->centre.x/8+headnode->centre.x*7/8,
				endnode->centre.y/8+headnode->centre.y*7/8-5);
	pt1=GetAnglePoint(point.x,point.y,arrow,arrow,(int)(angle+14));
	pt2=GetAnglePoint(point.x,point.y,arrow,arrow,(int)(angle-14));
    pDC->MoveTo(point);
	pDC->LineTo(pt1);
	pDC->MoveTo(point);
	pDC->LineTo(pt2);
	char buf[20];
	sprintf(buf,"%d",weight);
	pDC->SetTextColor(RGB(0,0,255));
	pDC->TextOut( point1.x, point1.y ,buf );

}

float CPathObject::CalcAngle(float x,float y)
{
	float angle;
	if	(fabs(x)<0.0001 && fabs(y)<0.0001)
		return 0;	
	if	(fabs(x)<0.0001 && y>0)
		return 270;
	else if (fabs(x)<0.0001 && y<0 )
		return 90;
	else  if (fabs(y)<0.0001 && x>0 )
		return 0;
	else  if (fabs(y)<0.0001 && x<0)
		return 180;
	angle=(float)(atan2(-y,x)*180.0/PI);
	if	(angle<0)
		angle+=360.0;
	return	angle;
}

void CPathObject::GetAnglePoint1(int x,int y,int rx,int ry, int angle,float *x1,float *y1)
{
	float	tmp;

	angle=angle-abs(angle)/360*360;
	if	(angle<0)
		angle=360+angle;
	if	((angle>=0 && angle<45 ) || (angle>315 && angle<=360) ||(angle>135 && angle<=225 ))
	{
		tmp=(float)sqrt(rx*rx*tan(angle*PI/180)*tan(angle*PI/180)+ry*ry);
		if	(fabs(tmp)<0.00001)
		{
			*x1=(float)x;
			*y1=(float)y;
			return	;		
		}
		if	(angle>135 && angle<=225 )
			*x1=x-rx*ry /tmp;
		else
			*x1=x+rx*ry /tmp;
		if	((angle>135 && angle <=180) || (angle>=0 && angle <45))
			*y1=(float)(y-rx*ry/tmp*fabs(tan(angle*PI/180)));	
		else
			*y1=(float)(y+rx*ry/tmp*fabs(tan(angle*PI/180)));	
		
	}
	else 
	{
		tmp=(float)sqrt(ry*ry*tan(PI/2-angle*PI/180.0)*tan(PI/2-angle*PI/180.0)+rx*rx);
		if	(fabs(tmp)<0.00001)
		{
			*x1=(float)x;
			*y1=(float)y;
			return	;		
		}
		if	(angle>=45 && angle<=135 )
			*y1=y-rx*ry /tmp;
		else
			*y1=y+rx*ry/tmp;
		if	((angle>=45 && angle <=90) || (angle>=270 && angle <=315))
			*x1=(float)(x+rx*ry/tmp*fabs(tan(PI/2-angle*PI/180.0)));
		else
			*x1=(float)(x-rx*ry/tmp*fabs(tan(PI/2-angle*PI/180.0)));
	
	} 
}

CPoint CPathObject::GetAnglePoint(int x,int y,int rx,int ry, int angle)
{
	CPoint	point(x,y);
	float	aa,bb;
	GetAnglePoint1( x, y, rx, ry,  angle,&aa,&bb);
	point.x=Round(aa);
	point.y=Round(bb);
	return	point;
}

int CPathObject::Round(float f)
{
	if (f<0) 
		return	((int)(f-0.5));
  else
		return	((int)(f+0.5));
}
