#include <iostream>

using namespace std;

class matrix{
    public:
    int i,j;
    int size;
    int arr[4][4];

    matrix(){
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                arr[i][j] = 0;
            }
        }
    }

    void addEdge(int i,int j){
        arr[i][j] = 1;
        arr[j][i] = 1;
    }

    void printMatrix(){
        for (int i = 0; i < 4; i++)
        {
            cout<<i<<":";
            for (int j = 0; j < 4; j++)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }
};

int main(){
    matrix m;
    m.addEdge(1,3);
    m.addEdge(1,2);
    m.printMatrix();
}