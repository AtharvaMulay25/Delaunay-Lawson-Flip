a.out:
	@g++ -std=c++17 main.cpp ./lib/point.cpp ./lib/edge.cpp ./lib/triangle.cpp

clean:
	@rm a.out flips.txt output.txt