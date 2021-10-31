files = src/main.cpp src/clock.cpp src/colors.cpp src/rule.cpp src/grid.cpp src/segment.cpp src/ws2812-rpi/ws2812-rpi.cpp

main: $(files)
	g++ -ggdb3 -o main $(files)

.PHONY: main

# Remember to add -W and -Wall later
