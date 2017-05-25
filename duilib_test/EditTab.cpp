#include "stdafx.h"
#include "EditTab.h"

CEditTab::CEditTab( CPaintManagerUI* ppm /*= NULL*/ )
{
	CDialogBuilder builder;
	CContainerUI* pbtnTab = static_cast<CContainerUI*>(builder.Create(_T("Edit.xml"), 0, NULL, ppm));
	if( pbtnTab ) {
		this->Add(pbtnTab);
	}
	else {
		this->RemoveAll();
		return;
	}
}

CEditTab::~CEditTab(void)
{
}
