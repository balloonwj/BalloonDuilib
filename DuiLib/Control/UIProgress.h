#ifndef __UIPROGRESS_H__
#define __UIPROGRESS_H__

#pragma once

namespace DuiLib
{
	class DUILIB_API CProgressUI : public CLabelUI
	{
	public:
		CProgressUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		bool IsHorizontal();
		void SetHorizontal(bool bHorizontal = true);
		int GetMinValue() const;
		void SetMinValue(int nMin);
		int GetMaxValue() const;
		void SetMaxValue(int nMax);
		int GetValue() const;
		void SetValue(int nValue);
		LPCTSTR GetForeImage() const;
		void SetForeImage(LPCTSTR pStrImage);

        /** 支持的属性
         *  foreimage string 前景图片 
         *  hor bool 设置成true为水平进度条，为false为垂直进度条
         *  min int 最小值
         *  max int 最大值
         *  value int 当前值
         **/
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
		void PaintStatusImage(HDC hDC);

	protected:
		bool m_bHorizontal;
		int m_nMax;
		int m_nMin;
		int m_nValue;

		TDrawInfo m_diFore;
	};

} // namespace DuiLib

#endif // __UIPROGRESS_H__
