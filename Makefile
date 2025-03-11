CFLAGS = -Wall -g -O

NAME = tanki

OBJ = 


all: $(NAME)

%.o: %.cpp
	g++ -c -o $@ $^

$(NAME) : $(OBJ)
	g++ -o $(NAME) $^ $(CFLAGS)

clean:
	$(RM) $(OBJ) $(NAME)