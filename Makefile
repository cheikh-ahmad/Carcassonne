SRC_DIR := src
OBJ_DIR := obj
INC_DIR := include
BIN_DIR := .

LIB :=  -lsfml-graphics -lsfml-window -lsfml-system
EXE := $(BIN_DIR)/projet.bin

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

.PHONY : clean all

# -MMD et -MP sont importants pour generer les dépendances .hpp automatiquement.
CPPFLAGS := -I $(INC_DIR) -std=c++11 -MMD -MP -Wall -Wextra -pedantic
CFLAGS := -Wall
CPP := g++ $(CPPFLAGS) $(CFLAGS)

all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) $^ -o $@ $(LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CPP) -c $< -o $@

# Si le dossier OBJ_DIR n'existe pas/plus, on le crée
$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR) $(EXE)

# - permet d'ignorer les erreurs
-include $(OBJ:.o=.d)
