Application: prefix.o main.cpp
	g++ prefix.o main.cpp -o Application

prefix.o: prefix.cpp prefix.h
	g++ -c prefix.cpp

clean:
	rm -f *.o Application
