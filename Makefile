.PHONY: build
build:
	mkdir -p build
	cmake -E chdir build cmake ..
	cmake --build build

.PHONY: run
run:
	build/main

.PHONY: plot
plot:
	build/main > output.txt
	gnuplot -p plot.p
