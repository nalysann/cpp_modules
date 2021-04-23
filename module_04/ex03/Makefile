BIN := test_materia

SRC := AMateria.cpp \
       Character.cpp \
       Cure.cpp \
       Ice.cpp \
       main.cpp \
       MateriaSource.cpp

OBJ := $(SRC:.cpp=.o)
DEP := $(SRC:.cpp=.d)

INC_DIRS := .

CXX := clang++

CXXFLAGS += -std=c++98 \
            $(addprefix -I , $(INC_DIRS)) \
            -Wall -Wextra -Werror \
            -MMD \
            -O2 -march=native -pipe

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

clean:
	rm -f $(BIN) $(OBJ) $(DEP)
