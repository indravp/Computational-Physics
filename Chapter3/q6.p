set terminal postscript enhanced color
set output 'q6.eps'
set xlabel 'x'
set ylabel 'f(x)'
set grid
plot 'q6.txt' w p
set term x11
