set terminal postscript enhanced color
set output 'q5ai3.eps'
set xlabel 'y'
set ylabel 'z'
plot 'q5i.txt' u 2:3 w p title 'y vs z'
set term x11
