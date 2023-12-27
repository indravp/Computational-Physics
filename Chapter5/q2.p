set terminal postscript enhanced color
set output 'q2.eps'
set xlabel 't'
set ylabel 'theta'
set xrange [0:1.1]
plot 'q2.txt' u 1:2 title 'RK-4' w p, 'q2.txt' u 1:3 title 'Exact' w p
set term x11
