CFLAGS = -Wall -g -O

SFML_FLAG = -lsfml-graphics -lsfml-window -lsfml-system

NAME = tanki

OBJ = main.o view.o model.o controller.o


all: $(NAME)

%.o: %.cpp
	g++ -c -o $@ $^

$(NAME) : $(OBJ)
	g++ -o $(NAME) $^ $(CFLAGS) $(SFML_FLAG)

clean:
	$(RM) $(OBJ) $(NAME)