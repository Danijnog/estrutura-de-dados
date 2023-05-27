set term png
set output "../tmp/out/arvorelog-hist-0-0.png"
set style fill solid 1.0
set title "Distancia de Pilha (Total 0 # 45 Media 0.00) - Fase  0 - ID 0"
set xlabel "Distancia"
set ylabel "Frequencia"
plot [-1:1] "../tmp/out/arvorelog-hist-0-0.gpdat" u 3:4 w boxes t ""
