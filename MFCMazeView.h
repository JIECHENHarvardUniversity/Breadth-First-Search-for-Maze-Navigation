// MFCMazeView.h : CMFCMazeView ��Ľӿ�
//


#pragma once
#include <afxwin.h>
#include "Grid.h"


class CMFCMazeView : public CView
{
protected: // �������л�����
	CMFCMazeView();
	DECLARE_DYNCREATE(CMFCMazeView)

// ����
public:
	CMFCMazeDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCMazeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

private:
   void DrawBlock(int i,int j,CDC* pDC,Block *block);

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnInitmap();
	afx_msg void OnFindway();

private:
	int _width;
	int _height;

	int _wStep;
	int _hStep;

	Grid *_grid;

	bool _isDrawWay;

	CBrush *_canPass;//(RGB(255,255,255));//��ɫ��ͨ������
	CBrush *_barrer;//(RGB(0,0,0));//��ɫΪ�ϰ�
	CBrush *_way;//(RGB(0,255,0));//��ɫΪ��·

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // MFCMazeView.cpp �еĵ��԰汾
inline CMFCMazeDoc* CMFCMazeView::GetDocument() const
   { return reinterpret_cast<CMFCMazeDoc*>(m_pDocument); }
#endif

