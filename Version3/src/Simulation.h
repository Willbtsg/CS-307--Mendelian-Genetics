/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: Simulation.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 12/9/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#pragma once


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

#include <stdlib.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <time.h>

using namespace std;

class Simulation
{

public:
	Simulation(); //constructor
	~Simulation(); //destructor

	void initializeSimulation(const char *fileName); //creates objects needed to run the simulation
	CString runSimulation(int offspring); //starts a timer and calls the SimController
};

