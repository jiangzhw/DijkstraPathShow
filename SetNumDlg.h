#if !defined(AFX_SETNUMDLG_H__06DA7111_506D_429B_BFF2_0640AF457F4D__INCLUDED_)
#define AFX_SETNUMDLG_H__06DA7111_506D_429B_BFF2_0640AF457F4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetNumDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetNumDlg dialog

class CSetNumDlg : public CDialog
{
// Construction
public:
	CSetNumDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetNumDlg)
	enum { IDD = IDD_SETNUMDLG };
	int		m_nodenum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetNumDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetNumDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETNUMDLG_H__06DA7111_506D_429B_BFF2_0640AF457F4D__INCLUDED_)
