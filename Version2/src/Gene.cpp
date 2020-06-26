/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Gene.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "Gene.h"
#include "MasterGene.h"

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
Gene::Gene()
{
	char alleles[2] = ""; //initialize array
}

//-----------------------------------
// Destructor
//-----------------------------------
Gene::~Gene()
{

}

//----------------------------------------------------
// sets pointer to appropriate MasterGene object
//
// Argument: 
//
// *master- pointer to appropriate MasterGene object
//
//----------------------------------------------------
void Gene::setMG(MasterGene *master)
{
	source = master;

	return;
}

//-----------------------------------
// sets alleles
//
// Arguments:
//
// pass1- first allele
// pass2- second allele
//
//-----------------------------------
void Gene::setAlleles(char pass1, char pass2)
{
	alleles[0] = pass1;
	alleles[1] = pass2;

	return;
}

//----------------------------------------------------------------------
//calculates if crossover occurs using the random number and returns 
// the allele opposite to the one passed in if a crossover takes place
//
// Arguments:
//
// allele- allele from the previously specified strand in Chromosome
// crossCheck- pointer to a bool set to true if a crossover occurs
//
//----------------------------------------------------------------------
char Gene::getAllele(char allele, bool *crossCheck)
{
	double cross;
	double decimal;

	cross = rand() % 100; //gets a number between 0 and 99
	decimal = rand() % 100; //gets a number between 0 and 99

	cross += decimal / 100; //uses decimal as the decimal value for crossover comparison

	if (cross <= source->getCross()) 
	{
		*crossCheck = true;
		if (allele == alleles[0])
		{
			allele = alleles[1];
		}
		else
		{
			allele = alleles[0];
		}
	}

	return allele;
}

//-----------------------------------------------
// returns information about the gene's alleles
// and potential phenotypes
//-----------------------------------------------
string Gene::getAlleleInfo()
{
	string alleleInfo = "				Allele 1: ";
	
	alleleInfo += source->getDomDesc();
	alleleInfo += "(";
	alleleInfo += alleles[0];
	alleleInfo += ")\n				Allele 2: ";
	alleleInfo += source->getRecDesc();
	alleleInfo += "(";
	alleleInfo += alleles[1];
	alleleInfo += ")\n";


	return alleleInfo;
}

//---------------------------------------------------
// returns the name of the trait this Gene controls
//---------------------------------------------------
string Gene::passName()
{
	return source->getTrait(); //calls MasterGene to get name of the trait
}