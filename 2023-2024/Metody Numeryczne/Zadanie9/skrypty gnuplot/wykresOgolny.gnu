set terminal pngcairo enhanced size 800,600
set output 'wykresOgolny.png'

set multiplot layout 2,2
set xlabel "Oś x"
set ylabel "Oś y"
set title "Wektory Wartosci Wlasnych"

set title "Wektor Wartosci Wlasnej 1"
plot 'wyniki1.txt' with linespoints title 'Dane 1' lc rgb 'blue' lw 2 pt 7 ps 1.5

set title "Wektor Wartosci Wlasnej 2"
plot 'wyniki2.txt' with linespoints title 'Dane 2' lc rgb 'green' lw 2 pt 7 ps 1.5

set title "Wektor Wartosci Wlasnej 3"
plot 'wyniki3.txt' with linespoints title 'Dane 3' lc rgb 'purple' lw 2 pt 7 ps 1.5

set title "Wektor Wartosci Wlasnej 4"
plot 'wyniki4.txt' with linespoints title 'Dane 4' lc rgb 'red' lw 2 pt 7 ps 1.5

unset multiplot

