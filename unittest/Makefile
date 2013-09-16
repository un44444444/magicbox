all: test_random_mt.exe
clean:
	rm -rf test_random_rand.exe test_random_std.exe test_random_mt.exe
rebuild: clean all

test_random_rand.exe: test_random_rand.cpp ../randoms/random_rand.cpp
	g++ -I../ $^ -o $@

test_random_std.exe: test_random_std.cpp ../randoms/random_std.cpp
	g++ -std=c++11 -I../ $^ -o $@

test_random_mt.exe: test_random_mt.cpp ../randoms/random_mt.cpp
	g++ -I../ $^ -o $@
