#if !defined(AFX_VOLTS_H__6955AAB7_D2F1_41B0_8BB6_A880D167C40F__INCLUDED_)
#define AFX_VOLTS_H__6955AAB7_D2F1_41B0_8BB6_A880D167C40F__INCLUDED_

#include "Bmp.h"	// Added by ClassView
#include <afxtempl.h>
#define VOLTS_NUM 9
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Volts.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVolts window

class CVolts : public CStatic
{
// Construction
public:
	CVolts();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVolts)
	//}}AFX_VIRTUAL

// Implementation
public:
	CPoint m_center1, m_center2;
	float m_array_volts1_symb[VOLTS_NUM], m_array_volts2_symb[VOLTS_NUM];
	CArray<CPoint,CPoint> m_array1_volts, m_array2_volts;
	int m_volts1_pointer, m_volts2_pointer;
	float m_volts1_value;
	float m_volts2_value;
	CBmp m_bmp_volts;
	virtual ~CVolts();

	// Generated message map functions
protected:
	//{{AFX_MSG(CVolts)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VOLTS_H__6955AAB7_D2F1_41B0_8BB6_A880D167C40F__INCLUDED_)
