/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: SimController.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 12/9/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "stdafx.h"
#include "SimController.h"
#include "SimModel.h"


using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
SimController::SimController()
{

}

//-----------------------------------
// Destructor
//-----------------------------------
SimController::~SimController()
{

}

//----------------------------------------------------------
// controls simulation once it has been initialized
// returns CString containing results of genetic cross
//
// Arguments:
//
// offspring- number of offspring the user wants to create
//----------------------------------------------------------
CString SimController::manageSimulation(int offspring)
{
	int i;
	int j;
	SimModel *Model = SimModel::getInstance();

	do {

		if (offspring < 1 || offspring > 1000) //prompts user to try again if input is not between 1 and 1000
		{
			return "Number must be between 1 and 1000. Please try again.";
		}

	} while (offspring < 1 || offspring > 1000);

	Model->resetStats(); //ensures that each run of the simulation is unaffected by the previous one

	for (i = 0; i < offspring; i++) //make the desired number Offspring genotypes
	{
		Model->reproduce();
	}

	string output = "A total of ";
	output += to_string(Model->getCrossCount()); //retrieve the number of organisms that had at least one genetic crossover
	output += " offspring had at least one crossover gene.\r\n";

	for (i = 0; i < Model->getMGListSize(); i++)
	{
		output += "Gene: ";
		output += Model->getMGName(Model->getMGCOrder(i)) + "\r\n"; //retrieve and output which trait the Gene controls

		for (j = 0; j < 3; j++)
		{
			output += Model->passTraitCount(i, j) + "\r\n"; //retrieve and output count for given trait and genotype
		}
	}

	output += "\r\n";

	return output.c_str();
}