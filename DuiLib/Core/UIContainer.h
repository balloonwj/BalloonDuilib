#ifndef __UICONTAINER_H__
#define __UICONTAINER_H__

#pragma once

namespace DuiLib {
/////////////////////////////////////////////////////////////////////////////////////
//

class IContainerUI
{
public:
    virtual CControlUI* GetItemAt(int iIndex) const = 0;
    virtual int GetItemIndex(CControlUI* pControl) const  = 0;
    virtual bool SetItemIndex(CControlUI* pControl, int iNewIndex) = 0;
    virtual bool SetMultiItemIndex(CControlUI* pStartControl, int iCount, int iNewStartIndex) = 0;
    virtual int GetCount() const = 0;
    virtual bool Add(CControlUI* pControl) = 0;
    virtual bool AddAt(CControlUI* pControl, int iIndex)  = 0;
    virtual bool Remove(CControlUI* pControl, bool bDoNotDestroy=false) = 0;
    virtual bool RemoveAt(int iIndex, bool bDoNotDestroy=false)  = 0;
    virtual void RemoveAll() = 0;
};


/////////////////////////////////////////////////////////////////////////////////////
//
class CScrollBarUI;
/*
    Container布局是其他所有布局以及含有容器特性（如CList、CListContainerElement）的控件的基类，
    而实际上开发过程中很少使用这个布局，只用他来做其他更高级的布局的基类。
    因为Container布局中的所有控件都会自动填充满整个布局，
    所有的控件都叠到了一起。而这个效果一般不是我们想要的。
    我目前想得到的他的唯一用途就是用于绝对布局，而且里面的所有元素都使用绝对布局。
*/
class DUILIB_API CContainerUI : public CControlUI, public IContainerUI
{
public:
    CContainerUI();
    virtual ~CContainerUI();

public:
    LPCTSTR GetClass() const;
    LPVOID GetInterface(LPCTSTR pstrName);

    CControlUI* GetItemAt(int iIndex) const;
    int GetItemIndex(CControlUI* pControl) const;
    bool SetItemIndex(CControlUI* pControl, int iNewIndex);
    bool SetMultiItemIndex(CControlUI* pStartControl, int iCount, int iNewStartIndex);
    int GetCount() const;
    bool Add(CControlUI* pControl);
    bool AddAt(CControlUI* pControl, int iIndex);
    bool Remove(CControlUI* pControl, bool bDoNotDestroy=false);
    bool RemoveAt(int iIndex, bool bDoNotDestroy=false);
    void RemoveAll();

    void DoEvent(TEventUI& event);
    void SetVisible(bool bVisible = true);
    void SetInternVisible(bool bVisible = true);
    void SetMouseEnabled(bool bEnable = true);

    virtual RECT GetInset() const;
    virtual void SetInset(RECT rcInset); // 设置内边距，相当于设置客户区
    virtual int GetChildPadding() const;
    virtual void SetChildPadding(int iPadding);
	virtual UINT GetChildAlign() const;
	virtual void SetChildAlign(UINT iAlign);
	virtual UINT GetChildVAlign() const;
	virtual void SetChildVAlign(UINT iVAlign);
    virtual bool IsAutoDestroy() const;
    virtual void SetAutoDestroy(bool bAuto);
    virtual bool IsDelayedDestroy() const;
    virtual void SetDelayedDestroy(bool bDelayed);
    virtual bool IsMouseChildEnabled() const;
    virtual void SetMouseChildEnabled(bool bEnable = true);

    virtual int FindSelectable(int iIndex, bool bForward = true) const;

	RECT GetClientPos() const;
	void SetPos(RECT rc, bool bNeedInvalidate = true);
	void Move(SIZE szOffset, bool bNeedInvalidate = true);
    //实际画法方法
    bool DoPaint(HDC hDC, const RECT& rcPaint, CControlUI* pStopControl);
    
    /** 支持的属性
     *  inset   内嵌距离 left,top,right,bottom 容器的内边距,如(2,2,2,2)
     *  mousechild bool 子对象是否响应鼠标事件
     *  vscrollbar bool 是否启用垂直滚动条
     *  vscrollbarstyle 垂直滚动条样式 ??
     *  hscrollbar  是否启用水平滚动条
     *  hscrollbarstyle 水平关东条样式 ??
     *  childpadding    子控件之间的额外距离,如(4)
     *  childalign 子对象水平对齐方式 left/center/right
     *  childvalign 子对象垂直对齐方式 top/vcenter/bottom
     **/
    void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

    void SetManager(CPaintManagerUI* pManager, CControlUI* pParent, bool bInit = true);
    CControlUI* FindControl(FINDCONTROLPROC Proc, LPVOID pData, UINT uFlags);

	bool SetSubControlText(LPCTSTR pstrSubControlName,LPCTSTR pstrText);
	bool SetSubControlFixedHeight(LPCTSTR pstrSubControlName,int cy);
	bool SetSubControlFixedWdith(LPCTSTR pstrSubControlName,int cx);
	bool SetSubControlUserData(LPCTSTR pstrSubControlName,LPCTSTR pstrText);

	CDuiString GetSubControlText(LPCTSTR pstrSubControlName);
	int GetSubControlFixedHeight(LPCTSTR pstrSubControlName);
	int GetSubControlFixedWdith(LPCTSTR pstrSubControlName);
	const CDuiString GetSubControlUserData(LPCTSTR pstrSubControlName);
	CControlUI* FindSubControl(LPCTSTR pstrSubControlName);

    virtual SIZE GetScrollPos() const;
    virtual SIZE GetScrollRange() const;
    virtual void SetScrollPos(SIZE szPos);
    virtual void LineUp();
    virtual void LineDown();
    virtual void PageUp();
    virtual void PageDown();
    virtual void HomeUp();
    virtual void EndDown();
    virtual void LineLeft();
    virtual void LineRight();
    virtual void PageLeft();
    virtual void PageRight();
    virtual void HomeLeft();
    virtual void EndRight();
    virtual void EnableScrollBar(bool bEnableVertical = true, bool bEnableHorizontal = false);
    virtual CScrollBarUI* GetVerticalScrollBar() const;
    virtual CScrollBarUI* GetHorizontalScrollBar() const;

protected:
    virtual void SetFloatPos(int iIndex);
    virtual void ProcessScrollBar(RECT rc, int cxRequired, int cyRequired);

protected:
    CDuiPtrArray  m_items;
    RECT          m_rcInset;                //对应内嵌属性inset:左，上，右，下
    int           m_iChildPadding;
	UINT          m_iChildAlign;
	UINT          m_iChildVAlign;
    bool          m_bAutoDestroy;
    bool          m_bDelayedDestroy;
    bool          m_bMouseChildEnabled;
    bool          m_bScrollProcess; // 防止SetPos循环调用

    CScrollBarUI* m_pVerticalScrollBar;
    CScrollBarUI* m_pHorizontalScrollBar;
};

} // namespace DuiLib

#endif // __UICONTAINER_H__
