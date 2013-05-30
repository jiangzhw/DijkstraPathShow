// dijshowDoc.h : interface of the CDijshowDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIJSHOWDOC_H__58052FC3_16C6_43B6_A80D_F4AE635A70DB__INCLUDED_)
#define AFX_DIJSHOWDOC_H__58052FC3_16C6_43B6_A80D_F4AE635A70DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDijshowDoc : public CDocument
{
protected: // create from serialization only
	CDijshowDoc();
	DECLARE_DYNCREATE(CDijshowDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDijshowDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDijshowDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDijshowDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIJSHOWDOC_H__58052FC3_16C6_43B6_A80D_F4AE635A70DB__INCLUDED_)
