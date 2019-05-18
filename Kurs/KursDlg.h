// KursDlg.h : header file
//

#if !defined(AFX_KURSDLG_H__F67BF825_5D7F_444A_BA1B_B7C146BB9273__INCLUDED_)
#define AFX_KURSDLG_H__F67BF825_5D7F_444A_BA1B_B7C146BB9273__INCLUDED_

#include "Volts.h"	// Added by ClassView
#include "Screen.h"	// Added by ClassView
#include "TimeDiv.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CKursDlg dialog

class CKursDlg : public CDialog
{
// Construction
public:
	CTimeDiv m_time;
	CVolts m_volts;
	CScreen m_scr;
	
	CKursDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CKursDlg)
	enum { IDD = IDD_KURS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKursDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKursDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KURSDLG_H__F67BF825_5D7F_444A_BA1B_B7C146BB9273__INCLUDED_)
