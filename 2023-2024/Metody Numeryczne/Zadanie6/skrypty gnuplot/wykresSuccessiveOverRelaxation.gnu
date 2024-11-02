set terminal png
set output 'wykresSuccessiveOverRelaxation.png'
set title 'Successive OverRelaxation'
set xlabel 'Oś nh'
set ylabel 'Oś y'
set style line 1 lt 1 lw 2 pt 7 ps 0.5
plot 'wynikiS.txt' with linespoints ls 1
