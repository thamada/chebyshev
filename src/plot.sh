#!/usr/bin/env gnuplot

set grid

plot "/tmp/log.txt" using 1:2 w lines title "f(x)", \
     "/tmp/log.txt" using 1:3 w lines title "chebyshev", \
     "/tmp/log.txt" using 1:4 w lines title "diff"

pause -1


