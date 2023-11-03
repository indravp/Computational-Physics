set terminal postscript enhanced color
set output 'q2.eps'
set xlabel 'x'
set ylabel 'cos(x)'
set grid
plot 'q2.txt' u 1:2 title 'series' w points,'q2.txt' u 1:3 title 'exact' w lp
set term x11
