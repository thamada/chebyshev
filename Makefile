build:
	python3 ./main.py

setup:
	pip3 install -r requirements.txt


clean:
	rm -f *~ .*~ work/*.*

c: clean


