set terminal postscript enhanced color
set output 'q5biii1.eps'
set xlabel 'x'
set ylabel 'y'
plot 'q5iii.txt' u 1:2 w p title 'x vs y'
set term x11
