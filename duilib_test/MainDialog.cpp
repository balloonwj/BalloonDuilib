#include "StdAfx.h"
#include "MainDialog.h"
#include "MyList.h"
#include "TreeView.h"
#include <exdisp.h>
#include <comdef.h>


CMainDialog::CMainDialog(void)
{
}


CMainDialog::~CMainDialog(void)
{
}

void CMainDialog::OnClick( CControlUI* pSender)
{
	if (pSender->GetName() == TEXT ("btnExit")) {
		PostQuitMessage(0);
		return;
	}
	else if (pSender->GetName() == _T ("btnTip")) {
		CControlUI* pbtnTip = static_cast <CControlUI*> (m_pm.FindControl(_T ("btnTip")));
		if (pbtnTip) {
			pbtnTip->SetVisible(false);
		}

		CEditUI* peditSearch = static_cast <CEditUI*> (m_pm.FindControl(_T ("editSearch")));
		if (peditSearch != NULL) {
			peditSearch->SetFocus();
		}
	}

	else if (pSender->GetName() == _T ("lstDelButton")) {
		int iIndex = 0;
		CMyList* pParent = static_cast <CMyList*> (pSender->GetParent()->GetParent());
		if (pParent) {
			iIndex = pParent->GetItemIndex(pSender->GetParent());
		}
		CDuiString str;
		str.Format(_T ("您要删除 %d 项"), iIndex);
		if (IDNO == MessageBox (GetHWND (), str, NULL, MB_OK | MB_YESNO)) return;
		CMyList* pList = static_cast <CMyList*> (m_pm.FindControl(_T ("lstControl")));
		ASSERT(pList);
		if (pList) {
			pList->RemoveAt(iIndex);
			
			CControlUI* pItem = pList->GetItemAt(iIndex+5);
			if (pItem) {
				const RECT& rc = pItem->GetPos();
				SIZE sz = {0, rc.top};
				pList->SetScrollPos(sz);
			}
		}
	}
	else if (pSender->GetName() == _T ("btnAddComboItem")) {
		CComboUI* pcbx = static_cast <CComboUI*> (m_pm.FindControl(_T ("combo1")));
		assert (pcbx);
		if (pcbx) {
			CListLabelElementUI* pItem = new CListLabelElementUI ();
			pItem->SetText(_T ("{b}{i}新加项{/i}{/b}"));
			pcbx->Add(pItem);
		}

		AddComboboxItem();
		CComboUI* pcbx2 = static_cast <CComboUI*> (m_pm.FindControl(_T ("combo2")));
	}
	else if (pSender->GetName() == _T ("btnGoIe")) {
		CActiveXUI* pActiveXUI = static_cast<CActiveXUI*>(m_pm.FindControl(_T("ie")));
		if( pActiveXUI ) {
			IWebBrowser2* pWebBrowser = NULL;
			pActiveXUI->GetControl(IID_IWebBrowser2, (void**)&pWebBrowser);
			if( pWebBrowser != NULL ) {
				CEditUI* pEdit = static_cast <CEditUI*> (m_pm.FindControl(_T ("editIePath")));
				ASSERT (pEdit);
				CDuiString strIePath = _T ("www.baidu.com");
				if (pEdit) {
					strIePath = pEdit->GetText();
				}

				WCHAR szPath [1024] = {0};
#if defined(_UNICODE) || defined(UNICODE)
				lstrcpyW (szPath, strIePath);
#else
				::MultiByteToWideChar(CP_ACP, 0, strIePath, -1, szPath, 1023);
#endif
				pWebBrowser->Navigate(szPath,NULL,NULL,NULL,NULL);  
				pWebBrowser->Release();
			}
		}
	}
}

void CMainDialog::OnSelChanged( CControlUI* pSender )
{
	CTabLayoutUI* pTabTest = static_cast <CTabLayoutUI*>(m_pm.FindControl(_T ("tabTest")));
	if (pTabTest == NULL) {
		return;
	}

	CDuiString strSelName = pSender->GetName();
	if (strSelName == _T ("tabButton")) {
		pTabTest->SelectItem(0);
	}
	else if (strSelName == _T ("tabEdit")) {
		pTabTest->SelectItem(1);
	}
	else if (strSelName == _T ("tabTree")) {
		pTabTest->SelectItem(2);
	}
	else if (strSelName == _T ("tabList")) {
		pTabTest->SelectItem(3);
	}
	else if (strSelName == _T ("tabMenu")) {
		pTabTest->SelectItem(4);
	}
	else if (strSelName == _T ("tabActivex")) {
		pTabTest->SelectItem(5);
	}
	else if (strSelName == _T ("tabCombobox")) {
		pTabTest->SelectItem(6);
	}
}

void CMainDialog::OnKillFocus( CControlUI* pSender )
{
	if (pSender->GetName() == _T ("editSearch")) {
		CControlUI* pbtnTip = static_cast <CControlUI*> (m_pm.FindControl(_T ("btnTip")));
		CEditUI* peditSearch = static_cast <CEditUI*> (m_pm.FindControl(_T ("editSearch")));

		if (pbtnTip && peditSearch) {
			CDuiString strText = peditSearch->GetText();
			if (strText.IsEmpty()) {
				strText = "請輸入查找條件";
				pbtnTip->SetAttribute(_T("textcolor"), _T("#00A0A0A4"));
			} else {
				pbtnTip->SetAttribute(_T("textcolor"), _T("#FF000000"));
			}
			
			pbtnTip->SetText(strText);
			pbtnTip->SetVisible(true);
		}
	}
}

void CMainDialog::OnInit()
{
	CListUI* pList = static_cast <CListUI*> (m_pm.FindControl(_T ("lstNormal")));
	ASSERT(pList);
	if (pList) {
		pList->SetTextCallback(this);
		for (int i = 0; i < 100; ++i) {
			CListTextElementUI* pItem = new CListTextElementUI;
			m_arstrListString0 [i].Format(_T ("{i list_png.png}{/i}{x 4}%d"), i);
			m_arstrListString1 [i].Format(_T ("%d - 1"), i);
			m_arstrListString2 [i].Format(_T ("%d - 2"), i);
			pList->Add(pItem);
		}
	}

	AddComboboxItem ();
	AddTreeItem ();
}

LPCTSTR CMainDialog::GetItemText( CControlUI* pList, int iItem, int iSubItem )
{
	if (iSubItem == 0) {
		return m_arstrListString0 [iItem];
	}
	else if (iSubItem == 1) {
		return m_arstrListString1 [iItem];
	}
	else if (iSubItem == 2) {
		return m_arstrListString2 [iItem];
	}

	return _T ("");
}

void CMainDialog::OnNotify( TNotifyUI& msg )
{
	if (msg.sType == _T ("itemactivate")) {
		if (_tcsicmp (msg.pSender->GetClass(), _T("ListUI")) == 0) {
			CListUI* pList = static_cast <CListUI*> (m_pm.FindControl(_T ("lstNormal")));
			ASSERT(pList);
			if (pList) {
				CDuiString str;
				str.Format(_T ("双击或回车了 %d 项"), pList->GetCurSel());
				MessageBox (GetHWND(), str, NULL, MB_OK);
			}
		} else if (msg.pSender && msg.pSender->GetParent () && msg.pSender->GetParent ()->GetParent () &&
			_tcsicmp (msg.pSender->GetParent ()->GetParent ()->GetClass(), _T("Tree")) == 0)
		{
			CDuiTreeView* pTree1 = static_cast<CDuiTreeView*>(m_pm.FindControl(_T("Tree1")));
			if( pTree1 != NULL && pTree1->GetItemIndex(msg.pSender) != -1 )
			{
				if( _tcscmp(msg.pSender->GetClass(), _T("ListLabelElementUI")) == 0 ) {
					CDuiTreeView::Node* node = (CDuiTreeView::Node*)msg.pSender->GetTag();
					pTree1->SetChildVisible(node, !node->data()._child_visible);
				}
			}
		}
	}

	if( msg.sType == _T("itemclick") ) {
		if (msg.pSender && msg.pSender->GetParent () && msg.pSender->GetParent ()->GetParent () &&
			_tcsicmp (msg.pSender->GetParent ()->GetParent ()->GetClass(), _T("Tree")) == 0)
		{
			CDuiTreeView* pTree1 = static_cast<CDuiTreeView*>(m_pm.FindControl(_T("Tree1")));
			if( pTree1 && pTree1->GetItemIndex(msg.pSender) != -1 )
			{
				if( _tcscmp(msg.pSender->GetClass(), _T("ListLabelElementUI")) == 0 ) {
					CDuiTreeView::Node* node = (CDuiTreeView::Node*)msg.pSender->GetTag();

					POINT pt = { 0 };
					::GetCursorPos(&pt);
					::ScreenToClient(m_pm.GetPaintWindow(), &pt);
					pt.x -= msg.pSender->GetX();
					SIZE sz = pTree1->GetExpanderSizeX(node);
					if( pt.x >= sz.cx && pt.x < sz.cy )                     
						pTree1->SetChildVisible(node, !node->data()._child_visible);
				}
			}
		}
	}

	if (_tcsicmp (msg.pSender->GetClass(), _T ("ListHeaderItemUI")) == 0 && msg.sType == _T ("headerclick")) {
		CListUI* pList = static_cast <CListUI*> (m_pm.FindControl(_T ("lstNormal")));
		ASSERT(pList);
		if (pList) {
			CListHeaderUI* pHeader = pList->GetHeader();
			ASSERT(pHeader);
			if (pHeader) {
				for (int i = 0; i < pHeader->GetCount(); ++i) {
					CControlUI* pItem = pHeader->GetItemAt (i);
					ASSERT(pItem);
					if (pItem) {
						if (PtInRect (&pItem->GetPos(), msg.ptMouse)) {
							CDuiString str;
							str.Format(_T ("单击了头 %d 项"), i);
							MessageBox (GetHWND(), str, NULL, MB_OK);
						}
					}
				}
			}
		}
	}

	CDuiDialog::OnNotify(msg);
}

void CMainDialog::AddComboboxItem()
{
	CComboUI* pcbx2 = static_cast <CComboUI*> (m_pm.FindControl(_T("combo2")));
	assert (pcbx2);
	if (pcbx2) {
		CDialogBuilder builder;
		CContainerUI* pItem = static_cast <CContainerUI*> (builder.Create(_T("comboitem.xml"), 0));
		pItem->GetItemAt(0)->SetBkImage(_T ("icon_home.png"));
		if (pcbx2->GetCount() % 2 == 0) {
			pItem->GetItemAt(1)->SetText(_T ("百度一下，你就知道了"));
			pItem->GetItemAt(2)->SetText(_T ("http://www.baidu.com"));
		}
		else {
			pItem->GetItemAt(1)->SetText(_T ("360搜索 - 干净、安全、可信任的搜索引擎"));
			pItem->GetItemAt(2)->SetText(_T ("http://www.so.com/"));
		}

		pItem->SetTag(pcbx2->GetCount());
		pItem->OnEvent += MakeDelegate (this, &CMainDialog::OnClickItem);
		pcbx2->Add(pItem);
	}
}

bool CMainDialog::OnClickItem (void* pParam)
{
	TEventUI* pEvent = (TEventUI*)pParam;
	if (pEvent->Type == UIEVENT_BUTTONDOWN) {
		CComboUI* pcbx = static_cast <CComboUI*> (m_pm.FindControl(_T ("combo2")));
		CEditUI* pedit = static_cast <CEditUI*> (m_pm.FindControl(_T ("ComboEdit")));
		assert (pedit);
		CContainerUI*  pItem = static_cast <CContainerUI*> (pcbx->GetItemAt (pEvent->pSender->GetTag()));
		pedit->SetText(pItem->GetItemAt(2)->GetText());
	}
	else if (pEvent->Type == UIEVENT_MOUSEENTER) {
		pEvent->pSender->SetBkColor(0xFF00FF00);
	}
	else if (pEvent->Type == UIEVENT_MOUSELEAVE) {
		pEvent->pSender->SetBkColor(0xFFFFFFFF);
	}
	return true;
}

void CMainDialog::AddTreeItem()
{
	CDuiTreeView* pTree1 = static_cast<CDuiTreeView*>(m_pm.FindControl(_T("Tree1")));
	if (pTree1) {
		pTree1->SetDepth(4);
		pTree1->SetExpandImage(_T ("tree_expand.png"));
		CDuiTreeView::Node* pCategoryNode = NULL;
		CDuiTreeView::Node* pGameNode = NULL;
		CDuiTreeView::Node* pServerNode = NULL;
		CDuiTreeView::Node* pRoomNode = NULL;
		pCategoryNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 3}{x 4}推荐游戏"));
		for( int i = 0; i < 4; ++i )
		{
			pGameNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 10}{x 4}四人斗地主"), pCategoryNode);
			for( int i = 0; i < 3; ++i )
			{
				pServerNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 10}{x 4}测试服务器"), pGameNode);
				for( int i = 0; i < 3; ++i )
				{
					pRoomNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 10}{x 4}测试房间"), pServerNode);
				}
			}
		}
		pCategoryNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 3}{x 4}最近玩过的游戏"));
		for( int i = 0; i < 2; ++i )
		{
			pTree1->AddNode(_T("三缺一"), pCategoryNode);
		}
		pCategoryNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 3}{x 4}棋牌游戏"));
		for( int i = 0; i < 8; ++i )
		{
			pTree1->AddNode(_T("双扣"), pCategoryNode);
		}
		pCategoryNode = pTree1->AddNode(_T("{x 4}{i gameicons.png 18 3}{x 4}休闲游戏"));
		for( int i = 0; i < 8; ++i )
		{
			pTree1->AddNode(_T("飞行棋"), pCategoryNode);
		}
	}
}
