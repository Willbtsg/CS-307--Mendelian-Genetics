/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: Genetics3Dlg.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 12/9/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
/*******************************************************************
*	This program was modified post-submission on 6/26/2020 to
*	fix errors present in the release version of the executable.
*******************************************************************/
// Genetics3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Genetics3.h"
#include "Genetics3Dlg.h"
#include "afxdialogex.h"
#include "Simulation.h"
#include "SimModel.h"
#include "SimController.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGenetics3Dlg dialog



CGenetics3Dlg::CGenetics3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGenetics3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGenetics3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_fileEdit);
	DDX_Control(pDX, IDC_EDIT2, m_GSBox);
	DDX_Control(pDX, IDC_EDIT3, m_CNBox);
	DDX_Control(pDX, IDC_EDIT4, m_ChromosomeBox);
	DDX_Control(pDX, IDC_EDIT5, m_GenesBox);
	DDX_Control(pDX, IDC_EDIT6, m_P1Geno);
	DDX_Control(pDX, IDC_EDIT7, m_P2Geno);
	DDX_Control(pDX, IDC_EDIT10, m_resultsBox);
	DDX_Control(pDX, IDC_EDIT8, m_countBox);
	DDX_Control(pDX, IDC_EDIT9, m_outfileBox);
}

int clickCount = 0; //counts number of times the Initialize Simulation button is clicked

BEGIN_MESSAGE_MAP(CGenetics3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CGenetics3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CGenetics3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CGenetics3Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CGenetics3Dlg message handlers

BOOL CGenetics3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	SetWindowText("Mendelian Genetics Simulator (By Will Thomason)");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGenetics3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGenetics3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGenetics3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGenetics3Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	if (clickCount < 1) //ensures that Simulation does not get initialized more than once
	{
		int i;
		int j;
		int k;
		Simulation Sim;
		SimModel* Model = SimModel::getInstance();
		SimController Control;

		const char *fileName;

		CString input;
		m_fileEdit.GetWindowText(input); //retrieves user input for source file

		fileName = (LPCTSTR)input;

		Sim.initializeSimulation(fileName); //intialize the simulation using the file
	
		m_GSBox.SetWindowTextA(Model->getParentSciName(0).c_str());
		m_CNBox.SetWindowTextA(Model->getParentComName(0).c_str());
		m_ChromosomeBox.SetWindowTextA(to_string(Model->getParentChromosomeListSize(0)).c_str());

		m_GenesBox.SetWindowTextA("");

		CString chOutput = "";
		CString p1Output = "";
		CString p2Output = "";
		string number;
		CString copy;
		int geneNum = 0;

		for (i = 0; i < Model->getParentChromosomeListSize(0); i++) //go to each Gene object within Parent
		{
			number = to_string(i + 1);
			chOutput += "Chromosome ";
			chOutput += number.c_str();
			chOutput += ":\r\n";
		
			for (j = 0; j < Model->getChromosomeGeneListSize(0, i); j++)
			{
				chOutput += "  Trait Name: ";
				chOutput += Model->getMGName(Model->getMGCOrder(j + geneNum)).c_str(); //retrieves trait name from MasterGene item
				chOutput += "\r\n";

				chOutput += "    Dominant Name: ";
				chOutput += Model->getMGDom(Model->getMGCOrder(j + geneNum)).c_str(); //retrieves name of dominant trait and its symbol from MasterGene
				chOutput += "\r\n";

				chOutput += "    Recessive Name: ";
				chOutput += Model->getMGRec(Model->getMGCOrder(j + geneNum)).c_str(); //retrieves name of recessive trait and its symbol from MasterGene
				chOutput += "\r\n";

				chOutput += "    Chance of crossover: ";
				copy = Model->getMGCross(Model->getMGCOrder(j + geneNum)).c_str(); //retrives crossover chance from MasterGene
				for (k = 0; k < 4; k++)
				{
					chOutput += copy[k]; //adds double result of getMGCross to MGCross out to two decimal palces
				}
			
				chOutput += "\r\n\r\n";

			}
		
			geneNum += j;
			m_GenesBox.SetWindowTextA(chOutput);
		}

	
		for (i = 0; i < Model->getParentListSize(); i++) //go to each Parent object within SimModel
		{ 
			for (j = 0; j < Model->getParentChromosomeListSize(i); j++) //go to each Gene object within Parent
			{
				for (k = 0; k < Model->getChromosomeGeneListSize(i, j); k++)
				{
					if (i == 0)
					{
						p1Output += Model->getAlleleInfo(i, j, k).c_str(); //retrieve and output the Gene's alleles
					}
					else
					{
						p2Output += Model->getAlleleInfo(i, j, k).c_str();
					}
				}
			}
		}

		m_P1Geno.SetWindowTextA(p1Output);
		m_P2Geno.SetWindowTextA(p2Output);
		clickCount++;
	}


}


void CGenetics3Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	Simulation Sim;

	CString offspring;
	CString results;

	m_countBox.GetWindowTextA(offspring);

	int pass = atoi(offspring);

	m_resultsBox.SetWindowTextA(Sim.runSimulation(pass));
}


void CGenetics3Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	ofstream outFile;
	CString fileName;
	CString output;

	m_outfileBox.GetWindowTextA(fileName);
	outFile.open(fileName);

	m_resultsBox.GetWindowTextA(output);
	outFile << output;

	outFile.close();
}
