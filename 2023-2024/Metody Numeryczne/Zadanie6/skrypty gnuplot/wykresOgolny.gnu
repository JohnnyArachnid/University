set terminal pngcairo enhanced size 800,600
set output 'wykresOgolny.png'

set multiplot layout 2,2

set title "Metoda Relaksacyjna Richardsona"
plot 'wynikiR.txt' with linespoints title 'Dane 1' lc rgb 'blue' lw 2 pt 7 ps 1.5

set title "Metoda Jacobiego"
plot 'wynikiJ.txt' with linespoints title 'Dane 2' lc rgb 'green' lw 2 pt 7 ps 1.5

set title "Metoda Gausa-Seidla"
plot 'wynikiGS.txt' with linespoints title 'Dane 3' lc rgb 'purple' lw 2 pt 7 ps 1.5

set title "Successive OverRelaxation"
plot 'wynikiS.txt' with linespoints title 'Dane 4' lc rgb 'red' lw 2 pt 7 ps 1.5

unset multiplot

