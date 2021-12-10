
// MFCScanPortDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCScanPort.h"
#include "MFCScanPortDlg.h"
#include "afxdialogex.h"
#include "CClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Диалоговое окно CMFCScanPortDlg



CMFCScanPortDlg::CMFCScanPortDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSCANPORT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCScanPortDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, PortsList);
}

BEGIN_MESSAGE_MAP(CMFCScanPortDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCScanPortDlg::OnEnChangeEdit1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCScanPortDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCScanPortDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCScanPortDlg

BOOL CMFCScanPortDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCScanPortDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCScanPortDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCScanPortDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCScanPortDlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CAboutDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений

}


void CMFCScanPortDlg::OnLbnSelchangeList1()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCScanPortDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	CClientSocket* pSocket;  // VAR pSocket типа CClientSocket для TCP/IP
	CString ip;
	CString messtr;
	int port;

	pSocket = new CClientSocket(); // Выделяем память и создаем объект
	pSocket->Create();
	GetDlgItemText(IDC_EDIT1, ip); // Узнаем IP юзера в поле ввода через ф-ю: ID компонента и VAR в которую пишет result
	port = 1; // Начал. значение отсчет для скана
	while (port < 100)
	{
		if (pSocket->Connect(ip, port)) // Try connect server; если удачно то результат не 0
		{
			messtr.Format(L"Port=%d opened", port);
			PortsList.AddString(messtr); // Заносим VAR в список 
			pSocket->Close(); // Закрываем и снова открываем чтобы пройтись дальше по списку, либо в противном случае только первый порт узнаем
			pSocket->Create();
		}
		port++;
	}
}
