// MFCMazeDoc.cpp : CMFCMazeDoc 类的实现
//

#include "stdafx.h"
#include "MFCMaze.h"

#include "MFCMazeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMazeDoc

IMPLEMENT_DYNCREATE(CMFCMazeDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCMazeDoc, CDocument)
END_MESSAGE_MAP()


// CMFCMazeDoc 构造/析构

CMFCMazeDoc::CMFCMazeDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMFCMazeDoc::~CMFCMazeDoc()
{
}

BOOL CMFCMazeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFCMazeDoc 序列化

void CMFCMazeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CMFCMazeDoc 诊断

#ifdef _DEBUG
void CMFCMazeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCMazeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCMazeDoc 命令
