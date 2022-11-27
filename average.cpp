#include <iostream>

using namespace std;

int main(){
    double total = 0;
    double counter = 0;
    int grade = 0;
    cout<<"Enter Grade, -1 to end: ";
    cin>>grade;
    while(grade!=-1){
        total += grade;
        cout<<"Enter Grade, -1 to end: ";
        cin>>grade;
        counter++;
    }
    if(counter != 0){
        double average = total/counter;
        cout<<"Class Average is: "<<average;
    }
    else{
        cout<<"No grades were entered!";
    }
    return 0;
}