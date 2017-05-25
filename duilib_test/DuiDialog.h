// DuiDialog.h: interface for the CDuiDialog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DUIDIALOG_H__F0608F4A_CEA2_44BE_9F21_F5FAFD3B2454__INCLUDED_)
#define AFX_DUIDIALOG_H__F0608F4A_CEA2_44BE_9F21_F5FAFD3B2454__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDuiDialog  : public CWindowWnd, public INotifyUI
{
public:
	CDuiDialog();
	virtual ~CDuiDialog();

	HWND Create (LPCTSTR lpszUISkin, IDialogBuilderCallback* pCallback = NULL);
	
	virtual LPCTSTR GetWindowClassName() const { return _T("UIDialog"); };
    UINT GetClassStyle() const { return UI_CLASSSTYLE_DIALOG; };

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

    virtual void OnFinalMessage(HWND /*hWnd*/) { delete this; };
	virtual void OnInit ();
	virtual void OnNotify(TNotifyUI& msg);
	virtual void OnClick (CControlUI* pSender);
	virtual void OnSelChanged( CControlUI* pSender );
	virtual void OnKillFocus (CControlUI* pSender);

	virtual LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	
protected:
	void Notify(TNotifyUI& msg);
	
public:
    CPaintManagerUI m_pm;
	CDuiString		m_strUISkin;
	IDialogBuilderCallback* m_pCallback;
};

#endif // !defined(AFX_DUIDIALOG_H__F0608F4A_CEA2_44BE_9F21_F5FAFD3B2454__INCLUDED_)
