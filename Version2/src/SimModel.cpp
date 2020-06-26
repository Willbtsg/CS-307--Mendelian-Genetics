/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: SimModel.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "SimModel.h"
#include "Gene.h"
#include"MasterGene.h"
#include "Parent.h"
#include "Offspring.h"

using namespace std;

SimModel* SimModel::instance = NULL; //sets instance to NULL until constructor getInstance is called for the first time

//-----------------------------------
// Constructor
//-----------------------------------
SimModel::SimModel()
{
	crossCount = 0; //set crossover counter to zero
	fill(&geneStats[0][0], &geneStats[0][0] + 10*3, 0); //set 2D array to zero

};

//-----------------------------------
// returns instance of SimModel
//-----------------------------------
SimModel* SimModel::getInstance()
{
	if (instance == NULL) //if no instance of SimModel exists...
	{ 
		instance = new SimModel(); //...create a new one
	}

	return instance;
}

//-----------------------------------
// Destructor
//-----------------------------------
SimModel::~SimModel()
{

}

//---------------------------------------------------
// creates new string to be stored within Offspring
//---------------------------------------------------
void SimModel::reproduce()
{
	char alleles[30]; //create character array to store genotype

	int i = 0;
	int j = 0;
	int k = 0;
	int geneNum = 0;
	char pass1 = NULL; //stores Parent 1 allele
	char pass2 = NULL; //stores Parent 2 allele
	int strandNumP1 = 0; //indicates which Chromosome strand should be used for first Parent
	int strandNumP2 = 0; //indicates which Chromosome strand should be used for second Parent
	bool crossCheck = false; //used to check for genetic crossover

	for (i = 0; i < ParentList[0].getChromosomeListSize(); i++) //for every Chromosome within the Parent
	{
		strandNumP1 = rand() % 2; //picks which strand the first Parent will draw from
		strandNumP2 = rand() % 2; //picks which strand the second Parent will draw from

		for (j = 0; j < ParentList[0].getGeneListSize(i); j++) //for every Gene within the Chromosome
		{
			pass1 = ParentList[0].passGene(i, strandNumP1, j, &crossCheck); //get the allele letter from the first Parent

			if ((int)pass1 >= 97) //if the letter is lower case...
			{
				alleles[k + 1] = pass1; //...put it in the second position for that gene...
				pass2 = ParentList[1].passGene(i, strandNumP2, j, &crossCheck);
				alleles[k] = pass2; //and put the allele from the other Parent in the first gene position, regardless of its case

				if (pass1 == pass2) //checks to see if the gene is homozygous
				{
					geneStats[geneNum + j][2]++; //increment homozygous recessive
				}
				else
				{
					geneStats[geneNum + j][1]++; //increment heterozygous
				}

			}
			else //if the letter is upper case...
			{
				alleles[k] = pass1; //..put it in the first position...
				pass2 = ParentList[1].passGene(i, strandNumP2, j, &crossCheck);
				alleles[k + 1] = pass2; //and store the otherr letter in the second position, regardless of case

				if (pass1 == pass2) //checks to see if the gene is homozygous
				{
					geneStats[geneNum + j][0]++; //increment homozygous dominant
				}
				else
				{
					geneStats[geneNum + j][1]++; //increment heterozygous
				}

			}

			alleles[k + 2] = ' '; //put a space between each allele pair

			k += 3; //set j to starting position for next pair of alleles
		}

		geneNum += ParentList[0].getGeneListSize(i); //makes sure proper geneStat index is called after gene loop counter gets set back to zero
	}

	if (crossCheck)
	{
		crossCount++; //if a crossover occurred anywhere for this new genotype, increment the crossover counter
	}

	childList.addChild(string(alleles)); //convert new genotype to a string and store it in the Offspring object

	return;
}

//---------------------------------------------------------------------
// returns value from geneStats
//
// Arguments:
//
// gene- which array's (gene's) value you want to check
// index- which value (genotype count) within array you want to check
//
//---------------------------------------------------------------------
string SimModel::passTraitCount(int gene, int index)
{
	int i;
	int count; //holds number from geneStats
	string genotype; //holds genotype description
	string appearance; //holds physical description
	string allelePair = " "; //holds allele pair
	string output; //holds combination of above strings for output


	count = geneStats[gene][index]; //get value from geneStats

	switch (index)
	{
	case 0:
		genotype = " homozygous dominant (";

		appearance = MGList[MGCOrder[gene]].getDomDesc(); //gets physical description from MasterGene

		for (i = 0; i < 2; i++)
		{
			allelePair = allelePair + MGList[MGCOrder[gene]].getDomSym(); //gets appropriate allele combination from MasterGene
		}

		allelePair = allelePair + ")";

		break;

	case 1:
		genotype = " heterozygous (";

		appearance = MGList[MGCOrder[gene]].getDomDesc();

		allelePair = allelePair + MGList[MGCOrder[gene]].getDomSym() + MGList[MGCOrder[gene]].getRecSym();

		allelePair = allelePair + ")";

		break;

	case 2:
		genotype = " homozygous recessive (";

		appearance = MGList[MGCOrder[gene]].getRecDesc();

		for (i = 0; i < 2; i++)
		{
			allelePair = allelePair + MGList[MGCOrder[gene]].getRecSym();
		}

		allelePair = allelePair + ")";
		
		break;

	default:
		genotype = " invalid input received ";
	}

	output = "	" + to_string(count) + genotype + appearance + allelePair; //combines strings into a single one for output

	return output;
}


//-------------------------------------------------
// adds Parent object to ParentList vector
//
// Argument:
// 
// newParent- Parent object to be added to vector
//-------------------------------------------------
void SimModel::addParent(Parent *newParent)
{
	ParentList.push_back(*newParent);

	return;
}

//------------------------------------------------------------
// adds MasterGene object to MGList vector
//
// Argument:
// 
// newMG- pointer to MasterGene object to be added to vector
//------------------------------------------------------------
void SimModel::addMG(MasterGene *newMG)
{
	MGList.push_back(*newMG);

	return;
}

//----------------------------------------------
// returns pointer to MasterGene object 
// to be assigned to a Gene object
//
// Argument:
//
// allele- domSym of desired MasterGene object
//
//----------------------------------------------
MasterGene* SimModel::getMG(char allele)
{
	for (int i = 0; getMGListSize(); i++)
	{
		if (allele == MGList[i].getDomSym())
		{
			return &MGList[i];
		}
	}

	return NULL;
}

//---------------------------------------
// returns name of MasterGene object
//
// Argument:
//
// i- index of item needed within MGList
//
//---------------------------------------
string SimModel::getMGName(int i)
{
	return MGList[i].getTrait();
}

//----------------------------------------------------
// returns dominant description of MasterGene object
//
// Argument:
//
// i- index of item needed within MGList
//
//----------------------------------------------------
string SimModel::getMGDom(int i)
{
	string attribute;
	char allele;

	attribute = MGList[i].getDomDesc() + "(";
	allele = MGList[i].getDomSym();

	return attribute + allele + ")";
}

//-----------------------------------------------------
// returns recessive description of MasterGene object
//
// Argument:
//
// i- index of item needed within MGList
//
//-----------------------------------------------------
string SimModel::getMGRec(int i)
{
	string attribute;
	char allele;

	attribute = MGList[i].getRecDesc() + "(";
	allele = MGList[i].getRecSym();

	return attribute + allele + ")";
}

//-----------------------------------------------------
// returns crossover chance of MasterGene object
//
// Argument:
//
// i- index of item needed within MGList
//
//-----------------------------------------------------
string SimModel::getMGCross(int i)
{
	return to_string(MGList[i].getCross());
}

//--------------------------------------------
// returns scientific name of Parent object
//
// Argument:
//
// i- index of item needed within ParentList
//
//--------------------------------------------
string SimModel::getParentSciName(int i)
{
	return ParentList[i].getScientificName();
}

//--------------------------------------------
// returns common name of Parent object
//
// Argument:
//
// i- index of item needed within ParentList
//
//--------------------------------------------
string SimModel::getParentComName(int i)
{
	return ParentList[i].getCommonName();
}

//--------------------------------------------------------
// returns trait controlled by Gene within Parent object
//
// Arguments:
//
// i- index of item needed within ParentList
// j- index of item need within Parent's GeneList
//
//--------------------------------------------------------
string SimModel::getParentGeneName(int i, int j, int k)
{
	return ParentList[i].getGeneName(j, k);
}

//-------------------------------------------------------------------
// returns information about alleles from a Gene
//
// Arguments:
//
// parentNum- which index of ParentList to use
// chromosomeNum- which index of the Parent's ChromosomeList to use
// geneNum- which index of the Chromosome's GeneList to use
//
//-------------------------------------------------------------------
string SimModel::getAlleleInfo(int parentNum, int chromosomeNum, int geneNum)
{
	return ParentList[parentNum].getAlleleInfo(chromosomeNum, geneNum);
}

//-------------------------------------------------
// returns size of MGList
//-------------------------------------------------
int SimModel::getMGListSize()
{
	return MGList.size();
}

//-------------------------------------------------
// returns size of ParentList
//-------------------------------------------------
int SimModel::getParentListSize()
{
	return ParentList.size();
}

//--------------------------------------------------------
// returns size of ChromosomeList within Parent object
//
// Arguments:
//
// i- index of item needed within ParentList
//
//-------------------------------------------------------
int SimModel::getParentChromosomeListSize(int i)
{
	return ParentList[i].getChromosomeListSize();
}

//--------------------------------------------------
// returns size of a Parent's Chromosome's GenList
//
// Arguments
//
// i- index of ParentList to use
// j- index of the Parent's ChromosomeList to use
//
//--------------------------------------------------
int SimModel::getChromosomeGeneListSize(int i, int j)
{
	return ParentList[i].getGeneListSize(j);
}

//--------------------------------------------------
// fills MGCOrder with indices for MGList items in 
// the order they appear in the Chromosome strands
//--------------------------------------------------
void SimModel::setMGCOrder()
{
	int i = 0;
	int j = 0;
	int k = 0;
	char check = NULL;
	int geneNum = 0;
	bool ignore; //this variable is only used to satisfy the argument requirements of Parent::passGene

	for (i = 0; i < ParentList[0].getChromosomeListSize(); i++)
	{
		for (j = 0; j < ParentList[0].getGeneListSize(i); j++)
		{
			check = toupper(ParentList[0].passGene(i, 0, j, &ignore));

			for (k = 0; getMGListSize(); k++)
			{
				if (check == MGList[k].getDomSym())
				{
					MGCOrder[geneNum + j] = k;
					break;
				}
			}
		}

		geneNum += j;
	}

	return;

}

//------------------------------------------------------
// returns the value of MGCOrder at the given index
//
// Arguments:
//
// i- index of MGCOrder to get a value for MGList from
//------------------------------------------------------
int SimModel::getMGCOrder(int i)
{
	return MGCOrder[i];
}

//------------------------------------------------------------------
// returns number of organisms with at least one genetic crossover
//------------------------------------------------------------------
int SimModel::getCrossCount()
{
	return crossCount;
}