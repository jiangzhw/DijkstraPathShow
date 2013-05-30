// SetNumDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dijshow.h"
#include "SetNumDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetNumDlg dialog


CSetNumDlg::CSetNumDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetNumDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetNumDlg)
	m_nodenum = 0;
	//}}AFX_DATA_INIT
}


void CSetNumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetNumDlg)
	DDX_Text(pDX, IDC_ENTERNUM, m_nodenum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetNumDlg, CDialog)
	//{{AFX_MSG_MAP(CSetNumDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetNumDlg message handlers


