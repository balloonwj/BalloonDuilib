#ifndef __UIVERTICALLAYOUT_H__
#define __UIVERTICALLAYOUT_H__

#pragma once

namespace DuiLib
{
	class DUILIB_API CVerticalLayoutUI : public CContainerUI
	{
	public:
		CVerticalLayoutUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);
		UINT GetControlFlags() const;

		void SetSepHeight(int iHeight);
		int GetSepHeight() const;
		void SetSepImmMode(bool bImmediately);
		bool IsSepImmMode() const;
        /** 支持的属性
         *  sepheight   int 分隔符高度 正值表示分隔符在顶部，负值表示分隔符在底部
         *  sepimm      bool 拖动分隔符是否立即改变大小
         **/
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
		void DoEvent(TEventUI& event);

		void SetPos(RECT rc, bool bNeedInvalidate = true);
		void DoPostPaint(HDC hDC, const RECT& rcPaint);

		RECT GetThumbRect(bool bUseNew = false) const;

	protected:
		int     m_iSepHeight;
		UINT    m_uButtonState;
		POINT   m_ptLastMouse;
		RECT    m_rcNewPos;
		bool    m_bImmMode;
	};
}
#endif // __UIVERTICALLAYOUT_H__
