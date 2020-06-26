/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: SimController.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
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

	SimModel* Model = SimModel::getInstance(); //retrieves instance of SimModel
	string MGName; //holds name from MasterGene
	string MGDom; //holds dominant appearance from MasterGene
	string MGRec; //holds recessive appearance from MasterGene

	SimViewer View; //instantiate a View object
	View.printMessage("Master Genes:");

	for (i = 0; i < Model->getMGListSize(); i++) //goes thorugh every member of MGList
	{
		MGName = "	Trait Name: ";
		MGName = MGName + Model->getMGName(i); //retrieves trait name from MasterGene item
		View.printMessage(MGName);

		MGDom = "		Dominant Name: ";
		MGDom = MGDom + Model->getMGDom(i); //retrieves name of dominant trait and its symbol from MasterGene
		View.printMessage(MGDom);

		MGRec = "		Recessive Name: ";
		MGRec = MGRec + Model->getMGRec(i); //retrieves name of recessive trait and its symbol from MasterGene
		View.printMessage(MGRec);
	}

	View.printMessage("\n");

	string ParentNum; //holds name and number of Parent organism
	string ParentSci; //holds Parent's scientific name
	string ParentCom; //holds Parent's common name
	string GeneName; //holds name of trait controlled by Gene
	string GeneAlleles; //holds alleles contained within Gene

	for (i = 0; i < Model->getParentListSize(); i++) //go to each Parent object within SimModel
	{ 
		ParentNum = "Sim Parent " + to_string(i + 1); //retrieve and output Parent number
		View.printMessage(ParentNum);

		ParentSci = "	Organism genus-species: ";
		ParentSci = ParentSci + Model->getParentSciName(i); //retrieve and output scientific name
		View.printMessage(ParentSci);

		ParentCom = "	Common name: ";
		ParentCom = ParentCom + Model->getParentComName(i); //retrieve and output common name
		View.printMessage(ParentCom);

		View.printMessage("	Genes:");
		for (j = 0; j < Model->getParentGeneListSize(i); j++) //go to each Gene object within Parent
		{
			GeneName = "		Gene type = ";
			GeneName = GeneName + Model->getParentGeneName(i, j); //retrieve and output which trait the Gene controls
			View.printMessage(GeneName);

			GeneAlleles = "			Genotype = ";
			GeneAlleles = GeneAlleles + Model->getParentAlleles(i, j); //retrieve and output the Gene's alleles
			View.printMessage(GeneAlleles);
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
		Model->crossPollinate();
	}

	View.printMessage("\n");
	View.printMessage("======================= Results of this Run =======================");
	View.printMessage("");

	for (i = 0; i < Model->getMGListSize(); i++)
	{
		GeneName = "Gene: ";
		GeneName = GeneName + Model->getMGName(i); //retrieve and output which trait the Gene controls
		View.printMessage(GeneName);

		for (j = 0; j < 3; j++)
		{
			View.printMessage(Model->passTraitCount(i, j)); //retrieve and output count for given trait and genotype
		}

		View.printMessage("");
	}

	View.printMessage("Press any key to view the extra credit portion of the assignment.");
	system("pause");

	View.printMessage("");
	View.printMessage("			*==============*");
	View.printMessage("			* Extra Credit *");
	View.printMessage("			*==============*");
	View.printMessage("");
	View.printMessage("	All occurring genotypes with the count of each.");
	View.printMessage("");

	Model->setGenoStatsItr(); //sets iterator to beginning of genotypeStats map within Model

	for (i = 0; i < Model->getGenoStatsSize(); i++) //for every item in the genotypeStats map...
	{
		View.printMessage(Model->passGenotypeCount()); //print its information
	}

	View.printMessage("");

	return;
}