CXXFLAGS += -std=c++03 -Wpedantic -Wall -Wextra -O2 -I../build/headers/
LDFLAGS += -L../build/libraries/anna/sound -lAnnaSound -lopenal

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o $(LDFLAGS)

clean:
	find . -name "*.o" -type f -delete
