/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: GeneFactory.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
/*******************************************************************
*	This program was modified post-submission on 6/26/2020 to
*	fix errors present in the release version of the executable.
*******************************************************************/
#include "GeneFactory.h"
#include "GeneticsSimDataParser.h"
#include "SimModel.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


GeneFactory* GeneFactory::instance = NULL; //sets instance to NULL until constructor getInstance is called for the first time

//-----------------------------------
// Constructor
//-----------------------------------
GeneFactory::GeneFactory()
{
}

//-----------------------------------
// returns instance of GeneFactory
//-----------------------------------
GeneFactory* GeneFactory::getInstance()
{
	if (instance == NULL) //if no instance of GeneFactory exists...
	{
		instance = new GeneFactory(); //...create a new one
	}

	return instance;
}

//-----------------------------------
// Destructor
//-----------------------------------
GeneFactory::~GeneFactory()
{
}

//----------------------------------------------
// returns pointer to a new MasterGene object
//----------------------------------------------
MasterGene* GeneFactory::createMasterGene()
{
	GeneticsSimDataParser *Parser = GeneticsSimDataParser::getInstance(); //instantiate the Parser

	MasterGene *MGItem = new MasterGene(); //create new MasterGene object

	char MGTrait[32]; //holds name for MasterGene
	char MGDomDesc[32]; //holds dominant description for MasterGene
	char MGDomSym; //holds dominant symbol for MasterGene
	char MGRecDesc[32]; //holds recessive description for MasterGene
	char MGRecSym; //holds recessive symbol for MasterGene
	double MGCross; //holds crossover chance for MasterGene

	Parser->getGeneData(MGTrait, MGDomDesc, &MGDomSym, MGRecDesc, &MGRecSym, &MGCross);

	MGItem->setTrait(MGTrait); //set its name and other attributes
	MGItem->setDomDesc(MGDomDesc);
	MGItem->setDomSym(MGDomSym);
	MGItem->setRecDesc(MGRecDesc);
	MGItem->setRecSym(MGRecSym);
	MGItem->setCross(MGCross);

	return MGItem;
}

//-----------------------------------------------------------------
// returns pointer to new Gene object
//
// Arguments:
//
// allele1- character representing the first allele
// allele2- character representing the first allele
//
//-----------------------------------------------------------------
Gene* GeneFactory::createGene(char *allele1, char *allele2)
{
	SimModel *Model = SimModel::getInstance(); //get instance of SimModel
	Gene *newGene = new Gene(); //create a new Gene object

	newGene->setAlleles(*allele1, *allele2); //set alleles within the Gene
	newGene->setMG(Model->getMG(*allele1)); //pass a pointer to the proper MasterGene object to the Gene

	return newGene;
}