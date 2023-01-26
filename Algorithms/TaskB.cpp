#include <iostream>

using namespace std;

#define student 5
#define quizes 5

int data[student][quizes];

void displayAllQuizesMarks(int rollNo){
    for (int i = 0; i < student; i++)
    {
        if(data[i][0] == rollNo){
            for (int j = 1; j < quizes; j++)
            {
                cout<<data[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
}

void displayOneQuizesMarks(int rollNo,int quizNo){
    for (int i = 0; i < student; i++)
    {
        if(data[i][0] == rollNo){
            cout<<data[i][quizNo]<<endl;
        }
    }
}

void enterData(int rollNo,int marks[quizes-1]){
    for (int i = 0; i < student; i++)
    {
        if(data[i][0] != -1){
            data[i][0] = rollNo;
            for (int j = 1; j < quizes; j++)
            {
                data[i][j] = marks[j-1];
            }
        }
    }
    
}

void calculateAverage(){
    double average = 0;
    for (int i = 0; i < student; i++)
    {
        if(data[i][0] != -1){
            cout<<"Average of Student "<<data[i][0]<<endl;
            for (int j = 1; j < quizes; j++)
            {
                average += data[i][j];
            }
            average = average/(quizes-1);
            cout<<average<<endl;
        }
    }
}

int main(){
    for (int i = 0; i < student; i++)
    {
        for (int j = 0; j < quizes; j++)
        {
            data[i][j] = -1;
        }
    }
    data[0][0] = 001;
    data[0][1] = 12;
    data[0][2] =23;
    int quiz[quizes-1] = {12,23,42,41};
    displayAllQuizesMarks(001);
}

