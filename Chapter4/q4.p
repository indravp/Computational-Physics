set terminal postscript enhanced color
set output 'q4.eps'
set xlabel 'x'
set ylabel 'y'
set grid
plot 'q4.txt' w p
set term x11
