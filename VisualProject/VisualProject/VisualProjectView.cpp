
// VisualProjectView.cpp : implementation of the CVisualProjectView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "VisualProject.h"
#endif

#include "VisualProjectDoc.h"
#include "VisualProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVisualProjectView

IMPLEMENT_DYNCREATE(CVisualProjectView, CView)

BEGIN_MESSAGE_MAP(CVisualProjectView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CVisualProjectView construction/destruction

CVisualProjectView::CVisualProjectView()
{
	// TODO: add construction code here

}

CVisualProjectView::~CVisualProjectView()
{
}

BOOL CVisualProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CVisualProjectView drawing

void CVisualProjectView::OnDraw(CDC* /*pDC*/)
{
	CVisualProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CVisualProjectView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CVisualProjectView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CVisualProjectView diagnostics

#ifdef _DEBUG
void CVisualProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CVisualProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVisualProjectDoc* CVisualProjectView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVisualProjectDoc)));
	return (CVisualProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CVisualProjectView message handlers
