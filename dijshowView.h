// dijshowView.h : interface of the CDijshowView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIJSHOWVIEW_H__7ED0DE42_AA7B_4576_8CE2_867D56FB919C__INCLUDED_)
#define AFX_DIJSHOWVIEW_H__7ED0DE42_AA7B_4576_8CE2_867D56FB919C__INCLUDED_
	// Added by ClassView
//#include "ShortestPath.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPathObject;
class CNodeObject;
class CShortestPath;
#include <afxtempl.h>
class CDijshowView : public CView
{
protected: // create from serialization only
	CDijshowView();
	DECLARE_DYNCREATE(CDijshowView)

// Attributes
public:
	CDijshowDoc* GetDocument();

// Operations
public:
	CShortestPath *shortestpath;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDijshowView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation

public:
	CString title;
	CNodeObject * tmpNode;
	CNodeObject * moveNode;
	CPathObject * currentpath;
	int  cur_tool;  //0-node 1-path 2-move 3-execute 4-step
//	bool IsHead;
//	bool IsDrawPath;
//	bool IsDrawNode;
//	bool IsMove;
//	bool IsExecute;
	CList<CPathObject *,CPathObject *> PathList;
	int currentnum;
	int sequencenum;
	int stepnum;
	CList<CNodeObject *,CNodeObject *> NodeList;
//	CNodeObject **NodeArray;
	int nodenum;
	virtual ~CDijshowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDijshowView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnStart();
	afx_msg void OnPathtool();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBeginsearch();
	afx_msg void OnMovenode();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	afx_msg void OnExstep();
	afx_msg void OnUpdateBeginsearch(CCmdUI* pCmdUI);
	afx_msg void OnUpdateExstep(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMovenode(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePathtool(CCmdUI* pCmdUI);
	afx_msg void OnNodetool();
	afx_msg void OnUpdateNodetool(CCmdUI* pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP()

};

#ifndef _DEBUG  // debug version in dijshowView.cpp
inline CDijshowDoc* CDijshowView::GetDocument()
   { return (CDijshowDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIJSHOWVIEW_H__7ED0DE42_AA7B_4576_8CE2_867D56FB919C__INCLUDED_)
