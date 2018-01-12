// MFCMazeView.cpp : CMFCMazeView 类的实现
//

#include "stdafx.h"
#include "MFCMaze.h"

#include "MFCMazeDoc.h"
#include "MFCMazeView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMazeView

IMPLEMENT_DYNCREATE(CMFCMazeView, CView)

BEGIN_MESSAGE_MAP(CMFCMazeView, CView)
	ON_COMMAND(ID_INITMAP, &CMFCMazeView::OnInitmap)
	ON_COMMAND(ID_FINDWAY, &CMFCMazeView::OnFindway)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CMFCMazeView 构造/析构

CMFCMazeView::CMFCMazeView()
{
	_grid = new Grid(CMainFrame::GRID_HEIGHT,CMainFrame::GRID_WIDTH);
	_grid->InitGrid();

	_height = CMainFrame::HEIGHT;
	_width =  CMainFrame::WIDTH;
	_hStep = _height/_grid->Width();
	_wStep = _width/_grid->Height();

	_isDrawWay = false;

	_way = new CBrush(RGB(0,200,0));
	_canPass = new CBrush(RGB(200,200,200));
	_barrer = new CBrush(RGB(0,0,0));

}

CMFCMazeView::~CMFCMazeView()
{
}

BOOL CMFCMazeView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

// CMFCMazeView 绘制

void CMFCMazeView::OnDraw(CDC* pDC)
{
	CMFCMazeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int i=0;i<_grid->Height();i++)
		for (int j=0;j<_grid->Width();j++)
			DrawBlock(i,j,pDC,_grid->Get(i,j));
}


// CMFCMazeView 诊断

#ifdef _DEBUG
void CMFCMazeView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMazeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMazeDoc* CMFCMazeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMazeDoc)));
	return (CMFCMazeDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMazeView 消息处理程序

void CMFCMazeView::OnInitmap()
{
	_isDrawWay = false;
	_grid->InitGrid();
	Invalidate();
}

void CMFCMazeView::OnFindway()
{
   CString msg;

	_isDrawWay = true;

	int times =  _grid->InitMap();
	bool isOk = _grid->FindWay();

	if (isOk)
		msg.Format(L"寻路成功！\n迭代次数：%d",times);
	else
       msg.Format(L"寻路失败！\n迭代次数：%d",times);

	MessageBox(msg);

	Invalidate();
}

void CMFCMazeView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	_width = cx;
	_height = cy;
	_hStep = cy/_grid->Height();
	_wStep = cx/_grid->Width();
}

void CMFCMazeView::DrawBlock( int i,int j,CDC* pDC,Block *block )
{
	if (_isDrawWay)
		if(block->CanPass())
			if(block->IsWay())
				pDC->SelectObject(_way);
			else
				pDC->SelectObject(_canPass);
		else
			pDC->SelectObject(_barrer);
	else
		if (block->CanPass())
			pDC->SelectObject(_canPass);
		else
			pDC->SelectObject(_barrer);

	pDC->Rectangle(j*_wStep+1,i*_hStep+1,(j+1)*_wStep-1,(i+1)*_hStep-1);

	if (block->CanPass()&&block->CanReach())
	{
		CString num;
		num.Format(L"%d",block->JumpCount());
		pDC->TextOut(j*_wStep+_wStep/2-6,i*_hStep+_hStep/2-8,num);
	}
}

