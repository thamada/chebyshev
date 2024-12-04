#!/usr/bin/env gnuplot

set grid

plot "/tmp/log.txt" using 1:2 w lines, \
     "/tmp/log.txt" using 1:3 w lines, \
     "/tmp/log.txt" using 1:4 w lines

pause -1


