set terminal pngcairo enhanced size 800,600
set output 'wykresPorownanie.png'

set multiplot

# Ustawienia ogólne
set xlabel "Oś x"
set ylabel "Oś y"
set title "Wektory Wartosci Wlasnych"
set key autotitle columnhead

# Wykres 1
plot 'wyniki1.txt' with linespoints title 'Wektor Wartosci Wlasnej 1' lc rgb 'blue' lw 2 pt 7 ps 1.5, \
     'wyniki2.txt' with linespoints title 'Wektor Wartosci Wlasnej 2' lc rgb 'green' lw 2 pt 7 ps 1.5, \
     'wyniki3.txt' with linespoints title 'Wektor Wartosci Wlasnej 3' lc rgb 'purple' lw 2 pt 7 ps 1.5, \
     'wyniki4.txt' with linespoints title 'Wektor Wartosci Wlasnej 4' lc rgb 'red' lw 2 pt 7 ps 1.5

unset multiplot
