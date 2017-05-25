#pragma once
#include "duidialog.h"
class CMainDialog :
	public CDuiDialog, public IListCallbackUI
{
public:
	CMainDialog(void);
	virtual ~CMainDialog(void);

	virtual void OnClick (CControlUI* pSender);
	virtual void OnSelChanged( CControlUI* pSender );
	virtual void OnKillFocus (CControlUI* pSender);
	virtual void OnInit();
	virtual void OnNotify(TNotifyUI& msg);

	virtual LPCTSTR GetItemText(CControlUI* pList, int iItem, int iSubItem);
	void AddComboboxItem();
	void AddTreeItem();
	bool OnClickItem (void* pParam);
private:
	CDuiString	m_arstrListString0[100];
	CDuiString	m_arstrListString1[100];
	CDuiString	m_arstrListString2[100];
};

