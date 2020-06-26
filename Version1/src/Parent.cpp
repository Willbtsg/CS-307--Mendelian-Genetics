/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Parent.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
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
	char genotype[12] = "";
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

//--------------------------------------------------
// set genotype
//
// Argument:
//
// *newGeno- pointer to character array containing
// the genotype
//
//--------------------------------------------------
void Parent::setGenotype(char *newGeno)
{
	strcpy(genotype, newGeno);

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

//-----------------------------------------------
// adds Gene to GeneList
//
// Argument:
// 
// newGene- Gene object to be added to GeneList
//
//-----------------------------------------------
void Parent::addGene(Gene newGene)
{
	GeneList.push_back(newGene);

	return;
}

//---------------------------------------------------
// returns allele from Gene
//
// Argument: 
//
// geneNum- index of GeneList to get an allele from
//
//---------------------------------------------------
char Parent::passGene(int geneNum)
{
	return GeneList[geneNum].getAllele();
}

//-------------------------------------------
// returns both alleles from a Gene
//
// Argument:
//
// i- index of GeneList to get alleles from
//
//-------------------------------------------
string Parent::getAlleles(int i)
{
	return GeneList[i].getBoth();
}

//-----------------------------------
// returns size of GeneList
//-----------------------------------
int Parent::getGeneListSize()
{
	return GeneList.size();
}

//------------------------------------------
// gets name of trait that a Gene controls
//
// Argument:
//
// i- index of GeneList to get trait from
//
//------------------------------------------
string Parent::getGeneName(int i)
{
	return GeneList[i].passName();
}