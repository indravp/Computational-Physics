set terminal postscript enhanced color
set output 'q3.eps'
set xlabel 'x'
set ylabel 'y'
set grid
plot 'q3.txt' w p
set term x11
