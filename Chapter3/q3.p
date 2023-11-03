set terminal postscript enhanced color
set output 'q3.eps'
set xlabel 'x'
set ylabel 'J(x)'
set grid
plot 'q3.txt' title "Bessel's Function" w p
set term x11
