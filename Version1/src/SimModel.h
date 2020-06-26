/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: SimModel.h
*   Author: Will Thomason
*   Desc: This program attempts to recreate Gregor Mendel's model of
*	how genes are passed to new organisms during reproduction.
*   Date: 10/28/19
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

	int geneStats[4][3]; //2D array of integers containing number of gene pair occurrences
	map<string, int> genotypeStats; //map to contain genotypes and their number of occurrences
	map<string, int>::iterator genotypeStatsItr; //iterator to be used with genotypeStats


public:
	static SimModel* getInstance(); //retrieve instance of SimModel
	~SimModel(void); //destructor

	void crossPollinate(); //creates one new child genotype for Offspring
	string passTraitCount(int gene, int index); //gets information from geneStats
	string passGenotypeCount(); //gets information from genotypeStats
	void addParent(Parent newParent);
	void addMG(MasterGene *newMG);
	MasterGene* getMG(int i); //returns pointer to MasterGene object
	string getMGName(int i);
	string getMGDom(int i);
	string getMGRec(int i);
	string getParentSciName(int i);
	string getParentComName(int i);
	string getParentGeneName(int i, int j); //gets name of trait a Gene controls
	string getParentAlleles(int i, int j); //calls Gene within Parent to get alleles 
	int getMGListSize();
	int getParentListSize();
	int getParentGeneListSize(int i); //returns number of genes within Parent
	int getGenoStatsSize();
	void setGenoStatsItr(); //sets genotypeStatsItr to beginning of genotypeStats
};

