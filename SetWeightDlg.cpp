// SetWeightDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dijshow.h"
#include "SetWeightDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetWeightDlg dialog


CSetWeightDlg::CSetWeightDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetWeightDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetWeightDlg)
	m_weight = 0;
	//}}AFX_DATA_INIT
}


void CSetWeightDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetWeightDlg)
	DDX_Text(pDX, IDC_SETWEIGHT, m_weight);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetWeightDlg, CDialog)
	//{{AFX_MSG_MAP(CSetWeightDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetWeightDlg message handlers
