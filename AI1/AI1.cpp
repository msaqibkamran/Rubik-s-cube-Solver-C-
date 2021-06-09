// AI1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

void takeInput(int ***startState, int ***finalState) {

	ifstream file("input.txt");

	if (file.is_open()) {
		
		int value = 0;

		while (!file.eof()) {
			
			//read start state from file
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						file >> value;
						startState[i][j][k] = value;
					}
				}
			}   
			
			//read start state from file
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{

						file >> value;
						finalState[i][j][k] = value;
					}
				}
			}   
		}
		
	}
	else cout << "Cannot open file" << endl;
}

void print(int*** arr)
{
	cout << "Printing " << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				
				cout<< arr[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

int*** rightAntiClock(int*** cube) {
	int *** temp;
	temp = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[4][0][1] = cube[4][1][0];
	temp[4][1][0] = cube[4][2][1];
	temp[4][2][1] = cube[4][1][2];
	temp[4][1][2] = cube[4][0][1];

	temp[4][0][0] = cube[4][2][0];
	temp[4][2][0] = cube[4][2][2];
	temp[4][2][2] = cube[4][0][2];
	temp[4][0][2] = cube[4][0][0];

	temp[0][0][2] = cube[3][0][2];
	temp[0][1][2] = cube[3][1][2];
	temp[0][2][2] = cube[3][2][2];

	temp[3][0][2] = cube[5][0][2];
	temp[3][1][2] = cube[5][1][2];
	temp[3][2][2] = cube[5][2][2];

	temp[5][0][2] = cube[1][0][2];
	temp[5][1][2] = cube[1][1][2];
	temp[5][2][2] = cube[1][2][2];

	temp[1][0][2] = cube[0][0][2];
	temp[1][1][2] = cube[0][1][2];
	temp[1][2][2] = cube[0][2][2];

	return temp;
}

int*** rightClock(int*** cube) {
	int *** temp;
	temp = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[4][0][1] = cube[4][1][2];
	temp[4][1][0] = cube[4][0][1];
	temp[4][2][1] = cube[4][1][0];
	temp[4][1][2] = cube[4][2][1];

	temp[4][0][0] = cube[4][0][2];
	temp[4][2][0] = cube[4][0][0];
	temp[4][2][2] = cube[4][2][0];
	temp[4][0][2] = cube[4][2][2];

	temp[0][0][2] = cube[1][0][2];
	temp[0][1][2] = cube[1][1][2];
	temp[0][2][2] = cube[1][2][2];

	temp[3][0][2] = cube[0][0][2];
	temp[3][1][2] = cube[0][1][2];
	temp[3][2][2] = cube[0][2][2];

	temp[5][0][2] = cube[3][0][2];
	temp[5][1][2] = cube[3][1][2];
	temp[5][2][2] = cube[3][2][2];

	temp[1][0][2] = cube[5][0][2];
	temp[1][1][2] = cube[5][1][2];
	temp[1][2][2] = cube[5][2][2];

	return temp;
}

int*** upClock(int*** cube) {
	int *** temp;
	temp = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[0][0][1] = cube[0][1][2];
	temp[0][1][0] = cube[0][0][1];
	temp[0][2][1] = cube[0][1][0];
	temp[0][1][2] = cube[0][2][1];

	temp[0][0][0] = cube[0][0][2];
	temp[0][2][0] = cube[0][0][0];
	temp[0][2][2] = cube[0][2][0];
	temp[0][0][2] = cube[0][2][2];

	temp[2][0][0] = cube[1][0][0];
	temp[2][1][0] = cube[1][1][0];
	temp[2][2][0] = cube[1][2][0];

	temp[3][0][0] = cube[2][0][0];
	temp[3][1][0] = cube[2][1][0];
	temp[3][2][0] = cube[2][2][0];

	temp[4][0][0] = cube[3][0][0];
	temp[4][1][0] = cube[3][1][0];
	temp[4][2][0] = cube[3][2][0];

	temp[1][0][0] = cube[4][0][0];
	temp[1][1][0] = cube[4][1][0];
	temp[1][2][0] = cube[4][2][0];

	return temp;
}

int*** upAntiClock(int*** cube) {
	int *** temp;
	temp = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[0][0][1] = cube[0][1][0];
	temp[0][1][0] = cube[0][2][1];
	temp[0][2][1] = cube[0][1][2];
	temp[0][1][2] = cube[0][0][1];

	temp[0][0][0] = cube[0][2][0];
	temp[0][2][0] = cube[0][2][2];
	temp[0][2][2] = cube[0][0][2];
	temp[0][0][2] = cube[0][0][0];

	temp[2][0][0] = cube[3][0][0];
	temp[2][1][0] = cube[3][1][0];
	temp[2][2][0] = cube[3][2][0];

	temp[3][0][0] = cube[4][0][0];
	temp[3][1][0] = cube[4][1][0];
	temp[3][2][0] = cube[4][2][0];

	temp[4][0][0] = cube[1][0][0];
	temp[4][1][0] = cube[1][1][0];
	temp[4][2][0] = cube[1][2][0];

	temp[1][0][0] = cube[2][0][0];
	temp[1][1][0] = cube[2][1][0];
	temp[1][2][0] = cube[2][2][0];

	return temp;
}

int*** leftClock(int*** cube)
{
	int *** temp;
	temp = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}




	temp[2][0][1] = cube[2][1][0];
	temp[2][1][0] = cube[2][2][1];
	temp[2][2][1] = cube[2][1][2];
	temp[2][1][2] = cube[2][0][1];

	temp[2][0][0] = cube[2][2][0];
	temp[2][2][0] = cube[2][2][2];
	temp[2][2][2] = cube[2][0][2];
	temp[2][0][2] = cube[2][0][0];

	temp[0][0][0] = cube[3][0][0];
	temp[0][1][0] = cube[3][1][0];
	temp[0][2][0] = cube[3][2][0];

	temp[3][0][0] = cube[5][0][0];
	temp[3][1][0] = cube[5][1][0];
	temp[3][2][0] = cube[5][2][0];

	temp[5][0][0] = cube[1][0][0];
	temp[5][1][0] = cube[1][1][0];
	temp[5][2][0] = cube[1][2][0];

	temp[1][0][0] = cube[0][0][0];
	temp[1][1][0] = cube[0][1][0];
	temp[1][2][0] = cube[0][2][0];

	return temp;
}

int*** leftAntiClock(int*** cube)
{
	int *** temp;
	temp = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[2][0][1] = cube[2][1][2];
	temp[2][1][0] = cube[2][0][1];
	temp[2][2][1] = cube[2][1][0];
	temp[2][1][2] = cube[2][2][1];

	temp[2][0][0] = cube[2][0][2];
	temp[2][2][0] = cube[2][0][0];
	temp[2][2][2] = cube[2][2][0];
	temp[2][0][2] = cube[2][2][2];

	temp[0][0][0] = cube[1][0][0];
	temp[0][1][0] = cube[1][1][0];
	temp[0][2][0] = cube[1][2][0];

	temp[3][0][0] = cube[0][0][0];
	temp[3][1][0] = cube[0][1][0];
	temp[3][2][0] = cube[0][2][0];

	temp[5][0][0] = cube[3][0][0];
	temp[5][1][0] = cube[3][1][0];
	temp[5][2][0] = cube[3][2][0];

	temp[1][0][0] = cube[5][0][0];
	temp[1][1][0] = cube[5][1][0];
	temp[1][2][0] = cube[5][2][0];

	return temp;
}

int*** downClock(int*** cube) {
	int *** temp;
	temp = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[5][0][1] = cube[5][1][0];
	temp[5][1][0] = cube[5][2][1];
	temp[5][2][1] = cube[5][1][2];
	temp[5][1][2] = cube[5][0][1];

	temp[5][0][0] = cube[5][2][0];
	temp[5][2][0] = cube[5][2][2];
	temp[5][2][2] = cube[5][0][2];
	temp[5][0][2] = cube[5][0][0];

	temp[2][0][2] = cube[3][0][2];
	temp[2][1][2] = cube[3][1][2];
	temp[2][2][2] = cube[3][2][2];

	temp[3][0][2] = cube[4][0][2];
	temp[3][1][2] = cube[4][1][2];
	temp[3][2][2] = cube[4][2][2];

	temp[4][0][2] = cube[1][0][2];
	temp[4][1][2] = cube[1][1][2];
	temp[4][2][2] = cube[1][2][2];

	temp[1][0][2] = cube[2][0][2];
	temp[1][1][2] = cube[2][1][2];
	temp[1][2][2] = cube[2][2][2];

	return temp;
}

int*** downAntiClock(int*** cube) {
	int *** temp;
	temp = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[5][0][1] = cube[5][1][2];
	temp[5][1][0] = cube[5][0][1];
	temp[5][2][1] = cube[5][1][0];
	temp[5][1][2] = cube[5][2][1];

	temp[5][0][0] = cube[5][0][2];
	temp[5][2][0] = cube[5][0][0];
	temp[5][2][2] = cube[5][2][0];
	temp[5][0][2] = cube[5][2][2];

	temp[2][0][2] = cube[1][0][2];
	temp[2][1][2] = cube[1][1][2];
	temp[2][2][2] = cube[1][2][2];

	temp[3][0][2] = cube[2][0][2];
	temp[3][1][2] = cube[2][1][2];
	temp[3][2][2] = cube[2][2][2];

	temp[4][0][2] = cube[3][0][2];
	temp[4][1][2] = cube[3][1][2];
	temp[4][2][2] = cube[3][2][2];

	temp[1][0][2] = cube[4][0][2];
	temp[1][1][2] = cube[4][1][2];
	temp[1][2][2] = cube[4][2][2];

	return temp;
}

int*** frontClock(int*** cube) {
	int *** temp;
	temp = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[1][0][1] = cube[1][1][2];
	temp[1][1][0] = cube[1][0][1];
	temp[1][2][1] = cube[1][1][0];
	temp[1][1][2] = cube[1][2][1];

	temp[1][0][0] = cube[1][0][2];
	temp[1][2][0] = cube[1][0][0];
	temp[1][2][2] = cube[1][2][0];
	temp[1][0][2] = cube[1][2][2];

	temp[0][0][2] = cube[2][0][2];
	temp[0][1][2] = cube[2][1][2];
	temp[0][2][2] = cube[2][2][2];

	temp[4][0][2] = cube[0][0][2];
	temp[4][1][2] = cube[0][1][2];
	temp[4][2][2] = cube[0][2][2];

	temp[5][0][2] = cube[4][0][2];
	temp[5][1][2] = cube[4][1][2];
	temp[5][2][2] = cube[4][2][2];

	temp[2][0][2] = cube[5][0][2];
	temp[2][1][2] = cube[5][1][2];
	temp[2][2][2] = cube[5][2][2];

	return temp;
}

int*** frontAntiClock(int*** cube) {
	int *** temp;
	temp = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[1][0][1] = cube[1][1][0];
	temp[1][1][0] = cube[1][2][1];
	temp[1][2][1] = cube[1][1][2];
	temp[1][1][2] = cube[1][0][1];

	temp[1][0][0] = cube[1][2][0];
	temp[1][2][0] = cube[1][2][2];
	temp[1][2][2] = cube[1][0][2];
	temp[1][0][2] = cube[1][0][0];

	temp[5][0][2] = cube[2][0][2];
	temp[5][1][2] = cube[2][1][2];
	temp[5][2][2] = cube[2][2][2];

	temp[2][0][2] = cube[0][0][2];
	temp[2][1][2] = cube[0][1][2];
	temp[2][2][2] = cube[0][2][2];

	temp[0][0][2] = cube[4][0][2];
	temp[0][1][2] = cube[4][1][2];
	temp[0][2][2] = cube[4][2][2];

	temp[4][0][2] = cube[5][0][2];
	temp[4][1][2] = cube[5][1][2];
	temp[4][2][2] = cube[5][2][2];

	return temp;
}

int*** backClock(int*** cube) {
	int *** temp;
	temp = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[3][0][1] = cube[3][1][0];
	temp[3][1][0] = cube[3][2][1];
	temp[3][2][1] = cube[3][1][2];
	temp[3][1][2] = cube[3][0][1];

	temp[3][0][0] = cube[3][2][0];
	temp[3][2][0] = cube[3][2][2];
	temp[3][2][2] = cube[3][0][2];
	temp[3][0][2] = cube[3][0][0];

	temp[5][0][0] = cube[2][0][0];
	temp[5][1][0] = cube[2][1][0];
	temp[5][2][0] = cube[2][2][0];

	temp[2][0][0] = cube[0][0][0];
	temp[2][1][0] = cube[0][1][0];
	temp[2][2][0] = cube[0][2][0];

	temp[0][0][0] = cube[4][0][0];
	temp[0][1][0] = cube[4][1][0];
	temp[0][2][0] = cube[4][2][0];

	temp[4][0][0] = cube[5][0][0];
	temp[4][1][0] = cube[5][1][0];
	temp[4][2][0] = cube[5][2][0];

	return temp;
}

int*** backAntiClock(int*** cube) {
	int *** temp;
	temp = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{

				temp[i][j][k] = cube[i][j][k];
			}
		}
	}

	temp[3][0][1] = cube[3][1][2];
	temp[3][1][0] = cube[3][0][1];
	temp[3][2][1] = cube[3][1][0];
	temp[3][1][2] = cube[3][2][1];

	temp[3][0][0] = cube[3][0][2];
	temp[3][2][0] = cube[3][0][0];
	temp[3][2][2] = cube[3][2][0];
	temp[3][0][2] = cube[3][2][2];

	temp[0][0][0] = cube[2][0][0];
	temp[0][1][0] = cube[2][1][0];
	temp[0][2][0] = cube[2][2][0];

	temp[4][0][0] = cube[0][0][0];
	temp[4][1][0] = cube[0][1][0];
	temp[4][2][0] = cube[0][2][0];

	temp[5][0][0] = cube[4][0][0];
	temp[5][1][0] = cube[4][1][0];
	temp[5][2][0] = cube[4][2][0];

	temp[2][0][0] = cube[5][0][0];
	temp[2][1][0] = cube[5][1][0];
	temp[2][2][0] = cube[5][2][0];

	return temp;
}

bool compareState(int*** currentState, int*** finalState)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (currentState[i][j][k] != finalState[i][j][k])
					return false;
			}	
		}	
	}
	return true;
}

void printStack(stack<int> s)
{
	while (!s.empty())
	{
		cout << '\t' << s.top();
		s.pop();
	}
	cout << endl;
}

int*** getCube() {
	int *** temp;
	temp = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			temp[i][j] = new int[3];
		}
	}
	return temp;
}

class node {
public:
	int*** curr;
	int prevMove;
	int depthLevel;
    node * parent;
	vector<node *> child;
	
	node() {
		prevMove = 0;
		depthLevel = 0;
		parent = nullptr;
		curr = getCube();

	}

	void generateChild() {
		
		node * temp = new node[1];

		temp->curr = leftClock(this->curr);
		temp->depthLevel = this->depthLevel + 1;
		temp->prevMove = 1;
		temp->parent = this;

		this->child.push_back(temp);

		temp->curr = leftAntiClock(this->curr);
		temp->prevMove = 2;
		this->child.push_back(temp);

		temp->curr = rightClock(this->curr);
		temp->prevMove = 3;
		this->child.push_back(temp);

		temp->curr = rightAntiClock(this->curr);
		temp->prevMove = 4;
		this->child.push_back(temp);

		temp->curr = upClock(this->curr);
		temp->prevMove = 5;
		this->child.push_back(temp);

		temp->curr = upAntiClock(this->curr);
		temp->prevMove = 6;
		this->child.push_back(temp);

		temp->curr = downClock(this->curr);
		temp->prevMove = 7;
		this->child.push_back(temp);

		temp->curr = downAntiClock(this->curr);
		temp->prevMove = 8;
		this->child.push_back(temp);

		temp->curr = frontClock(this->curr);
		temp->prevMove = 9;
		this->child.push_back(temp);

		temp->curr = frontAntiClock(this->curr);
		temp->prevMove = 10;
		this->child.push_back(temp);

		temp->curr = backClock(this->curr);
		temp->prevMove = 11;
		this->child.push_back(temp);

		temp->curr = backAntiClock(this->curr);
		temp->prevMove = 12;
		this->child.push_back(temp);



	}

	void setCurrState(int*** c) {
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					curr[i][j][k] = c[i][j][k];
				}	
			}
		}
	}

	int*** getCurrState() {
		return this->curr;
	}

	void setprevMove(int move) {
		this->prevMove = move;
	}

	int getprevMove() {
		return this->prevMove;
	}

	void setdepthLevel(int depth) {
		this->depthLevel = depth;
	}

	int getdepthLevel() {
		return this->depthLevel;
	}

	void setParent(node * p) {
		this->parent = p;
	}

	node * getParent() {
		this->parent;
	}

	void addChild(node * c)
	{
		this->child.push_back(c);
	}
     
};

void addChilds(node * p, stack<node *> &s)
{
	    // leftClock         1
		// leftAntiClock     2
		// rightClock        3
		// rightAntiClock    4
		// upClock           5
		// upAntiClock       6
		// downClock         7
		// downAntiClock     8
		// frontClock        9
		// frontAntiClock    10
		// backClock         11
		// backAntiClock     12
	
	node * temp1 = new node[1];
	temp1->curr = leftClock(p->curr);
	temp1->depthLevel = p->depthLevel + 1;
	temp1->parent = p;
	temp1->prevMove = 1;
	p->addChild(temp1);
	s.push(temp1);

	node * temp4 = new node[1];
	temp4->curr = rightAntiClock(p->curr);
	temp4->depthLevel = p->depthLevel + 1;
	temp4->parent = p;
	temp4->prevMove = 4;
	p->addChild(temp4);
	s.push(temp4);

	node * temp3 = new node[1];
	temp3->curr = rightClock(p->curr);
	temp3->depthLevel = p->depthLevel + 1;
	temp3->parent = p;
	temp3->prevMove = 3;
	p->addChild(temp3);
	s.push(temp3);

	node * temp7 = new node[1];
	temp7->curr = downClock(p->curr);
	temp7->depthLevel = p->depthLevel + 1;
	temp7->parent = p;
	temp7->prevMove = 7;
	p->addChild(temp7);
	s.push(temp7);

	node * temp10 = new node[1];
	temp10->curr = frontAntiClock(p->curr);
	temp10->depthLevel = p->depthLevel + 1;
	temp10->parent = p;
	temp10->prevMove = 10;
	p->addChild(temp10);
	s.push(temp10);

	node * temp5 = new node[1];
	temp5->curr = upClock(p->curr);
	temp5->depthLevel = p->depthLevel + 1;
	temp5->parent = p;
	temp5->prevMove = 5;
	p->addChild(temp5);
	s.push(temp5);

	node * temp2 = new node[1];
	temp2->curr = leftAntiClock(p->curr);
	temp2->depthLevel = p->depthLevel + 1;
	temp2->parent = p;
	temp2->prevMove = 2;
	p->addChild(temp2);
	s.push(temp2);

	node * temp8 = new node[1];
	temp8->curr = downAntiClock(p->curr);
	temp8->depthLevel = p->depthLevel + 1;
	temp8->parent = p;
	temp8->prevMove = 8;
	p->addChild(temp8);
	s.push(temp8);

	node * temp12 = new node[1];
	temp12->curr = backAntiClock(p->curr);
	temp12->depthLevel = p->depthLevel + 1;
	temp12->parent = p;
	temp12->prevMove = 12;
	p->addChild(temp12);
	s.push(temp12);

	node * temp9 = new node[1];
	temp9->curr = frontClock(p->curr);
	temp9->depthLevel = p->depthLevel + 1;
	temp9->parent = p;
	temp9->prevMove = 9;
	p->addChild(temp9);
	s.push(temp9);

	

	node * temp6 = new node[1];
	temp6->curr = upAntiClock(p->curr);
	temp6->depthLevel = p->depthLevel + 1;
	temp6->parent = p;
	temp6->prevMove = 6;
	p->addChild(temp6);
	s.push(temp6);

	node * temp11 = new node[1];
	temp11->curr = backClock(p->curr);
	temp11->depthLevel = p->depthLevel + 1;
	temp11->parent = p;
	temp11->prevMove = 11;
	p->addChild(temp11);
	s.push(temp11);

	
	
}

void printStackWithMoves(stack<int> s) {
		// leftClock         1
		// leftAntiClock     2
		// rightClock        3
		// rightAntiClock    4
		// upClock           5
		// upAntiClock       6
		// downClock         7
		// downAntiClock     8
		// frontClock        9
		// frontAntiClock    10
		// backClock         11
		// backAntiClock     12
	while (!s.empty())
	{
		int p = s.top();
		if (p == 1) {
			cout << "move Left ClockWise" << endl;
		}
		else if (p == 2) {
			cout << "move Left AntiClockWise" << endl;
		}
		else if (p == 3) {
			cout << "move Right ClockWise" << endl;
		}
		else if (p == 4) {
			cout << "move Right AntiClockWise" << endl;
		}
		else if (p == 5) {
			cout << "move Up ClockWise" << endl;
		}
		else if (p == 6) {
			cout << "move Up AntiClockWise" << endl;
		}
		else if (p == 7) {
			cout << "move Down ClockWise" << endl;
		}
		else if (p == 8) {
			cout << "move Down AntiClockWise" << endl;
		}
		else if (p == 9) {
			cout << "move Front ClockWise" << endl;
		}
		else if (p == 10) {
			cout << "move Front AntiClockWise" << endl;
		}
		else if (p == 11) {
			cout << "move Back ClockWise" << endl;
		}
		else if (p == 12) {
			cout << "move Back AntiClockWise" << endl;
		}
		s.pop();
	}
	cout << endl;
	

}

int magicFunction(int*** currentState, int*** finalState)
{
	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (currentState[i][j][k] == finalState[i][j][k])
					count++;
			}
		}
	}
	return count;
}

int main()
{
	int *** array;
	array = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		array[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			array[i][j] = new int[3];
		}
	}

	int *** startState;
	startState = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		startState[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			startState[i][j] = new int[3];
		}
	}

	int *** finalState;
	finalState = new int **[6];
	for (int i = 0; i < 6; i++)
	{
		finalState[i] = new int *[3];
		for (int j = 0; j < 3; j++)
		{
			finalState[i][j] = new int[3];
		}
	}

	takeInput(startState, finalState);

	stack<node *> mystack;
	node * curr = new node();
	curr->setCurrState(finalState);
	curr->curr = leftAntiClock(curr->curr);
	curr->curr = rightAntiClock(curr->curr);
	curr->curr = upClock(curr->curr);
	bool found = false;

	int depth = 30;

	mystack.push(curr);

	while (!mystack.empty())
	{
		if (compareState(curr->curr, finalState))
		{
			found = true;
			break;
		}

		if (curr->depthLevel < depth)
		{
			addChilds(curr, mystack);
			curr = mystack.top();
			mystack.pop();
		}
		else
		{
			curr = mystack.top();
			mystack.pop();
		}
	}

	if (found)
	{
		cout << "Found!" << endl;
		stack<int> path;
		while (curr->parent != nullptr)
		{
			path.push(curr->prevMove);
			curr = curr->parent;
		}

		//printStack(path);
		cout << "The depth is: " << depth << endl;
		printStackWithMoves(path);
		//print(curr->curr);
	}
	else {
		cout << "Not Found" << endl;
	}


	
	

	return 0;
}
