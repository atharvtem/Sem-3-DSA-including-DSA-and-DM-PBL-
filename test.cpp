#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int N = 5;

int final_path[N+1];
 
bool visited[N];
 
int final_res = INT_MAX;

void copyToFinal(int curr_path[])
{
    for (int i=0; i<N; i++)
    {
        final_path[i] = curr_path[i];
    }
    final_path[N] = curr_path[0];
}
 
int firstMin(int adj[N][N], int i)
{
    int min = INT_MAX;
    for (int k=0; k<N; k++)
        if (adj[i][k]<min && i != k)
            min = adj[i][k];
    return min;
}

int secondMin(int adj[N][N], int i)
{
    int first = INT_MAX, second = INT_MAX;
    for (int j=0; j<N; j++)
    {
        if (i == j)
            continue;
 
        if (adj[i][j] <= first)
        {
            second = first;
            first = adj[i][j];
        }
        else if (adj[i][j] <= second &&
                 adj[i][j] != first)
            second = adj[i][j];
    }
    return second;
}

void TSPRec(int adj[N][N], int curr_bound, int curr_weight, int level, int curr_path[])
{
    if (level==N)
    {
        if (adj[curr_path[level-1]][curr_path[0]] != 0)
        {
            int curr_res = curr_weight + adj[curr_path[level-1]][curr_path[0]];

            if (curr_res < final_res)
            {
                copyToFinal(curr_path);
                final_res = curr_res;
            }
        }
        return;
    }

    for (int i=0; i<N; i++)
    {
        if (adj[curr_path[level-1]][i] != 0 && visited[i] == false)
        {
            int temp = curr_bound;
            curr_weight += adj[curr_path[level-1]][i];

            if (level==1)
            {
                curr_bound -= ((firstMin(adj, curr_path[level-1]) + firstMin(adj, i))/2);
            }

            else
            {
                curr_bound -= ((secondMin(adj, curr_path[level-1]) + firstMin(adj, i))/2);
            }

            if (curr_bound + curr_weight < final_res)
            {
                curr_path[level] = i;
                visited[i] = true;
 
                TSPRec(adj, curr_bound, curr_weight, level+1, curr_path);
            }

            curr_weight -= adj[curr_path[level-1]][i];
            curr_bound = temp;

            memset(visited, false, sizeof(visited));
            for (int j=0; j<=level-1; j++)
                visited[curr_path[j]] = true;
        }
    }
}

void solve(int adj[N][N])
{
    int curr_path[N+1];

    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(curr_path));
 
    for (int i=0; i<N; i++)
        curr_bound += (firstMin(adj, i) + secondMin(adj, i));
 
    curr_bound = (curr_bound&1) ? curr_bound/2 + 1 : curr_bound/2;

    visited[0] = true;
    curr_path[0] = 0;

    TSPRec(adj, curr_bound, 0, 1, curr_path);
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
		cout<<"\nTop Colleges for you: \n1)COEP \n2)PICT \n3)VIT \n4)VIIT ";
		condition = 1;
	}
	else if(marks>=90 && marks<95)
	{
		cout<<"\nTop Colleges for you: \n1)D.Y.Patil Akurdi \n2) MIT WPU \n3) MIT ADT \n4) JSPM ";
		condition = 2;
	}
	else if(marks>=85 && marks<90)
	{
		cout<<"\nTop Colleges for you: \n1) Modern College Of Engineering  \n2) AISSMS \n3) MIT Alandi \n4) DY Patil Pimpri ";
		condition = 3;
	}
	else if(marks<85)
	{
		cout<<"\nTop Colleges for you: \n1) MMMCOE (Marathwada Mitra Mandal College of Enginerring) \n2) Kashibai Navale College of Engineering \n3) Sinhagad College of Engineering \n4) Sinhagad College of Engineering Kondhwa  ";
		condition = 4;
	}

	int MatrixOne[N][N] = { { 0, 3, 12, 10, 10},
								{ 3, 0, 11, 10,12 },
								{ 12, 11, 0, 4, 6 },
								{ 10, 10, 4, 0, 3},
                                { 10,12 ,6 ,3 ,0} };
	int MatrixTwo[N][N] = { { 0, 14, 9, 18,16 },
								{ 14, 0, 20, 32,35 },
								{ 9, 20, 0, 26, 15},
								{ 18, 32, 26, 0, 29},
                                {16, 35, 15, 29,0} };
	int MatrixThree[N][N] = { { 0, 4, 2, 19,14 },
								{ 4, 0, 4, 21,13 },
								{ 2, 4, 0, 20,14 },
								{ 19, 21, 20, 0,12 },
                                { 14, 13, 14,12,0 } };
	int MatrixFour[N][N] = { { 0,11, 14, 13,12 },
								{ 11, 0, 7, 7,11 },
								{ 14, 7, 0, 1, 9},
								{ 13, 7, 1, 0,9 },
                                { 12, 11, 9, 9,0 } };
	
	switch (condition)
	{
	case 1:
		cout<<'\n';
		solve(MatrixOne);
		break;
	
	case 2:
		cout<<'\n';
		solve(MatrixTwo);
		break;
	
	case 3:
		cout<<'\n';
		solve(MatrixThree); 
		break;
	
	case 4:
		cout<<'\n';
		solve(MatrixFour); 
		break;
	}
    cout<<"\n\nMinimum cost :  " << final_res << "\n";
    cout<<"\nPath Taken : ";
    for (int i = 0; i <= N; i++)
        {
            if(final_path[i]==0)
            {
                cout<<"Pune Tasen";
            }
            else if(final_path[i]==1 && condition==1)
            {
                cout<<"COEP";
            }
            else if(final_path[i]==2 && condition==1)
            {
                cout<<"PICT";
            }
            else if(final_path[i]==3 && condition==1)
            {
                cout<<"VIT";
            }
            else if(final_path[i]==4 && condition==1)
            {
                cout<<"VIIT";
            }
            else if(final_path[i]==1 && condition==2)
            {
                cout<<"D.Y.Patil Akurdi";
            }
            else if(final_path[i]==2 && condition==2)
            {
                cout<<"MIT WPU";
            }
            else if(final_path[i]==3 && condition==2)
            {
                cout<<"MIT ADT";
            }
            else if(final_path[i]==4 && condition==2)
            {
                cout<<"JSPM";
            }
            else if(final_path[i]==1 && condition==3)
            {
                cout<<"Modern College Of Engineering";
            }
            else if(final_path[i]==2 && condition==3)
            {
                cout<<"AISSMS";
            }
            else if(final_path[i]==3 && condition==3)
            {
                cout<<"MIT Alandi";
            }
            else if(final_path[i]==4 && condition==3)
            {
                cout<<"D.Y.Patil Pimpri";
            }
            else if(final_path[i]==1 && condition==4)
            {
                cout<<"MMMCOE (Marathwada Mitra Mandal College of Enginerring)";
            }
            else if(final_path[i]==2 && condition==4)
            {
                cout<<"Kashibai Navale College of Engineering";
            }
            else if(final_path[i]==3 && condition==4)
            {
                cout<<"Sinhagad College of Engineering,Vadgoan";
            }
            else if(final_path[i]==4 && condition==4)
            {
                cout<<"Sinhagad College of Engineering,Kondhwa";
            }

            if(i<N)
            {
                cout<<"-> ";
            }

        }

	cout<<"\n\nDo you want to continue?\n";
	string que;
	cout<<"\nY for Yes \nN for No\nEnter: ";
	cin>>que;
	if(que=="Y" or que=="y")
	{
		goto p;
	}
	else
	{
		cout<<"Thank you!!!";
		return 0;
	}
}