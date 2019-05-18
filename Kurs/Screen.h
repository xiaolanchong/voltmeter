#if !defined(AFX_SCREEN_H__A553C9D7_16AB_4323_B65B_96EF4B6F91E2__INCLUDED_)
#define AFX_SCREEN_H__A553C9D7_16AB_4323_B65B_96EF4B6F91E2__INCLUDED_

#include "Bmp.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Screen.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScreen window

class CScreen : public CStatic
{
// Construction
public:
	CScreen();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScreen)
	//}}AFX_VIRTUAL

// Implementation
public:
	float* m_pVolt2;
	float* m_pVolt1;
	float* m_pTime;
	CBmp m_bmp_scr;
	virtual ~CScreen();

	// Generated message map functions
protected:
	//{{AFX_MSG(CScreen)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCREEN_H__A553C9D7_16AB_4323_B65B_96EF4B6F91E2__INCLUDED_)
