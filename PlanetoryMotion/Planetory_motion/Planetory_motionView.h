// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface
// (the "Fluent UI") and is provided only as referential material to supplement the
// Microsoft Foundation Classes Reference and related electronic documentation
// included with the MFC C++ library software.
// License terms to copy, use or distribute the Fluent UI are available separately.
// To learn more about our Fluent UI licensing program, please visit
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// Planetory_motionView.h : interface of the CPlanetorymotionView class
//

#pragma once


class CPlanetorymotionView : public CView
{
	CWinThread *m_pCurrentThread;
	int x1, y1,x2,y2;
protected: // create from serialization only
	CPlanetorymotionView() noexcept;
	DECLARE_DYNCREATE(CPlanetorymotionView)

// Attributes
public:
	CPlanetorymotionDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CPlanetorymotionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnButtonstart();
	afx_msg void OnButtonsuspend();
	afx_msg void OnButtonresume();
	static unsigned int start_thread(LPVOID param);
};

#ifndef _DEBUG  // debug version in Planetory_motionView.cpp
inline CPlanetorymotionDoc* CPlanetorymotionView::GetDocument() const
   { return reinterpret_cast<CPlanetorymotionDoc*>(m_pDocument); }
#endif

