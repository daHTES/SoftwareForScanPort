
// MFCScanPort.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCScanPortApp:
// Сведения о реализации этого класса: MFCScanPort.cpp
//

class CMFCScanPortApp : public CWinApp
{
public:
	CMFCScanPortApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCScanPortApp theApp;
