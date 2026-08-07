#include <iostream>
#include <string.h>
using namespace std;

#define tam 3
typedef struct Cadastro{
    int conta;
    char nome[30];
    float saldo;
}Cad[tam];
int value;
void Menu(){
    cout<<"====================MENU===================="<<endl;
    cout<<"ENTRADA DAS INFORMAÇÕES - DIGITE 1"<<endl;
    cout<<"ORDENAÇÃO DO NOME EM ORDEM ASCENDENTE - DIGITE 2"<<endl;
    cout<<"GRAVAÇÃO DAS INFORMAÇÕES NO ARQUIVO - DIGITE 3"<<endl;
    cout<<"LEITURA DO ARQUIVO - DIGITE 4"<<endl;
    cout<<"LEITURA DAS INFORMAÇÕES DA ESTRUTURA - DIGITE 5"<<endl;
    cout<<"SAIR - DIGITE 6"<<endl;
    cout<<endl;
    cin>>value;
    
    
}

Cad pessoa;
void CadastrarIndividuos(){
    for(int i=0; i<tam; i++){
        cout<<"INDIVIDUO N* "<<i<<" - CONTA: "; cin>>pessoa[i].conta;
        cin.ignore();
        cout<<"INDIVIDUO N* "<<i<<" - NOME: "; gets(pessoa[i].nome);
        cout<<"INDIVIDUO N* "<<i<<" - SALDO: "; cin>>pessoa[i].saldo;
        
    }
}



int main(){
    Menu();
    while(true){
    switch(value){
        case 1:
            CadastrarIndividuos();
            Menu();
            break;
    }
    }
}
