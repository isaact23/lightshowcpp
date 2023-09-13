CFLAGS = -W -Wall -ggdb3

main: main.o strip.o
	g++ $(CFLAGS) -o main main.o strip.o

main.o: src/main.cpp
	g++ $(CFLAGS) -o main.o src/main.cpp

strip.o: src/strip/strip.cpp
	g++ $(CFLAGS) -o strip.o src/strip/strip.cpp

colors.o: src/data/colors/colors.cpp
	g++ $(CFLAGS) -o colors.o src/data/colors/colors.cpp

ws2812-esp32.o: src/led-control/ws2812-esp32/src/Freenove_WS2812_Lib_for_ESP32.cpp
	g++ $(CFLAGS) -o ws2812-esp32.0 src/led-control/ws2812-esp32/src/Freenove_WS2812_Lib_for_ESP32.cpp

.PHONY: main

