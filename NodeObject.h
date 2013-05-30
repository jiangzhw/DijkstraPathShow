// NodeObject.h: interface for the CNodeObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODEOBJECT_H__B6DC6B90_A016_478C_872D_E114EB1F0C65__INCLUDED_)
#define AFX_NODEOBJECT_H__B6DC6B90_A016_478C_872D_E114EB1F0C65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNodeObject  
{
public:
	CRect rect;
	bool hittest(CPoint point);
	CNodeObject();
	CNodeObject(int ser,CPoint point);
	virtual ~CNodeObject();
	CPoint centre;
	int	sernum;	
	void	Draw(CDC *pDC);

};

#endif // !defined(AFX_NODEOBJECT_H__B6DC6B90_A016_478C_872D_E114EB1F0C65__INCLUDED_)
