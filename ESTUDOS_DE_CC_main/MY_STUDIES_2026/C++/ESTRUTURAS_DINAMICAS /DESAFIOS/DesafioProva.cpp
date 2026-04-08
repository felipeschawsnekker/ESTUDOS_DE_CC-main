#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


struct tam(){
    int x; 
    int y;
}
//pA[i*a[1] + j]
void multiplicaMatriz(float *a, tam A, float *b, tam B,float *C){
    for(int i=0; i<A.x; i++){
        for(int j=0; j<B.y; j++){
            C[i*B.y+j]=0;
            for(int k=0; k<A.y; k++){
                C[i*B.y+j]=(A[i*A.y+k])*(B[k*B.y+j]);
            }
        }
    }
}

void mostrarMatriz(float *p,int tam L){

    for(int i=0; i<(T.x); i++){
        cout<<"[ ";
        for(int j=0; j<(T.y); i++){
            cout<<p[i*T.y+j];
        }
        cout<<" ]"
        cout<<endl;
    }
}

preencherMatriz(float *p){
    for(int i=0; i<)
}
int main(){
    cout<<"Digite o tamanho da matriz A: "<<endl;
    int a[2];
    cout<<"A[][]: "; 
    cin>>a[0];
    cout<<"A["<<a[0]<<"][]: ";
    cin>>a[1];
    cout<<"A["<<a[0]<<"]["<<a[1]<<"]"<<endl;
    tam A;
    A.x=a[0];
    A.y=a[1];
    
    cout<<"Digite o tamanho da matriz B: "<<endl;
    int b[2];
    cout<<"B[][]: "; 
    cin>>b[0];
    cout<<"B["<<b[0]<<"][]: ";
    cin>>b[1];
    cout<<"B["<<b[0]<<"]["<<b[1]<<"]"<<endl;
    tam B;
    B.x=b[0];
    B.y=b[1];
    
    tam C={A.x,B.y}
    if(!((a[0] == b[0] && a[1]==b[1] )|| a[1]==b[0])){
        cout<<"Tamanho inválido para multiplicação"<<endl;
        return 0;
    }
    
    //float *a, tam A, float *b, tam B,float *C
    multiplicaMatriz(p)
    
    float matrizA[a[0]][a[1]];
    float matrizB[b[0]][b[1]];
    float matrizC[a[0]][b[1]];
    float *pA=&matrizA[0][0]; // pA[i*a[1] + j]
    float *pB=&matrizB[0][0]; // pB [i*b[1]+ j]
    float *pC=&matriz[0][0];
    
    
}

