
#include "stdafx.h"
#include "TreeTab.h"
#include "DialogBuilderCallbackEx.h"

CTreeTab::CTreeTab(CPaintManagerUI* ppm)
{
	CDialogBuilder builder;
	CDialogBuilderCallbackEx cb (ppm);
	CContainerUI* pbtnTab = static_cast<CContainerUI*>(builder.Create(_T("tree.xml"), 0, &cb, ppm));
	if( pbtnTab ) {
		this->Add(pbtnTab);
	}
	else {
		this->RemoveAll();
		return;
	}
}

CTreeTab::~CTreeTab(void)
{
}
