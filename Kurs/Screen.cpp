// Screen.cpp : implementation file
//

#include "stdafx.h"
#include "Kurs.h"
#include "KursDlg.h"
#include "Screen.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScreen

CScreen::CScreen()
{
	//m_bmp_scr.LoadBmpToMemory("d:\\4.jpg");
	m_bmp_scr.LoadBmpFromFile("3.bmp");
	
}

CScreen::~CScreen()
{
}


BEGIN_MESSAGE_MAP(CScreen, CStatic)
	//{{AFX_MSG_MAP(CScreen)
	ON_WM_PAINT()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void CScreen::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	//CClientDC dc(this);
	CString str;
//	float fVolt1,fVolt2;
	// TODO: Add your message handler code here
	//m_bmp_scr.DrawBmpFromMemory(&dc, 0, 0, 1, 1);
	m_bmp_scr.DrawBmpFromLoadedFile(&dc, 0, 0, 1, 1);
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(255,0,255));
	if(*m_pTime < 0.0006)
		str.Format("%.1f us",*m_pTime * 1000);
	else
		if(*m_pTime < 0.09)
			str.Format("%.0f us",*m_pTime * 1000);
		else 
			if(*m_pTime < 0.6f)
				str.Format("%.1f ms",*m_pTime);
			else
				str.Format("%.0f ms",*m_pTime);
	dc.TextOut(270,35,str);

	dc.SetTextColor(RGB(255,255,0));
	if(*m_pVolt1 < 0.09f)
		str.Format("%.0f mV",*m_pVolt1 * 1000);
	else 
		if(*m_pVolt1 < 0.6f)
			str.Format("%.1f V",*m_pVolt1);
		else
			str.Format("%.0f V",*m_pVolt1);	
	dc.TextOut(60,35,str);

	dc.SetTextColor(RGB(0,255,0));
	if(*m_pVolt2 < 0.09f)
		str.Format("%.0f mV",*m_pVolt2 * 1000);
	else 
		if(*m_pVolt2 < 0.6f)
			str.Format("%.1f V",*m_pVolt2);
		else
			str.Format("%.0f V",*m_pVolt2);
	dc.TextOut(120,35,str);
	// Do not call CStatic::OnPaint() for painting messages
}

int CScreen::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_pTime = &static_cast<CKursDlg*>(GetParent())->m_time.m_time_value;
	m_pVolt1 = &static_cast<CKursDlg*>(GetParent())->m_volts.m_volts1_value;
	m_pVolt2 = &static_cast<CKursDlg*>(GetParent())->m_volts.m_volts2_value;

	return 0;
}
