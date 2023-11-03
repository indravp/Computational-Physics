set terminal postscript enhanced color
set output 'q5.eps'
set xlabel 'x'
set ylabel 'f(2,x)'
set grid
plot 'q5.txt' w p
set term x11
