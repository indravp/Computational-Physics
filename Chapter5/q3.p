set terminal postscript enhanced color
set output 'q3.eps'
set xlabel 'x'
set ylabel 'y'
plot 'q3.txt' w p title 'Prey-Predator Model'
set term x11
