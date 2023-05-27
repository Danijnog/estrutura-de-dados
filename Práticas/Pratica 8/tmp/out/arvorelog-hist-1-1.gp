set term png
set output "../tmp/out/arvorelog-hist-1-1.png"
set style fill solid 1.0
set title "Distancia de Pilha (Total 0 # 46 Media 0.00) - Fase  1 - ID 1"
set xlabel "Distancia"
set ylabel "Frequencia"
plot [-1:1] "../tmp/out/arvorelog-hist-1-1.gpdat" u 3:4 w boxes t ""
