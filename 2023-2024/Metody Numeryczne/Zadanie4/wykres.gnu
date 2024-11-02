set terminal png
set output 'wykres.png'
set title 'Zadanie N4'
set xlabel 'Oś nh'
set ylabel 'Oś y'
set style line 1 lt 1 lw 2 pt 7 ps 0.5
plot 'wyniki.txt' with linespoints ls 1
