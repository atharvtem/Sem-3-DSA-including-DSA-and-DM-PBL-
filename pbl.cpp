#include <bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

#define N 5
#define INF INT_MAX

struct Node 
{
	vector<pair<int, int> > path;
	int reducedMatrix[N][N],cost,vertex,level;
};

Node* newNode(int parentMatrix[N][N],vector<pair<int, int> > const& path,int level, int i, int j)
{
	Node* node = new Node;
	node->path = path;

	if (level != 0) 
	{
		node->path.push_back(make_pair(i, j));
	}
	memcpy(node->reducedMatrix, parentMatrix,sizeof node->reducedMatrix);

	for (int k = 0; level != 0 && k < N; k++) 
	{
		node->reducedMatrix[i][k] = INF;
		node->reducedMatrix[k][j] = INF;
	}
	node->reducedMatrix[j][0] = INF;
	node->level = level;
	node->vertex = j;
	return node;
}

int rowReduction(int reducedMatrix[N][N],int row[N])
{
	fill_n(row, N, INF);
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (reducedMatrix[i][j] < row[i]) 
			{
				row[i] = reducedMatrix[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (reducedMatrix[i][j] != INF && row[i] != INF) 
			{
				reducedMatrix[i][j] -= row[i];
			}
		}
	}
	return 0;
}

int columnReduction(int reducedMatrix[N][N],int col[N])
{
	fill_n(col, N, INF);
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (reducedMatrix[i][j] < col[j]) 
			{
				col[j] = reducedMatrix[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if (reducedMatrix[i][j] != INF && col[j] != INF) 
			{
				reducedMatrix[i][j] -= col[j];
			}
		}
	}
	return 0;
}

int calculateCost(int reducedMatrix[N][N])
{
	int cost = 0;
	int row[N];
	rowReduction(reducedMatrix, row);
	int col[N];
	columnReduction(reducedMatrix, col);
	for (int i = 0; i < N; i++) {
		cost += (row[i] != INT_MAX) ? row[i] : 0,
			cost += (col[i] != INT_MAX) ? col[i] : 0;
	}
	return cost;
}

void TSPPAthPrint(vector<pair<int, int> > const& list)
{
	cout<<"\n\n";
	for (int i = 0; i < list.size(); i++) 
	{
		cout << list[i].first + 1 << " -> "
			<< list[i].second + 1 << "\n";
	}
}

struct Min_Heap {
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return lhs->cost > rhs->cost;
	}
};

int solve(int CostGraphMatrix[N][N])
{
	priority_queue<Node*, vector<Node*>, Min_Heap> pq;
	vector<pair<int, int> > v;
	Node* root = newNode(CostGraphMatrix, v, 0, -1, 0);
	root->cost = calculateCost(root->reducedMatrix);
	pq.push(root);

	while (!pq.empty()) 
	{
		Node* min = pq.top();
		pq.pop();
		int i = min->vertex;
		if (min->level == N - 1) 
		{

			min->path.push_back(make_pair(i, 0));
			TSPPAthPrint(min->path);
			return min->cost;
		}

		for (int j = 0; j < N; j++) 
		{
			if (min->reducedMatrix[i][j] != INF) 
			{
				Node* child
					= newNode(min->reducedMatrix, min->path,
							min->level + 1, i, j);

				child->cost
					= min->cost + min->reducedMatrix[i][j]
					+ calculateCost(child->reducedMatrix);

				pq.push(child);
			}
		}
		delete min;
	}
	return 0;
}

int main()
{
	p:
	system("cls");
	int marks;
	int condition;
	cout<<"Enter MHTCET Percentile:";
	cin>>marks;
	if(marks>100 || marks<0)
	{
		goto p;
	}
	if(marks>=95 && marks<=100)
	{
		cout<<"Top Colleges for you: \n1)COEP \n2)PICT \n3)VIT \n4)VIIT ";
		condition = 1;
	}
	else if(marks>=90 && marks<95)
	{
		cout<<"Top Colleges for you: \n1)D.Y.Patil Akurdi \n2) MIT WPU \n3) MIT ADT \n4) JSPM ";
		condition = 2;
	}
	else if(marks>=85 && marks<90)
	{
		cout<<"Top Colleges for you: \n1) Modern College Of Engineering  \n2) AISSMS \n3) MIT Alandi \n4) DY Patil Pimpri ";
		condition = 3;
	}
	else if(marks<85)
	{
		cout<<"Top Colleges for you: \n1) MMMCOE (Marathwada Mitra Mandal College of Enginerring) \n2) Kashibai Navale College of Engineering \n3) Sinhagad College of Engineering,Vadgoan \n4) Sinhagad College of Engineering Kondhwa  ";
		condition = 4;
	}

	int MatrixOne[N][N] = { { INF, 3, 12, 10, 10},
								{ 3, INF, 11, 10,12 },
								{ 12, 11, INF, 4,6 },
								{ 10, 10, 4, INF, 3},
                                { 10,12 ,6 ,3 ,INF} };
	int MatrixTwo[N][N] = { { INF, 14, 9, 18,16 },
								{ 14, INF, 20, 32,35 },
								{ 9, 20, INF, 26, 15},
								{ 18, 32, 26, INF, 29},
                                {16, 35, 15, 29,INF} };
	int MatrixThree[N][N] = { { INF, 4, 2, 19,14 },
								{ 4, INF, 4, 21,13 },
								{ 2, 4, INF, 20,14 },
								{ 19, 21, 20, INF,12 },
                                { 14, 13, 14,12,INF } };
	int MatrixFour[N][N] = { { INF,11, 14, 13,12 },
								{ 11, INF, 7, 7,11 },
								{ 14, 7, INF, 1, 9},
								{ 13, 7, 1, INF,9 },
                                { 12, 11, 9, 9,INF } };
	
	switch (condition)
	{
	case 1:
		cout << "\n" << solve(MatrixOne)<< " is the total cost (in kms)" ;
		break;
	
	case 2:
		cout << "\n"<<solve(MatrixTwo)<< " is the total cost(in kms)" ;
		break;
	
	case 3:
		cout << "\n"<<solve(MatrixThree)<< " is the total cost(in kms)" ;
		break;
	
	case 4:
		cout << "\n"<<solve(MatrixFour)<< " is the total cost(in kms)" ;
		break;
	}
	cout<<"\n\nDo you want to continue?\n";
	string que;
	cout<<"\nY for Yes \nN for No\nEnter: ";
	cin>>que;
	if(que=="Y")
	{
		goto p;
	}
	else
	{
		cout<<"Thank you!!!";
		return 0;
	}
}