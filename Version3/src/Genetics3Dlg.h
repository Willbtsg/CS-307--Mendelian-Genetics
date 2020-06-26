/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: Genetics3Dlg.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 12/9/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
// Genetics3Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// CGenetics3Dlg dialog
class CGenetics3Dlg : public CDialogEx
{
// Construction
public:
	CGenetics3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_GENETICS3_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	CEdit m_fileEdit;
	CEdit m_GSBox;
	CEdit m_CNBox;
	CEdit m_ChromosomeBox;
	CEdit m_GenesBox;
	CEdit m_P1Geno;
	CEdit m_P2Geno;
	CEdit m_resultsBox;
	CEdit m_countBox;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CEdit m_outfileBox;
};
