# Variables
CC = g++
CFLAGS = -I. -Wall -Wextra -Werror -std=c++11
LDFLAGS = -lglfw -lGL -lGLU
TARGET = pingpong3D
SOURCES = main.cpp classes.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Règle principale
all: $(TARGET)

all: run

run: $(TARGETS)
	@echo "🚀 Lancement du programme..."
	./$(TARGET)

$(TARGET): $(OBJECTS)
	@echo "🔨 Création de l'exécutable $(TARGET)..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)
	@echo "✅ Compilation terminée avec succès."

# Compilation des fichiers sources en objets
%.o: %.cpp
	@echo "🔨 Compilation de $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# 🧹 Nettoyage des fichiers objets et exécutables
clean:
	@echo "🧹 Suppression des fichiers objets..."
	rm -f $(OBJECTS)
	@echo "🧹 Nettoyage terminé."

fclean: clean
	@echo "🧹 Suppression de l'exécutable $(TARGET)..."
	rm -f $(TARGET)
	@echo "🧹 Suppression terminée."

# Recompilation complète
re: fclean all

# Aide
help:
	@echo "📝 Commandes disponibles :"
	@echo "  make ou make all → Compile le projet"
	@echo "  make clean       → Supprime les fichiers objets (.o)"
	@echo "  make fclean      → Supprime les exécutables et les objets"
	@echo "  make re          → Nettoie tout et recompile entièrement"
	@echo "  make help        → Affiche les commandes disponibles"
