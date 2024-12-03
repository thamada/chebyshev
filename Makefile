build:
	mkdir -p work
	python3 ./main.py

setup:
	pip3 install -r requirements.txt


setup.macOS:
	brew install wkhtmltopdf
	brew install pandoc

setup.ubuntu:
	sudo apt install -y wkhtmltopdf
	sudo apt install -y pandoc

gen.markdown:
	pandoc work/chebyshev_interpolation.html -f html -t markdown -o work/chebyshev_interpolation.md

clean:
	rm -f *~ .*~ work/*.*

c: clean


