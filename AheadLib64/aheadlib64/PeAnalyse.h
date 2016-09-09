#pragma once
#include "stdafx.h"
#include <vector>

typedef struct tagFUNCINFO
{
	string strFuncName;
	DWORD dwFuncXuhao;
}*PFUNCINFO,FUNCINFO;




class PeAnalyse
{
public:
	PeAnalyse(string strPath);
	~PeAnalyse(void);


public:
	string strFilePath;
	HANDLE g_hFile;
	HANDLE g_hMapping;
	LPVOID g_ImageBase;
	vector<FUNCINFO> m_FuncArray;


	//用于将文件载入内存
	BOOL LoadPEFile();
	
	//枚举导出表函数
	BOOL ListExportFunc();
	DWORD RavToPtr(DWORD dwRva);
	BOOL WriteCppFile();
};
