#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int distances[9];
bool visited[9];
int resultant[9];


int minDistanceVertex(int d[],bool v[]){
    int minimum = INT_MAX;
    int index;
    for (int i = 0; i < 9; i++)
    {
        if(!v[i] && d[i] <= minimum){
            minimum = d[i];
            index = i;
        }
    }
    return index;
}

void Dijkstra(int graph[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    distances[0] = 0;

    for (int i = 0; i < 9; i++)
    {
        int minVertexIndex = minDistanceVertex(distances,visited);
        visited[minVertexIndex] = true;
        for (int j = 0; j < 9; j++)
        {
            if(graph[minVertexIndex][j] && !visited[j]){
                int tempDistance = distances[minVertexIndex]+graph[minVertexIndex][j];
                if(tempDistance < distances[j]){
                    distances[j] = tempDistance;
                }
            }
        }
        
    }

    cout<<"Distance from Source:"<<endl;
    for (int j = 0; j < 9; j++)
    {
        cout<<distances[j];
        cout<<endl;
    }
}


int main()
{
    int adjMatrix[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                           {4, 0, 8, 0, 0, 0, 0, 11, 0},
                           {0, 8, 0, 7, 0, 4, 0, 0, 2},
                           {0, 0, 7, 0, 9, 14, 0, 0, 0},
                           {0, 0, 0, 9, 0, 10, 0, 0, 0},
                           {0, 0, 4, 14, 10, 0, 2, 0, 0},
                           {0, 0, 0, 0, 0, 2, 0, 1, 6},
                           {8, 11, 0, 0, 0, 0, 1, 0, 7},
                           {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    Dijkstra(adjMatrix);
}