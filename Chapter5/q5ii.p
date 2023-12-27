set terminal postscript enhanced color
set output 'q5bii1.eps'
set xlabel 'x'
set ylabel 'y'
plot 'q5ii.txt' u 1:2 w p title 'x vs y'
set terminal x11
