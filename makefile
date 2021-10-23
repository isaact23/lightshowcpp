main: main.cpp
	g++ -ggdb3 -o main main.cpp colors.cpp rule.cpp

.PHONY: main

# Remember to add -W and -Wall later