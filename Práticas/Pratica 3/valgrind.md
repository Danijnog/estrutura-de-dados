# Valgrind
-> uso para detecção de vazamentos de memória

## Comando
valgrind --leak-check=full ./"nome_do_executavel"
valgrind --leak-check=full --track-origins=yes -s  "./nome_do_executavel"