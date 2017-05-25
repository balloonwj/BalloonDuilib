#ifndef __UIMARKUP_H__
#define __UIMARKUP_H__

#pragma once

namespace DuiLib {

enum
{
    XMLFILE_ENCODING_UTF8 = 0,
    XMLFILE_ENCODING_UNICODE = 1,
    XMLFILE_ENCODING_ASNI = 2,
};

class CMarkup;
class CMarkupNode;


class DUILIB_API CMarkup
{
    friend class CMarkupNode;
public:
    CMarkup(LPCTSTR pstrXML = NULL);
    ~CMarkup();

    bool Load(LPCTSTR pstrXML);
    bool LoadFromMem(BYTE* pByte, DWORD dwSize, int encoding = XMLFILE_ENCODING_UTF8);
    bool LoadFromFile(LPCTSTR pstrFilename, int encoding = XMLFILE_ENCODING_UTF8);
    void Release();
    bool IsValid() const;

    void SetPreserveWhitespace(bool bPreserve = true);
    void GetLastErrorMessage(LPTSTR pstrMessage, SIZE_T cchMax) const;
    void GetLastErrorLocation(LPTSTR pstrSource, SIZE_T cchMax) const;

    CMarkupNode GetRoot();

private:
    typedef struct tagXMLELEMENT
    {
        ULONG iStart;               //xml元素标签字符串相对于m_pstrXML在内存中的偏移值
        ULONG iChild;               //xml元素子元素的个数
        ULONG iNext;
        ULONG iParent;
        ULONG iData;                //当前标签最后一个属性结束位置相对于m_pstrXML在内存中的偏移值
    } XMLELEMENT;

    LPTSTR      m_pstrXML;              //指向内存中的xml布局文件，以0结束（堆内存）
    XMLELEMENT* m_pElements;            //最多500个元素？
    ULONG       m_nElements;
    ULONG       m_nReservedElements;
    TCHAR       m_szErrorMsg[100];
    TCHAR       m_szErrorXML[50];
    bool m_bPreserveWhitespace;

private:
    bool _Parse();
    bool _Parse(LPTSTR& pstrText, ULONG iParent);
    XMLELEMENT* _ReserveElement();                      //预分配500个节点元素
    inline void _SkipWhitespace(LPTSTR& pstr) const;
    inline void _SkipWhitespace(LPCTSTR& pstr) const;
    inline void _SkipIdentifier(LPTSTR& pstr) const;
    inline void _SkipIdentifier(LPCTSTR& pstr) const;
    bool _ParseData(LPTSTR& pstrText, LPTSTR& pstrData, char cEnd);
    void _ParseMetaChar(LPTSTR& pstrText, LPTSTR& pstrDest);
    bool _ParseAttributes(LPTSTR& pstrText);
    bool _Failed(LPCTSTR pstrError, LPCTSTR pstrLocation = NULL);
};


class DUILIB_API CMarkupNode
{
    friend class CMarkup;
private:
    CMarkupNode();
    CMarkupNode(CMarkup* pOwner, int iPos);

public:
    bool IsValid() const;

    CMarkupNode GetParent();
    CMarkupNode GetSibling();
    CMarkupNode GetChild();
    CMarkupNode GetChild(LPCTSTR pstrName);

    bool HasSiblings() const;
    bool HasChildren() const;
    LPCTSTR GetName() const;
    LPCTSTR GetValue() const;

    bool HasAttributes();
    bool HasAttribute(LPCTSTR pstrName);
    int GetAttributeCount();
    LPCTSTR GetAttributeName(int iIndex);
    LPCTSTR GetAttributeValue(int iIndex);
    LPCTSTR GetAttributeValue(LPCTSTR pstrName);
    bool GetAttributeValue(int iIndex, LPTSTR pstrValue, SIZE_T cchMax);
    bool GetAttributeValue(LPCTSTR pstrName, LPTSTR pstrValue, SIZE_T cchMax);

private:
    void _MapAttributes();

    enum { MAX_XML_ATTRIBUTES = 64 };

    typedef struct
    {
        ULONG iName;            //当前标签属性名相对于m_pstrXML在内存中的偏移值
        ULONG iValue;           //当前标签属性值相对于m_pstrXML在内存中的偏移值
    } XMLATTRIBUTE;

    int                 m_iPos;                             //该元素在CMarkup::m_pElements数组中的索引
    int                 m_nAttributes;
    XMLATTRIBUTE        m_aAttributes[MAX_XML_ATTRIBUTES];  //标签的所有属性，最多支持64个
    CMarkup*            m_pOwner;
};

} // namespace DuiLib

#endif // __UIMARKUP_H__
