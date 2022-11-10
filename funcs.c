#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "definitions.h"


//Função que cria o vetor alturas
int* criar_vetor(int tamanho){
  int* alturas;
  int i;

  alturas = calloc(tamanho, sizeof(int));

  for(i=0;i<tamanho; i++){
    alturas[i]=0;
  }

return alturas;
}

//Função que cria as alturas
int* criar_alturas(int tamanho, int esquerda, int direita, double n, int* alturas){
  int i,j;


  alturas[0]=esquerda;
  alturas[tamanho-1]=direita;
  //Preenchimento do vetor alturas
 for(i=0; i<tamanho-1; i+=2){
   for(j=tamanho-1; j>i; j-=2){
     //Controle dos loops
     if((i+j)%2==1){
       //Quando impar, não existe midpoint
     }else{
       if(alturas[(i+j)/2]==0){
         if(alturas[j]==0){
         }else{
          alturas[(i+j)/2]=(alturas[i]+alturas[j])/2;
          if(rand()%2 == 0){
            alturas[(i+j)/2] -= ((rand() % 10)+1)*(n/100);
          }else{
            alturas[(i+j)/2] += ((rand() % 10)+1)*(n/100);
            }
          }//print do vetor a cada nova mudança
         }else {
         if(alturas[j]==0){
           //printf(" Valor em [j] zerado!\n");
         }else{
           alturas[(i+j)/2]=(alturas[i]+alturas[j])/2;
           if(rand()%2 == 0){
            alturas[(i+j)/2] -= ((rand() % 10)+1)*(n/100);
          }else{
            alturas[(i+j)/2] += ((rand() % 10)+1)*(n/100);
          }
           //printf(" Substitui!\n"); //controle de vetor já preenchido
         }
       }
     }
   }
 }



return alturas;
}

//Função para criar alturas secundárias
int* criar_diagonal(int tamanho, int v, int* alturas){
  int i,j;

    if(v==2){
      alturas[0]=0;
      for(i=0,j=1;i<tamanho-1;i++,j++){
        alturas[j]=alturas[i] + (rand() % 2);
      }
    }if(v==3){
      alturas[0]=180;
      for(i=0,j=1;i<tamanho-1;i++,j++){
        alturas[j]=alturas[i] - (rand() % 2);
      }
    }

  return alturas;
}

//Função para criar matriz e zerar a mesma
int** criar_matriz(int tamanho){
  int** matriz;
  int i,j;

  matriz = calloc(tamanho, sizeof(int *));
  for(i=0; i<tamanho; i++){
    matriz[i]=calloc(tamanho, sizeof(int));
  }

  for(i=0; i<tamanho; i++){
    for(j=0; j<tamanho; j++){
      if((i>24 && i<73) && (j>26 && j<75)){
         matriz[i][j] = 5;
      }else{
        matriz[i][j]= 0;
      }
    }
  }

  
return matriz;
}


int** criar_montanha(int* alturas,int tamanho,int **matriz_montanha, int v){
  int i,j;

 //Representando alturas em matriz
  for(i=0; i<tamanho; i++){
    for(j=tamanho-1; j>=tamanho-alturas[i]; j--){
      matriz_montanha[j][i]=v;
    }
  }

return matriz_montanha;
}

int** criar_montanha2(int* alturas,int tamanho,int **matriz_montanha){
  int i,j;

 //Representando alturas em matriz
  for(i=0; i<tamanho; i++){
    for(j=tamanho-1; j>=tamanho-alturas[i]; j--){
      matriz_montanha[j][i]=1;
    }
  }

return matriz_montanha;
}