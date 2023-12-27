set terminal postscript enhanced color
set output 'q4.eps'
set xlabel 'x'
set ylabel 'y'
plot 'q4.txt' w p title 'x vs y'
set term x11
