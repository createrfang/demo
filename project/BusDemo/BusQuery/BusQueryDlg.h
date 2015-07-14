
// BusQueryDlg.h : header file
//

#pragma once

//-----------------------------------------------------
#include "dev\window\MainWindowT.h"

#include "BusEdit.h"
//-----------------------------------------------------

// CBusQueryDlg dialog
class CBusQueryDlg : public CDialogEx,
//-----------------------------------------------------
                     public MainWindowT<CBusQueryDlg, CBusEdit>
//-----------------------------------------------------
{
// Construction
public:
	CBusQueryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_BUSQUERY_DIALOG };

//------------------------------------------------------------
//------------------------------------------------------------


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnQuery();
};
