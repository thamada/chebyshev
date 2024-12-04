#!/usr/bin/env gnuplot
plot "tmp.txt" using 1:2 w lines, \
     "tmp.txt" using 1:3 w lines, \
     "tmp.txt" using 1:4 w lines \

pause -1


