BIN = test_zombie

SRC = main.cpp \
      utils.cpp \
      Zombie.cpp \
      ZombieEvent.cpp

OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

INC_DIRS = .

CXX = clang++

CXXFLAGS += -c \
            -std=c++98 \
            $(addprefix -I , $(INC_DIRS)) \
            -Wall -Wextra -Werror \
            -MMD

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

include $(wildcard $(DEP))

clean:
	rm -f $(BIN) $(OBJ) $(DEP)
