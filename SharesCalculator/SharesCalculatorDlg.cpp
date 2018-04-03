
// SharesCalculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SharesCalculator.h"
#include "SharesCalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSharesCalculatorDlg 对话框




CSharesCalculatorDlg::CSharesCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSharesCalculatorDlg::IDD, pParent)
	, ShareType(0)
	, DisableYHS(FALSE)
	, DisableGHF(FALSE)
	, DisableYJ(FALSE)
	, DisableTXF(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSharesCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RSHARETYPE_S, ShareType);
	DDX_Check(pDX, IDC_CDISABLE_YHS, DisableYHS);
	DDX_Check(pDX, IDC_CDISABLE_GHF, DisableGHF);
	DDX_Check(pDX, IDC_CDISABLE_YJ, DisableYJ);
	DDX_Check(pDX, IDC_CDISABLE_TXF, DisableTXF);
}

BEGIN_MESSAGE_MAP(CSharesCalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BCALCULATE, &CSharesCalculatorDlg::OnBnClickedBcalculate)
	ON_BN_CLICKED(IDC_BRESET, &CSharesCalculatorDlg::OnBnClickedBreset)
	ON_BN_CLICKED(IDC_BEXIT, &CSharesCalculatorDlg::OnBnClickedBexit)
	ON_BN_CLICKED(IDC_RSHARETYPE_S, &CSharesCalculatorDlg::OnBnClickedRsharetype)
	ON_BN_CLICKED(IDC_RSHARETYPE_H, &CSharesCalculatorDlg::OnBnClickedRsharetype)
	ON_BN_CLICKED(IDC_BSTANDARD_YHS, &CSharesCalculatorDlg::OnBnClickedBstandardYhs)
	ON_BN_CLICKED(IDC_BSTANDARD_GHF, &CSharesCalculatorDlg::OnBnClickedBstandardGhf)
	ON_BN_CLICKED(IDC_BSTANDARD_YJ, &CSharesCalculatorDlg::OnBnClickedBstandardYj)
	ON_BN_CLICKED(IDC_BSTANDARD_TXF, &CSharesCalculatorDlg::OnBnClickedBstandardTxf)
	ON_BN_CLICKED(IDC_CDISABLE_YHS, &CSharesCalculatorDlg::OnBnClickedCdisableYhs)
	ON_BN_CLICKED(IDC_CDISABLE_GHF, &CSharesCalculatorDlg::OnBnClickedCdisableGhf)
	ON_BN_CLICKED(IDC_CDISABLE_YJ, &CSharesCalculatorDlg::OnBnClickedCdisableYj)
	ON_BN_CLICKED(IDC_CDISABLE_TXF, &CSharesCalculatorDlg::OnBnClickedCdisableTxf)
END_MESSAGE_MAP()


// CSharesCalculatorDlg 消息处理程序

BOOL CSharesCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	OnBnClickedBreset();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSharesCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSharesCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSharesCalculatorDlg::OnBnClickedBcalculate()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取标准手续费数据
	//获取印花税数据
	float f_YHS=0;
	CString cstr_YHS=_T("");
	GetDlgItemText(IDC_EYHS,cstr_YHS);
	f_YHS=GetFloatValueFromCString(cstr_YHS);
	//获取过户费数据
	float f_GHF=0;
	CString cstr_GHF=_T("");
	GetDlgItemText(IDC_EGHF,cstr_GHF);
	f_GHF=GetFloatValueFromCString(cstr_GHF);
	//获取券商交易佣金数据
	float f_YJ=0;
	CString cstr_YJ=_T("");
	GetDlgItemText(IDC_EYJ,cstr_YJ);
	f_YJ=GetFloatValueFromCString(cstr_YJ);
	//获取异地通讯费数据
	float f_TXF=0;
	CString cstr_TXF=_T("");
	GetDlgItemText(IDC_ETXF,cstr_TXF);
	f_TXF=GetFloatValueFromCString(cstr_TXF);

	//获取自定义手续费数据
	//获取仅买入收取数据
	float f_Self_Buy=0;
	CString cstr_Self_Buy=_T("");
	GetDlgItemText(IDC_ESELF_BUY,cstr_Self_Buy);
	f_Self_Buy=GetFloatValueFromCString(cstr_Self_Buy);
	//获取仅卖出收取数据
	float f_Self_Sell=0;
	CString cstr_Self_Sell=_T("");
	GetDlgItemText(IDC_ESELF_SELL,cstr_Self_Sell);
	f_Self_Sell=GetFloatValueFromCString(cstr_Self_Sell);
	//获取买入卖出均收取数据
	float f_Self_BuySell=0;
	CString cstr_Self_BuySell=_T("");
	GetDlgItemText(IDC_ESELF_BUYSELL,cstr_Self_BuySell);
	f_Self_BuySell=GetFloatValueFromCString(cstr_Self_BuySell);

	//获取买卖参数设置
	//获取第一次买入单价数据
	float f_Price_Buy_1=0;
	CString cstr_Price_Buy_1=_T("");
	GetDlgItemText(IDC_EPRICE_BUY_1,cstr_Price_Buy_1);
	f_Price_Buy_1=GetFloatValueFromCString(cstr_Price_Buy_1);
	//获取第一次买入数量数据
	float f_Num_Buy_1=0;
	CString cstr_Num_Buy_1=_T("");
	GetDlgItemText(IDC_ENUM_BUY_1,cstr_Num_Buy_1);
	f_Num_Buy_1=GetFloatValueFromCString(cstr_Num_Buy_1);
	//获取第二次买入单价数据
	float f_Price_Buy_2=0;
	CString cstr_Price_Buy_2=_T("");
	GetDlgItemText(IDC_EPRICE_BUY_2,cstr_Price_Buy_2);
	f_Price_Buy_2=GetFloatValueFromCString(cstr_Price_Buy_2);
	//获取第二次买入数量数据
	float f_Num_Buy_2=0;
	CString cstr_Num_Buy_2=_T("");
	GetDlgItemText(IDC_ENUM_BUY_2,cstr_Num_Buy_2);
	f_Num_Buy_2=GetFloatValueFromCString(cstr_Num_Buy_2);
	//获取第三次买入单价数据
	float f_Price_Buy_3=0;
	CString cstr_Price_Buy_3=_T("");
	GetDlgItemText(IDC_EPRICE_BUY_3,cstr_Price_Buy_3);
	f_Price_Buy_3=GetFloatValueFromCString(cstr_Price_Buy_3);
	//获取第三次买入数量数据
	float f_Num_Buy_3=0;
	CString cstr_Num_Buy_3=_T("");
	GetDlgItemText(IDC_ENUM_BUY_3,cstr_Num_Buy_3);
	f_Num_Buy_3=GetFloatValueFromCString(cstr_Num_Buy_3);
	//获取第四次买入单价数据
	float f_Price_Buy_4=0;
	CString cstr_Price_Buy_4=_T("");
	GetDlgItemText(IDC_EPRICE_BUY_4,cstr_Price_Buy_4);
	f_Price_Buy_4=GetFloatValueFromCString(cstr_Price_Buy_4);
	//获取第四次买入数量数据
	float f_Num_Buy_4=0;
	CString cstr_Num_Buy_4=_T("");
	GetDlgItemText(IDC_ENUM_BUY_4,cstr_Num_Buy_4);
	f_Num_Buy_4=GetFloatValueFromCString(cstr_Num_Buy_4);
	//获取第五次买入单价数据
	float f_Price_Buy_5=0;
	CString cstr_Price_Buy_5=_T("");
	GetDlgItemText(IDC_EPRICE_BUY_5,cstr_Price_Buy_5);
	f_Price_Buy_5=GetFloatValueFromCString(cstr_Price_Buy_5);
	//获取第五次买入数量数据
	float f_Num_Buy_5=0;
	CString cstr_Num_Buy_5=_T("");
	GetDlgItemText(IDC_ENUM_BUY_5,cstr_Num_Buy_5);
	f_Num_Buy_5=GetFloatValueFromCString(cstr_Num_Buy_5);
	//获取第一次卖出单价数据
	float f_Price_Sell_1=0;
	CString cstr_Price_Sell_1=_T("");
	GetDlgItemText(IDC_EPRICE_SELL_1,cstr_Price_Sell_1);
	f_Price_Sell_1=GetFloatValueFromCString(cstr_Price_Sell_1);
	//获取第一次卖出数量数据
	float f_Num_Sell_1=0;
	CString cstr_Num_Sell_1=_T("");
	GetDlgItemText(IDC_ENUM_SELL_1,cstr_Num_Sell_1);
	f_Num_Sell_1=GetFloatValueFromCString(cstr_Num_Sell_1);
	//获取第二次卖出单价数据
	float f_Price_Sell_2=0;
	CString cstr_Price_Sell_2=_T("");
	GetDlgItemText(IDC_EPRICE_SELL_2,cstr_Price_Sell_2);
	f_Price_Sell_2=GetFloatValueFromCString(cstr_Price_Sell_2);
	//获取第二次卖出数量数据
	float f_Num_Sell_2=0;
	CString cstr_Num_Sell_2=_T("");
	GetDlgItemText(IDC_ENUM_SELL_2,cstr_Num_Sell_2);
	f_Num_Sell_2=GetFloatValueFromCString(cstr_Num_Sell_2);
	//获取第三次卖出单价数据
	float f_Price_Sell_3=0;
	CString cstr_Price_Sell_3=_T("");
	GetDlgItemText(IDC_EPRICE_SELL_3,cstr_Price_Sell_3);
	f_Price_Sell_3=GetFloatValueFromCString(cstr_Price_Sell_3);
	//获取第三次卖出数量数据
	float f_Num_Sell_3=0;
	CString cstr_Num_Sell_3=_T("");
	GetDlgItemText(IDC_ENUM_SELL_3,cstr_Num_Sell_3);
	f_Num_Sell_3=GetFloatValueFromCString(cstr_Num_Sell_3);
	//获取第四次卖出单价数据
	float f_Price_Sell_4=0;
	CString cstr_Price_Sell_4=_T("");
	GetDlgItemText(IDC_EPRICE_SELL_4,cstr_Price_Sell_4);
	f_Price_Sell_4=GetFloatValueFromCString(cstr_Price_Sell_4);
	//获取第四次卖出数量数据
	float f_Num_Sell_4=0;
	CString cstr_Num_Sell_4=_T("");
	GetDlgItemText(IDC_ENUM_SELL_4,cstr_Num_Sell_4);
	f_Num_Sell_4=GetFloatValueFromCString(cstr_Num_Sell_4);
	//获取第五次卖出单价数据
	float f_Price_Sell_5=0;
	CString cstr_Price_Sell_5=_T("");
	GetDlgItemText(IDC_EPRICE_SELL_5,cstr_Price_Sell_5);
	f_Price_Sell_5=GetFloatValueFromCString(cstr_Price_Sell_5);
	//获取第五次卖出数量数据
	float f_Num_Sell_5=0;
	CString cstr_Num_Sell_5=_T("");
	GetDlgItemText(IDC_ENUM_SELL_5,cstr_Num_Sell_5);
	f_Num_Sell_5=GetFloatValueFromCString(cstr_Num_Sell_5);

	//定义计算结果数据
	float f_result_out_GP=0;//买入股票支出
	float f_result_out_SXF=0;//手续费总支出
	float f_result_out_ALL=0;//总支出
	float f_result_in_ALL=0;//目前总收入
	float f_result_in_PROFITS=0;//目前净收入
	float f_result_NUM=0;//剩余股票数量
	float f_result_PRICE=0;//剩余股票不亏本最低卖出价格

	//定义临时变量
	CString cstr_temp=_T("");

	//检查所有数据的合法性
	if
	(
	    f_YHS>=0             &&
		f_GHF>=0             &&
		f_YJ>=0              &&
		f_TXF>=0             &&
		f_Self_Buy>=0        &&
		f_Self_Sell>=0       &&
		f_Self_BuySell>=0    &&
		f_Price_Buy_1>=0     &&
		f_Num_Buy_1>=0       &&
		f_Price_Buy_2>=0     &&
		f_Num_Buy_2>=0       &&
		f_Price_Buy_3>=0     &&
		f_Num_Buy_3>=0       &&
		f_Price_Buy_4>=0     &&
		f_Num_Buy_4>=0       &&
		f_Price_Buy_5>=0     &&
		f_Num_Buy_5>=0       &&
		f_Price_Sell_1>=0    &&
		f_Num_Sell_1>=0      &&
		f_Price_Sell_2>=0    &&
		f_Num_Sell_2>=0      &&
		f_Price_Sell_3>=0    &&
		f_Num_Sell_3>=0      &&
		f_Price_Sell_4>=0    &&
		f_Num_Sell_4>=0      &&
		f_Price_Sell_5>=0    &&
		f_Num_Sell_5>=0      &&
		f_Num_Buy_1+f_Num_Buy_2+f_Num_Buy_3+f_Num_Buy_4+f_Num_Buy_5-f_Num_Sell_1-f_Num_Sell_2-f_Num_Sell_3-f_Num_Sell_4-f_Num_Sell_5>=0
	);//数据合法
	else if(f_Num_Buy_1+f_Num_Buy_2+f_Num_Buy_3+f_Num_Buy_4+f_Num_Buy_5-f_Num_Sell_1-f_Num_Sell_2-f_Num_Sell_3-f_Num_Sell_4-f_Num_Sell_5<0)//卖出的总股数大于买入的总股数
	{
		AfxMessageBox(_T("卖出的总股数大于买入的总股数，请重新检查输入的数据"),MB_OK,NULL);
		return;
	}
	else//数据不合法
	{
		AfxMessageBox(_T("输入的数据格式错误，请重新检查输入的数据"),MB_OK,NULL);
		return;
	}

	//详细计算
	//计算买入股票支出
	f_result_out_GP=f_Price_Buy_1*f_Num_Buy_1+f_Price_Buy_2*f_Num_Buy_2+f_Price_Buy_3*f_Num_Buy_3+f_Price_Buy_4*f_Num_Buy_4+f_Price_Buy_5*f_Num_Buy_5;
	cstr_temp.Format(_T("%.2f"),f_result_out_GP);
	SetDlgItemText(IDC_ERESULT_OUT_GP,cstr_temp);//设置买入股票支出结果
	//计算目前总收入
	f_result_in_ALL=f_Price_Sell_1*f_Num_Sell_1+f_Price_Sell_2*f_Num_Sell_2+f_Price_Sell_3*f_Num_Sell_3+f_Price_Sell_4*f_Num_Sell_4+f_Price_Sell_5*f_Num_Sell_5;
	cstr_temp.Format(_T("%.2f"),f_result_in_ALL);
	SetDlgItemText(IDC_ERESULT_IN_ALL,cstr_temp);//设置目前总收入结果
	//计算剩余股票数量
	f_result_NUM=f_Num_Buy_1+f_Num_Buy_2+f_Num_Buy_3+f_Num_Buy_4+f_Num_Buy_5-f_Num_Sell_1-f_Num_Sell_2-f_Num_Sell_3-f_Num_Sell_4-f_Num_Sell_5;
	cstr_temp.Format(_T("%.0f"),f_result_NUM);
	SetDlgItemText(IDC_ERESULT_NUM,cstr_temp);//设置剩余股票数量结果
	//计算手续费总支出
	//定义变量
	float f_result_YHS=0;//印花税
	float f_result_GHF=0;//过户费
	float f_result_YJ=0;//券商交易佣金
	float f_result_TXF=0;//异地通讯费
	//计算印花税
	f_result_YHS=f_result_in_ALL*f_YHS*0.001;
	//计算过户费
	if(DisableGHF==false)//未禁用
	{
		if(f_Num_Buy_1==0)                         f_result_GHF+=0;
		    else if(f_Num_Buy_1<1000)              f_result_GHF+=f_GHF;
		    else if(((int)f_Num_Buy_1%1000==0))    f_result_GHF+=((int)f_Num_Buy_1/1000)*f_GHF;
		    else                                   f_result_GHF+=((int)f_Num_Buy_1/1000+1)*f_GHF;
		if(f_Num_Buy_2==0)                         f_result_GHF+=0;
		    else if(f_Num_Buy_2<1000)              f_result_GHF+=f_GHF;
		    else if(((int)f_Num_Buy_2%1000==0))    f_result_GHF+=((int)f_Num_Buy_2/1000)*f_GHF;
		    else                                   f_result_GHF+=((int)f_Num_Buy_2/1000+1)*f_GHF;
		if(f_Num_Buy_3==0)                         f_result_GHF+=0;
		    else if(f_Num_Buy_3<1000)              f_result_GHF+=f_GHF;
		    else if(((int)f_Num_Buy_3%1000==0))    f_result_GHF+=((int)f_Num_Buy_3/1000)*f_GHF;
		    else                                   f_result_GHF+=((int)f_Num_Buy_3/1000+1)*f_GHF;
		if(f_Num_Buy_4==0)                         f_result_GHF+=0;
		    else if(f_Num_Buy_4<1000)              f_result_GHF+=f_GHF;
		    else if(((int)f_Num_Buy_4%1000==0))    f_result_GHF+=((int)f_Num_Buy_4/1000)*f_GHF;
		    else                                   f_result_GHF+=((int)f_Num_Buy_4/1000+1)*f_GHF;
		if(f_Num_Buy_5==0)                         f_result_GHF+=0;
		    else if(f_Num_Buy_5<1000)              f_result_GHF+=f_GHF;
		    else if(((int)f_Num_Buy_5%1000==0))    f_result_GHF+=((int)f_Num_Buy_5/1000)*f_GHF;
		    else                                   f_result_GHF+=((int)f_Num_Buy_5/1000+1)*f_GHF;
		if(f_Num_Sell_1==0)                        f_result_GHF+=0;
		    else if(f_Num_Sell_1<1000)             f_result_GHF+=f_GHF;
		    else if(((int)f_Num_Sell_1%1000==0))   f_result_GHF+=((int)f_Num_Sell_1/1000)*f_GHF;
		    else                                   f_result_GHF+=((int)f_Num_Sell_1/1000+1)*f_GHF;
		if(f_Num_Sell_2==0)                        f_result_GHF+=0;
		    else if(f_Num_Sell_2<1000)             f_result_GHF+=f_GHF;
		    else if(((int)f_Num_Sell_2%1000==0))   f_result_GHF+=((int)f_Num_Sell_2/1000)*f_GHF;
		    else                                   f_result_GHF+=((int)f_Num_Sell_2/1000+1)*f_GHF;
		if(f_Num_Sell_3==0)                        f_result_GHF+=0;
		    else if(f_Num_Sell_3<1000)             f_result_GHF+=f_GHF;
		    else if(((int)f_Num_Sell_3%1000==0))   f_result_GHF+=((int)f_Num_Sell_3/1000)*f_GHF;
		    else                                   f_result_GHF+=((int)f_Num_Sell_3/1000+1)*f_GHF;
		if(f_Num_Sell_4==0)                        f_result_GHF+=0;
		    else if(f_Num_Sell_4<1000)             f_result_GHF+=f_GHF;
		    else if(((int)f_Num_Sell_4%1000==0))   f_result_GHF+=((int)f_Num_Sell_4/1000)*f_GHF;
		    else                                   f_result_GHF+=((int)f_Num_Sell_4/1000+1)*f_GHF;
		if(f_Num_Sell_5==0)                        f_result_GHF+=0;
		    else if(f_Num_Sell_5<1000)             f_result_GHF+=f_GHF;
		    else if(((int)f_Num_Sell_5%1000==0))   f_result_GHF+=((int)f_Num_Sell_5/1000)*f_GHF;
		    else                                   f_result_GHF+=((int)f_Num_Sell_5/1000+1)*f_GHF;
		
	}
	//计算券商交易佣金
	if(DisableYJ==false)//未禁用
	{
		if(f_Num_Buy_1>0)		f_result_YJ+=(f_Price_Buy_1*f_Num_Buy_1*f_YJ*0.001<3)?3:(f_Price_Buy_1*f_Num_Buy_1*f_YJ*0.001);
		if(f_Num_Buy_2>0)		f_result_YJ+=(f_Price_Buy_2*f_Num_Buy_2*f_YJ*0.001<3)?3:(f_Price_Buy_2*f_Num_Buy_2*f_YJ*0.001);
		if(f_Num_Buy_3>0)		f_result_YJ+=(f_Price_Buy_3*f_Num_Buy_3*f_YJ*0.001<3)?3:(f_Price_Buy_3*f_Num_Buy_3*f_YJ*0.001);
		if(f_Num_Buy_4>0)		f_result_YJ+=(f_Price_Buy_4*f_Num_Buy_4*f_YJ*0.001<3)?3:(f_Price_Buy_4*f_Num_Buy_4*f_YJ*0.001);
		if(f_Num_Buy_5>0)		f_result_YJ+=(f_Price_Buy_5*f_Num_Buy_5*f_YJ*0.001<3)?3:(f_Price_Buy_5*f_Num_Buy_5*f_YJ*0.001);
		if(f_Num_Sell_1>0)		f_result_YJ+=(f_Price_Sell_1*f_Num_Sell_1*f_YJ*0.001<3)?3:(f_Price_Sell_1*f_Num_Sell_1*f_YJ*0.001);
		if(f_Num_Sell_2>0)		f_result_YJ+=(f_Price_Sell_2*f_Num_Sell_2*f_YJ*0.001<3)?3:(f_Price_Sell_2*f_Num_Sell_2*f_YJ*0.001);
		if(f_Num_Sell_3>0)		f_result_YJ+=(f_Price_Sell_3*f_Num_Sell_3*f_YJ*0.001<3)?3:(f_Price_Sell_3*f_Num_Sell_3*f_YJ*0.001);
		if(f_Num_Sell_4>0)		f_result_YJ+=(f_Price_Sell_4*f_Num_Sell_4*f_YJ*0.001<3)?3:(f_Price_Sell_4*f_Num_Sell_4*f_YJ*0.001);
		if(f_Num_Sell_5>0)		f_result_YJ+=(f_Price_Sell_5*f_Num_Sell_5*f_YJ*0.001<3)?3:(f_Price_Sell_5*f_Num_Sell_5*f_YJ*0.001);
	}
	//计算异地通讯费
	f_result_TXF=(f_result_out_GP+f_result_in_ALL)*f_TXF*0.001;
	//计算手续费总支出
	f_result_out_SXF=f_result_YHS+f_result_GHF+f_result_YJ+f_result_TXF+f_result_out_GP*f_Self_Buy*0.001+f_result_in_ALL*f_Self_Sell*0.001+(f_result_out_GP+f_result_in_ALL)*f_Self_BuySell*0.001;
	cstr_temp.Format(_T("%.2f"),f_result_out_SXF);
	SetDlgItemText(IDC_ERESULT_OUT_SXF,cstr_temp);//设置手续费总支出结果
	//计算总支出
	f_result_out_ALL=f_result_out_GP+f_result_out_SXF;
	cstr_temp.Format(_T("%.2f"),f_result_out_ALL);
	SetDlgItemText(IDC_ERESULT_OUT_ALL,cstr_temp);//设置总支出结果
	//计算目前净收入
	f_result_in_PROFITS=f_result_in_ALL-f_result_out_ALL;
	cstr_temp.Format(_T("%.2f"),f_result_in_PROFITS);
	SetDlgItemText(IDC_ERESULT_IN_PROFITS,cstr_temp);//设置目前净收入结果
	//计算剩余股票不亏本最低卖出价格
	if(f_result_NUM==0)//股票已经全部卖出
	{
		SetDlgItemText(IDC_ERESULT_PRICE,_T("0"));//设置剩余股票不亏本最低卖出价格结果
		return;
	}
	//定义变量
	float f_temp_GHF=0;//过户费
	//计算过户费
	if(DisableGHF==false)//未禁用
	{
		if(f_result_NUM==0)                         f_temp_GHF=0;
		    else if(f_result_NUM<1000)              f_temp_GHF=f_GHF;
		    else if((int)f_result_NUM%1000==0)      f_temp_GHF=((int)f_result_NUM/1000)*f_GHF;
		    else                                    f_temp_GHF=((int)f_result_NUM/1000+1)*f_GHF;
	}
	f_result_PRICE=(f_temp_GHF-f_result_in_PROFITS)/(1-f_YHS*0.001-f_YJ*0.001-f_TXF*0.001-f_Self_Sell*0.001-f_Self_BuySell*0.001)/f_result_NUM;
	if(f_result_PRICE*f_result_NUM>=3)//券商交易佣金验证
	{
		cstr_temp.Format(_T("%.2f"),f_result_PRICE);
	    SetDlgItemText(IDC_ERESULT_PRICE,cstr_temp);//设置剩余股票不亏本最低卖出价格结果
		return;
	}
	else//券商交易佣金不符合条件，重新计算
	{
		f_result_PRICE=(f_temp_GHF+3-f_result_in_PROFITS)/(1-f_YHS*0.001-f_TXF*0.001-f_Self_Sell*0.001-f_Self_BuySell*0.001)/f_result_NUM;
		if(f_result_PRICE*f_result_NUM<3)//券商交易佣金验证
		{
			cstr_temp.Format(_T("%.2f"),f_result_PRICE);
	        SetDlgItemText(IDC_ERESULT_PRICE,cstr_temp);//设置剩余股票不亏本最低卖出价格结果
		    return;
		}
		else//无符合条件的结果
		{
	        SetDlgItemText(IDC_ERESULT_PRICE,_T("无"));//设置剩余股票不亏本最低卖出价格结果
		    return;
		}
	}
}


void CSharesCalculatorDlg::OnBnClickedBreset()
{
	// TODO: 在此添加控件通知处理程序代码

	//设置股票类型为深圳股票(深)
	CButton* button=(CButton*)GetDlgItem(IDC_RSHARETYPE_S);
    button->SetCheck(TRUE);
	button=(CButton*)GetDlgItem(IDC_RSHARETYPE_H);
    button->SetCheck(FALSE);

	//设置标准手续费
	OnBnClickedRsharetype();

	//设置标准手续费禁用模式
	button=(CButton*)GetDlgItem(IDC_CDISABLE_YHS);
    button->SetCheck(FALSE);//设置印花税禁用模式为非禁用
	button=(CButton*)GetDlgItem(IDC_CDISABLE_GHF);
    button->SetCheck(FALSE);//设置过户费禁用模式为非禁用
	button=(CButton*)GetDlgItem(IDC_CDISABLE_YJ);
    button->SetCheck(FALSE);//设置券商交易佣金禁用模式为非禁用
	button=(CButton*)GetDlgItem(IDC_CDISABLE_TXF);
    button->SetCheck(TRUE);//设置异地通讯费禁用模式为禁用
	OnBnClickedCdisableYhs();
	OnBnClickedCdisableGhf();
	OnBnClickedCdisableYj();
	OnBnClickedCdisableTxf();


	//设置自定义手续费
	SetDlgItemText(IDC_ESELF_BUY,_T("0"));//设置仅买入收取为0‰
	SetDlgItemText(IDC_ESELF_SELL,_T("0"));//设置仅卖出收取为0‰
	SetDlgItemText(IDC_ESELF_BUYSELL,_T("0"));//设置买入卖出均收取为0‰

	//设置买卖参数设置
	SetDlgItemText(IDC_EPRICE_BUY_1,_T("0"));//设置第一次买入单价为0元/股
	SetDlgItemText(IDC_ENUM_BUY_1,_T("0"));//设置第一次买入数量为0股
	SetDlgItemText(IDC_EPRICE_BUY_2,_T("0"));//设置第二次买入单价为0元/股
	SetDlgItemText(IDC_ENUM_BUY_2,_T("0"));//设置第二次买入数量为0股
	SetDlgItemText(IDC_EPRICE_BUY_3,_T("0"));//设置第三次买入单价为0元/股
	SetDlgItemText(IDC_ENUM_BUY_3,_T("0"));//设置第三次买入数量为0股
	SetDlgItemText(IDC_EPRICE_BUY_4,_T("0"));//设置第四次买入单价为0元/股
	SetDlgItemText(IDC_ENUM_BUY_4,_T("0"));//设置第四次买入数量为0股
	SetDlgItemText(IDC_EPRICE_BUY_5,_T("0"));//设置第五次买入单价为0元/股
	SetDlgItemText(IDC_ENUM_BUY_5,_T("0"));//设置第五次买入数量为0股
	SetDlgItemText(IDC_EPRICE_SELL_1,_T("0"));//设置第一次卖出单价为0元/股
	SetDlgItemText(IDC_ENUM_SELL_1,_T("0"));//设置第一次卖出数量为0股
	SetDlgItemText(IDC_EPRICE_SELL_2,_T("0"));//设置第二次卖出单价为0元/股
	SetDlgItemText(IDC_ENUM_SELL_2,_T("0"));//设置第二次卖出数量为0股
	SetDlgItemText(IDC_EPRICE_SELL_3,_T("0"));//设置第三次卖出单价为0元/股
	SetDlgItemText(IDC_ENUM_SELL_3,_T("0"));//设置第三次卖出数量为0股
	SetDlgItemText(IDC_EPRICE_SELL_4,_T("0"));//设置第四次卖出单价为0元/股
	SetDlgItemText(IDC_ENUM_SELL_4,_T("0"));//设置第四次卖出数量为0股
	SetDlgItemText(IDC_EPRICE_SELL_5,_T("0"));//设置第五次卖出单价为0元/股
	SetDlgItemText(IDC_ENUM_SELL_5,_T("0"));//设置第五次卖出数量为0股

	//设置计算结果
	SetDlgItemText(IDC_ERESULT_OUT_GP,_T("0"));//设置买入股票支出为0元
	SetDlgItemText(IDC_ERESULT_OUT_SXF,_T("0"));//设置手续费总支出为0元
	SetDlgItemText(IDC_ERESULT_OUT_ALL,_T("0"));//设置总支出为0元
	SetDlgItemText(IDC_ERESULT_IN_ALL,_T("0"));//设置目前总收入为0元
	SetDlgItemText(IDC_ERESULT_IN_PROFITS,_T("0"));//设置目前净收入为0元
	SetDlgItemText(IDC_ERESULT_NUM,_T("0"));//设置剩余股票数量为0股
	SetDlgItemText(IDC_ERESULT_PRICE,_T("0"));//设置剩余股票不亏本最低卖出价格为0元
}


void CSharesCalculatorDlg::OnBnClickedBexit()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CSharesCalculatorDlg::OnBnClickedRsharetype()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	OnBnClickedCdisableYhs();
	OnBnClickedCdisableGhf();
	OnBnClickedCdisableYj();
	OnBnClickedCdisableTxf();
}


void CSharesCalculatorDlg::OnBnClickedBstandardYhs()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxMessageBox(_T("印花税收费标准：成交金额的1‰。深圳股票上海股票均收取。仅卖出时收取。"),MB_OK,NULL);
}


void CSharesCalculatorDlg::OnBnClickedBstandardGhf()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxMessageBox(_T("过户费收费标准：每1000股收取0.3元，不足1000股按0.3元收取。仅上海股票收取。买入卖出时均收取。"),MB_OK,NULL);
}


void CSharesCalculatorDlg::OnBnClickedBstandardYj()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxMessageBox(_T("券商交易佣金收费标准：成交金额的0.3‰，但是最低收取标准是3元。深圳股票上海股票均收取。买入卖出时均收取。"),MB_OK,NULL);
}


void CSharesCalculatorDlg::OnBnClickedBstandardTxf()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxMessageBox(_T("异地通讯费收费标准：由各券商自行决定收不收。"),MB_OK,NULL);
}


void CSharesCalculatorDlg::OnBnClickedCdisableYhs()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(DisableYHS==true)//禁用
	{
		SetDlgItemText(IDC_EYHS,_T("0"));//设置印花税为0‰
		CEdit *edit = (CEdit*)GetDlgItem(IDC_EYHS);
		edit->SetReadOnly(true);//设置印花税编辑框为只读
	}
	else if(DisableYHS==false)//非禁用
	{
		SetDlgItemText(IDC_EYHS,_T("1"));//设置印花税为1‰
		CEdit *edit = (CEdit*)GetDlgItem(IDC_EYHS);
		edit->SetReadOnly(false);//设置印花税编辑框为非只读
	}
	else//有误
	{
		AfxMessageBox(_T("印花税禁用模式选择有误。"),MB_OK,NULL);
	}
}


void CSharesCalculatorDlg::OnBnClickedCdisableGhf()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(DisableGHF==true)//禁用
	{
		SetDlgItemText(IDC_EGHF,_T("0"));//设置过户费为0‰
		CEdit *edit = (CEdit*)GetDlgItem(IDC_EGHF);
		edit->SetReadOnly(true);//设置过户费编辑框为只读
	}
	else if(DisableGHF==false)//非禁用
	{
		if(ShareType==0)             SetDlgItemText(IDC_EGHF,_T("0"));//深圳股票(深)设置过户费为0‰
		    else if(ShareType==1)    SetDlgItemText(IDC_EGHF,_T("0.3"));//上海股票(沪)设置过户费为0.3‰
		CEdit *edit = (CEdit*)GetDlgItem(IDC_EGHF);
		edit->SetReadOnly(false);//设置过户费编辑框为非只读
	}
	else//有误
	{
		AfxMessageBox(_T("过户费禁用模式选择有误。"),MB_OK,NULL);
	}
}


void CSharesCalculatorDlg::OnBnClickedCdisableYj()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(DisableYJ==true)//禁用
	{
		SetDlgItemText(IDC_EYJ,_T("0"));//设置券商交易佣金为0‰
		CEdit *edit = (CEdit*)GetDlgItem(IDC_EYJ);
		edit->SetReadOnly(true);//设置券商交易佣金编辑框为只读
	}
	else if(DisableYJ==false)//非禁用
	{
		SetDlgItemText(IDC_EYJ,_T("0.3"));//设置券商交易佣金为0.3‰
		CEdit *edit = (CEdit*)GetDlgItem(IDC_EYJ);
		edit->SetReadOnly(false);//设置券商交易佣金编辑框为非只读
	}
	else//有误
	{
		AfxMessageBox(_T("券商交易佣金禁用模式选择有误。"),MB_OK,NULL);
	}
}


void CSharesCalculatorDlg::OnBnClickedCdisableTxf()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(DisableTXF==true)//禁用
	{
		SetDlgItemText(IDC_ETXF,_T("0"));//设置异地通讯费为0‰
		CEdit *edit = (CEdit*)GetDlgItem(IDC_ETXF);
		edit->SetReadOnly(true);//设置异地通讯费编辑框为只读
	}
	else if(DisableTXF==false)//非禁用
	{
		SetDlgItemText(IDC_ETXF,_T("0"));//设置异地通讯费为0‰
		CEdit *edit = (CEdit*)GetDlgItem(IDC_ETXF);
		edit->SetReadOnly(false);//设置异地通讯费编辑框为非只读
	}
	else//有误
	{
		AfxMessageBox(_T("异地通讯费禁用模式选择有误。"),MB_OK,NULL);
	}
}


float CSharesCalculatorDlg::GetFloatValueFromCString(CString cstr)//从编辑框内的CString型变量中获取转化float型数值
{
	const char* char_value=MyCStringToConstChar(cstr);
	int nLength=strlen(char_value);
	int point_flag=0;//小数点标志位
	float floatvalue=0;
	float point_rate=1;
	for(int i=0;i<nLength;i++)
	{
		if(i>6)//数据过大(含小数点占1位最多7位数)
		{
			//AfxMessageBox(_T("数据过大，请重新检查输入的数据"),MB_OK,NULL);
			return -2;
		}
		if(char_value[i]>='0'&&char_value[i]<='9')//校检数据格式
		{
			if(point_flag==0)//目前无小数点出现
			{
				floatvalue=floatvalue*10+(char_value[i]-'0');
			}
			else if(point_flag==1)//目前有小数点出现
			{
				point_rate=point_rate*0.1;
				floatvalue=floatvalue+(char_value[i]-'0')*point_rate;
			}
		}
		else if(char_value[i]=='.')//出现小数点
		{
			if(point_flag==0)//目前无小数点出现
			{
				point_flag=1;
			}
			else//目前已经有小数点出现
			{
				//AfxMessageBox(_T("输入的数据格式错误，请重新检查输入的数据"),MB_OK,NULL);
			    return -1;
			}
		}
		else
		{
			//AfxMessageBox(_T("输入的数据格式错误，请重新检查输入的数据"),MB_OK,NULL);
			return -1;
		}
	}
	return floatvalue;
}