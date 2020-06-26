/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: SimController.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#pragma once

#include "SimViewer.h"
#include "SimModel.h"
#include "Simulation.h"

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

	void manageSim(); //makes sure simulation runs correctly once it has been initialized
};

