#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

class Node
{
public:
	Node(const int x, const int y, const bool wall = false, const bool start = false, const bool goal = false);
	inline ~Node() {}

	void AddRightNode(Node* node);
	void AddDownNode(Node* node);
	void SetAsGoal();
	void SetAsStart();
	void SetAsWall();
	void Draw();

	int x, y;

	bool goal;
	bool start;
	bool wall;

	Node* up;
	Node* right;
	Node* down;
	Node* left;
	Node* parent;

	byte colour;

private:
	void SetColor(const byte number);
};

#endif NODE_H