#ifndef __UIEDIT_H__
#define __UIEDIT_H__

#pragma once

namespace DuiLib
{
	class CEditWnd;

    //对应<Edit>标签
	class DUILIB_API CEditUI : public CLabelUI
	{
		friend class CEditWnd;
	public:
		CEditUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);
		UINT GetControlFlags() const;
		HWND GetNativeWindow() const;

		void SetEnabled(bool bEnable = true);
		void SetText(LPCTSTR pstrText);
		void SetMaxChar(UINT uMax);
		UINT GetMaxChar();
		void SetReadOnly(bool bReadOnly);
		bool IsReadOnly() const;
		void SetPasswordMode(bool bPasswordMode);
		bool IsPasswordMode() const;
		void SetPasswordChar(TCHAR cPasswordChar);
		TCHAR GetPasswordChar() const;
		bool IsAutoSelAll();
		void SetAutoSelAll(bool bAutoSelAll);
		void SetNumberOnly(bool bNumberOnly);
		bool IsNumberOnly() const;
		int GetWindowStyls() const;
		HWND GetNativeEditHWND() const;

		LPCTSTR GetNormalImage();
		void SetNormalImage(LPCTSTR pStrImage);
		LPCTSTR GetHotImage();
		void SetHotImage(LPCTSTR pStrImage);
		LPCTSTR GetFocusedImage();
		void SetFocusedImage(LPCTSTR pStrImage);
		LPCTSTR GetDisabledImage();
		void SetDisabledImage(LPCTSTR pStrImage);
		void SetNativeEditBkColor(DWORD dwBkColor);
		DWORD GetNativeEditBkColor() const;

		void SetSel(long nStartChar, long nEndChar);
		void SetSelAll();
		void SetReplaceSel(LPCTSTR lpszReplace);

		void SetPos(RECT rc, bool bNeedInvalidate = true);
		void Move(SIZE szOffset, bool bNeedInvalidate = true);
		void SetVisible(bool bVisible = true);
		void SetInternVisible(bool bVisible = true);
		SIZE EstimateSize(SIZE szAvailable);
		void DoEvent(TEventUI& event);
        /** 支持的属性
         *  readonly bool 是否只读
         *  numberonly bool 只能输入数值
         *  password bool 是否是密码框
         *  autoselall  bool 自动全选
         *  maxchar int 最大字符数目
         *  normalimage/hotimage/focusedimage/disabledimage string 相关状态的图片路径
         *  nativebkcolor int 背景颜色 十六进制0xAARRGGBB/0xAARRGGBB
         **/
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

		void PaintStatusImage(HDC hDC);
		void PaintText(HDC hDC);

	protected:
		CEditWnd* m_pWindow;

		UINT m_uMaxChar;
		bool m_bReadOnly;
		bool m_bPasswordMode;
		bool m_bAutoSelAll;
		TCHAR m_cPasswordChar;
		UINT m_uButtonState;
		DWORD m_dwEditbkColor;
		int m_iWindowStyls;

		TDrawInfo m_diNormal;
		TDrawInfo m_diHot;
		TDrawInfo m_diFocused;
		TDrawInfo m_diDisabled;
	};
}
#endif // __UIEDIT_H__