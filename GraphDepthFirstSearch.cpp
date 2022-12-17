#include <iostream>

using namespace std;

#define MAX 5


// Defining stack for DFS
int stack[MAX];
int top = -1;

bool isEmptyStack(){
    if(top == -1){
        return true;
    }
    return false;
}

void push(int element){
    stack[++top] = element;
}

int pop(){
    return stack[top--];
}

int topElement(){
    return stack[top];
}




//Defining Graph
struct vertex{
    char label;
    bool visited;
};

int adjMatrix[MAX][MAX];
int vertexCount = 0;
vertex *listVertices[MAX];

void addVertex(char element){
    vertex *temp = new vertex;
    temp->label = element;
    temp->visited = false;
    listVertices[vertexCount++] = temp;
}

void addEdge(int vNum,int eNum){
    adjMatrix[vNum][eNum] = 1;
    adjMatrix[eNum][vNum] = 1;
}

void displayVertex(int vNum){
    cout<<listVertices[vNum]->label<<endl;
}

int getAdjacentUnvisitedNodes(int vNum){
    for (int i = 0; i < vertexCount; i++)
    {
        if(adjMatrix[vNum][i] == 1 && listVertices[i]->visited == false){
            return i;
        }
    }
    return -1;
}

void depthFirstSearch(){
    listVertices[0]->visited = true;
    displayVertex(0);
    push(0);
    while(!isEmptyStack()){
        //getting unvisited nodes
        int unvisitedNode = getAdjacentUnvisitedNodes(topElement());
        if(unvisitedNode == -1){
            pop();
        }
        else{
            listVertices[unvisitedNode]->visited = true;
            displayVertex(unvisitedNode);
            push(unvisitedNode);
        }

    }

    //after stack empty, reset the visited state of each vertix
    for (int i = 0; i < vertexCount; i++)
    {
        listVertices[i]->visited = false;
    }
}





int main(){
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    addVertex('A');
    addVertex('F');
    addVertex('H');
    addEdge(0,1);
    depthFirstSearch();
}