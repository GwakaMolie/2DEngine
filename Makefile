TARGET = game

VPATH = %.cpp src
VPATH = %.hpp include

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

SRC_DIR = src
OBJ_DIR = build

CXX = g++
CXXFLAGS = -I include -Wall -Wextra -g
LDFLAGS = -lSDL2 -lSDL2_image -lm -ltinyxml -lz
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< $(LDFLAGS) -o $@

.PHONY:clean
clean:
	rm -fr $(TARGET) $(OBJ_DIR)
