set terminal postscript enhanced color
set output 'q5.eps'
set xlabel 'x'
set ylabel 'U4(x)'
set xrange [-1.1:1.1]
set grid
plot 'q5.txt' w p
set term x11
