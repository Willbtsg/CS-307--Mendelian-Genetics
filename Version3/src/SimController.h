/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: SimController.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 12/9/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#pragma once

#include "SimModel.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>


using namespace std;

class SimController
{
public:
	SimController(void); //constructor
	~SimController(void); //destructor

	CString manageSimulation(int offspring); //makes sure simulation runs correctly once it has been initialized
};

