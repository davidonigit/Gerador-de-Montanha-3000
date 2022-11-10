# Gerador-de-Montanha-3000

- O que foi feito: Um gerador de terrenos que gera uma imagem .ppm de tamanho fixo de 513x513 pixeis, com 3 montanhas e um sol.
- O programa primeiro gera a montanha principal por meio de "midpoint displacement algorithm".
- Em seguida gera mais 2 montanhas adicionais, uma crescente e outra decrescente, todas as montanhas variam sua altura de acordo com o "deslocamento aleatório máximo"
- Por fim adionando tambem um sol quadrado no fundo da imagem, atras das montanhas.

* Deslocamento aleatório máximo: o "n" é o deslocamento aleatório máximo, ele é um double que é convertido em porcentagem, na hora de somar ou subtrair no valor no meio, ele soma ou subtrai um valor aleatorio de 1 a 10 multiplicado pela porcentagem "n".

- Como compilar o projeto: 
    - gcc funcs.c -c -g -w 
    - gcc io.c -c -g -w 
    - gcc main.c funcs.c io.c -o executavel -g -w 
    
- Como executar o programa:
    - ./executavel -d 'num' -o 'nome do arquivo.ppm'
        - num = deslocamento aleatório máximo (porcentagem)
  
- Por fim, basta visualizar o arquivo .ppm em um conversor ou programa.
  
- Integrantes:
    - Davi Duarte de Freitas
    - Gabriel Victor de Lima Pimentel
