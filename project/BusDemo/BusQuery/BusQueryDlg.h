
// BusQueryDlg.h : header file
//

#pragma once

//-----------------------------------------------------
#include "BusEdit.h"
//-----------------------------------------------------

// CBusQueryDlg dialog
class CBusQueryDlg : public CDialogEx
{
// Construction
public:
	CBusQueryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_BUSQUERY_DIALOG };

//------------------------------------------------------------
    CBusEdit m_editStart;
    CBusEdit m_editEnd;
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
};
