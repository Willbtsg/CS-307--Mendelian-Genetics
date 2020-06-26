/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: Simulation.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 12/9/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "stdafx.h"
#include "Simulation.h"
#include "SimModel.h"
#include "SimController.h"
#include "GeneticsSimDataParser.h"
#include "GeneFactory.h"
#include "ParentFactory.h"

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
Simulation::Simulation()
{

}

//-----------------------------------
// Destructor
//-----------------------------------
Simulation::~Simulation()
{

}

//------------------------------------------------
// creates SimModel and uses Parser 
// to create necessary objects within the Model 
//
// Arguments:
//
// fileName- name of the data file to be used
//------------------------------------------------
void Simulation::initializeSimulation(const char *fileName)
{
	int i;
	
	GeneticsSimDataParser *Parser = GeneticsSimDataParser::getInstance(); //instantiate the Parser
	Parser->initDataFile(fileName); //initialize the data file


	SimModel* Model = SimModel::getInstance(); //gets instance of SimModel
	GeneFactory* GFactory = GeneFactory::getInstance();


	for (i = 0; i < Parser->getGeneCount(); i++) //until Parser runs out of gene data...
	{
		Model->addMG(GFactory->createMasterGene()); //create a new MasterGene and add it to the Model
	}
		

	ParentFactory* PFactory = ParentFactory::getInstance(); //gets instance of ParentFactory

	for (i = 0; i < 2; i++)
	{
		Model->addParent(PFactory->createParent(i)); //create both of the Parent objects using the ParentFactory and store them in Model
	}

	Model->setMGCOrder(); //set MGCOrder so MGList data can be retrieved in the proper order later

	return;
}

//----------------------------------------------------------
// starts timer and calls SimController
// returns CString containing results of simulation
//
// Arguments:
//
// offspring- number of offspring the user wants to create
//----------------------------------------------------------
CString Simulation::runSimulation(int offspring)
{
	srand((unsigned int)(time(NULL)));

	SimController Control;

	return Control.manageSimulation(offspring);
}