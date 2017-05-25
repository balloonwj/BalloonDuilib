#ifndef __UIBUTTON_H__
#define __UIBUTTON_H__

#pragma once

namespace DuiLib
{
	//对应<Button>标签
    class DUILIB_API CButtonUI : public CLabelUI
	{
	public:
		CButtonUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);
		UINT GetControlFlags() const;

		bool Activate();
		void SetEnabled(bool bEnable = true);
		void DoEvent(TEventUI& event);

		LPCTSTR GetNormalImage();
		void SetNormalImage(LPCTSTR pStrImage);
		LPCTSTR GetHotImage();
		void SetHotImage(LPCTSTR pStrImage);
		LPCTSTR GetPushedImage();
		void SetPushedImage(LPCTSTR pStrImage);
		LPCTSTR GetFocusedImage();
		void SetFocusedImage(LPCTSTR pStrImage);
		LPCTSTR GetDisabledImage();
		void SetDisabledImage(LPCTSTR pStrImage);
		LPCTSTR GetForeImage();
		void SetForeImage(LPCTSTR pStrImage);
		LPCTSTR GetHotForeImage();
		void SetHotForeImage(LPCTSTR pStrImage);

		// 对应按钮的5个状态图
		void SetFiveStatusImage(LPCTSTR pStrImage);
		void SetFadeAlphaDelta(BYTE uDelta);
		BYTE GetFadeAlphaDelta();

		void SetHotBkColor(DWORD dwColor);
		DWORD GetHotBkColor() const;
		void SetHotTextColor(DWORD dwColor);
		DWORD GetHotTextColor() const;
		void SetPushedTextColor(DWORD dwColor);
		DWORD GetPushedTextColor() const;
		void SetFocusedTextColor(DWORD dwColor);
		DWORD GetFocusedTextColor() const;
		SIZE EstimateSize(SIZE szAvailable);

        /** 支持的属性
         *  normalimage string
         *  hotimage string
         *  pushedimage string
         *  focusedimage string
         *  disabledimage string
         *  foreimage string    前景图片
         *  hotforeimage    string
         *  fivestatusimage string ??
         *  fadedelta int
         *  hotbkcolor int 十六进制 0xAARRGGBB/#AARRGGBB
         *  hottextcolor int 十六进制 0xAARRGGBB/#AARRGGBB
         *  pushedtextcolor int 十六进制 0xAARRGGBB/#AARRGGBB
         *  focusedtextcolor int 十六进制 0xAARRGGBB/#AARRGGBB   
         **/
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

		void PaintText(HDC hDC);
		void PaintStatusImage(HDC hDC);

	protected:
		enum
		{ 
			FADE_TIMERID = 11,
			FADE_ELLAPSE = 30,
		};

		UINT m_uButtonState;

		DWORD m_dwHotBkColor;
		DWORD m_dwHotTextColor;
		DWORD m_dwPushedTextColor;
		DWORD m_dwFocusedTextColor;
		BYTE m_uFadeAlpha;
		BYTE m_uFadeAlphaDelta;

		TDrawInfo m_diNormal;
		TDrawInfo m_diHot;
		TDrawInfo m_diHotFore;
		TDrawInfo m_diPushed;
		TDrawInfo m_diPushedFore;
		TDrawInfo m_diFocused;
		TDrawInfo m_diDisabled;
	};

}	// namespace DuiLib

#endif // __UIBUTTON_H__