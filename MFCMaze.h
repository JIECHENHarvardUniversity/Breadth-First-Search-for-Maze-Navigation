// MFCMaze.h : MFCMaze Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCMazeApp:
// �йش����ʵ�֣������ MFCMaze.cpp
//

class CMFCMazeApp : public CWinApp
{
public:
	CMFCMazeApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCMazeApp theApp;