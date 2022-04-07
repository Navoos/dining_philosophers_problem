NAME = philo_m
NAME_B = bonus

$(NAME) : 
	make -C philo

$(NAME_B) : 
	make -C philo_bonus

clean : 
	make -C philo clean && make -C philo_bonus clean

fclean : 
	make -C philo fclean && make -C philo_bonus fclean

re : 
	make -C philo re && make -C philo_bonus re


