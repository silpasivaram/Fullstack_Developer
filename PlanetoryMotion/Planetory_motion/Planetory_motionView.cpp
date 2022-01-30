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

// Planetory_motionView.cpp : implementation of the CPlanetorymotionView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Planetory_motion.h"
#endif

#include "Planetory_motionDoc.h"
#include "Planetory_motionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPlanetorymotionView

IMPLEMENT_DYNCREATE(CPlanetorymotionView, CView)

BEGIN_MESSAGE_MAP(CPlanetorymotionView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPlanetorymotionView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_BUTTONstart, &CPlanetorymotionView::OnButtonstart)
	ON_COMMAND(ID_BUTTONsuspend, &CPlanetorymotionView::OnButtonsuspend)
	ON_COMMAND(ID_BUTTONresume, &CPlanetorymotionView::OnButtonresume)
END_MESSAGE_MAP()

// CPlanetorymotionView construction/destruction

CPlanetorymotionView::CPlanetorymotionView() noexcept
{
	// TODO: add construction code here
	m_pCurrentThread=NULL;

	x1 = 275 + 225 * cos(0);
	y1 = 275 + 225 * sin(0);
	x2 = 275 + 125 * cos(3.14);
	y2 = 275 + 125 * sin(3.14);
	/*x1 = 500; y1 = 250; 
	x2=400, y2 = 250;*/
}

CPlanetorymotionView::~CPlanetorymotionView()
{
}

BOOL CPlanetorymotionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPlanetorymotionView drawing

void CPlanetorymotionView::OnDraw(CDC* pDC)
{
	CPlanetorymotionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPen greenPen,bluePen;
	bluePen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	CPen* OldPen = pDC->SelectObject(&bluePen);
	pDC-> Ellipse(50,50,500,500);//orbit2

	greenPen.CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	pDC->SelectObject(&greenPen);
    pDC->Ellipse(150, 150, 400, 400);//orbit1
	pDC->SelectObject(OldPen);

	CBrush brushRed, brushYellow, brushCyan;

	brushRed.CreateSolidBrush(RGB(255, 0, 0));
	CBrush* OldBrush = pDC->SelectObject(&brushRed);
	pDC->Ellipse(250, 250, 300, 300);

	//bluePen.CreatePen(PS_SOLID, 2, RGB(0,0,255));
	//pDC->SelectObject(&bluePen);
	//pDC->Ellipse(250, 250, 300,300);//sun

	brushYellow.CreateSolidBrush(RGB(255, 255, 0));
	pDC->SelectObject(&brushYellow);

	pDC->Ellipse(x1 - 15, y1 - 15, x1 + 15, y1 + 15);//planet2

	brushCyan.CreateSolidBrush(RGB(0, 255, 255));
	pDC->SelectObject(&brushCyan);

	pDC->Ellipse(x2 - 15, y2 - 15, x2 + 15, y2 + 15);//planet1

	pDC->SelectObject(OldBrush);

	// TODO: add draw code for native data here
}


// CPlanetorymotionView printing


void CPlanetorymotionView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPlanetorymotionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPlanetorymotionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPlanetorymotionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPlanetorymotionView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPlanetorymotionView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPlanetorymotionView diagnostics

#ifdef _DEBUG
void CPlanetorymotionView::AssertValid() const
{
	CView::AssertValid();
}

void CPlanetorymotionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlanetorymotionDoc* CPlanetorymotionView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlanetorymotionDoc)));
	return (CPlanetorymotionDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlanetorymotionView message handlers


void CPlanetorymotionView::OnButtonstart()
{
	m_pCurrentThread=AfxBeginThread(start_thread, this);

	// TODO: Add your command handler code here
}


void CPlanetorymotionView::OnButtonsuspend()
{
	m_pCurrentThread->SuspendThread();
	
	// TODO: Add your command handler code here
}


void CPlanetorymotionView::OnButtonresume()
{

	m_pCurrentThread-> ResumeThread();
	// TODO: Add your command handler code here
}


unsigned int CPlanetorymotionView::start_thread(LPVOID param)
{
	CPlanetorymotionView* pview = (CPlanetorymotionView*)param;
	int i=0;
	while (true)
	{
		
		pview->x1 = 275 + 225 * cos(i/57.3);
		pview->y1 = 275 + 225 * sin(i/57.3);

		pview->x2 = 275 - 125 * cos((i)/57.3);
		pview->y2 = 275 - 125 * sin((i)/57.3);

		pview->Invalidate();

		i = i +5;

		Sleep(1000);
	}

	// TODO: Add your implementation code here.
	return 0;
}
