/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Simulation.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "Simulation.h"
#include "SimModel.h"
#include "SimViewer.h"
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
//------------------------------------------------
void Simulation::initializeSimulation()
{
	int i;
	const char *filename; //used to hold user input

	string fileRequest = "Please input the name of the data file you would like to use.";

	SimViewer View; //instantiate a View object
	View.printMessage(fileRequest); //print fileRequest to the screen

	string input = View.returnText(); //store user input

	filename = input.data(); //copy user input into proper format

	GeneticsSimDataParser *Parser = GeneticsSimDataParser::getInstance(); //instantiate the Parser
	Parser->initDataFile(filename); //initialize the data file


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

//--------------------------------------
// starts timer and calls SimController
//--------------------------------------
void Simulation::runSimulation()
{
	srand((unsigned int)(time(NULL)));

	SimViewer View;

	View.printMessage("Running Simulation...");
	View.printMessage("\n");

	SimController Control;

	Control.manageSim();

	return;
}