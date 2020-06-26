/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: SimController.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "SimController.h"
#include "Simulation.h"
#include "SimViewer.h"
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

//---------------------------------------------------
// controls simulation once it has been initialized
//---------------------------------------------------
void SimController::manageSim()
{
	int i;
	int j;
	int k;

	SimModel* Model = SimModel::getInstance(); //retrieves instance of SimModel
	string MGName; //holds name from MasterGene
	string MGDom; //holds dominant appearance from MasterGene
	string MGRec; //holds recessive appearance from MasterGene
	string MGCross; //holds crossover chance from MasterGene
	string copy; //used as middleman to shorten crossover double to two decimal places

	SimViewer View; //instantiate a View object
	View.printMessage("		Master Genes:");

	for (i = 0; i < Model->getMGListSize(); i++) //goes thorugh every member of MGList
	{
		MGName = "	Trait Name: ";
		MGName += Model->getMGName(i); //retrieves trait name from MasterGene item
		View.printMessage(MGName);

		MGDom = "		Dominant Name: ";
		MGDom += Model->getMGDom(i); //retrieves name of dominant trait and its symbol from MasterGene
		View.printMessage(MGDom);

		MGRec = "		Recessive Name: ";
		MGRec += Model->getMGRec(i); //retrieves name of recessive trait and its symbol from MasterGene
		View.printMessage(MGRec);

		MGCross = "		Chance of crossover: ";
		copy = Model->getMGCross(i); //retrives crossover chance from MasterGene
		for (j = 0; j < 4; j++)
		{
			MGCross += copy[j]; //adds double result of getMGCross to MGCross out to two decimal palces
		}
		View.printMessage(MGCross);
	}

	View.printMessage("\n");
	
	string ParentNum; //holds name and number of Parent organism
	string ParentSci; //holds Parent's scientific name
	string ParentCom; //holds Parent's common name
	string ChromosomeNum; //holds which number Chromosome is currently being used
	string GeneName; //holds name of trait controlled by Gene
	string AlleleInfo; //holds allele and trait information

	for (i = 0; i < Model->getParentListSize(); i++) //go to each Parent object within SimModel
	{ 
		ParentNum = "Sim Parent " + to_string(i + 1); //retrieve and output Parent number
		View.printMessage(ParentNum);

		ParentSci = "	Organism genus-species: ";
		ParentSci += Model->getParentSciName(i); //retrieve and output scientific name
		View.printMessage(ParentSci);

		View.printMessage("	Chromosomes:");
		for (j = 0; j < Model->getParentChromosomeListSize(i); j++) //go to each Gene object within Parent
		{
			ChromosomeNum = "		Chromosome " + to_string(j + 1) + ":";
			View.printMessage(ChromosomeNum);
			for (k = 0; k < Model->getChromosomeGeneListSize(i, j); k++)
			{
				GeneName = "			Gene Type: ";
				GeneName += Model->getParentGeneName(i, j, k); //retrieve and output which trait the Gene controls
				View.printMessage(GeneName);

				AlleleInfo = Model->getAlleleInfo(i, j, k); //retrieve and output the Gene's alleles
				View.printMessage(AlleleInfo);
			}
		}
		View.printMessage("");
	}
	
	int desired = 0; //will contain desired number of Offspring genotypes

	do {

		View.printMessage("How many offspring do you want to generate? (Type a number between 1 and 1000 then press Enter)");
		View.returnNumber(&desired);

		if (desired < 1 || desired > 1000) //prompts user to try again if input is not between 1 and 1000
		{
			View.printMessage("Number does not fall within the acceptable range. Please try again."); //loops until desired is between 1 and 1000
		}

	} while (desired < 1 || desired > 1000);


	for (i = 0; i < desired; i++) //make the desired number Offspring genotypes
	{
		Model->reproduce();
	}
	
	View.printMessage("\n");
	View.printMessage("======================= Results of this Run =======================");
	View.printMessage("");

	for (i = 0; i < Model->getMGListSize(); i++)
	{
		GeneName = "Gene: ";
		GeneName = GeneName + Model->getMGName(Model->getMGCOrder(i)); //retrieve and output which trait the Gene controls
		View.printMessage(GeneName);

		for (j = 0; j < 3; j++)
		{
			View.printMessage(Model->passTraitCount(i, j)); //retrieve and output count for given trait and genotype
		}

		View.printMessage("");
	}

	View.printMessage("");

	string showCross = "A total of ";
	showCross += to_string(Model->getCrossCount()); //retrieve the number of organisms that had at least one genetic crossover
	showCross += " offspring had at least one crossover gene.";

	View.printMessage(showCross);

	return;
}