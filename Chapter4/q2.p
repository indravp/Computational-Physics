set terminal postscript enhanced color
set output 'q2.eps'
set xlabel 'x'
set ylabel 'J0(x)'
set grid
plot 'q2.txt' w p
set term x11
