#include "Specimen.h"
#include <algorithm>
#include <random>
#include <iostream>

Specimen::Specimen(int l, int **newMatrix)
{
	length = l;
	for (int i = 0; i < length; i++)
	{
		path.push_back(i);
	}
	matrix = newMatrix;
	path_weight = countWeight();
}

Specimen::Specimen(int l, int ** newMatrix, vector<int> newPath)
{
	length = l;
	matrix = newMatrix;
	path = newPath;
	path_weight = countWeight();
}


Specimen::~Specimen()
{
}

void Specimen::shuffle_chromosome()
{
	std::random_shuffle(path.begin(), path.end());
	path_weight = countWeight();
}

void Specimen::mutate()
{
	int geneA, geneB;

	geneA = rand() % length;
	geneB = rand() % length;

	std::iter_swap(path.begin() + geneA, path.begin() + geneB);
	path_weight = countWeight();
}

int Specimen::countWeight()
{
	int current_pathweight = 0;

	int k = 0;
	for (int i = 0; i < length; i++) {
		if (path[i] != 0)
		{
			current_pathweight += matrix[k][path[i]];
			k = path[i];
		}
	}
	current_pathweight += matrix[k][0];
	return current_pathweight;
}

int Specimen::getGeneAt(int i)
{
	return path[i];
}

int Specimen::getWeight()
{
	return path_weight;
}

void Specimen::display()
{
	std::cout << "\nWaga minimalnej sciezki: " << path_weight;
	std::cout << "\nSciezka: 0 -> ";
	for (int i = 0; i < length; i++)
		if (path[i] != 0)
			std::cout << path[i] << " -> ";
	std::cout << "0\n";
}
