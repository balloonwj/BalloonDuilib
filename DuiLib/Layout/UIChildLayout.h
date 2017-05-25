#ifndef __UICHILDLAYOUT_H__
#define __UICHILDLAYOUT_H__

#pragma once

namespace DuiLib
{
	class DUILIB_API CChildLayoutUI : public CContainerUI
	{
	public:
		CChildLayoutUI();

		void Init();
        /** 支持的属性
         * xmlfile 子布局的xml文件路径 string
         **/
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
		void SetChildLayoutXML(CDuiString pXML);
		CDuiString GetChildLayoutXML();
		virtual LPVOID GetInterface(LPCTSTR pstrName);
		virtual LPCTSTR GetClass() const;

	private:
		CDuiString m_pstrXMLFile;
	};
} // namespace DuiLib
#endif // __UICHILDLAYOUT_H__
