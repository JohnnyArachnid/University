set terminal png
set output 'wartoscWlasna3.png'
set title 'Wektor Wartosci Wlasnej 3'
set xlabel 'Oś x'
set ylabel 'Oś y'
set style line 1 lt 1 lw 2 pt 7 ps 0.5
plot 'wyniki3.txt' with linespoints ls 1 title 'wyniki3.txt'
