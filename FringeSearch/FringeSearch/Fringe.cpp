#include "Fringe.h"

Fringe::Fringe()
{	
	// Initializes the 2D array.
	for (int y = 0; y < 40; ++y)
	{
		for (int x = 0; x < 40; ++x)
		{
			nodes[y][x] = new Node(x, y);
		}
	}

	// Makes the connections between the nodes.
	for (int y = 0; y < 40; ++y)
	{
		for (int x = 0; x < 40; ++x)
		{
			if (x < 39)
				nodes[y][x]->AddRightNode(nodes[y][x + 1]);
			if (y < 39)
				nodes[y][x]->AddDownNode(nodes[y + 1][x]);
		}
	}

	// Sets start, goal and wall nodes.
	ModifyNodes();

	Draw();
	system("pause");
}

void Fringe::Search()
{
	now.push_back(start); // Sets the start node into the 'now' list.
	bool add = true; // Tells whether to raise the limit after iteration.
	int h = 0; // The price of the shortest possible route to goal.
	int f = 0; // The price of the current path.
	int limit = abs(start->x - goal->x) + abs(start->y - goal->y); // Sets the initial price limit, which is the price of the shortest possible route to goal.
	Node* current; // Only used for determining the price of the path so far.

	// The actual search
	while (goal->parent == nullptr)
	{
		add = true; // Sets the add to true as a default. If there's a path that advances it sets this to false.

		for (Node* node : now)
		{
			h = abs(node->x - goal->x) + abs(node->y - goal->y); // Calculates the price of the shortest possible route to goal.

			// Calculates the price of the path so far.
			f = 0;
			current = node;
			while (current->parent != nullptr)
			{
				current = current->parent;
				++f;
			}

			if (h + f < limit) // if the price allows progressing to the next node.
			{
				if (node->up != nullptr)
					if (CheckNode(node, node->up)) break; // Checks up
				if (node->right != nullptr)
					if (CheckNode(node, node->right)) break; // Checks right
				if (node->down != nullptr)
					if (CheckNode(node, node->down)) break; // Checks down
				if (node->left != nullptr)
					if (CheckNode(node, node->left)) break; // Checks left

				add = false; // Because a node was added there's no need to raise the limit.
			}
			else
			{
				later.push_back(node); // if the node's price was too high, it's added to the later list.
			}
		}

		if (goal->parent == nullptr) // Only updates the lists if the iteration continues.
		{
			// Empties the now list and inserts the nodes from later to it. Then empties the later list for new iteration.
			for (Node* node : now) node->colour = 14; // Sets node's colour to yellow to indicate that it has been visited.
			now.clear();
			for (Node* node : later) { now.push_front(node); node->colour = 12; } // Sets the color of the node to red to indicate that it's being inspected. Also flips the list as it adds the later to now.
			later.clear();

			if (add) ++limit; // Raises the limit if needed.

			Draw();
		}
	}

	CreatePath();
	Draw();
	system("pause");
}

bool Fringe::CheckNode(Node* current, Node* next)
{
	// checks the given node and the next one. returns true only if the goal has been found.

	if (next->goal)
	{
		next->parent = current;
		return true;
	}
	else if (next->wall || next->start || next->parent != nullptr)
	{
		return false;
	}
	else
	{
		next->parent = current;
		later.push_back(next);
		return false;
	}
}
void Fringe::CreatePath()
{
	// Colours the path with green;

	Node* current = goal;

	while (current->parent != nullptr)
	{
		current->colour = 10;
		current = current->parent;
	}

	current->colour = 10;
}
void Fringe::Draw()
{
	// Draws all the nodes.

	system("cls");

	for (int y = 0; y < 40; ++y)
	{
		for (int x = 0; x < 40; ++x)
		{
			nodes[y][x]->Draw();
		}
	}

	Sleep(500);
}
void Fringe::ModifyNodes()
{
	// Setting up start and goal.
	nodes[1][1]->SetAsStart();
	start = nodes[1][1];

	nodes[36][38]->SetAsGoal();
	goal = nodes[36][38];

	// Also some walls...
	nodes[0][3]->SetAsWall();
	nodes[1][3]->SetAsWall();
	nodes[2][3]->SetAsWall();
	nodes[3][3]->SetAsWall();
	nodes[4][3]->SetAsWall();
	nodes[5][3]->SetAsWall();
	nodes[6][3]->SetAsWall();
	nodes[7][3]->SetAsWall();
	nodes[8][3]->SetAsWall();
	nodes[9][3]->SetAsWall();
	nodes[9][4]->SetAsWall();
	nodes[9][5]->SetAsWall();

	nodes[11][0]->SetAsWall();
	nodes[11][1]->SetAsWall();
	nodes[11][2]->SetAsWall();
	nodes[11][3]->SetAsWall();
	nodes[11][4]->SetAsWall();
	nodes[11][5]->SetAsWall();

	nodes[0][13]->SetAsWall();
	nodes[1][13]->SetAsWall();
	nodes[2][13]->SetAsWall();
	nodes[3][13]->SetAsWall();
	nodes[4][13]->SetAsWall();
	nodes[5][13]->SetAsWall();
	nodes[6][13]->SetAsWall();
	nodes[7][13]->SetAsWall();
	nodes[8][13]->SetAsWall();
	nodes[9][13]->SetAsWall();
	nodes[10][13]->SetAsWall();
	nodes[11][13]->SetAsWall();
	nodes[12][13]->SetAsWall();
	nodes[13][13]->SetAsWall();
	nodes[14][13]->SetAsWall();
	nodes[14][14]->SetAsWall();
	nodes[14][15]->SetAsWall();
	nodes[14][16]->SetAsWall();
	nodes[14][17]->SetAsWall();
	nodes[14][18]->SetAsWall();
	nodes[14][19]->SetAsWall();
	nodes[14][20]->SetAsWall();
	nodes[14][21]->SetAsWall();

	nodes[12][38]->SetAsWall();
	nodes[13][37]->SetAsWall();
	nodes[14][36]->SetAsWall();
	nodes[15][35]->SetAsWall();
	nodes[16][34]->SetAsWall();
	nodes[17][33]->SetAsWall();
	nodes[18][32]->SetAsWall();
	nodes[19][31]->SetAsWall();
	nodes[20][30]->SetAsWall();
	nodes[21][29]->SetAsWall();
	nodes[22][28]->SetAsWall();
	nodes[23][27]->SetAsWall();
	nodes[24][26]->SetAsWall();
	nodes[25][25]->SetAsWall();
	nodes[26][24]->SetAsWall();
	nodes[27][23]->SetAsWall();
	nodes[28][22]->SetAsWall();
	nodes[29][21]->SetAsWall();
	nodes[30][20]->SetAsWall();
	nodes[31][19]->SetAsWall();
	nodes[32][18]->SetAsWall();
	nodes[33][17]->SetAsWall();
	nodes[33][16]->SetAsWall();
	nodes[32][16]->SetAsWall();
	nodes[31][16]->SetAsWall();
	nodes[30][16]->SetAsWall();
	nodes[29][16]->SetAsWall();
	nodes[28][16]->SetAsWall();
	nodes[27][16]->SetAsWall();
	nodes[26][16]->SetAsWall();
	nodes[25][16]->SetAsWall();

	nodes[24][4]->SetAsWall();
	nodes[24][5]->SetAsWall();
	nodes[24][6]->SetAsWall();
	nodes[24][7]->SetAsWall();
	nodes[24][8]->SetAsWall();
	nodes[24][9]->SetAsWall();
	nodes[24][10]->SetAsWall();
	nodes[24][11]->SetAsWall();
	nodes[24][12]->SetAsWall();
	nodes[24][13]->SetAsWall();
	nodes[23][13]->SetAsWall();
	nodes[22][13]->SetAsWall();
	nodes[21][13]->SetAsWall();

	nodes[33][38]->SetAsWall();
	nodes[33][37]->SetAsWall();
	nodes[33][36]->SetAsWall();
	nodes[34][36]->SetAsWall();
	nodes[35][36]->SetAsWall();
	nodes[36][36]->SetAsWall();
	nodes[37][36]->SetAsWall();
	nodes[38][36]->SetAsWall();
	nodes[39][36]->SetAsWall();
}