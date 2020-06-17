#include<iostream>
#include<string>
#include <vector>
using namespace std;

vector<vector<int>> incidence_matrix_to_adjacency(vector<vector<int>> incidenceMatrix, int M, int N)
{
	vector<vector<int>> adjacencyMartix(N, vector<int>(N, 0));
	for (int column = 0; column < M; column++)
	{
		int from = -1;
		int to = -1;
		for (int row = 0; row < N; row++)
		{
			if (from != -1 && to != -1) 
			{
				break;
			}
			if (incidenceMatrix[row][column] == 1)
			{
				from = row;
			}
			else if (incidenceMatrix[row][column] == -1)
			{
				to = row;
			}
		}
		adjacencyMartix[from][to] = 1;
	}
	return adjacencyMartix;
}

void print(vector<vector<int>> matrix)
{
	cout << "ћатрица смежности: " << endl;
	for (auto row : matrix)
	{
		for (auto item : row)
		{
			cout << item << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> edge_list_to_adjacency(vector<int> g, vector<int> h, int N)
{
	vector<vector<int>> adjacencyMartix(N, vector<int>(N, 0));
	int from;
	int to;
	for (int i = 0; i < g.size(); i++)
	{
		from = g[i] - 1;
		to = h[i] - 1;
		adjacencyMartix[from][to] = 1;
	}
	return adjacencyMartix;
}

vector<vector<int>> adjacency_list_to_adjacency(vector<vector<int>> adjacency_list, int N)
{
	vector<vector<int>> adjacencyMartix(N, vector<int>(N, 0));
	int from;
	int to;
	for (int row = 0; row < N; row++)
	{
		from = row;
		if (!adjacency_list[row].empty())
		{
			for (auto item : adjacency_list[row])
			{
				to = item - 1;
				adjacencyMartix[from][to] = 1;
			}
		}
	}
	return adjacencyMartix;
}

vector<vector<int>> build_adjacency_martix(vector<vector<int>> graph, string storage_method, int N)
{
	if (storage_method == "матрица инцидентности")
	{
		return incidence_matrix_to_adjacency(graph, graph[0].size(), N);
	}
	else if (storage_method == "список ребер")
	{
		return edge_list_to_adjacency(graph[0], graph[1], N);
	}
	else if (storage_method == "список смежности")
	{
		return adjacency_list_to_adjacency(graph, N);
	}
	else
	{
		cout << "Ќекорректный ввод" << endl;
		return vector<vector<int>>();
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	
	vector<vector<int>> incidenceMatrix = { {1,0,0,-1,0},{-1,1,0,0,1},{0,-1,-1,0,0},{0,0,1,1,-1} };
	auto adjacency_matrix = build_adjacency_martix(incidenceMatrix, "матрица инцидентности", 4);
	print(adjacency_matrix);

	vector<vector<int>> edge_list = { {1,2,2,4,4},{2,3,4,1,3} };
	adjacency_matrix = build_adjacency_martix(edge_list, "список ребер", 4);
	print(adjacency_matrix);

	vector<vector<int>> adjacency_list = { {2},{3,4},{},{1,3} };
	adjacency_matrix = build_adjacency_martix(adjacency_list, "список смежности", 4);
	print(adjacency_matrix);

	system("pause");
	return 0;
}