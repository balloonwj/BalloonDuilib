#pragma once

class CMyList :
	public CTileLayoutUI
{
public:
	CMyList(CPaintManagerUI* ppm = NULL);
	void Init (CPaintManagerUI* ppm = NULL);
	~CMyList(void);
	bool OnTheEvent (void* pParam);
};
