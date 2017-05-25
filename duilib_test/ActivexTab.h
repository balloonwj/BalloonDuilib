
#pragma once

class CActivexTab : public CContainerUI
{
public:
	CActivexTab (CPaintManagerUI* ppm)
	{
		CDialogBuilder builder;
		CContainerUI* pbtnTab = static_cast<CContainerUI*>(builder.Create(_T("Activex.xml"), 0, NULL, ppm));
		if( pbtnTab ) {
			this->Add(pbtnTab);
		}
		else {
			this->RemoveAll();
			return;
		}
	};
};