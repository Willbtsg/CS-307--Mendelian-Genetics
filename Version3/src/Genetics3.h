/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: Genetics3.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 12/9/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
// Genetics3.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGenetics3App:
// See Genetics3.cpp for the implementation of this class
//

class CGenetics3App : public CWinApp
{
public:
	CGenetics3App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CGenetics3App theApp;