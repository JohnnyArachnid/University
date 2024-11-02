set terminal png
set output 'wykresJacobiego.png'
set title 'Metoda Jacobiego'
set xlabel 'Oś nh'
set ylabel 'Oś y'
set style line 1 lt 1 lw 2 pt 7 ps 0.5
plot 'wynikiJ.txt' with linespoints ls 1
