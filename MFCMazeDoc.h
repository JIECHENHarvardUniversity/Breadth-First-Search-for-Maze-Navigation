// MFCMazeDoc.h : CMFCMazeDoc ��Ľӿ�
//


#pragma once


class CMFCMazeDoc : public CDocument
{
protected: // �������л�����
	CMFCMazeDoc();
	DECLARE_DYNCREATE(CMFCMazeDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CMFCMazeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


