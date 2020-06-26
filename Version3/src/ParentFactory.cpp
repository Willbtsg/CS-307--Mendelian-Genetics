/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: ParenFactory.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 12/9/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "stdafx.h"
#include "ParentFactory.h"
#include "ChromosomeFactory.h"
#include "GeneticsSimDataParser.h"

ParentFactory* ParentFactory::instance = NULL; //sets instance to NULL until constructor getInstance is called for the first time

//-----------------------------------
// Constructor
//-----------------------------------
ParentFactory::ParentFactory()
{
}

//------------------------------------
// returns instance of ParentFactory
//------------------------------------
ParentFactory* ParentFactory::getInstance()
{
	if (instance == NULL) //if no instance of ParentFactory exists...
	{
		instance = new ParentFactory(); //...create a new one
	}

	return instance;
}

//-----------------------------------
// Destructor
//-----------------------------------
ParentFactory::~ParentFactory()
{
}

//-----------------------------------------------------------
// returns pointer to new Parent object
//
// Arguments:
//
// parentNum- indicates which Parent to get information for
//
//-----------------------------------------------------------
Parent* ParentFactory::createParent(int parentNum)
{
	Parent *newParent = new Parent(); //create a new Parent object
	GeneticsSimDataParser* Parser = GeneticsSimDataParser::getInstance(); //get the instance of GeneticsSimDataParser
	ChromosomeFactory* CFactory = ChromosomeFactory::getInstance(); //get the instance of ChromosomeFactory

	newParent->setScientificName(Parser->getScientificName()); //set scientific name
	newParent->setCommonName(Parser->getCommonName()); //set common name

	char strand1[12]; //character array to hold first chromosome strand
	char strand2[12]; //character array to hold second chromosome strand
	char genotype[30];

	for (int i = 0; i < Parser->getChromosomeCount(); i++) //until there are no more chromosomes to be created
	{

		if (parentNum == 0) //get strand information for the appropriate Parent object
		{
			Parser->getP1Chromosome(strand1, strand2);
		}
		else
		{
			Parser->getP2Chromosome(strand1, strand2);
		}

		newParent->addChromosome(CFactory->createChromosome(strand1, strand2)); //create a new Chromosome for the Parent using the ChromosomeFactory
	}

	int j = 0;

	for (int i = 0; i < 12; i++)
	{
		genotype[j] = strand1[i];
		genotype[j+1] = strand2[i];
		j += 2;
	}
	
	newParent->setGenotype(genotype);

	return newParent;

}