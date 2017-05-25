#ifndef __UIOPTION_H__
#define __UIOPTION_H__

#pragma once

namespace DuiLib
{
    //对应<Option>标签，单选按钮，同一组的单选按钮必须设置同一个group属性
	class DUILIB_API COptionUI : public CButtonUI
	{
	public:
		COptionUI();
		~COptionUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		void SetManager(CPaintManagerUI* pManager, CControlUI* pParent, bool bInit = true);

		bool Activate();
		void SetEnabled(bool bEnable = true);

		LPCTSTR GetSelectedImage();
		void SetSelectedImage(LPCTSTR pStrImage);

		LPCTSTR GetSelectedHotImage();
		void SetSelectedHotImage(LPCTSTR pStrImage);

		void SetSelectedTextColor(DWORD dwTextColor);
		DWORD GetSelectedTextColor();

		void SetSelectedBkColor(DWORD dwBkColor);
		DWORD GetSelectBkColor();

		LPCTSTR GetForeImage();
		void SetForeImage(LPCTSTR pStrImage);

		LPCTSTR GetGroup() const;
		void SetGroup(LPCTSTR pStrGroupName = NULL);
		bool IsSelected() const;
        /**
         *param bSelected 选中该单选框设置成true，反之设置为false
         **/
		virtual void Selected(bool bSelected, bool bTriggerEvent=true);

		SIZE EstimateSize(SIZE szAvailable);
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

		void PaintStatusImage(HDC hDC);
		void PaintText(HDC hDC);

	protected:
		bool			m_bSelected;
		CDuiString		m_sGroupName;               //单选框的组名

		DWORD			m_dwSelectedBkColor;
		DWORD			m_dwSelectedTextColor;

		TDrawInfo		m_diSelected;
		TDrawInfo		m_diSelectedHot;
		TDrawInfo		m_diFore;
	};

} // namespace DuiLib

#endif // __UIOPTION_H__