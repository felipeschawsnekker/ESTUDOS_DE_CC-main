/* Faça um programa que utiliza duas variáveis globais e 
calcule a média na função calculo. Imprima na main*/
#include <iostream>
using namespace std;
float X;
float Y;

float Calculo(float X, float Y){
    return (X+Y)/2;
}

int main(){
    cout<<"Digite dois valores: "<<endl;
    cout<<"Valor 1: "; cin>>X;
    cout<<"Valor 2: "; cin>>Y;
    float media=Calculo(X,Y);
    cout<<"A media e: "<<media;
    return 0;
}