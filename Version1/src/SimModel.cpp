/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: SimModel.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
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
	fill(&geneStats[0][0], &geneStats[0][0] + 4*3, 0); //set 2D array to zero
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

//--------------------------------------------------
// creates new array to be stored within Offspring
//--------------------------------------------------
void SimModel::crossPollinate()
{
	char alleles[12]; //create character array to store genotype

	int i = 0;
	int j = 0; //used to iterate through array of characters for genotype
	char pass1 = NULL; //stores Parent 1 allele
	char pass2 = NULL; //stores Parent 2 allele
	int compare;

	for (i = 0; i < 4; i++) //call all four genes from both parents
	{
		pass1 = ParentList[0].passGene(i); //get the allele letter from the first Parent

		compare = (int)pass1;
		if (compare >= 97) //if the letter is lower case...
		{
			alleles[j + 1] = pass1; //...put it in the second position for that gene...
			pass2 = ParentList[1].passGene(i);
			alleles[j] = pass2; //and put the allele from the other Parent in the first gene position, regardless of its case

			if (pass1 == pass2) //checks to see if the gene is homozygous
			{
				geneStats[i][2]++; //increment homozygous recessive
			}
			else
			{
				geneStats[i][1]++; //increment heterozygous
			}

		}
		else //if the letter is upper case...
		{
			alleles[j] = pass1; //..put it in the first position...
			pass2 = ParentList[1].passGene(i);
			alleles[j + 1] = pass2; //and store the otherr letter in the second position, regardless of case

			if (pass1 == pass2) //checks to see if the gene is homozygous
			{
				geneStats[i][0]++; //increment homozygous dominant
			}
			else
			{
				geneStats[i][1]++; //increment heterozygous
			}

		}

		alleles[j + 2] = ' '; //put a space between each allele pair

		j = j + 3; //set j to starting position for next pair of alleles
	}

	string mapString = ""; //string to hold genotype for genotypeStats

	for (i = 0; i < 12; i++) //for every character within alleles
	{
		mapString = mapString + alleles[i]; //put the character into the string
	
	}

	auto itr = genotypeStats.find(mapString); //have iterator find mapString within genotypeStats

	if (itr != genotypeStats.end())
	{
		genotypeStats[mapString]++; //increment the value of that key if it is found
	}
	else
	{
		genotypeStats.insert(pair<string, int>(mapString, 1)); //add mapString to the map with a value of 1 if it isn't already there
	}

	childList.addChild(alleles); //add child's genotype to vector within Offspring object

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

		appearance = MGList[gene].getDomDesc(); //gets physical description from MasterGene

		for (i = 0; i < 2; i++)
		{
			allelePair = allelePair + MGList[gene].getDomSym(); //gets appropriate allele combination from MasterGene
		}

		allelePair = allelePair + ")";

		break;

	case 1:
		genotype = " heterozygous (";

		appearance = MGList[gene].getDomDesc();

		allelePair = allelePair + MGList[gene].getDomSym() + MGList[gene].getRecSym();

		allelePair = allelePair + ")";

		break;

	case 2:
		genotype = " homozygous recessive (";

		appearance = MGList[gene].getRecDesc();

		for (i = 0; i < 2; i++)
		{
			allelePair = allelePair + MGList[gene].getRecSym();
		}

		allelePair = allelePair + ")";
		
		break;

	default:
		genotype = " invalid input received ";
	}

	output = "	" + to_string(count) + genotype + appearance + allelePair; //combines strings into a single one for output

	return output;
}

//---------------------------------------------------------------------------------
// returns string containing keyvalue and mapvalue for next item in genotypeStats
//---------------------------------------------------------------------------------
string SimModel::passGenotypeCount()
{
	int count = 0;
	string genotype = "";
	string output = "";

	genotype = "	Genotype = ";
	genotype = genotype + genotypeStatsItr->first; //puts keyvalue into genotype string
	genotype = genotype + "   Offspring count = ";
	
	count = genotypeStatsItr->second; //puts mapvalue into count int

	genotypeStatsItr++; //moves iterator to next item in map

	output = genotype + to_string(count); //combines genotype and count into one output string

	return output;
}
//-------------------------------------------------
// adds Parent object to ParentList vector
//
// Argument:
// 
// newParent- Parent object to be added to vector
//-------------------------------------------------
void SimModel::addParent(Parent newParent)
{
	ParentList.push_back(newParent);

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

//---------------------------------------
// returns pointer to MasterGene object 
// to be assigned to a Gene object
//
// Argument:
//
// i- index of item needed within MGList
//
//---------------------------------------
MasterGene* SimModel::getMG(int i)
{
	return &MGList[i];
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
string SimModel::getParentGeneName(int i, int j)
{
	return ParentList[i].getGeneName(j);
}

//-------------------------------------------------
// returns alleles from Gene within Parent object
//
// Arguments:
//
// i- index of item needed within ParentList
// j- index of item need within Parent's GeneList
//
//-------------------------------------------------
string SimModel::getParentAlleles(int i, int j)
{
	return ParentList[i].getAlleles(j);
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

//-------------------------------------------------
// returns size of GeneList within Parent object
//
// Arguments:
//
// i- index of item needed within ParentList
// j- index of item need within Parent's GeneList
//
//-------------------------------------------------
int SimModel::getParentGeneListSize(int i)
{
	return ParentList[i].getGeneListSize();
}

//-------------------------------------------------
// returns size of genotypeStats map
//-------------------------------------------------
int SimModel::getGenoStatsSize()
{
	return genotypeStats.size();
}

//-------------------------------------------------
// rsets iterator to begining of genotypeStats
//-------------------------------------------------
void SimModel::setGenoStatsItr()
{
	genotypeStatsItr = genotypeStats.begin();
}