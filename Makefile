main: src/main.cpp src/colors.cpp src/rule.cpp src/timer.cpp
	g++ -ggdb3 -o main src/main.cpp src/colors.cpp src/rule.cpp src/timer.cpp

.PHONY: main

# Remember to add -W and -Wall later
