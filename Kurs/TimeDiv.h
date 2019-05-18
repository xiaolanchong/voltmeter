#if !defined(AFX_TIMEDIV_H__9BE60CED_84AF_4173_A7E6_841D47AAD918__INCLUDED_)
#define AFX_TIMEDIV_H__9BE60CED_84AF_4173_A7E6_841D47AAD918__INCLUDED_

#include "Bmp.h"	// Added by ClassView
//#include <afxcoll.h>
#include <afxtempl.h>
#define TIME_NUM 19
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TimeDiv.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTimeDiv window

class CTimeDiv : public CStatic
{
// Construction
public:
	CTimeDiv();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeDiv)
	//}}AFX_VIRTUAL

// Implementation
public:
	float m_time_value;
	CPoint m_center;
	CArray<CPoint,CPoint> m_array_time;
	float m_array_time_symb[TIME_NUM];
	int m_time_pointer;
	CBmp m_bmp_time;
	virtual ~CTimeDiv();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTimeDiv)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

		//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMEDIV_H__9BE60CED_84AF_4173_A7E6_841D47AAD918__INCLUDED_)
