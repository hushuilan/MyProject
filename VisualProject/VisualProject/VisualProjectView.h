
// VisualProjectView.h : interface of the CVisualProjectView class
//

#pragma once


class CVisualProjectView : public CView
{
protected: // create from serialization only
	CVisualProjectView();
	DECLARE_DYNCREATE(CVisualProjectView)

// Attributes
public:
	CVisualProjectDoc* GetDocument() const;
	
	// Operations
public:

	void DrawEllipse(int x, int y, int r);
	BOOL DrawFunc();
	// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CVisualProjectView();
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
};

#ifndef _DEBUG  // debug version in VisualProjectView.cpp
inline CVisualProjectDoc* CVisualProjectView::GetDocument() const
   { return reinterpret_cast<CVisualProjectDoc*>(m_pDocument); }
#endif

