
#include "stdafx.h"
#include "ComboTab.h"

CComboTab::CComboTab(CPaintManagerUI* ppm)
{
	CDialogBuilder builder;
	CContainerUI* pbtnTab = static_cast<CContainerUI*>(builder.Create(_T("Combobox.xml"), 0, NULL, ppm));
	if( pbtnTab ) {
		this->Add(pbtnTab);
	}
	else {
		this->RemoveAll();
		return;
	}
}

CComboTab::~CComboTab(void)
{
}
