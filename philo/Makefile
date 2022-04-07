SRC = colors.c genisis.c init.c main.c parser.c util.c
INCLUDE = philo.h
OBJ = $(SRC:.c=.o)
PHILO = philo
%.o : %.c $(INCLUDE)
	$(CC) -Wall -Wextra -Werror -O2 -c -o $@ $< 

$(NAME) : $(PHILO)

$(PHILO) : $(OBJ)
	$(CC) -o $@ $(OBJ)
clean : 
	rm -f $(OBJ)
fclean : clean
	rm -f $(PHILO)
re : fclean $(PHILO)
