# Gerador-de-Montanha-3000

- O que foi feito: Um gerador de terrenos que gera uma imagem .ppm de tamanho fixo de 513x513 pixeis, com 3 montanhas e um sol.
- O programa primeiro gera a montanha principal por meio de "midpoint displacement algorithm".
- Em seguida gera mais 2 montanhas adicionais, uma crescente e outra decrescente, todas as montanhas variam sua altura de acordo com o "deslocamento aleatório máximo"
- Por fim adionando tambem um sol quadrado no fundo da imagem, atras das montanhas.
  \_>Deslocamento aleatório máximo: o "n" é o deslocamento aleatório máximo, ele é um double que é convertido em porcentagem, na hora de somar ou subtrair no valor no meio, ele soma ou subtrai um valor aleatorio de 1 a 10 multiplicado pela porcentagem "n".

-Como compilar o projeto:
  \_>Comandos de compliação:
    gcc funcs.c -c -g -W
    gcc io.c -c -g -W
    gcc main.c funcs.c io.c -o executavel -g -w
    
  \_>Como executar o programa:
    -d <num> -o <nome do arquivo.ppm>
        \_>num = deslocamento aleatório máximo (porcentagem)

-Integrantes:
Davi Duarte de Freitas (criação de contorno, matriz e modularização)
Gabriel Victor de Lima Pimentel (criação das funções adicionais, gerenciamento das entradas e palheta de cores, variação maxima somada ou subtraida)