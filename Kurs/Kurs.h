// Kurs.h : main header file for the KURS application
//

#if !defined(AFX_KURS_H__0D5C4BA7_9F1C_4E03_A17B_ED7F0305626E__INCLUDED_)
#define AFX_KURS_H__0D5C4BA7_9F1C_4E03_A17B_ED7F0305626E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKursApp:
// See Kurs.cpp for the implementation of this class
//

class CKursApp : public CWinApp
{
public:
	CKursApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKursApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CKursApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KURS_H__0D5C4BA7_9F1C_4E03_A17B_ED7F0305626E__INCLUDED_)
