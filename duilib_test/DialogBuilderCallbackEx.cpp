#include "StdAfx.h"
#include "DialogBuilderCallbackEx.h"
#include "ButtonTab.h"
#include "EditTab.h"
#include "ListTab.h"
#include "MyList.h"
#include "ComboTab.h"
#include "UserDefinedComboItem.h"
#include "TreeTab.h"
#include "TreeView.h"
#include "ActivexTab.h"


CDialogBuilderCallbackEx::CDialogBuilderCallbackEx(CPaintManagerUI* ppm)
{
	m_pm = ppm;
}


CDialogBuilderCallbackEx::~CDialogBuilderCallbackEx(void)
{
}

CControlUI* CDialogBuilderCallbackEx::CreateControl( LPCTSTR pstrClass )
{
	if (_tcsicmp (pstrClass, _T ("tabButton")) == 0) {
		return new CButtonTab (m_pm);
	}
	else if (_tcsicmp (pstrClass, _T ("tabEdit")) == 0) {
		return new CEditTab (m_pm);
	}
	else if (_tcsicmp (pstrClass, _T ("tabList")) == 0) {
		return new CListTab (m_pm);
	}
	else if (_tcsicmp (pstrClass, _T ("MyList")) == 0) {
		return new CMyList (m_pm);
	}
	else if (_tcsicmp (pstrClass, _T ("tabCombo")) == 0) {
		return new CComboTab (m_pm);
	}
	else if (_tcsicmp (pstrClass, _T ("tabTree")) == 0) {
		return new CTreeTab (m_pm);
	}
	else if (_tcsicmp (pstrClass, _T ("Tree")) == 0) {
		return new CDuiTreeView;
	}
	else if (_tcsicmp (pstrClass, _T ("tabActivex")) == 0) {
		return new CActivexTab (m_pm);
	}

	return NULL;
}
