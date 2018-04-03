
// SharesCalculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SharesCalculator.h"
#include "SharesCalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSharesCalculatorDlg �Ի���




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


// CSharesCalculatorDlg ��Ϣ�������

BOOL CSharesCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	OnBnClickedBreset();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSharesCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSharesCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSharesCalculatorDlg::OnBnClickedBcalculate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��ȡ��׼����������
	//��ȡӡ��˰����
	float f_YHS=0;
	CString cstr_YHS=_T("");
	GetDlgItemText(IDC_EYHS,cstr_YHS);
	f_YHS=GetFloatValueFromCString(cstr_YHS);
	//��ȡ����������
	float f_GHF=0;
	CString cstr_GHF=_T("");
	GetDlgItemText(IDC_EGHF,cstr_GHF);
	f_GHF=GetFloatValueFromCString(cstr_GHF);
	//��ȡȯ�̽���Ӷ������
	float f_YJ=0;
	CString cstr_YJ=_T("");
	GetDlgItemText(IDC_EYJ,cstr_YJ);
	f_YJ=GetFloatValueFromCString(cstr_YJ);
	//��ȡ���ͨѶ������
	float f_TXF=0;
	CString cstr_TXF=_T("");
	GetDlgItemText(IDC_ETXF,cstr_TXF);
	f_TXF=GetFloatValueFromCString(cstr_TXF);

	//��ȡ�Զ�������������
	//��ȡ��������ȡ����
	float f_Self_Buy=0;
	CString cstr_Self_Buy=_T("");
	GetDlgItemText(IDC_ESELF_BUY,cstr_Self_Buy);
	f_Self_Buy=GetFloatValueFromCString(cstr_Self_Buy);
	//��ȡ��������ȡ����
	float f_Self_Sell=0;
	CString cstr_Self_Sell=_T("");
	GetDlgItemText(IDC_ESELF_SELL,cstr_Self_Sell);
	f_Self_Sell=GetFloatValueFromCString(cstr_Self_Sell);
	//��ȡ������������ȡ����
	float f_Self_BuySell=0;
	CString cstr_Self_BuySell=_T("");
	GetDlgItemText(IDC_ESELF_BUYSELL,cstr_Self_BuySell);
	f_Self_BuySell=GetFloatValueFromCString(cstr_Self_BuySell);

	//��ȡ������������
	//��ȡ��һ�����뵥������
	float f_Price_Buy_1=0;
	CString cstr_Price_Buy_1=_T("");
	GetDlgItemText(IDC_EPRICE_BUY_1,cstr_Price_Buy_1);
	f_Price_Buy_1=GetFloatValueFromCString(cstr_Price_Buy_1);
	//��ȡ��һ��������������
	float f_Num_Buy_1=0;
	CString cstr_Num_Buy_1=_T("");
	GetDlgItemText(IDC_ENUM_BUY_1,cstr_Num_Buy_1);
	f_Num_Buy_1=GetFloatValueFromCString(cstr_Num_Buy_1);
	//��ȡ�ڶ������뵥������
	float f_Price_Buy_2=0;
	CString cstr_Price_Buy_2=_T("");
	GetDlgItemText(IDC_EPRICE_BUY_2,cstr_Price_Buy_2);
	f_Price_Buy_2=GetFloatValueFromCString(cstr_Price_Buy_2);
	//��ȡ�ڶ���������������
	float f_Num_Buy_2=0;
	CString cstr_Num_Buy_2=_T("");
	GetDlgItemText(IDC_ENUM_BUY_2,cstr_Num_Buy_2);
	f_Num_Buy_2=GetFloatValueFromCString(cstr_Num_Buy_2);
	//��ȡ���������뵥������
	float f_Price_Buy_3=0;
	CString cstr_Price_Buy_3=_T("");
	GetDlgItemText(IDC_EPRICE_BUY_3,cstr_Price_Buy_3);
	f_Price_Buy_3=GetFloatValueFromCString(cstr_Price_Buy_3);
	//��ȡ������������������
	float f_Num_Buy_3=0;
	CString cstr_Num_Buy_3=_T("");
	GetDlgItemText(IDC_ENUM_BUY_3,cstr_Num_Buy_3);
	f_Num_Buy_3=GetFloatValueFromCString(cstr_Num_Buy_3);
	//��ȡ���Ĵ����뵥������
	float f_Price_Buy_4=0;
	CString cstr_Price_Buy_4=_T("");
	GetDlgItemText(IDC_EPRICE_BUY_4,cstr_Price_Buy_4);
	f_Price_Buy_4=GetFloatValueFromCString(cstr_Price_Buy_4);
	//��ȡ���Ĵ�������������
	float f_Num_Buy_4=0;
	CString cstr_Num_Buy_4=_T("");
	GetDlgItemText(IDC_ENUM_BUY_4,cstr_Num_Buy_4);
	f_Num_Buy_4=GetFloatValueFromCString(cstr_Num_Buy_4);
	//��ȡ��������뵥������
	float f_Price_Buy_5=0;
	CString cstr_Price_Buy_5=_T("");
	GetDlgItemText(IDC_EPRICE_BUY_5,cstr_Price_Buy_5);
	f_Price_Buy_5=GetFloatValueFromCString(cstr_Price_Buy_5);
	//��ȡ�����������������
	float f_Num_Buy_5=0;
	CString cstr_Num_Buy_5=_T("");
	GetDlgItemText(IDC_ENUM_BUY_5,cstr_Num_Buy_5);
	f_Num_Buy_5=GetFloatValueFromCString(cstr_Num_Buy_5);
	//��ȡ��һ��������������
	float f_Price_Sell_1=0;
	CString cstr_Price_Sell_1=_T("");
	GetDlgItemText(IDC_EPRICE_SELL_1,cstr_Price_Sell_1);
	f_Price_Sell_1=GetFloatValueFromCString(cstr_Price_Sell_1);
	//��ȡ��һ��������������
	float f_Num_Sell_1=0;
	CString cstr_Num_Sell_1=_T("");
	GetDlgItemText(IDC_ENUM_SELL_1,cstr_Num_Sell_1);
	f_Num_Sell_1=GetFloatValueFromCString(cstr_Num_Sell_1);
	//��ȡ�ڶ���������������
	float f_Price_Sell_2=0;
	CString cstr_Price_Sell_2=_T("");
	GetDlgItemText(IDC_EPRICE_SELL_2,cstr_Price_Sell_2);
	f_Price_Sell_2=GetFloatValueFromCString(cstr_Price_Sell_2);
	//��ȡ�ڶ���������������
	float f_Num_Sell_2=0;
	CString cstr_Num_Sell_2=_T("");
	GetDlgItemText(IDC_ENUM_SELL_2,cstr_Num_Sell_2);
	f_Num_Sell_2=GetFloatValueFromCString(cstr_Num_Sell_2);
	//��ȡ������������������
	float f_Price_Sell_3=0;
	CString cstr_Price_Sell_3=_T("");
	GetDlgItemText(IDC_EPRICE_SELL_3,cstr_Price_Sell_3);
	f_Price_Sell_3=GetFloatValueFromCString(cstr_Price_Sell_3);
	//��ȡ������������������
	float f_Num_Sell_3=0;
	CString cstr_Num_Sell_3=_T("");
	GetDlgItemText(IDC_ENUM_SELL_3,cstr_Num_Sell_3);
	f_Num_Sell_3=GetFloatValueFromCString(cstr_Num_Sell_3);
	//��ȡ���Ĵ�������������
	float f_Price_Sell_4=0;
	CString cstr_Price_Sell_4=_T("");
	GetDlgItemText(IDC_EPRICE_SELL_4,cstr_Price_Sell_4);
	f_Price_Sell_4=GetFloatValueFromCString(cstr_Price_Sell_4);
	//��ȡ���Ĵ�������������
	float f_Num_Sell_4=0;
	CString cstr_Num_Sell_4=_T("");
	GetDlgItemText(IDC_ENUM_SELL_4,cstr_Num_Sell_4);
	f_Num_Sell_4=GetFloatValueFromCString(cstr_Num_Sell_4);
	//��ȡ�����������������
	float f_Price_Sell_5=0;
	CString cstr_Price_Sell_5=_T("");
	GetDlgItemText(IDC_EPRICE_SELL_5,cstr_Price_Sell_5);
	f_Price_Sell_5=GetFloatValueFromCString(cstr_Price_Sell_5);
	//��ȡ�����������������
	float f_Num_Sell_5=0;
	CString cstr_Num_Sell_5=_T("");
	GetDlgItemText(IDC_ENUM_SELL_5,cstr_Num_Sell_5);
	f_Num_Sell_5=GetFloatValueFromCString(cstr_Num_Sell_5);

	//�������������
	float f_result_out_GP=0;//�����Ʊ֧��
	float f_result_out_SXF=0;//��������֧��
	float f_result_out_ALL=0;//��֧��
	float f_result_in_ALL=0;//Ŀǰ������
	float f_result_in_PROFITS=0;//Ŀǰ������
	float f_result_NUM=0;//ʣ���Ʊ����
	float f_result_PRICE=0;//ʣ���Ʊ��������������۸�

	//������ʱ����
	CString cstr_temp=_T("");

	//����������ݵĺϷ���
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
	);//���ݺϷ�
	else if(f_Num_Buy_1+f_Num_Buy_2+f_Num_Buy_3+f_Num_Buy_4+f_Num_Buy_5-f_Num_Sell_1-f_Num_Sell_2-f_Num_Sell_3-f_Num_Sell_4-f_Num_Sell_5<0)//�������ܹ�������������ܹ���
	{
		AfxMessageBox(_T("�������ܹ�������������ܹ����������¼�����������"),MB_OK,NULL);
		return;
	}
	else//���ݲ��Ϸ�
	{
		AfxMessageBox(_T("��������ݸ�ʽ���������¼�����������"),MB_OK,NULL);
		return;
	}

	//��ϸ����
	//���������Ʊ֧��
	f_result_out_GP=f_Price_Buy_1*f_Num_Buy_1+f_Price_Buy_2*f_Num_Buy_2+f_Price_Buy_3*f_Num_Buy_3+f_Price_Buy_4*f_Num_Buy_4+f_Price_Buy_5*f_Num_Buy_5;
	cstr_temp.Format(_T("%.2f"),f_result_out_GP);
	SetDlgItemText(IDC_ERESULT_OUT_GP,cstr_temp);//���������Ʊ֧�����
	//����Ŀǰ������
	f_result_in_ALL=f_Price_Sell_1*f_Num_Sell_1+f_Price_Sell_2*f_Num_Sell_2+f_Price_Sell_3*f_Num_Sell_3+f_Price_Sell_4*f_Num_Sell_4+f_Price_Sell_5*f_Num_Sell_5;
	cstr_temp.Format(_T("%.2f"),f_result_in_ALL);
	SetDlgItemText(IDC_ERESULT_IN_ALL,cstr_temp);//����Ŀǰ��������
	//����ʣ���Ʊ����
	f_result_NUM=f_Num_Buy_1+f_Num_Buy_2+f_Num_Buy_3+f_Num_Buy_4+f_Num_Buy_5-f_Num_Sell_1-f_Num_Sell_2-f_Num_Sell_3-f_Num_Sell_4-f_Num_Sell_5;
	cstr_temp.Format(_T("%.0f"),f_result_NUM);
	SetDlgItemText(IDC_ERESULT_NUM,cstr_temp);//����ʣ���Ʊ�������
	//������������֧��
	//�������
	float f_result_YHS=0;//ӡ��˰
	float f_result_GHF=0;//������
	float f_result_YJ=0;//ȯ�̽���Ӷ��
	float f_result_TXF=0;//���ͨѶ��
	//����ӡ��˰
	f_result_YHS=f_result_in_ALL*f_YHS*0.001;
	//���������
	if(DisableGHF==false)//δ����
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
	//����ȯ�̽���Ӷ��
	if(DisableYJ==false)//δ����
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
	//�������ͨѶ��
	f_result_TXF=(f_result_out_GP+f_result_in_ALL)*f_TXF*0.001;
	//������������֧��
	f_result_out_SXF=f_result_YHS+f_result_GHF+f_result_YJ+f_result_TXF+f_result_out_GP*f_Self_Buy*0.001+f_result_in_ALL*f_Self_Sell*0.001+(f_result_out_GP+f_result_in_ALL)*f_Self_BuySell*0.001;
	cstr_temp.Format(_T("%.2f"),f_result_out_SXF);
	SetDlgItemText(IDC_ERESULT_OUT_SXF,cstr_temp);//������������֧�����
	//������֧��
	f_result_out_ALL=f_result_out_GP+f_result_out_SXF;
	cstr_temp.Format(_T("%.2f"),f_result_out_ALL);
	SetDlgItemText(IDC_ERESULT_OUT_ALL,cstr_temp);//������֧�����
	//����Ŀǰ������
	f_result_in_PROFITS=f_result_in_ALL-f_result_out_ALL;
	cstr_temp.Format(_T("%.2f"),f_result_in_PROFITS);
	SetDlgItemText(IDC_ERESULT_IN_PROFITS,cstr_temp);//����Ŀǰ��������
	//����ʣ���Ʊ��������������۸�
	if(f_result_NUM==0)//��Ʊ�Ѿ�ȫ������
	{
		SetDlgItemText(IDC_ERESULT_PRICE,_T("0"));//����ʣ���Ʊ��������������۸���
		return;
	}
	//�������
	float f_temp_GHF=0;//������
	//���������
	if(DisableGHF==false)//δ����
	{
		if(f_result_NUM==0)                         f_temp_GHF=0;
		    else if(f_result_NUM<1000)              f_temp_GHF=f_GHF;
		    else if((int)f_result_NUM%1000==0)      f_temp_GHF=((int)f_result_NUM/1000)*f_GHF;
		    else                                    f_temp_GHF=((int)f_result_NUM/1000+1)*f_GHF;
	}
	f_result_PRICE=(f_temp_GHF-f_result_in_PROFITS)/(1-f_YHS*0.001-f_YJ*0.001-f_TXF*0.001-f_Self_Sell*0.001-f_Self_BuySell*0.001)/f_result_NUM;
	if(f_result_PRICE*f_result_NUM>=3)//ȯ�̽���Ӷ����֤
	{
		cstr_temp.Format(_T("%.2f"),f_result_PRICE);
	    SetDlgItemText(IDC_ERESULT_PRICE,cstr_temp);//����ʣ���Ʊ��������������۸���
		return;
	}
	else//ȯ�̽���Ӷ�𲻷������������¼���
	{
		f_result_PRICE=(f_temp_GHF+3-f_result_in_PROFITS)/(1-f_YHS*0.001-f_TXF*0.001-f_Self_Sell*0.001-f_Self_BuySell*0.001)/f_result_NUM;
		if(f_result_PRICE*f_result_NUM<3)//ȯ�̽���Ӷ����֤
		{
			cstr_temp.Format(_T("%.2f"),f_result_PRICE);
	        SetDlgItemText(IDC_ERESULT_PRICE,cstr_temp);//����ʣ���Ʊ��������������۸���
		    return;
		}
		else//�޷��������Ľ��
		{
	        SetDlgItemText(IDC_ERESULT_PRICE,_T("��"));//����ʣ���Ʊ��������������۸���
		    return;
		}
	}
}


void CSharesCalculatorDlg::OnBnClickedBreset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//���ù�Ʊ����Ϊ���ڹ�Ʊ(��)
	CButton* button=(CButton*)GetDlgItem(IDC_RSHARETYPE_S);
    button->SetCheck(TRUE);
	button=(CButton*)GetDlgItem(IDC_RSHARETYPE_H);
    button->SetCheck(FALSE);

	//���ñ�׼������
	OnBnClickedRsharetype();

	//���ñ�׼�����ѽ���ģʽ
	button=(CButton*)GetDlgItem(IDC_CDISABLE_YHS);
    button->SetCheck(FALSE);//����ӡ��˰����ģʽΪ�ǽ���
	button=(CButton*)GetDlgItem(IDC_CDISABLE_GHF);
    button->SetCheck(FALSE);//���ù����ѽ���ģʽΪ�ǽ���
	button=(CButton*)GetDlgItem(IDC_CDISABLE_YJ);
    button->SetCheck(FALSE);//����ȯ�̽���Ӷ�����ģʽΪ�ǽ���
	button=(CButton*)GetDlgItem(IDC_CDISABLE_TXF);
    button->SetCheck(TRUE);//�������ͨѶ�ѽ���ģʽΪ����
	OnBnClickedCdisableYhs();
	OnBnClickedCdisableGhf();
	OnBnClickedCdisableYj();
	OnBnClickedCdisableTxf();


	//�����Զ���������
	SetDlgItemText(IDC_ESELF_BUY,_T("0"));//���ý�������ȡΪ0��
	SetDlgItemText(IDC_ESELF_SELL,_T("0"));//���ý�������ȡΪ0��
	SetDlgItemText(IDC_ESELF_BUYSELL,_T("0"));//����������������ȡΪ0��

	//����������������
	SetDlgItemText(IDC_EPRICE_BUY_1,_T("0"));//���õ�һ�����뵥��Ϊ0Ԫ/��
	SetDlgItemText(IDC_ENUM_BUY_1,_T("0"));//���õ�һ����������Ϊ0��
	SetDlgItemText(IDC_EPRICE_BUY_2,_T("0"));//���õڶ������뵥��Ϊ0Ԫ/��
	SetDlgItemText(IDC_ENUM_BUY_2,_T("0"));//���õڶ�����������Ϊ0��
	SetDlgItemText(IDC_EPRICE_BUY_3,_T("0"));//���õ��������뵥��Ϊ0Ԫ/��
	SetDlgItemText(IDC_ENUM_BUY_3,_T("0"));//���õ�������������Ϊ0��
	SetDlgItemText(IDC_EPRICE_BUY_4,_T("0"));//���õ��Ĵ����뵥��Ϊ0Ԫ/��
	SetDlgItemText(IDC_ENUM_BUY_4,_T("0"));//���õ��Ĵ���������Ϊ0��
	SetDlgItemText(IDC_EPRICE_BUY_5,_T("0"));//���õ�������뵥��Ϊ0Ԫ/��
	SetDlgItemText(IDC_ENUM_BUY_5,_T("0"));//���õ������������Ϊ0��
	SetDlgItemText(IDC_EPRICE_SELL_1,_T("0"));//���õ�һ����������Ϊ0Ԫ/��
	SetDlgItemText(IDC_ENUM_SELL_1,_T("0"));//���õ�һ����������Ϊ0��
	SetDlgItemText(IDC_EPRICE_SELL_2,_T("0"));//���õڶ�����������Ϊ0Ԫ/��
	SetDlgItemText(IDC_ENUM_SELL_2,_T("0"));//���õڶ�����������Ϊ0��
	SetDlgItemText(IDC_EPRICE_SELL_3,_T("0"));//���õ�������������Ϊ0Ԫ/��
	SetDlgItemText(IDC_ENUM_SELL_3,_T("0"));//���õ�������������Ϊ0��
	SetDlgItemText(IDC_EPRICE_SELL_4,_T("0"));//���õ��Ĵ���������Ϊ0Ԫ/��
	SetDlgItemText(IDC_ENUM_SELL_4,_T("0"));//���õ��Ĵ���������Ϊ0��
	SetDlgItemText(IDC_EPRICE_SELL_5,_T("0"));//���õ������������Ϊ0Ԫ/��
	SetDlgItemText(IDC_ENUM_SELL_5,_T("0"));//���õ������������Ϊ0��

	//���ü�����
	SetDlgItemText(IDC_ERESULT_OUT_GP,_T("0"));//���������Ʊ֧��Ϊ0Ԫ
	SetDlgItemText(IDC_ERESULT_OUT_SXF,_T("0"));//������������֧��Ϊ0Ԫ
	SetDlgItemText(IDC_ERESULT_OUT_ALL,_T("0"));//������֧��Ϊ0Ԫ
	SetDlgItemText(IDC_ERESULT_IN_ALL,_T("0"));//����Ŀǰ������Ϊ0Ԫ
	SetDlgItemText(IDC_ERESULT_IN_PROFITS,_T("0"));//����Ŀǰ������Ϊ0Ԫ
	SetDlgItemText(IDC_ERESULT_NUM,_T("0"));//����ʣ���Ʊ����Ϊ0��
	SetDlgItemText(IDC_ERESULT_PRICE,_T("0"));//����ʣ���Ʊ��������������۸�Ϊ0Ԫ
}


void CSharesCalculatorDlg::OnBnClickedBexit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}


void CSharesCalculatorDlg::OnBnClickedRsharetype()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	OnBnClickedCdisableYhs();
	OnBnClickedCdisableGhf();
	OnBnClickedCdisableYj();
	OnBnClickedCdisableTxf();
}


void CSharesCalculatorDlg::OnBnClickedBstandardYhs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxMessageBox(_T("ӡ��˰�շѱ�׼���ɽ�����1�롣���ڹ�Ʊ�Ϻ���Ʊ����ȡ��������ʱ��ȡ��"),MB_OK,NULL);
}


void CSharesCalculatorDlg::OnBnClickedBstandardGhf()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxMessageBox(_T("�������շѱ�׼��ÿ1000����ȡ0.3Ԫ������1000�ɰ�0.3Ԫ��ȡ�����Ϻ���Ʊ��ȡ����������ʱ����ȡ��"),MB_OK,NULL);
}


void CSharesCalculatorDlg::OnBnClickedBstandardYj()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxMessageBox(_T("ȯ�̽���Ӷ���շѱ�׼���ɽ�����0.3�룬���������ȡ��׼��3Ԫ�����ڹ�Ʊ�Ϻ���Ʊ����ȡ����������ʱ����ȡ��"),MB_OK,NULL);
}


void CSharesCalculatorDlg::OnBnClickedBstandardTxf()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxMessageBox(_T("���ͨѶ���շѱ�׼���ɸ�ȯ�����о����ղ��ա�"),MB_OK,NULL);
}


void CSharesCalculatorDlg::OnBnClickedCdisableYhs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if(DisableYHS==true)//����
	{
		SetDlgItemText(IDC_EYHS,_T("0"));//����ӡ��˰Ϊ0��
		CEdit *edit = (CEdit*)GetDlgItem(IDC_EYHS);
		edit->SetReadOnly(true);//����ӡ��˰�༭��Ϊֻ��
	}
	else if(DisableYHS==false)//�ǽ���
	{
		SetDlgItemText(IDC_EYHS,_T("1"));//����ӡ��˰Ϊ1��
		CEdit *edit = (CEdit*)GetDlgItem(IDC_EYHS);
		edit->SetReadOnly(false);//����ӡ��˰�༭��Ϊ��ֻ��
	}
	else//����
	{
		AfxMessageBox(_T("ӡ��˰����ģʽѡ������"),MB_OK,NULL);
	}
}


void CSharesCalculatorDlg::OnBnClickedCdisableGhf()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if(DisableGHF==true)//����
	{
		SetDlgItemText(IDC_EGHF,_T("0"));//���ù�����Ϊ0��
		CEdit *edit = (CEdit*)GetDlgItem(IDC_EGHF);
		edit->SetReadOnly(true);//���ù����ѱ༭��Ϊֻ��
	}
	else if(DisableGHF==false)//�ǽ���
	{
		if(ShareType==0)             SetDlgItemText(IDC_EGHF,_T("0"));//���ڹ�Ʊ(��)���ù�����Ϊ0��
		    else if(ShareType==1)    SetDlgItemText(IDC_EGHF,_T("0.3"));//�Ϻ���Ʊ(��)���ù�����Ϊ0.3��
		CEdit *edit = (CEdit*)GetDlgItem(IDC_EGHF);
		edit->SetReadOnly(false);//���ù����ѱ༭��Ϊ��ֻ��
	}
	else//����
	{
		AfxMessageBox(_T("�����ѽ���ģʽѡ������"),MB_OK,NULL);
	}
}


void CSharesCalculatorDlg::OnBnClickedCdisableYj()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if(DisableYJ==true)//����
	{
		SetDlgItemText(IDC_EYJ,_T("0"));//����ȯ�̽���Ӷ��Ϊ0��
		CEdit *edit = (CEdit*)GetDlgItem(IDC_EYJ);
		edit->SetReadOnly(true);//����ȯ�̽���Ӷ��༭��Ϊֻ��
	}
	else if(DisableYJ==false)//�ǽ���
	{
		SetDlgItemText(IDC_EYJ,_T("0.3"));//����ȯ�̽���Ӷ��Ϊ0.3��
		CEdit *edit = (CEdit*)GetDlgItem(IDC_EYJ);
		edit->SetReadOnly(false);//����ȯ�̽���Ӷ��༭��Ϊ��ֻ��
	}
	else//����
	{
		AfxMessageBox(_T("ȯ�̽���Ӷ�����ģʽѡ������"),MB_OK,NULL);
	}
}


void CSharesCalculatorDlg::OnBnClickedCdisableTxf()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if(DisableTXF==true)//����
	{
		SetDlgItemText(IDC_ETXF,_T("0"));//�������ͨѶ��Ϊ0��
		CEdit *edit = (CEdit*)GetDlgItem(IDC_ETXF);
		edit->SetReadOnly(true);//�������ͨѶ�ѱ༭��Ϊֻ��
	}
	else if(DisableTXF==false)//�ǽ���
	{
		SetDlgItemText(IDC_ETXF,_T("0"));//�������ͨѶ��Ϊ0��
		CEdit *edit = (CEdit*)GetDlgItem(IDC_ETXF);
		edit->SetReadOnly(false);//�������ͨѶ�ѱ༭��Ϊ��ֻ��
	}
	else//����
	{
		AfxMessageBox(_T("���ͨѶ�ѽ���ģʽѡ������"),MB_OK,NULL);
	}
}


float CSharesCalculatorDlg::GetFloatValueFromCString(CString cstr)//�ӱ༭���ڵ�CString�ͱ����л�ȡת��float����ֵ
{
	const char* char_value=MyCStringToConstChar(cstr);
	int nLength=strlen(char_value);
	int point_flag=0;//С�����־λ
	float floatvalue=0;
	float point_rate=1;
	for(int i=0;i<nLength;i++)
	{
		if(i>6)//���ݹ���(��С����ռ1λ���7λ��)
		{
			//AfxMessageBox(_T("���ݹ��������¼�����������"),MB_OK,NULL);
			return -2;
		}
		if(char_value[i]>='0'&&char_value[i]<='9')//У�����ݸ�ʽ
		{
			if(point_flag==0)//Ŀǰ��С�������
			{
				floatvalue=floatvalue*10+(char_value[i]-'0');
			}
			else if(point_flag==1)//Ŀǰ��С�������
			{
				point_rate=point_rate*0.1;
				floatvalue=floatvalue+(char_value[i]-'0')*point_rate;
			}
		}
		else if(char_value[i]=='.')//����С����
		{
			if(point_flag==0)//Ŀǰ��С�������
			{
				point_flag=1;
			}
			else//Ŀǰ�Ѿ���С�������
			{
				//AfxMessageBox(_T("��������ݸ�ʽ���������¼�����������"),MB_OK,NULL);
			    return -1;
			}
		}
		else
		{
			//AfxMessageBox(_T("��������ݸ�ʽ���������¼�����������"),MB_OK,NULL);
			return -1;
		}
	}
	return floatvalue;
}