#pragma once

class CDialogBuilderCallbackEx :
	public IDialogBuilderCallback
{
public:
	CDialogBuilderCallbackEx(CPaintManagerUI* ppm = NULL);
	~CDialogBuilderCallbackEx(void);

	virtual CControlUI* CreateControl(LPCTSTR pstrClass); 

private:
	// 加一个PAINTMANAGER是为了加载　Default 项
	CPaintManagerUI* m_pm;
};

