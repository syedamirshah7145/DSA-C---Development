#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minKey(int key[], bool visited[])
{
    int min = INT_MAX, min_index;

    for (int i = 0; i < 5; i++)
    {
        if (!visited[i] && key[i] < min)
        {
            min_index = i;
            min = key[i];
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[5][5])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < 5; i++){
        cout << parent[i] << " - " << i << " \t";
        cout << graph[i][parent[i]] << " \n";}
}

void primsAlgorithm(int graph[5][5])
{

    bool visited[5];
    int key[5];
    int resultant[5];

    for (int i = 0; i < 5; i++)
    {
        visited[i] = false;
        key[i] = INT_MAX;
    }

    // to pick 0 as first minimum vertex
    key[0] = 0;
    resultant[0] = -1;

    for (int i = 0; i < 5 - 1; i++)
    {
        int min = minKey(key, visited);

        visited[min] = true;

        for (int j = 0; j < 5; j++)
        {
            if (!visited[j] && graph[i][j] && graph[i][j] < key[j])
            {
                resultant[j] = min;
                key[j] = graph[i][j];
            }
        }
    }
    printMST(resultant, graph);
}

int main()
{
    int graph[5][5] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    primsAlgorithm(graph);
}