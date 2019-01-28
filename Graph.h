#pragma once

class Graph
{
	int size;
	int **matrix;
public:
	Graph();
	~Graph();
	void enterGraph();
	void showGraph();
	void geneticAlgorithmTSP(int, int, float, float);
};
