set terminal postscript enhanced color
set output 'q6.eps'
set xlabel 'a'
set ylabel 'x'
plot 'q6.txt' w p title 'Bifurcation Diagram'
set term x11
