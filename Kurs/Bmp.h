// Bmp.h: interface for the CBmp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BMP_H__11A3403B_25C4_4463_9672_3F24D57E8357__INCLUDED_)
#define AFX_BMP_H__11A3403B_25C4_4463_9672_3F24D57E8357__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBmp : public CBitmap  
{
public:
	BOOL LoadBmpFromResource(UINT nIDResource );
	BOOL DrawBmpFromResource(CDC* dc, int x, int y, int xfactor, int yfactor);
	BOOL DrawBmpFromLoadedFile(CDC* dc, int x, int y, int xfactor, int yfactor);
	BOOL LoadBmpFromFile(char* FilePath);
	CBmp();
	BOOL LoadBmpToMemory(char* FilePath);
	BOOL DrawBmpFromMemory(CDC* dc, int x, int y, int xfactor, int yfactor);
	virtual ~CBmp();

private:
	BITMAPINFO m_info;
	BYTE* m_buffer;
	BITMAP m_bitm;
	

};

#endif // !defined(AFX_BMP_H__11A3403B_25C4_4463_9672_3F24D57E8357__INCLUDED_)
