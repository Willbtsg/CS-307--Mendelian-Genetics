/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: SimController.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
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

