CC = g++
CFLAGS = -std=c++11 -Wall
INCLUDE = -F/Library/Frameworks/SDL2.framework/headers  -framework SDL2 -F/Library/Frameworks/SDL2_ttf.framework/headers -framework SDL2_ttf -F/Library/Frameworks/SDL2_image.framework/headers -framework SDL2_image
FILES = main.cpp global.cpp game.cpp army.cpp unit.cpp button.cpp text.cpp fselect.cpp field.cpp

all: compile run

compile:
	g++ -o War ${FILES} ${INCLUDE} ${CFLAGS}
run:
	./War
