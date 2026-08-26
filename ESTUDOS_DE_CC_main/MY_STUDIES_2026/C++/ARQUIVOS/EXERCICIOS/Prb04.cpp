#include <iostream>
#include <cstdio>
using namespace std;

void geraArquivo(){
    FILE *arquivo=fopen("Arq04.txt","w");
        if(arquivo!=nullptr){
            cout<<"Arquivo criado!";
        }
    fclose(arquivo);
    }

void gravarArquivo(){
    FILE *arquivo=fopen("Arq04.txt","w");
    fprintf(arquivo,"Frase qualquer, escrevendo");
    cout<<"Arquivo escrito!"<<endl;
    fclose(arquivo);
}

void lerArquivo(){
    FILE *arquivo=fopen("Arq04.txt","r");
    if(arquivo==NULL){
        cout<<"Erro ao abrir o arquivo!"<<endl;
    }
    char buffer[100];
    size_t itensLidos = fread(buffer,sizeof(char),99,arquivo);
    buffer[itensLidos]='\0';
    cout<<"Conteúdo lido: "<<buffer;
    fclose(arquivo);
}


int main(){
    geraArquivo();
    gravarArquivo();
    lerArquivo();
}
