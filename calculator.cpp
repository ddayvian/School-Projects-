//Author: Dayvian Pena
//Calculator App
/* in this calculator app, my goal is to make a simple calculator
while improving it on a daily basis. first, ill start with a 
calc app using switch cases, to lastly hoping to have an advance calc app
that uses different techniques or methods */

#include <iostream>
#include <string>

using namespace std;

//calculator using switch cases
int main(){

double num1, num2;
char op;

cout<<"enter an operator: ";
cin>>op;
cout<<"enter your two numbers: ";
cin>>num1 >> num2;

switch(op){
    case '+':
    cout<< num1 << " + " << num2 << " = " << num1 + num2;
    break;
    
    case '-':
    cout<< num1 << " - " << num2 << " = " << num1 - num2;
    break;
    
    case '/':
    cout<< num1 << "/" << num2 << " = " << num1/num2;
    break;

    case '*':
    cout<< num1 << " * " << num2 << " = " << num1 * num2;
    break;

    default:
    cout<<"\noperator does not exist";
    break;
    
}

    return 0;
}



