// ��ŵ��Dlg.h : header file
//
#include<vector>
#include "afxcmn.h"
using namespace std;
#if !defined(AFX_DLG_H__6F346C11_76E2_42CA_ACB6_7040244805B5__INCLUDED_)
#define AFX_DLG_H__6F346C11_76E2_42CA_ACB6_7040244805B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog
struct Node {
	int num;
	int beg;
	int end;
};
class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	int MoveDish(int n, int a, int b); // ��a�������n�������ƶ���b
	void ShowBg(CDC * dc); // ��ʾ����
	void SetDishNumber(int n); // �������Ӹ���

	int number; // ������
	int dish[7]; // ÿ����������λ��
	bool flag;
	bool flag1;//flag1��������button1����һ��button
	int last;
	int opt[30][3]; // ����ջ�����ڱ��潫Ҫ���еĲ�������Ϊ����Ҫ�ֲ����У��ʲ���ջģ��ݹ飬�Ӷ��������ֽ�
	int pn; // ջ��λ��
	vector<Node>res;//�洢����˳�򣬷���鿴��һ��
	int idx;//��ǰ����λ��
	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedNextButton();
	afx_msg void OnBnClickedPrevButton();
	afx_msg void OnBnClickedPauseButton();
	CSpinButtonCtrl m_spin;
	afx_msg void OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_val;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__6F346C11_76E2_42CA_ACB6_7040244805B5__INCLUDED_)
