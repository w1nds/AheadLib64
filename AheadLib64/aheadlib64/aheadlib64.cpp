// aheadlib64.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

#include "PeAnalyse.h"

void mytrim(string& str, char ch)
{
	string::size_type pos = str.find_first_not_of(ch);
	if (pos == string::npos)
	{
		str = "";
		return;
	}

	string::size_type pos2 = str.find_last_not_of(ch);
	if (pos2 != string::npos)
	{
		str = str.substr(pos, pos2 - pos + 1);
	}
	else
	{
		str = str.substr(pos);
	}
}

//http://ref.x86asm.net/coder.html x64指令
int _tmain(int argc, _TCHAR* argv[])
{
	string strDllPath;
	cout<<"dllpath:";
	getline(cin,strDllPath);
	mytrim(strDllPath,'"');

	
	cout<<"--Start analysis "<<strDllPath<<endl;
	
	PeAnalyse MyPe(strDllPath);

	do
	{
		if(!MyPe.LoadPEFile())
		{
			cout<<"--LoadPEFile failed!"<<endl;
			break;
		}
		if (!MyPe.ListExportFunc())
		{
			cout<<"--ListExportFunc failed!"<<endl;
			break;
		}
		if (!MyPe.WriteCppFile())
		{
			cout<<"--WriteCppFile failed!"<<endl;
			break;
		}	
	}while(0);
	
	system("pause");
	return 0;
}

