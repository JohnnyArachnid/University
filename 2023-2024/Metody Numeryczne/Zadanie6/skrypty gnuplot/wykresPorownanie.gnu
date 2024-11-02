set terminal pngcairo enhanced size 800,600
set output 'wykresPorownanie.png'

set multiplot

# Ustawienia ogólne
set xlabel "Oś nh"
set ylabel "Oś y"
set key autotitle columnhead

# Wykres 1
plot 'wynikiR.txt' with linespoints title 'Dane 1' lc rgb 'blue' lw 2 pt 7 ps 1.5, \
     'wynikiJ.txt' with linespoints title 'Dane 2' lc rgb 'green' lw 2 pt 7 ps 1.5, \
     'wynikiGS.txt' with linespoints title 'Dane 3' lc rgb 'purple' lw 2 pt 7 ps 1.5, \
     'wynikiS.txt' with linespoints title 'Dane 4' lc rgb 'red' lw 2 pt 7 ps 1.5

unset multiplot
