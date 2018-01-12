// MFCMazeView.h : CMFCMazeView 类的接口
//


#pragma once
#include <afxwin.h>
#include "Grid.h"


class CMFCMazeView : public CView
{
protected: // 仅从序列化创建
	CMFCMazeView();
	DECLARE_DYNCREATE(CMFCMazeView)

// 属性
public:
	CMFCMazeDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCMazeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

private:
   void DrawBlock(int i,int j,CDC* pDC,Block *block);

// 生成的消息映射函数
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

	CBrush *_canPass;//(RGB(255,255,255));//白色可通过区域
	CBrush *_barrer;//(RGB(0,0,0));//黑色为障碍
	CBrush *_way;//(RGB(0,255,0));//绿色为道路

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // MFCMazeView.cpp 中的调试版本
inline CMFCMazeDoc* CMFCMazeView::GetDocument() const
   { return reinterpret_cast<CMFCMazeDoc*>(m_pDocument); }
#endif

