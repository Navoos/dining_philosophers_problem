SRC = colors.c main.c parser.c util.c monitor.c
INCLUDE = philo_bonus.h
OBJ = $(SRC:.c=.o)
PHILO = philo_bonus
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
