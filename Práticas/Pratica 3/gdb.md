# GDB
-> permite executar o programa passo a passo, inspecionando melhor o que está acontecendo dentro de iterações por exemplo, e permitindo inspecionar os elementos e alterá-los

## Comando
gcc -g "nome do arquivo.c" -o "nome do executavel"
gdb "nome do executável"

## Breakpoints
-> define pontos de parada do seu arquivo para melhor análise e para esperar algum comando que vc execute
    - 'break main': a execução irá parar sempre quando a função for executada
    - 'break 10': o programa para ao chegar na linha 10
    - 'run': roda o programa até o breakpoint estabelecido ou o programa inteiro caso não haja breakpoint
    - 'list': código corrente
    - 'next': próxima linha
    - 'step': próxima linha a entrar na função
    - 'print x': imprime o valor da variável x
    - 'display x': imprime o valor da variável x a cada passo