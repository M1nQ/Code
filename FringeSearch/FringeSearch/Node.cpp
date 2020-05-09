#include "Node.h"

Node::Node(const int x, const int y, const bool wall, const bool start, const bool goal)
{
	this->x = x;
	this->y = y;

	this->wall = wall;
	this->start = start;
	this->goal = goal;

	up = nullptr;
	right = nullptr;
	down = nullptr;
	left = nullptr;
	parent = nullptr;

	if (wall) colour = 0;
	else colour = 15;
}

void Node::AddRightNode(Node* node)
{
	right = node;
	node->left = this;
}
void Node::AddDownNode(Node* node)
{
	down = node;
	node->up = this;
}
void Node::SetAsGoal()
{
	goal = true;
	colour = 13;
}
void Node::SetAsStart()
{
	start = true;
	colour = 13;
}
void Node::SetAsWall()
{
	wall = true;
	colour = 0;
}
void Node::Draw()
{
	SetColor(colour);

	// Draws the node.
	if (start) cout << "S ";
	else if (goal) cout << "G ";
	else if (wall)  cout << "* ";
	else cout << "* ";
}

void Node::SetColor(const byte number)
{
	static HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, number);
}