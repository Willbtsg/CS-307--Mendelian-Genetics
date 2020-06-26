/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Simulation.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of 
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "Simulation.h"
#include "SimModel.h"
#include "SimViewer.h"
#include "SimController.h"
#include "GeneticsSimDataParser.h"
#include "MasterGene.h"
#include "Parent.h"

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
	int j;
	const char *filename; //used to hold user input

	string fileRequest = "Please input the name of the data file you would like to use.";

	SimViewer View; //instantiate a View object
	View.printMessage(fileRequest); //print fileRequest to the screen

	string input = View.returnText(); //store user input

	filename = input.data(); //copy user input into proper format

	GeneticsSimDataParser Parser(filename); //instantiate the Parser


	char MGTrait[32]; //holds name for MasterGene
	char MGDomDesc[32]; //holds dominant description for MasterGene
	char MGDomSym; //holds dominant symbol for MasterGene
	char MGRecDesc[32]; //holds recessive description for MasterGene
	char MGRecSym; //holds recessive symbol for MasterGene
	
	MasterGene *MGItem; //instantiates a pointer to a MasterGene object

	SimModel* Model = SimModel::getInstance(); //gets instance of SimModel

	while (Parser.getGeneData(MGTrait, MGDomDesc, &MGDomSym, MGRecDesc, &MGRecSym) != false) //until Parser runs out of gene data...
	{
		MGItem = new MasterGene; //create new MasterGene object

		MGItem->setTrait(MGTrait); //set its name and other attributes
		MGItem->setDomDesc(MGDomDesc);
		MGItem->setDomSym(MGDomSym);
		MGItem->setRecDesc(MGRecDesc);
		MGItem->setRecSym(MGRecSym);

		Model->addMG(MGItem); //add MGItem to the vetor of MasterGenes within the Model
	}
		
	char ParentGeno[12]; //used to hold the genotype from Parser

	Parent *newParent; //pointer to Parent object
	Gene *newGene; //pointer to Gene object

	while (Parser.getParentGenotype(ParentGeno) != false) //until Parser runs out of Parent data...
	{
		newParent = new Parent; //create a new Parent object
		j = 0; //reset MasterGene iterator to zero

		newParent->setScientificName(Parser.getScientificName()); //set scientific name
		newParent->setCommonName(Parser.getCommonName()); //set common name
		newParent->setGenotype(ParentGeno); //set genotype

		for (i = 0; i < 12; i = i + 3) //until end of ParentGeno is reached...
		{
			newGene = new Gene; //create a new Gene object
			
			newGene->setAlleles(ParentGeno[i], ParentGeno[i + 1]); //get the alleles for the Gene from ParentGeno
			newGene->setMG(Model->getMG(j)); //assign the correct MasterGene to the Gene
			j++; //increment by one to get MasterGene object for next allele pair

			newParent->addGene(*newGene); //add newGene to vector inside of newParent
		}

	
		Model->addParent(*newParent); //add newParent object to vector inside of Model
	}


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