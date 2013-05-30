// dijshowDoc.cpp : implementation of the CDijshowDoc class
//

#include "stdafx.h"
#include "dijshow.h"

#include "dijshowDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDijshowDoc

IMPLEMENT_DYNCREATE(CDijshowDoc, CDocument)

BEGIN_MESSAGE_MAP(CDijshowDoc, CDocument)
	//{{AFX_MSG_MAP(CDijshowDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDijshowDoc construction/destruction

CDijshowDoc::CDijshowDoc()
{
	// TODO: add one-time construction code here

}

CDijshowDoc::~CDijshowDoc()
{
}

BOOL CDijshowDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDijshowDoc serialization

void CDijshowDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDijshowDoc diagnostics

#ifdef _DEBUG
void CDijshowDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDijshowDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDijshowDoc commands
