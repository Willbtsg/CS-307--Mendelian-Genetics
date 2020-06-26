/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: MasterGene.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#pragma warning(disable:4996)
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