#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "definitions.h"

void imprimir_menu(){
  printf("Bem vindo ao gerador de montanhas 3000!\nIremos gerar uma imagem de 513x513p em PPM com um gradiente de montanhas para você!\n");
}

void imprimir_complete(){
  printf("Arquivo gerado com sucesso!\n");
}
  
//Função que imprime as cores no arquivo
void imprime_cores(int tamanho, int** matriz_montanha, FILE* arquivo){
  int i, j;
  //Definição de cores
  palheta terreno1;
  terreno1.R=5;
  terreno1.G=196;
  terreno1.B=63;

  palheta terreno2;
  terreno2.R=4;
  terreno2.G=137;
  terreno2.B=88;

  palheta terreno3;
  terreno3.R=4;
  terreno3.G=113;
  terreno3.B=107;

  palheta ceu;
  ceu.R=30;
  ceu.G=255;
  ceu.B=247;

  palheta sol;
  sol.R=255;
  sol.G=216;
  sol.B=93;

  //fPrintf da Matriz no arquivo
  for(i=0;i<tamanho;i++){
    if(i!=0){
      fprintf(arquivo,"\n");
    }
    for(j=0;j<tamanho;j++){
        if(matriz_montanha[i][j]==0){
          //cor ceu
          fprintf(arquivo,"%d %d %d\n", ceu.R, ceu.G, ceu.B);
        }
        if(matriz_montanha[i][j]==1){
          //cor montanha 1
          fprintf(arquivo,"%d %d %d\n", terreno1.R, terreno1.G, terreno1.B);
        }
        if(matriz_montanha[i][j]==2){
          //cor montanha 2
          fprintf(arquivo,"%d %d %d\n", terreno2.R, terreno2.G, terreno2.B);
        }
        if(matriz_montanha[i][j]==3){
          //cor montanha 3
          fprintf(arquivo,"%d %d %d\n", terreno3.R, terreno3.G, terreno3.B);
        }
        if(matriz_montanha[i][j]==5){
          //cor montanha 3
          fprintf(arquivo,"%d %d %d\n", sol.R, sol.G, sol.B);
        }
      }
    }
  }
