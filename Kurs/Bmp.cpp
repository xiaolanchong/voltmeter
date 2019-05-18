// Bmp.cpp: implementation of the CBmp class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Bmp.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBmp::CBmp()
{
	
}

CBmp::~CBmp()
{
//	delete [] m_buffer;
}

BOOL CBmp::LoadBmpToMemory(char* FilePath)
{
	//Load BMP from file to memory

	CFileException m_e;
	CFile m_file;
	BITMAPFILEHEADER m_header;

	if(!m_file.Open(FilePath, CFile::modeRead, &m_e))
	{
		AfxMessageBox("Ошибка открытия файла !");
		return FALSE;
	};
	
	m_file.Read(&m_header, sizeof(BITMAPFILEHEADER));
	m_file.Read(&m_info, sizeof(BITMAPINFO));
	m_buffer = new BYTE[m_file.GetLength() - m_header.bfOffBits];
	m_file.Seek(m_header.bfOffBits, CFile::begin);
	m_file.Read(m_buffer, m_file.GetLength() - m_header.bfOffBits);
	m_file.Close();
	return TRUE;


}

BOOL CBmp::DrawBmpFromMemory(CDC* dc, int x, int y, int xfactor, int yfactor)
{
		if(StretchDIBits(dc->GetSafeHdc(), x, y, m_info.bmiHeader.biWidth/xfactor, m_info.bmiHeader.biHeight/yfactor, 0, 0, m_info.bmiHeader.biWidth, m_info.bmiHeader.biHeight, m_buffer, &m_info, DIB_PAL_COLORS, SRCCOPY) == GDI_ERROR) 
		return FALSE;
		else return TRUE;
		
}

BOOL CBmp::LoadBmpFromFile(char* FilePath)
{
	// TODO: load from app resources
	const CString pathToRes = "res//";
	CString filePathWithDir = pathToRes + FilePath;
	HBITMAP m_hBMP;
	m_hBMP = (HBITMAP)LoadImage(NULL, filePathWithDir, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION );
	if (m_hBMP == NULL)
	{
		::AfxMessageBox(CString(FilePath) + " not found");
		return FALSE;
	}
	Detach();
	Attach(m_hBMP);
	return TRUE;
}

BOOL CBmp::DrawBmpFromLoadedFile(CDC *dc, int x, int y, int xfactor, int yfactor)
{	
	CDC m_MemDC;
	m_MemDC.CreateCompatibleDC (dc);
	m_MemDC.SelectObject(this);
	GetObject(sizeof(BITMAP), &m_bitm);
	if(dc->StretchBlt(x, y, m_bitm.bmWidth/xfactor, m_bitm.bmHeight/yfactor, &m_MemDC, 0, 0 , m_bitm.bmWidth, m_bitm.bmHeight , SRCCOPY) == 0)
	{
		m_MemDC.DeleteDC();
		return FALSE;
	}
	else 
	{
		m_MemDC.DeleteDC();
		return TRUE;
	};

}

BOOL CBmp::DrawBmpFromResource(CDC* dc, int x, int y, int xfactor, int yfactor)
{
	CDC m_MemDC;
	m_MemDC.CreateCompatibleDC (dc);
	m_MemDC.SelectObject(this);
	GetObject(sizeof(BITMAP), &m_bitm);
	if(dc->StretchBlt(x, y, m_bitm.bmWidth/xfactor, m_bitm.bmHeight/yfactor, &m_MemDC, 0, 0 , m_bitm.bmWidth, m_bitm.bmHeight , SRCCOPY) == 0)
	return FALSE;
	else return TRUE;
}

BOOL CBmp::LoadBmpFromResource(UINT nIDResource )
{	
	Detach();
	if(LoadBitmap(nIDResource ) == 0)
		return FALSE;
		else return TRUE;
}
