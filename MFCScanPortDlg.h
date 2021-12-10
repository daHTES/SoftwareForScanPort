
// MFCScanPortDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCScanPortDlg
class CMFCScanPortDlg : public CDialogEx
{
// Создание
public:
	CMFCScanPortDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCSCANPORT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CListBox PortsList;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
};
