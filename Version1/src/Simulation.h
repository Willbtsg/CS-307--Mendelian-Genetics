/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Simulation.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
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

	void initializeSimulation(); //creates objects needed to run the simulation
	void runSimulation(); //starts a timer and calls the SimController
};

