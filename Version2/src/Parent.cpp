/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Parent.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#pragma warning(disable:4996)
#include "Parent.h"
#include "Gene.h"

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
Parent::Parent()
{
	//initialize all objects
	char scientificName[32] = "";
	char commonName[32] = "";
}

//-----------------------------------
// Destructor
//-----------------------------------
Parent::~Parent()
{

}

//--------------------------------------------------
// set scientific name
//
// Argument:
//
// *sciName- pointer to character array containing
// the scientific name
//
//--------------------------------------------------
void Parent::setScientificName(char *sciName)
{
	strcpy(scientificName, sciName);

	return;
}

//--------------------------------------------------
// set common name
//
// Argument:
//
// *comName- pointer to character array containing
// the common name
//
//--------------------------------------------------
void Parent::setCommonName(char *comName)
{
	strcpy(commonName, comName);

	return;
}

//-----------------------------------
// returns scientific name
//-----------------------------------
string Parent::getScientificName()
{
	return scientificName;
}

//-----------------------------------
// returns common name
//-----------------------------------
string Parent::getCommonName()
{
	return commonName;
}

//-----------------------------------------------------------------
// adds Chromosome to ChromosomeList
//
// Argument:
// 
// newChromosome- Chromosome object to be added to ChromosomeList
//
//-----------------------------------------------------------------
void Parent::addChromosome(Chromosome *newChromosome)
{
	ChromosomeList.push_back(*newChromosome);

	return;
}

//----------------------------------------------------------------
// returns allele from Gene
//
// Argument: 
//
// chromosomeNum- index of Parent's ChromosomeList to use
// strandNum- which strand in the Chromosome to use
// geneNum- index of Chromosome's GeneList to get an allele from
// crossCheck- pointer to a bool set to true if a crossover occurs
//
//----------------------------------------------------------------
char Parent::passGene(int chromosomeNum, int strandNum, int geneNum, bool *crossCheck)
{
	return ChromosomeList[chromosomeNum].getAllele(strandNum, geneNum, crossCheck);
}


//-----------------------------------
// returns size of ChromosomeList
//-----------------------------------
int Parent::getChromosomeListSize()
{
	return ChromosomeList.size();
}

//--------------------------------------------------------------
// gets name of trait that a Gene controls
//
// Argument:
//
// chromosomNum- which index of the ChromosomeList to check
// geneNum- which index of the Chromosome's GeneList to check
//
//--------------------------------------------------------------
string Parent::getGeneName(int chromosomeNum, int geneNum)
{
	return ChromosomeList[chromosomeNum].passGeneName(geneNum);
}

//---------------------------------------------------------
// returns size of a Chromosome's GeneList
//
// Arguments:
//
// i- index of ChromosomeList to get the GeneList size of
//---------------------------------------------------------
int Parent::getGeneListSize(int i)
{
	return ChromosomeList[i].getGeneListSize();
}

//-------------------------------------------------------------------
// returns information about alleles from a Gene
//
// Arguments:
//
// chromosomeNum- which index of the ChromosomeList to use
// geneNum- which index of the Chromosome's GeneList to use
//
//-------------------------------------------------------------------
string Parent::getAlleleInfo(int chromosomeNum, int geneNum)
{
	return ChromosomeList[chromosomeNum].getAlleleInfo(geneNum);
}