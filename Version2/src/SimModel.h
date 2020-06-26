/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: SimModel.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate a model of genetic
*	reproduction using chromosomes with linked traits.
*   Date: 11/21/19
*
*   I attest that this program is entirely my own work
*******************************************************************/
#pragma once

#include "Gene.h"
#include"MasterGene.h"
#include "Parent.h"
#include "Offspring.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

using namespace std;

class SimModel
{

private:

	static SimModel* instance; //implement as Singleton
	SimModel(void); //private constructor because of Singleton

	vector<MasterGene> MGList; //vector of MasterGene objects
	vector<Parent> ParentList; //vector of Parent objects
	Offspring childList; //Offspring object that will contain child genotypes

	int crossCount; //counter incremented whenever a new genotype has at least one crossover gene
	int geneStats[10][3]; //2D array of integers containing number of gene pair occurrences
	int MGCOrder[10]; //array that holds indices for MGList in the order that the genes appear in the Chromosome strands


public:
	static SimModel* getInstance(); //retrieve instance of SimModel
	~SimModel(void); //destructor
	
	void reproduce(); //creates one new child genotype for Offspring
	string passTraitCount(int gene, int index); //gets information from geneStats
	void addParent(Parent *newParent);
	void addMG(MasterGene *newMG);
	MasterGene* getMG(char allele); //returns pointer to MasterGene object
	string getMGName(int i);
	string getMGDom(int i);
	string getMGRec(int i);
	string getMGCross(int i);
	string getParentSciName(int i);
	string getParentComName(int i);
	string getParentGeneName(int i, int j, int k); //gets name of trait a Gene controls
	string getAlleleInfo(int ParentNum, int chromosomeNum, int geneNum); //returns info about possible traits from a Gene
	int getMGListSize();
	int getParentListSize();
	int getParentChromosomeListSize(int i); //returns number of Chromosomes within Parent
	int getChromosomeGeneListSize(int i, int j); //returns number of Genes within a Parent's Chromosome
	void setMGCOrder(); 
	int getMGCOrder(int i);
	int getCrossCount(); //returns number of offspring with a genetic crossover
};

