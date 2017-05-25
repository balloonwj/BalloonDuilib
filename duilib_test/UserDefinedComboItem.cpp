#include "stdafx.h"
#include "UserDefinedComboItem.h"

CUserDefinedComboItem::CUserDefinedComboItem(void)
{
	CDialogBuilder builder;
	CContainerUI* pbtnTab = static_cast<CContainerUI*>(builder.Create(_T("comboitem.xml"), 0));
	if( pbtnTab ) {
		this->Add(pbtnTab);
		int iWidth = pbtnTab->GetWidth();
		int iWidth2 = this->GetWidth();
		int iHeight = pbtnTab->GetHeight();

		int i = 2;
	}
	else {
		this->RemoveAll();
		return;
	}
}

CUserDefinedComboItem::~CUserDefinedComboItem(void)
{
}
