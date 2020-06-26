/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Gene.cpp
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
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

//----------------------------------------------
// returns one of the Gene's alleles at random
//----------------------------------------------
char Gene::getAllele()
{
	int index;

	index = rand() % 2;

	return alleles[index];
}

//-------------------------------------
// returns both of the Gene's alleles
//-------------------------------------
string Gene::getBoth()
{
	string both = "";
	both = alleles[0];
	both = both + alleles[1];
	return both;

}

//---------------------------------------------------
// returns the name of the trait this Gene controls
//---------------------------------------------------
string Gene::passName()
{
	return source->getTrait(); //calls MasterGene to get name of the trait
}