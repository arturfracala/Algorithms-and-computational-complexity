#pragma once
#include <vector>

using namespace std;
class Specimen
{
	int length;
	vector<int> path;
	int path_weight;
	int **matrix;
public:
	Specimen(int, int**);
	Specimen(int,int**,vector<int>);
	~Specimen();
	void shuffle_chromosome();
	void mutate();
	int countWeight();
	int getGeneAt(int);
	int getWeight();
	void display();
};

