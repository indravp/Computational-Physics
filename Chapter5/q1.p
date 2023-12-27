set terminal postscript enhanced color
set output 'q1.eps'
set xlabel 'x'
set ylabel 'y'
plot 'q1.txt' u 1:2 title 'RK-4' w p, 'q1.txt' u 1:3 title 'Exact' w p, 'q1.txt' u 1:4 title "Euler's Method" w p
set term x11
