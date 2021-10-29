main: src/main.cpp src/colors.cpp src/rule.cpp
	g++ -ggdb3 -o main src/main.cpp src/colors.cpp src/rule.cpp

.PHONY: main

# Remember to add -W and -Wall later
