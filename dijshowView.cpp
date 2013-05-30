// dijshowView.cpp : implementation of the CDijshowView class
//

#include "stdafx.h"

#include "include.h"

#define radius 10

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDijshowView

IMPLEMENT_DYNCREATE(CDijshowView, CView)

BEGIN_MESSAGE_MAP(CDijshowView, CView)
	//{{AFX_MSG_MAP(CDijshowView)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_BEGIN, OnStart)
	ON_COMMAND(ID_PATHTOOL, OnPathtool)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_BEGINSEARCH, OnBeginsearch)
	ON_COMMAND(ID_MOVENODE, OnMovenode)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_EXSTEP, OnExstep)
	ON_UPDATE_COMMAND_UI(ID_BEGINSEARCH, OnUpdateBeginsearch)
	ON_UPDATE_COMMAND_UI(ID_EXSTEP, OnUpdateExstep)
	ON_UPDATE_COMMAND_UI(ID_MOVENODE, OnUpdateMovenode)
	ON_UPDATE_COMMAND_UI(ID_PATHTOOL, OnUpdatePathtool)
	ON_COMMAND(ID_NODETOOL, OnNodetool)
	ON_UPDATE_COMMAND_UI(ID_NODETOOL, OnUpdateNodetool)
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDijshowView construction/destruction

CDijshowView::CDijshowView()
{
	cur_tool=-1;
	currentpath=NULL;
	currentnum=0;
	nodenum=0;
	sequencenum=0;
	moveNode=NULL;
	stepnum=-1;
	tmpNode=new CNodeObject();
	title="新图";
//	最短路径算法
	// TODO: add construction code here	
}

CDijshowView::~CDijshowView()
{
}

BOOL CDijshowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
		return CView::PreCreateWindow(cs);
	
}

/////////////////////////////////////////////////////////////////////////////
// CDijshowView drawing

void CDijshowView::OnDraw(CDC* pDC)
{
	CDijshowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CRect client,rect;  
    CPoint point;  
    CDC dc,*pDrawDC;
    CBitmap bitmap, *pOldBitmap;
    pDC->GetClipBox(client);
    point=client.TopLeft();
 
  // draw to offscreen bitmap for fast looking repaints
	if (dc.CreateCompatibleDC(pDC))
	{
		if (bitmap.CreateCompatibleBitmap(pDC, client.Width(),client.Height()))
		{
			OnPrepareDC(&dc, NULL);//用途?
			
			pDrawDC = &dc;
			// offset origin more because bitmap is just piece of the whole drawing
			pOldBitmap = dc.SelectObject(&bitmap);
			
			dc.OffsetViewportOrg(-client.left, -client.top);
		//	dc.OffsetViewportOrg(client.left, client.top);		
			dc.SetBrushOrg(client.left % 8, client.top % 8);
			// might as well clip to the same rectangle
			dc.IntersectClipRect(client);
			//用途 
		}
		
	}  
	
	CBrush br;
//	CBrush * old_br;

	br.CreateSolidBrush(RGB(255,255,255));
	pDrawDC->SelectObject(br);
	CRect rect1(client.left-5,client.top-5,client.right+5,client.bottom+5);
	pDrawDC->Rectangle(rect1);

	POSITION pos = NodeList.GetHeadPosition();
	for (int i=0;i < NodeList.GetCount();i++)
	{	
	    CNodeObject * node=NodeList.GetNext(pos);
		node->Draw(pDrawDC);
	}
	pos = PathList.GetHeadPosition();
	for ( i=0;i < PathList.GetCount();i++)
	{	
	    CPathObject * path=PathList.GetNext(pos);
		path->Draw(pDrawDC);
	}

    if (pDrawDC != pDC)
	{
		pDC->SetViewportOrg(0, 0);
		pDC->SetWindowOrg(0,0);
		pDC->SetMapMode(MM_TEXT);
		dc.SetViewportOrg(0, 0);
		dc.SetWindowOrg(0,0);
		dc.SetMapMode(MM_TEXT);
		pDC->BitBlt(client.left,client.top, client.Width(),client.Height(),
			&dc, 0,0, SRCCOPY);
		dc.SelectObject(pOldBitmap);
	}


	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDijshowView printing

BOOL CDijshowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDijshowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDijshowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDijshowView diagnostics

#ifdef _DEBUG
void CDijshowView::AssertValid() const
{
	CView::AssertValid();
}

void CDijshowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDijshowDoc* CDijshowView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDijshowDoc)));
	return (CDijshowDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDijshowView message handlers

void CDijshowView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	
	if(cur_tool==NODE_TOOL){		
		if(currentnum==nodenum){
			MessageBox("已到达最大点");
			return;
		}
		sequencenum++;
		CNodeObject *node=new CNodeObject(sequencenum,point);
		NodeList.AddTail(node);
		currentnum++;
			
	}
	else if(cur_tool==PATH_TOOL){
		POSITION pos = NodeList.GetHeadPosition();
		for (int i=0;i < NodeList.GetCount();i++)
		{	
			CNodeObject * node=NodeList.GetNext(pos);
			if(node->hittest(point))
				if(currentpath==NULL){

					currentpath=new CPathObject();
					currentpath->headnode=node;
					tmpNode->centre=node->centre;
					currentpath->endnode=tmpNode;
					PathList.AddTail(currentpath);
				}
				else{
					if(node==currentpath->headnode)
						return;
					currentpath->endnode=node;
					
					CSetWeightDlg dlg;
					if(dlg.DoModal()==IDCANCEL){
						PathList.RemoveTail();
						currentpath=NULL;
						return;
					}
					currentpath->weight=dlg.m_weight;
					currentpath=NULL;

				}
		}		
	}
	else if(cur_tool==MOVE_TOOL){
		POSITION pos = NodeList.GetHeadPosition();
		for (int i=0;i < NodeList.GetCount();i++)
		{	
			CNodeObject * node=NodeList.GetNext(pos);
			if(node->hittest(point))
				moveNode=node;
		}
	}

	Invalidate();
	CView::OnLButtonDown(nFlags, point);

}

void CDijshowView::OnStart() 
{

	CSetNumDlg dlg;
	if(dlg.DoModal()==IDCANCEL)
		return;
	NodeList.RemoveAll();
	PathList.RemoveAll();
	cur_tool=NODE_TOOL;
//	IsMove=false;
//	IsDrawPath=false;
	currentpath=NULL;
	moveNode=NULL;
	sequencenum=0;
	nodenum=dlg.m_nodenum;
	currentnum=0;
	Invalidate(false);
	
}

void CDijshowView::OnPathtool() 
{
//	IsDrawPath=true;
//	IsMove=false;
	cur_tool=PATH_TOOL;
	
	
}

void CDijshowView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	tmpNode->centre=point;
	if(cur_tool==MOVE_TOOL&&moveNode!=NULL){
		moveNode->centre=point;
		moveNode->rect.SetRect(point.x-radius,point.y-radius,point.x+radius,point.y+radius);
	}

	Invalidate(false);
	CView::OnMouseMove(nFlags, point);
}

void CDijshowView::OnBeginsearch() 
{
	if(currentpath!=NULL&&cur_tool==PATH_TOOL){
		PathList.RemoveTail();
		currentpath=NULL;
		Invalidate(false);
	}
	
	cur_tool=EXECUTE_TOOL;
	shortestpath=new CShortestPath(this);
	shortestpath->dij();
	POSITION pos =PathList.GetHeadPosition();
	for (int i=0;i < PathList.GetCount();i++)
	{	
		CPathObject * path=PathList.GetNext(pos);
	
		path->IsSelected=false;
	
	}

	int k1,k2;
	k2=0;
	for(i=0;i<nodenum;i++){
		k1=1;
		for(int j=0;j<nodenum;j++){
			int k2=shortestpath->route[i][j];
			pos =PathList.GetHeadPosition();
			for (int k=0;k < PathList.GetCount();k++)
			{	
				CPathObject * path=PathList.GetNext(pos);
				if(path->headnode->sernum==k1&&path->endnode->sernum==k2)
					path->IsSelected=true;
				
			}
			k1=k2;

		}
	}
	stepnum=0;
//	IsExecute=true;
//	IsDrawPath=false;
//	IsMove=false;

	Invalidate(false);
}

void CDijshowView::OnMovenode() 
{
	if(currentpath!=NULL&&cur_tool==PATH_TOOL){
		PathList.RemoveTail();
		currentpath=NULL;
		Invalidate(false);
	}
	cur_tool=MOVE_TOOL;
	
}

void CDijshowView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
//	IsMove=false;
	moveNode=NULL;
	CView::OnLButtonUp(nFlags, point);
}

void CDijshowView::OnFileSave() 
{
	CFileDialog dlg(false);
	if(dlg.DoModal()==IDCANCEL)
		return;
	
	fstream file;

    file.open(dlg.GetPathName(),ios::out);
	file<<nodenum<<" ";
	file<<currentnum<<" ";
	file<<sequencenum<<" \n";
//	file<<NodeList.GetCount()<<"\n";
	POSITION pos = NodeList.GetHeadPosition();
	for (int i=0;i < NodeList.GetCount();i++)
	{	
		CNodeObject * node=NodeList.GetNext(pos);
		file<<node->centre.x<<" ";
		file<<node->centre.y<<" ";
		file<<node->sernum<<" ";
	}

	file<<PathList.GetCount()<<"\n";
	pos =PathList.GetHeadPosition();
	for ( i=0;i < PathList.GetCount();i++)
	{	
		CPathObject * path=PathList.GetNext(pos);
		file<<path->headnode->sernum<<" ";
		file<<path->endnode->sernum<<" ";
		file<<path->weight<<" ";
	
	}
	file.close();

	
}

void CDijshowView::OnFileOpen() 
{
	CFileDialog dlg(true);
	if(dlg.DoModal()==IDCANCEL)
		return;
	fstream file;
	file.open(dlg.GetPathName(),ios::in);
	NodeList.RemoveAll();
	PathList.RemoveAll();
//	IsMove=true;
//	IsDrawPath=false;
	currentpath=NULL;
	moveNode=NULL;
	cur_tool=NODE_TOOL;
	
	
	file>>nodenum;
	file>>currentnum;
	file>>sequencenum;
	for(int i=0;i<currentnum;i++){
		CNodeObject *node=new CNodeObject();
		file>>node->centre.x;
		file>>node->centre.y;
		file>>node->sernum;
		node->rect.SetRect(node->centre.x-radius,node->centre.y-radius,
			node->centre.x+radius,node->centre.y+radius);
		NodeList.AddTail(node);
	}
	int pathnum,head,end;
	file>>pathnum;
	for(i=0;i<pathnum;i++){
		CPathObject *path=new CPathObject();
		file>>head;
		file>>end;
		file>>path->weight;
		POSITION pos = NodeList.GetHeadPosition();
		for (int j=0;j < NodeList.GetCount();j++)
		{	
			CNodeObject * node=NodeList.GetNext(pos);
			if(node->sernum==head)
				path->headnode=node;
			if(node->sernum==end)
				path->endnode=node;
		
			
		}
		PathList.AddTail(path);
	}

	Invalidate(false);
}
		

void CDijshowView::OnExstep() 
{
	if(stepnum==nodenum-1){
		MessageBox("已达到最大步数");
		return;
	}
	if(stepnum==0){
		POSITION pos =PathList.GetHeadPosition();
		for (int i=0;i < PathList.GetCount();i++)
		{	
			CPathObject * path=PathList.GetNext(pos);
			path->IsSelected=false;
		
		}
	}
	POSITION pos =PathList.GetHeadPosition();
	for (int i=0;i < PathList.GetCount();i++)
	{	
		CPathObject * path=PathList.GetNext(pos);
		if(path->headnode->sernum==shortestpath->choosepath[stepnum][0]
				&&path->endnode->sernum==shortestpath->choosepath[stepnum][1])
			path->IsSelected=true;
	
	}
	Invalidate();
	stepnum++;

}

void CDijshowView::OnUpdateBeginsearch(CCmdUI* pCmdUI) 
{
	if(PathList.GetCount()>0)
		pCmdUI->Enable(true);
	else
		pCmdUI->Enable(false);
	
	
}

void CDijshowView::OnUpdateExstep(CCmdUI* pCmdUI) 
{
	if(stepnum<0||stepnum==nodenum-1)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
	
	
}

void CDijshowView::OnUpdateMovenode(CCmdUI* pCmdUI) 
{
	if(cur_tool==EXECUTE_TOOL)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
	if(cur_tool==MOVE_TOOL)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);

//		this->GetParent()->SetWindowText(TITLE+title);
	
}

void CDijshowView::OnUpdatePathtool(CCmdUI* pCmdUI) 
{
	if(cur_tool==EXECUTE_TOOL)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
	if(cur_tool==PATH_TOOL)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
	
}

void CDijshowView::OnNodetool() 
{
	if(currentpath!=NULL&&cur_tool==PATH_TOOL){
		PathList.RemoveTail();
		currentpath=NULL;
		Invalidate(false);
	}
	cur_tool=NODE_TOOL;
}

void CDijshowView::OnUpdateNodetool(CCmdUI* pCmdUI) 
{
	if(cur_tool==EXECUTE_TOOL)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
	if(cur_tool==NODE_TOOL)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
	
}

void CDijshowView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	if(currentpath==NULL)
		return;
	if(cur_tool!=PATH_TOOL)
		return;
	PathList.RemoveTail();
	currentpath=NULL;
	Invalidate(false);

	CView::OnRButtonDown(nFlags, point);
}




