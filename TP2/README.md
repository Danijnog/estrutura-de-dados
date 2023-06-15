## Descrição
O seguinte programa tem por objetivo determinar o Fecho Convexo de um conjunto
de pontos passado como entrada do programa utilizando os algoritmos Scan de
Graham e o Marchar de Jarvis. O fecho convexo, por definição, dado uma entrada
de uma nuvem de pontos qualquer é fornecido uma saída contendo uma figura
convexa que envolva o menor conjunto de pontos contendo todos os pontos da
nuvem.

## Como funciona
O programa recebe como entrada um arquivo contendo um conjunto de pontos e, com isso,
determina o fecho convexo através do Scan de Graham utilizando 3 algoritmos de ordenação diferentes:
o MergeSort, InsertionSort e BucketSort, além de determinar o fecho convexo através do Marchar de Jarvis
também.
Além disso, o programa também realiza o desenho do fecho convexo com o uso da biblioteca 'graphics.h'.

## Instruções para compilação e execução
- No diretório do programa, de o comando ‘make’ para compilar todos os arquivos e
gerar o executável ‘fecho’ na pasta bin.
- Agora, de o comando
‘bin/fecho nome_arquivo_entrada.in’,
onde ‘nome_arquivo_entrada.in’ é o arquivo de entrada desejável para se executar o
programa. Caso o arquivo não esteja na raiz do programa, é preciso especificar o
caminho do arquivo.
- Caso queira visualizar o desenho do fecho convexo, é necessário passar apenas a
flag ‘-d’ no final do comando, como abaixo:
‘bin/fecho nome_arquivo_entrada.in -d’
Atualmente na pasta do programa, já existe um arquivo de entrada nomeado
‘entrada.in’ que pode ser utilizado também para testar o programa, caso deseje.



# Exemplo do desenho do fecho convexo de um conjunto de pontos:
![Captura de Tela (219)](https://github.com/Danijnog/estrutura-de-dados/assets/97178655/9d443826-70a8-4d8b-ae96-ed03a2812d7d)
















