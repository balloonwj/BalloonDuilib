#ifndef __UIHORIZONTALLAYOUT_H__
#define __UIHORIZONTALLAYOUT_H__

#pragma once

namespace DuiLib
{
	class DUILIB_API CHorizontalLayoutUI : public CContainerUI
	{
	public:
		CHorizontalLayoutUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);
		UINT GetControlFlags() const;

		void SetSepWidth(int iWidth);
		int GetSepWidth() const;
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
		int     m_iSepWidth;        //对应属性sepwidth
		UINT    m_uButtonState;
		POINT   m_ptLastMouse;
		RECT    m_rcNewPos;
		bool    m_bImmMode;         //对应属性sepimm
	};
}
#endif // __UIHORIZONTALLAYOUT_H__
