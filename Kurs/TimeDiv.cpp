// TimeDiv.cpp : implementation file
//

#include "stdafx.h"
#include "Kurs.h"
#include "TimeDiv.h"
#include "KursDlg.h"
#define TIME_NUM 19

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimeDiv

CTimeDiv::CTimeDiv() : m_center(110, 133)
{
	m_bmp_time.LoadBmpFromFile("1.bmp");
	m_time_pointer = 0;
	

		m_array_time_symb[0] = 100;
		m_array_time_symb[1] = 50;
		m_array_time_symb[2] = 20;
		m_array_time_symb[3] = 10;
		m_array_time_symb[4] = 5;
		m_array_time_symb[5] = 2;
		m_array_time_symb[6] = 1;
		m_array_time_symb[7] = 0.5f;
		m_array_time_symb[8] = 0.2f;
		m_array_time_symb[9] = 0.1f;
		m_array_time_symb[10] = 0.05f;
		m_array_time_symb[11] = 0.02f;
		m_array_time_symb[12] = 0.01f;
		m_array_time_symb[13] = 0.005f;
		m_array_time_symb[14] = 0.002f;
		m_array_time_symb[15] = 0.001f;
		m_array_time_symb[16] = 0.0005f;
		m_array_time_symb[17] = 0.0002f;
		m_array_time_symb[18] = 0.0001f;
	
		m_time_value = m_array_time_symb[0];

		m_array_time.Add(CPoint(49, 190));
		m_array_time.Add(CPoint(40, 173));
		m_array_time.Add(CPoint(35, 152));
		m_array_time.Add(CPoint(31, 133));
		m_array_time.Add(CPoint(36, 113));
		m_array_time.Add(CPoint(41, 96));
		m_array_time.Add(CPoint(55, 80));
		m_array_time.Add(CPoint(71, 66));
		m_array_time.Add(CPoint(89, 58));
		m_array_time.Add(CPoint(108, 56));
		m_array_time.Add(CPoint(131, 59));
		m_array_time.Add(CPoint(152, 66));
		m_array_time.Add(CPoint(169, 80));
		m_array_time.Add(CPoint(180, 96));
		m_array_time.Add(CPoint(184, 112));
		m_array_time.Add(CPoint(188, 133));
		m_array_time.Add(CPoint(185, 153));
		m_array_time.Add(CPoint(179, 173));
		m_array_time.Add(CPoint(165, 190));
}

CTimeDiv::~CTimeDiv()
{
}


BEGIN_MESSAGE_MAP(CTimeDiv, CStatic)
	//{{AFX_MSG_MAP(CTimeDiv)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeDiv message handlers

void CTimeDiv::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CBrush brush;
	CPen pen;
	brush.CreateHatchBrush(HS_BDIAGONAL, RGB(255,255,0));
	pen.CreatePen(PS_SOLID, 4, RGB(255,100,100));
	dc.SelectObject(&pen);
	
	
	// TODO: Add your message handler code here
	m_bmp_time.DrawBmpFromLoadedFile(&dc, 0, 0, 1, 1);
	dc.MoveTo(m_center.x,m_center.y);

	dc.FrameRect(CRect(m_array_time.GetAt(m_time_pointer).x - 12, m_array_time.GetAt(m_time_pointer).y - 8, m_array_time.GetAt(m_time_pointer).x + 12, m_array_time.GetAt(m_time_pointer).y +8), &brush);
	dc.MoveTo(m_center.x-(m_center.x-m_array_time.GetAt(m_time_pointer).x)/2.5,m_center.y+(m_array_time.GetAt(m_time_pointer).y - m_center.y)/2.5);
	dc.LineTo(m_center.x-(m_center.x-m_array_time.GetAt(m_time_pointer).x)/1.65,m_center.y+(m_array_time.GetAt(m_time_pointer).y - m_center.y)/1.65);

	brush.DeleteObject();
	pen.DeleteObject();
	// Do not call CStatic::OnPaint() for painting messages
}

void CTimeDiv::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default 
	CPaintDC dc(this);
	CRect rc(150,30,350,80);
	for(int i=0;i<TIME_NUM;i++)
	if(CRect(m_array_time.GetAt(i).x - 12,
			m_array_time.GetAt(i).y - 8, 
			m_array_time.GetAt(i).x + 12, 
			m_array_time.GetAt(i).y +8).PtInRect(point))
	{
		m_time_pointer = i;
		m_time_value = m_array_time_symb[i];
		static_cast<CKursDlg*>(GetParent())->m_scr.InvalidateRect(&rc,TRUE);
	}
	Invalidate();
	
	CStatic::OnLButtonDown(nFlags, point);
}



