#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

#define tam 3
typedef struct Cadastro{
    int conta;
    char nome[30];
    float saldo;
}Cad[tam];
int value;
bool cadastrado = false;

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
    cadastrado = true;
}

void OrdenarNomes(){
    if(!cadastrado){
        cout<<"NENHUM DADO CADASTRADO!"<<endl;
        return;
    }
    struct Cadastro aux;
    for(int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam; j++){
            if(strcmp(pessoa[i].nome, pessoa[j].nome) > 0){
                aux = pessoa[i];
                pessoa[i] = pessoa[j];
                pessoa[j] = aux;
            }
        }
    }
}

void GravarArquivo(){
    if(!cadastrado){
        cout<<"NENHUM DADO CADASTRADO PARA GRAVAR!"<<endl;
        return;
    }
    ofstream arq("dados.txt");
    for(int i=0; i<tam; i++){
        arq<<pessoa[i].conta<<endl;
        arq<<pessoa[i].nome<<endl;
        arq<<pessoa[i].saldo<<endl;
    }
    arq.close();
}

void LerArquivo(){
    ifstream arq("dados.txt");
    if(!arq.is_open()){
        cout<<"ERRO AO ABRIR O ARQUIVO OU ARQUIVO INEXISTENTE!"<<endl;
        return;
    }
    Cadastro temp;
    for(int i=0; i<tam; i++){
        arq>>temp.conta;
        arq.ignore();
        arq.getline(temp.nome, 30);
        arq>>temp.saldo;
        cout<<"INDIVIDUO N* "<<i<<" - CONTA: "<<temp.conta<<endl;
        cout<<"INDIVIDUO N* "<<i<<" - NOME: "<<temp.nome<<endl;
        cout<<"INDIVIDUO N* "<<i<<" - SALDO: "<<temp.saldo<<endl;
    }
    arq.close();
}

void LerEstrutura(){
    if(!cadastrado){
        cout<<"NENHUM DADO CADASTRADO!"<<endl;
        return;
    }
    for(int i=0; i<tam; i++){
        cout<<"INDIVIDUO N* "<<i<<" - CONTA: "<<pessoa[i].conta<<endl;
        cout<<"INDIVIDUO N* "<<i<<" - NOME: "<<pessoa[i].nome<<endl;
        cout<<"INDIVIDUO N* "<<i<<" - SALDO: "<<pessoa[i].saldo<<endl;
    }
}

int main(){
    Menu();
    while(value != 6){
        switch(value){
            case 1:
                CadastrarIndividuos();
                Menu();
                break;
            case 2:
                OrdenarNomes();
                Menu();
                break;
            case 3:
                GravarArquivo();
                Menu();
                break;
            case 4:
                LerArquivo();
                Menu();
                break;
            case 5:
                LerEstrutura();
                Menu();
                break;
            case 6:
                break;
        }
    }
}
