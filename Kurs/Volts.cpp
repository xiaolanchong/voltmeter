// Volts.cpp : implementation file
//

#include "stdafx.h"
#include "Kurs.h"
#include "Volts.h"
#include "KursDlg.h"
#define VOLTS_NUM 9

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVolts

CVolts::CVolts() : m_center1(80, 84)// , m_center2(288.84)
{
	m_center2 = CPoint(288,84);
	m_bmp_volts.LoadBmpFromFile("2.bmp");
	m_volts1_pointer = 0;
	m_volts2_pointer = 0;


		m_array_volts1_symb[0] = 5;
		m_array_volts1_symb[1] = 2;
		m_array_volts1_symb[2] = 1;
		m_array_volts1_symb[3] = 0.5f;
		m_array_volts1_symb[4] = 0.2f;
		m_array_volts1_symb[5] = 0.1f;
		m_array_volts1_symb[6] = 0.05f;
		m_array_volts1_symb[7] = 0.02f;
		m_array_volts1_symb[8] = 0.01f;

		m_volts1_value = m_array_volts1_symb[0];
		

		for(int i=0; i<VOLTS_NUM;i++)
			m_array_volts2_symb[i] = m_array_volts1_symb[i];

		m_volts2_value = m_array_volts2_symb[0];


	m_array1_volts.Add(CPoint(22, 118));
	m_array1_volts.Add(CPoint(14, 82));
	m_array1_volts.Add(CPoint(22, 49));
	m_array1_volts.Add(CPoint(40, 23));
	m_array1_volts.Add(CPoint(80, 15));
	m_array1_volts.Add(CPoint(116, 23));
	m_array1_volts.Add(CPoint(145, 48));
	m_array1_volts.Add(CPoint(152, 82));
	m_array1_volts.Add(CPoint(144, 118));

	m_array2_volts.Add(CPoint(228, 118));
	m_array2_volts.Add(CPoint(221, 82));
	m_array2_volts.Add(CPoint(228, 49));
	m_array2_volts.Add(CPoint(250, 23));
	m_array2_volts.Add(CPoint(288, 15));
	m_array2_volts.Add(CPoint(322, 23));
	m_array2_volts.Add(CPoint(350, 48));
	m_array2_volts.Add(CPoint(358, 82));
	m_array2_volts.Add(CPoint(352, 118));
}

CVolts::~CVolts()
{
}


BEGIN_MESSAGE_MAP(CVolts, CStatic)
	//{{AFX_MSG_MAP(CVolts)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVolts message handlers

void CVolts::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CBrush brush;
	CPen pen;
	brush.CreateHatchBrush(HS_BDIAGONAL, RGB(255,255,0));
	pen.CreatePen(PS_SOLID, 4, RGB(255,100,100));
	dc.SelectObject(&pen);
	
	// TODO: Add your message handler code here
	m_bmp_volts.DrawBmpFromLoadedFile(&dc, 0, 0, 1, 1);
	dc.MoveTo(m_center1.x,m_center1.y);
	dc.MoveTo(m_center2.x,m_center2.y);

	dc.FrameRect(CRect(m_array1_volts.GetAt(m_volts1_pointer).x - 10, m_array1_volts.GetAt(m_volts1_pointer).y - 8, m_array1_volts.GetAt(m_volts1_pointer).x + 10, m_array1_volts.GetAt(m_volts1_pointer).y +8), &brush);
	dc.MoveTo(m_center1.x-(m_center1.x-m_array1_volts.GetAt(m_volts1_pointer).x)/2.5,
				m_center1.y+(m_array1_volts.GetAt(m_volts1_pointer).y - m_center1.y)/2.5);
	dc.LineTo(m_center1.x-(m_center1.x-m_array1_volts.GetAt(m_volts1_pointer).x)/1.65,m_center1.y+(m_array1_volts.GetAt(m_volts1_pointer).y - m_center1.y)/1.65);

	dc.FrameRect(CRect(m_array2_volts.GetAt(m_volts2_pointer).x - 10, m_array1_volts.GetAt(m_volts2_pointer).y - 8, m_array2_volts.GetAt(m_volts2_pointer).x + 10, m_array2_volts.GetAt(m_volts2_pointer).y +8), &brush);
	dc.MoveTo(m_center2.x-(m_center2.x-m_array2_volts.GetAt(m_volts2_pointer).x)/2.5,m_center2.y+(m_array2_volts.GetAt(m_volts2_pointer).y - m_center2.y)/2.5);
	dc.LineTo(m_center2.x-(m_center2.x-m_array2_volts.GetAt(m_volts2_pointer).x)/1.65,m_center2.y+(m_array2_volts.GetAt(m_volts2_pointer).y - m_center2.y)/1.65);

	brush.DeleteObject();
	pen.DeleteObject();
	
	// Do not call CStatic::OnPaint() for painting messages
}

void CVolts::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CPaintDC dc(this);
	CRect rc(0,0,200,100);
	for(int i=0;i<VOLTS_NUM;i++){
	if(CRect(m_array1_volts.GetAt(i).x - 10, 
		m_array1_volts.GetAt(i).y - 8,
		m_array1_volts.GetAt(i).x + 10,
		m_array1_volts.GetAt(i).y +8).PtInRect(point))
	{
		m_volts1_pointer = i;
		m_volts1_value = m_array_volts1_symb[i];
		static_cast<CKursDlg*>(GetParent())->m_scr.InvalidateRect(&rc,FALSE);
	}

	if(CRect(m_array2_volts.GetAt(i).x - 10, 
		m_array2_volts.GetAt(i).y - 8, 
		m_array2_volts.GetAt(i).x + 10, 
		m_array2_volts.GetAt(i).y +8).PtInRect(point))
	{
		m_volts2_pointer = i;
		m_volts2_value = m_array_volts2_symb[i];
		static_cast<CKursDlg*>(GetParent())->m_scr.InvalidateRect(&rc,TRUE);
	}
	};
	Invalidate();
	
	CStatic::OnLButtonDown(nFlags, point);
}

