/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Main.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "Simulation.h"

using namespace std;

int main(void)
{

	Simulation Genetics; //instantiate a simulation object
	
	Genetics.initializeSimulation(); //set up the simulation
	Genetics.runSimulation(); //run the simulation

	system("pause");
	return 0;
}