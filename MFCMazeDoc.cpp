// MFCMazeDoc.cpp : CMFCMazeDoc ���ʵ��
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


// CMFCMazeDoc ����/����

CMFCMazeDoc::CMFCMazeDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMFCMazeDoc::~CMFCMazeDoc()
{
}

BOOL CMFCMazeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMFCMazeDoc ���л�

void CMFCMazeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CMFCMazeDoc ���

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


// CMFCMazeDoc ����
