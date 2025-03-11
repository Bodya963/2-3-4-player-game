CFLAGS = -Wall -g -O

NAME = tanki

OBJ = main.o


all: $(NAME)

%.o: %.cpp
	g++ -c -o $@ $^

$(NAME) : $(OBJ)
	g++ -o $(NAME) $^ $(CFLAGS)

clean:
	$(RM) $(OBJ) $(NAME)