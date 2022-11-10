#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "definitions.h"
#include "funcs.h"
#include "io.h"



/////////////MAIN//////////////////
int main(int argc, char* argv[]) {
  int i, j,tam=513,n_int; //n=deslocamento máximo
  double n;
  int* vetor_alturas,*aux;
  int** matriz_montanha;
  char nome_arquivo[100];
  char entrada_n[3] = "-d";
  char entrada_nome[3] = "-o";

  FILE *padrao;
  padrao = fopen("padrao", "r");

  aux = calloc(2, sizeof(int));

  // Leitor do buffer Inicial (gerenciamento das entradas)
  // se argc = 1 carrega os dados padrao
  if(argc == 1){
    fscanf(padrao," %d", aux);
    n = *aux;
    free(aux);
    fscanf(padrao," %[^\n]", nome_arquivo);
    printf("Base Default carregada com sucesso!\n");
  //se argc = 3 carrega o dado fornecido e um base
  }else if(argc == 3){
    if(strcmp(argv[1],entrada_n) == 0){
      n = atoi(argv[2]);
      fscanf(padrao," %d", aux);
      free(aux);
      fscanf(padrao," %[^\n]", nome_arquivo);
      printf("Nome Default carregado com sucesso!\n");
    }else if(strcmp(argv[1],entrada_nome) == 0){
      strcpy(nome_arquivo,argv[2]);
      fscanf(padrao," %d", aux);
      n = *aux;
      free(aux);
      printf("Valor Default carregado com sucesso!\n");
      }else{
      printf("Entrada não reconhecida!\n");
      return 0;
      }
  //se argc = 5 carrega os dois dados do buffer
  }else if(argc == 5){
    if(strcmp(argv[1],entrada_n) == 0){
      n = atoi(argv[2]);
    }else{
      printf("Entrada não reconhecida!\n");
      return 0;
    }
    if(strcmp(argv[3],entrada_nome) == 0){
      strcpy(nome_arquivo,argv[4]);
    }else{
      printf("Entrada não reconhecida!\n");
      return 0;
    }

  }

  fclose(padrao);

  imprimir_menu();

  srand(time(NULL));
  
  //Entrada do nome do arquivo

  n_int = n;
  //Inicializando os extremos das alturas
  int esquerda = (rand() % n_int)+(n+200);
  int direita = (rand() % n_int)+(n+200);
  
  //Criando o vetor com as alturas
  vetor_alturas = criar_vetor(tam);
  vetor_alturas = criar_alturas(tam, esquerda, direita, n, vetor_alturas);

  //Criando a matriz base
  matriz_montanha = criar_matriz(tam);

  //Representando alturas na matriz
  int v=1;
  matriz_montanha = criar_montanha(vetor_alturas, tam, matriz_montanha, v);
  
  //Montanhas secundárias diagonais
  //v representa o numero da montanha nova(de 2 à 3)
  for(int v=2; v<=3; v++){
    free(vetor_alturas);
    vetor_alturas = criar_vetor(tam);
    vetor_alturas = criar_diagonal(tam, v, vetor_alturas);
    matriz_montanha = criar_montanha(vetor_alturas, tam, matriz_montanha, v);
  }

  //Abertura do arquivo
  FILE *arquivo;
  arquivo=fopen(nome_arquivo, "w");
  if(arquivo==NULL){
    printf("Erro ao abrir o arquivo!");
    return 0;
  }

  //Cabeçalho PPM
  fprintf(arquivo, "P3\n");
  fprintf(arquivo, "%d %d\n", tam, tam);
  fprintf(arquivo, "255\n");

  //fPrintf da Matriz no arquivo
  imprime_cores(tam, matriz_montanha, arquivo);

  //Livrando a memória
  fclose(arquivo);
  imprimir_complete();

return 0;
}
