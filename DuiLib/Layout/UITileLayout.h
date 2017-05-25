#ifndef __UITILELAYOUT_H__
#define __UITILELAYOUT_H__

#pragma once

namespace DuiLib
{
	class DUILIB_API CTileLayoutUI : public CContainerUI
	{
	public:
		CTileLayoutUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		void SetPos(RECT rc, bool bNeedInvalidate = true);

		int GetFixedColumns() const;
		void SetFixedColumns(int iColums);
		int GetChildVPadding() const;
		void SetChildVPadding(int iPadding);

		SIZE GetItemSize() const;
		void SetItemSize(SIZE szSize);
		int GetColumns() const;
		int GetRows() const;
        /** 支持的属性
         *  itemsize 每一个格子的长和宽 int  cx,cy
         *  columns 格子的列数 int
         *  childvpadding 格子的垂直间隙
         **/
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

	protected:
		SIZE m_szItem;
		int m_nColumns;
		int m_nRows;

		int m_nColumnsFixed;
		int m_iChildVPadding;
		bool m_bIgnoreItemPadding;
	};
}
#endif // __UITILELAYOUT_H__
