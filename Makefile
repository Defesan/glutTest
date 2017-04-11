OBJS = glutTest.cpp stRect.cpp stCircle.cpp stVec3f.cpp stSphere.cpp

CC = g++

COMPILER_FLAGS = -std=c++14 -Wall

LINKER_FLAGS = -lGL -lGLU -lglut

OBJ_NAME = glutTest

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
