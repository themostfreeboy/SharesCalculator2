
// SharesCalculatorDlg.h : 头文件
//

#pragma once


// CSharesCalculatorDlg 对话框
class CSharesCalculatorDlg : public CDialogEx
{
// 构造
public:
	CSharesCalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SHARESCALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
	float GetFloatValueFromCString(CString cstr);//从编辑框内的CString型变量中获取转化float型数值
};
