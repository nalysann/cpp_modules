BIN := test_fallout

SRC := AlienAtomizer.cpp \
       AWeapon.cpp \
       Character.cpp \
       Deathclaw.cpp \
       Enemy.cpp \
       main.cpp \
       PlasmaRifle.cpp \
       PowerFist.cpp \
       RadScorpion.cpp \
       SuperMutant.cpp

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
