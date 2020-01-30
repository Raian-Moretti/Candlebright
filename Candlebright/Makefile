CC=g++
OBJDIR=obj
BINDIR=bin
EXEC=jogo
LDFLAGS = -Lsfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lm
CFLAGS = -Isfml/include -std=c++98 -Wall -pthread
VALFLAGS = --track-origins=yes --leak-check=full
CSOURCE = $(wildcard src/*.cpp src/*/**.cpp)
OBJ=$(subst src, obj, $(CSOURCE:.cpp=.o))

.PHONY: default
default: dependencies $(CSOURCE) $(EXEC)

.PHONY: run
run: default execute

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o "$(BINDIR)/$@"

$(OBJDIR)/%.o: src/%.cpp
	$(CC) $(CFLAGS) -o "$@" -c "$<"

.PHONY: debug
debug:
	$(CC) -c $(CSOURCE) $(LDFLAGS) $(CFLAGS) -ggdb
	mv *.o $(OBJDIR)/
	$(CC) $(OBJDIR)/*.o -o $(BINDIR)/$(EXEC)-debug $(LDFLAGS) $(SFML) $(CFLAGS)
	LD_LIBRARY_PATH=sfml/lib valgrind $(VALFLAGS) ./$(BINDIR)/$(EXEC)-debug

.PHONY: clean
clean:
	rm -f $(OBJDIR)/* $(OBJDIR)/*/** $(BINDIR)/* *.o 2>/dev/null

.PHONY: dependencies
dependencies:
	sh dependencies.sh

.PHONY: execute
execute:
	LD_LIBRARY_PATH=sfml/lib ./$(BINDIR)/$(EXEC)

compile-older:
	$(CC) -c $(CSOURCE) src/main.cpp $(CFLAGS)
	mv *.o $(OBJDIR)/
	$(CC) $(CFLAGS) $(OBJDIR)/*.o $(LDFLAGS) -o $(BINDIR)/jogo
