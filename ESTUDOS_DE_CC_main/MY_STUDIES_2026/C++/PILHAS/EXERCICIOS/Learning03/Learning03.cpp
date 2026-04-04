/* Inverta um array usando uma pilha
Dado um array de 10 inteiros, use uma pilha para deixar o array ao contrário.*/

#include <iostream>
#include <cstdlib>
using namespace std;

struct Pilha{
    int dados[10];
    int topo;
};

void init(Pilha &p){
    p.topo=-1;
}

void push(Pilha &p,int x){
    if(p.topo==9){
        cout<<"Pilha cheia\n";
        return;
    }
    p.dados[++p.topo]=x;
}

int pop(Pilha &p){
    if(p.topo==-1){
        cout<<"Pilha vazia\n";
        return -1;
    }
    return p.dados[p.topo--];
}

void show(Pilha &p){
    if(p.topo==-1){
        cout<<"Pilha vazia\n";
        return;
    }
    cout<<"Elementos da pilha: ";
    for(int i=p.topo; i>=0; i--){
        cout<<p.dados[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Pilha p;
    init(p);
    int arr[10];
    cout<<"Digite 10 números inteiros:\n";
    for(int i=0; i<10; i++){
        cin>>arr[i];
        push(p, arr[i]);
    }

    cout<<"\nArray invertido:\n";
    for(int i=0; i<10; i++){
        arr[i] = pop(p);
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}

