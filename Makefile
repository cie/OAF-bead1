all:dokumentacio.pdf

%.pdf: %.tex
	pdflatex $*


dokumentacio.pdf: bead.sty


bead.sty: dsl.sty
