
#include "stdafx.h"
#include "MyList.h"
#include "DialogBuilderCallbackEx.h"

CMyList::CMyList(CPaintManagerUI* ppm)
{
	Init(ppm);
}

CMyList::~CMyList(void)
{
}

void CMyList::Init(CPaintManagerUI* ppm)
{
	CDialogBuilder builder;
	CContainerUI* pList = static_cast<CContainerUI*>(builder.Create(_T("skin~/mylist.xml"), 0, NULL, ppm));
	if( pList != NULL ) {
		for(int i = 0; i < 100; ++i) 
		{
			if( pList == NULL ) pList = static_cast<CContainerUI*>(builder.Create());
			if( pList != NULL ) {
				this->Add(pList);
				TCHAR indexBuffer[16];
				CDuiString strIndexString = _T("- ");
				strIndexString += _itot(i+1, indexBuffer, 10);
				strIndexString += _T(" -");
				pList->GetItemAt(0)->SetText(strIndexString);

				CComboUI* pCombo = static_cast <CComboUI*> (pList->GetItemAt(1));
				if (pCombo != NULL) {
					for (int j = 0; j < 3; ++j) {
						CListLabelElementUI* pComboItem = new CListLabelElementUI;
						pComboItem->SetText(_T("xxx"));
						pCombo->Add(pComboItem);
					}
				}
				pList->GetItemAt(0)->OnEvent += MakeDelegate (this, &CMyList::OnTheEvent);
				pList->GetItemAt(1)->OnEvent += MakeDelegate (this, &CMyList::OnTheEvent);
				pList->GetItemAt(2)->OnEvent += MakeDelegate (this, &CMyList::OnTheEvent);
				pList->OnEvent += MakeDelegate (this, &CMyList::OnTheEvent);
				pList = NULL;
			}
			else {
				this->RemoveAll();
				return;
			}
		}
	}
}


bool CMyList::OnTheEvent (void* pParam)
{
	TEventUI* pEvent = (TEventUI*)pParam;
	CContainerUI* pContainer = NULL;

	if (pEvent->pSender == NULL) {
		return true;
	}


	if (_tcsicmp (pEvent->pSender->GetClass(), _T ("ContainerUI")) != 0) {
		pContainer = static_cast <CContainerUI*> (pEvent->pSender->GetParent());
	}
	else {
		pContainer = static_cast <CContainerUI*> (pEvent->pSender);
	}

	if (pContainer == NULL) {
		return true;
	}

	if (pEvent->Type == UIEVENT_MOUSEENTER) {
		if (pContainer->GetBkColor() != 0x1100FF00)
			pContainer->SetBkColor(0x1100FF00);
	}
	else if (pEvent->Type == UIEVENT_MOUSELEAVE) {
		if (pContainer->GetBkColor() != 0xFFFFFFFF)
			pContainer->SetBkColor(0xFFFFFFFF);
	}

	return true;
}