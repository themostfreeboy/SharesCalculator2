
// SharesCalculator.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSharesCalculatorApp:
// �йش����ʵ�֣������ SharesCalculator.cpp
//

class CSharesCalculatorApp : public CWinApp
{
public:
	CSharesCalculatorApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSharesCalculatorApp theApp;