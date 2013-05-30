#if !defined(AFX_SETWEIGHTDLG_H__0D2DAE7F_57FD_4274_A111_0695BEB63EF9__INCLUDED_)
#define AFX_SETWEIGHTDLG_H__0D2DAE7F_57FD_4274_A111_0695BEB63EF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetWeightDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetWeightDlg dialog

class CSetWeightDlg : public CDialog
{
// Construction
public:
	CSetWeightDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetWeightDlg)
	enum { IDD = IDD_SETWEIGHTDLG };
	int		m_weight;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetWeightDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetWeightDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETWEIGHTDLG_H__0D2DAE7F_57FD_4274_A111_0695BEB63EF9__INCLUDED_)
