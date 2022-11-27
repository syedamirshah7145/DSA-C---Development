#include <iostream>

using namespace std;

int main(){
    int passes = 0;
    int failures = 0;
    int studentCounter = 1;
    while(studentCounter<=10){
        int result = 0;
        cout<<"Enter result (1=pass, 2=fail): ";
        cin>>result;
        if(result==1){
            passes += 1;
        }
        else{
            failures +=1;
        }
        studentCounter += 1;
    }
    cout<<"Passed: "<<passes<<endl;
    cout<<"Failures: "<<failures<<endl;
    if(passes >= 8){
        cout<<"Raise tuition!";
    }
}