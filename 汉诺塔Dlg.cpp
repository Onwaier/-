// ��ŵ��Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "��ŵ��.h"
#include "��ŵ��Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
	, m_val(_T(""))
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	number = 0;
	pn = 0;
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_SPIN2, m_spin);
	DDX_Text(pDX, IDC_EDIT1, m_val);
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_NEXT_BUTTON, &CMyDlg::OnBnClickedNextButton)
	ON_BN_CLICKED(IDC_PREV_BUTTON, &CMyDlg::OnBnClickedPrevButton)
	ON_BN_CLICKED(IDC_PAUSE_BUTTON, &CMyDlg::OnBnClickedPauseButton)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, &CMyDlg::OnDeltaposSpin2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyDlg::OnBnClickedButton4)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	m_spin.SetRange32(2, 7);//��ʾ��ֵֻ����2��7�ڱ仯
	m_spin.SetBase(10);//���ý�����,ֻ����10���ƺ�16����
	m_val = "2";//��ʼ������2������
	SetDishNumber(2);
	last = 400;//��ʱ����ʼ��Ϊ400ms
	number = 2;//������Ŀ��ʼ��Ϊ2
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	if (IsIconic())
	{

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	// ��ʾ
	ShowBg(&dc);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnButton2() //�˳�
{
	// TODO: Add your control notification handler code here
	OnOK();
}



// ��a�������n�������ƶ���b��ʵ���ƶ������ӷ���0��ֻ�ǽ�ջ����1
int CMyDlg::MoveDish(int n, int a, int b) {

	if(1 == n){
		// �ƶ�����
		int i = 1;
		for(; i <= number ; i++){
			if(a == dish[number - i]){
				break;
			}
		}
		if(i > number){
			return 0;
		}
		dish[number - i] = b;
		res.push_back(Node{ number - i, a, b });
		++idx;
		return 0; // ���
	}
	else{
		// ��Ҫ���еĲ�����ջ
		opt[pn][0] = n-1;
		opt[pn][1] = 3-a-b;
		opt[pn][2] = b;
		pn ++;
		opt[pn][0] = 1;
		opt[pn][1] = a;
		opt[pn][2] = b;
		pn ++;
		opt[pn][0] = n-1;
		opt[pn][1] = a;
		opt[pn][2] = 3-a-b;
		pn ++;
		return 1;
	}
}



// �������Ӹ���
void CMyDlg::SetDishNumber(int n){

	KillTimer(1015); // ֹͣ��ʱ
	pn = 0; // ���ջ
	res.clear();//���vecotr����
	idx = -1;//λ�ó�ʼ��Ϊ-1,��ʾδ�����ӽ��в���
	number = n;
	for(int i = 0; i < n ; i++){
		dish[i] = 0; // ��ʼ��ÿ�����Ӷ��ڵ�һ��������
	}
	flag = false;
	Invalidate(FALSE);//�ػ�
}

//��ʾ
void CMyDlg::ShowBg(CDC * dc){

	//��ʾ����
	CDC pdc, ddc;
	pdc.CreateCompatibleDC(dc); // ����һ����ʱ��ʾ�豸
	ddc.CreateCompatibleDC(dc); // ����һ���������ӵ���ʱ��ʾ�豸

	CBitmap bmp, * obmp;
	bmp.LoadBitmap(IDB_BG); // ���ر���ͼƬ

	obmp = pdc.SelectObject(&bmp); // ��ͼƬ��ʾ���豸pdc�ϡ�

	//��ʾ����
	int n[] = {0, 0, 0}; // ���ڴ��ÿ����������ʾ��������
	for(int i = 0; i < number ; i++){
		CBitmap dbmp, * odbmp;
		dbmp.LoadBitmap(IDB_B7 - i); // ���شӴ�С��i������ͼƬ
		odbmp = ddc.SelectObject(&dbmp); // ��������ʾ���豸ddc�ϡ�
		pdc.BitBlt(10 + 150*dish[i], 225 - n[dish[i]]*20, 140, 15, &ddc, 0, 0, SRCCOPY); // ��ddc��������ʱ��ʾ�豸pdc��Ӧλ����
		n[dish[i]] ++;
		ddc.SelectObject(odbmp); // ��ʾ��ϣ���ԭ�豸
	}

	dc->BitBlt(10, 10, 460, 260, &pdc, 0, 0, SRCCOPY); // ��pdc������������ʾ�豸dc��
	pdc.SelectObject(obmp); // ��ʾ��ϣ���ԭ�豸
}

void CMyDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
	case 1015:
		if (pn > 0) {
			do {
				pn--; // ��ջ
			} while (1 == MoveDish(opt[pn][0], opt[pn][1], opt[pn][2])); // û�н��в������������ջ
			Invalidate(FALSE); // �ػ�
			if(flag1)
				KillTimer(nIDEvent);
		}
		else {
			KillTimer(nIDEvent);
		}
		break;
	}
	
	CDialog::OnTimer(nIDEvent);
}

void CMyDlg::OnButton1() {

	// ��ʼ��ʾ
	flag1 = false;
	if (0 == number) {
		MessageBox("��ѡ����������");
		return;
	}
	//if (!flag)
	//{
	UpdateData(TRUE);
	number = atoi(m_val);//��ȡ���õ����ӵĸ���
	SetDishNumber(number); // ��������
	MoveDish(number, 0, 2);
	flag = true;
	//}
	SetTimer(1015, last, NULL); // ��ʼ��ʱ��ÿ400����һ��
}

//��һ��
void CMyDlg::OnBnClickedNextButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag1 = true;
	if (0 == number) {
		MessageBox("��ѡ����������");
		return;
	}
	if (!flag)
	{
		CMyDlg::OnButton1();
	}
	else if (idx < int(res.size() - 1))
	{
		++idx;
		dish[res[idx].num] = res[idx].end;
		Invalidate(FALSE);//�ػ�
	}
	else
		SetTimer(1015, last, NULL);
}

//��һ��
void CMyDlg::OnBnClickedPrevButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag1 = true;
	if (idx >= 0)
	{
		dish[res[idx].num] = res[idx].beg;
		--idx;
		Invalidate(FALSE);//�ػ�
	}
}


void CMyDlg::OnBnClickedPauseButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(1015);
}


void CMyDlg::OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int num;
	*pResult = 0;
	UpdateData(TRUE);
	num = atoi(m_val);
	
	if (pNMUpDown->iDelta == 1)                 // �����ֵΪ1 , ˵�������Spin�����¼�ͷ  
	{
		m_val.Format("%d", num + 1);
	}
	else if (pNMUpDown->iDelta == -1)    // �����ֵΪ-1 , ˵�������Spin�����ϼ�ͷ  
	{
		m_val.Format("%d", num - 1);
	}
	num = atoi(m_val);
	if (num < 2)
		num = 2;
	if (num > 7)
		num = 7;
	number = num;
	UpdateData(FALSE);
	SetDishNumber(num);

}

//�ӿ�
void CMyDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (last > 100)
	{
		last -= 100;
		UpdateData(FALSE);
		KillTimer(1015);
		SetTimer(1015, last, NULL);
	}
}

//����
void CMyDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	
	if (last < 800)
	{
		CString str;
		last += 100;
		UpdateData(FALSE);
		KillTimer(1015);
		SetTimer(1015, last, NULL);
	}
}
