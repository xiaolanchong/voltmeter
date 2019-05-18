// gen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define PI			3.1459
#define STEP		0.01
#define STARTPOINT	0
#define ENDPOINT	4*PI

double Func(double fArg)
{
	return sin(fArg);
}

int main(int argc, char* argv[])
{
	DWORD dwWritten;
	LPSTR lpszName = "func.txt";
	TCHAR lpszBuf[255];
	LPSTR lpszFile = new TCHAR[4*50*1000] ;
	lpszFile[0] = _T('\0');
//	float fBuf[]
	HANDLE hFile = CreateFile(lpszName,GENERIC_WRITE,FILE_SHARE_READ,NULL,
				CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	if(hFile == INVALID_HANDLE_VALUE)
	{
		printf("Can't create file \n");
		return 0;
	};
	for(double i = STARTPOINT;i < ENDPOINT;i += STEP)
	{
		sprintf(lpszBuf,"%.2f = %.2f \r\n",i,Func(i));
		lstrcat(lpszFile,lpszBuf);
	}
	if(!WriteFile(hFile,lpszFile,lstrlen(lpszFile)+1,&dwWritten,NULL))
		printf("Can't write");
	printf("Done \n");
	delete[] lpszFile;
	return 0;
}
