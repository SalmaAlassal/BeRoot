#include <iostream>
using namespace std;
int sum(int a,int b);
int sub(int a,int b);
int main(){
    cout << "Hello World! I am a C++ program" << endl;
    cout << "The sum of 1 and 2 is " << sum(1,2) << endl;
    cout << "The sub of 1 and 2 is " << sub(1,2) << endl;
    return 0;
}
int sum(int a, int b){
    return a+b;
}
int sub(int a, int b){
    return a-b;
}
