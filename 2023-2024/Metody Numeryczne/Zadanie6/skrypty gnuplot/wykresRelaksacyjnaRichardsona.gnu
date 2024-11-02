set terminal png
set output 'wykresRelaksacyjnaRichardsona.png'
set title 'Metoda Relaksacyjna Richardsona'
set xlabel 'Oś nh'
set ylabel 'Oś y'
set style line 1 lt 1 lw 2 pt 7 ps 0.5
plot 'wynikiR.txt' with linespoints ls 1
