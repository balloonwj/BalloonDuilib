// duilib_test.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "duilib_test.h"
#include "MainDialog.h"
#include "DialogBuilderCallbackEx.h"

#include <atlbase.h>
CComModule _Module;
#include <atlwin.h>


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	CPaintManagerUI::SetInstance (hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin~"));

	HINSTANCE hInstRich = ::LoadLibrary(_T("Riched20.dll"));

	::CoInitialize(NULL);
	::OleInitialize(NULL);

	_Module.Init( 0, hInstance );


	CMainDialog * pdlg = new CMainDialog;
	CDialogBuilderCallbackEx cb (&pdlg->m_pm);
	pdlg->Create(TEXT ("main.xml"), &cb);
	pdlg->CenterWindow();
	pdlg->ShowModal();

	CPaintManagerUI::MessageLoop();
 	
	_Module.Term();

	::OleUninitialize();
	::CoUninitialize();

	::FreeLibrary(hInstRich);
	return 0;
}