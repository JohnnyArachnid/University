set terminal png
set output 'wykresGausaSeidla.png'
set title 'Metoda Gausa-Seidla'
set xlabel 'Oś nh'
set ylabel 'Oś y'
set style line 1 lt 1 lw 2 pt 7 ps 0.5
plot 'wynikiGS.txt' with linespoints ls 1
