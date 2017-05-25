#include "stdafx.h"
#include "ListTab.h"
#include "DialogBuilderCallbackEx.h"

CListTab::CListTab(CPaintManagerUI* ppm)
{
	CDialogBuilder builder;
	CDialogBuilderCallbackEx cb (ppm);
	CContainerUI* pbtnTab = static_cast<CContainerUI*>(builder.Create(_T("List.xml"), 0, &cb, ppm));
	if( pbtnTab ) {
		this->Add(pbtnTab);
	}
	else {
		this->RemoveAll();
		return;
	}
}

CListTab::~CListTab(void)
{
}
