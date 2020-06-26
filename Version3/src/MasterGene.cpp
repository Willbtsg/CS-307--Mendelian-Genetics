/*******************************************************************
*   CS 307 Programming Assignment 3
*   File: MasterGene.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 12/9/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#include "stdafx.h"
#include "MasterGene.h"

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
MasterGene::MasterGene(void)
{
	//initialize everything
	char name[32] = "";
	char domDesc[32] = "";
	char domSym = NULL;
	char recDesc[32] = "";
	char recSym = NULL;
	double crossOver = 0;
}

//-----------------------------------
// Destructor
//-----------------------------------
MasterGene::~MasterGene()
{

}

//------------------------------------------------
// sets trait name
//
// Argument:
//
// *trait- pointer to character array containing
// the desired trait name
//
//------------------------------------------------
void MasterGene::setTrait(char *trait)
{
	strcpy(name, trait);
	return;
}

//------------------------------------------------
// sets dominant description
//
// Argument:
//
// *description- pointer to character array containing
// the dominant appearance
//
//------------------------------------------------
void MasterGene::setDomDesc(char *description)
{
	strcpy(domDesc, description);

	return;
}

//--------------------------------------------------------
// sets dominant symbol
//
// Argument:
//
// symbol- character variable containing dominant symbol
//
//--------------------------------------------------------
void MasterGene::setDomSym(char symbol)
{
	domSym = symbol;

	return;
}

//------------------------------------------------
// sets recessive description
//
// Argument:
//
// *description- pointer to character array containing
// the recessive appearance
//
//------------------------------------------------
void MasterGene::setRecDesc(char *description)
{
	strcpy(recDesc, description);

	return;
}

//---------------------------------------------------------
// sets recessive symbol
//
// Argument:
//
// symbol- character variable containing recessive symbol
//
//---------------------------------------------------------
void MasterGene::setRecSym(char symbol)
{
	recSym = symbol;

	return;
}

//-----------------------------------------------------
// sets crossover chance
//
// Arguments:
//
// cross- double variable containing crossover chance
//-----------------------------------------------------
void MasterGene::setCross(double cross)
{
	crossOver = cross;
}

//-----------------------------------
// returns trait name
//-----------------------------------
string MasterGene::getTrait()
{
	return name;
}

//----------------------------------------
// returns description of dominant trait
//----------------------------------------
string MasterGene::getDomDesc()
{
	return domDesc;

}

//-----------------------------------
// returns dominant allele
//-----------------------------------
char MasterGene::getDomSym()
{
	return domSym;
}

//-----------------------------------------
// returns description of recessive trait
//-----------------------------------------
string MasterGene::getRecDesc()
{
	return recDesc;
}

//-----------------------------------
// returns recessive allele
//-----------------------------------
char MasterGene::getRecSym()
{
	return recSym;
}

//-----------------------------------
// returns crossover chance
//-----------------------------------
double MasterGene::getCross()
{
	return crossOver;
}