#ifndef FRINGE_H
#define FRINGE_H

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include "Node.h"

using namespace std;

class Fringe
{
public:
	Fringe();
	inline ~Fringe() {}

	void Search();

private:
	bool CheckNode(Node* node, Node* next);
	void CreatePath();
	void Draw();
	void ModifyNodes();

	Node* nodes[40][40];
	Node* start;
	Node* goal;

	deque<Node*> now;
	vector<Node*> later;
};

#endif FRINGE_H