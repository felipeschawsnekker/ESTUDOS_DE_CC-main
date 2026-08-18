#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct no{
    int valor;
    struct no *dir, *esq;
} NoArv;

// Função para inserir um novo valor na árvore binária de busca
NoArv* Inserir(NoArv *raiz, int num) {
    if (raiz == NULL) {
        NoArv *novo = new NoArv();
        novo->valor = num;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    } else {
        if (num < raiz->valor)
            raiz->esq = Inserir(raiz->esq, num);
        else
            raiz->dir = Inserir(raiz->dir, num);
        return raiz;
    }
}

// Imprime a árvore de forma hierárquica usando o nível para identação
void Imprimir(NoArv *raiz, int Nivel){
    if(raiz != NULL){
        Imprimir(raiz->dir, Nivel + 1);
        for(int i = 0; i < Nivel; i++)
            cout << "   ";
        cout << raiz->valor << endl;
        Imprimir(raiz->esq, Nivel + 1);
    }
}

// Busca um valor na árvore
NoArv* Buscar(NoArv *raiz, int chave){
    if(raiz == NULL || raiz->valor == chave)
        return raiz;
    if(chave < raiz->valor)
        return Buscar(raiz->esq, chave);
    else
        return Buscar(raiz->dir, chave);
}

// Calcula a altura da árvore
int Altura(NoArv *raiz){
    if(raiz == NULL)
        return -1;
    else {
        int esq = Altura(raiz->esq);
        int dir = Altura(raiz->dir);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

// Remove um nó da árvore
NoArv* RemoverNo(NoArv *raiz, int chave) {
    if(raiz == NULL)
        return NULL;
    
    if(raiz->valor == chave) {
        // Nó sem filhos (folha)
        if(raiz->esq == NULL && raiz->dir == NULL) {
            delete raiz;
            return NULL;
        }
        // Nó apenas com filho à direita
        if(raiz->esq == NULL) {
            NoArv *temp = raiz->dir;
            delete raiz;
            return temp;
        }
        // Nó apenas com filho à esquerda
        if(raiz->dir == NULL) {
            NoArv *temp = raiz->esq;
            delete raiz;
            return temp;
        }
        // Nó com dois filhos: pega o menor do ramo direito
        NoArv *temp = raiz->dir;
        while(temp->esq != NULL)
            temp = temp->esq;
        raiz->valor = temp->valor;
        raiz->dir = RemoverNo(raiz->dir, temp->valor);
        return raiz;
    } else {
        if(chave < raiz->valor)
            raiz->esq = RemoverNo(raiz->esq, chave);
        else
            raiz->dir = RemoverNo(raiz->dir, chave);
        return raiz;
    }
}

// Menu de opções
int Menu(){
    int opcao;
    cout << "\n=== MENU ARVORE ===" << endl;
    cout << "1. Inserir" << endl;
    cout << "2. Imprimir" << endl;
    cout << "3. Buscar" << endl;
    cout << "4. Altura" << endl;
    cout << "5. Remover" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opcao: ";
    cin >> opcao;
    return opcao;
}

int main() {
    NoArv *raiz = NULL;
    int opcao, valor;

    do {
        opcao = Menu();
        switch(opcao) {
            case 1:
                cout << "Digite o valor a inserir: ";
                cin >> valor;
                raiz = Inserir(raiz, valor);
                break;
            case 2:
                cout << "\nArvore Binaria:\n";
                Imprimir(raiz, 0);
                break;
            case 3:
                cout << "Digite o valor a buscar: ";
                cin >> valor;
                if(Buscar(raiz, valor))
                    cout << "Valor encontrado!\n";
                else
                    cout << "Valor nao encontrado.\n";
                break;
            case 4:
                cout << "Altura da arvore: " << Altura(raiz) << endl;
                break;
            case 5:
                cout << "Digite o valor a remover: ";
                cin >> valor;
                raiz = RemoverNo(raiz, valor);
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }
    } while(opcao != 0);

    return 0;
}
