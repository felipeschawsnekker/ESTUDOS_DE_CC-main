#include <iostream>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Jogador{
    double vida;
    double ataque_padrao;
    double chance_de_esquivar;
    double multiplicador_critico;
};

int LancarDado(){
    srand(time(0));
    return (rand()%6+1);
}


double Esquivar(){
    srand(time(0));
    int numero_aleatorio=(rand()%100+70);
    int temp_soma=0;
    double porcentagem;
    for(int i=1; i<numero_aleatorio; i++){
        if(LancarDado()>=5){
            temp_soma+=LancarDado();
        }
    }
    porcentagem=double((1000-double((temp_soma+numero_aleatorio)))/100.0);
    return porcentagem;
}

double Critico(){
    return ((Esquivar()+Esquivar()*(1+1*(LancarDado()/100)))/10);
}

double Vida(){
    int temp_vida=0;
    for(int i=0; i<10; i++){
        temp_vida+=LancarDado();
    }
    return (temp_vida*Critico())*(1+Esquivar());
}

double AtaquePadrao(){
    return (Vida()*0.1415)/2;
}




int main(){
/* struct Jogador{
    double vida;
    double ataque_padrao;
    double chance_de_esquivar;
    double multiplicador_critico;
    int dados_sorteados[];
};*/
    
    Jogador player;
    player.vida=Vida();
    cout<<int(Vida())<<endl;
    cout<<int(AtaquePadrao())<<endl;
}

