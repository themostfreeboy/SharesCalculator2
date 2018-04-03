
// SharesCalculatorDlg.h : ͷ�ļ�
//

#pragma once


// CSharesCalculatorDlg �Ի���
class CSharesCalculatorDlg : public CDialogEx
{
// ����
public:
	CSharesCalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SHARESCALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBcalculate();
	afx_msg void OnBnClickedBreset();
	afx_msg void OnBnClickedBexit();
	int ShareType;
	afx_msg void OnBnClickedRsharetype();
	BOOL DisableYHS;
	BOOL DisableGHF;
	BOOL DisableYJ;
	BOOL DisableTXF;
	afx_msg void OnBnClickedBstandardYhs();
	afx_msg void OnBnClickedBstandardGhf();
	afx_msg void OnBnClickedBstandardYj();
	afx_msg void OnBnClickedBstandardTxf();
	afx_msg void OnBnClickedCdisableYhs();
	afx_msg void OnBnClickedCdisableGhf();
	afx_msg void OnBnClickedCdisableYj();
	afx_msg void OnBnClickedCdisableTxf();
	float GetFloatValueFromCString(CString cstr);//�ӱ༭���ڵ�CString�ͱ����л�ȡת��float����ֵ
};
