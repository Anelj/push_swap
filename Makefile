NAME_PS = push_swap
NAME_CH = checker
DIR_OBJ = obj
LIST = ft_atoilong.c ft_lst.c ft_options.c ft_sort.c ft_zeroj_ilsts.c ft_free.c ft_mid.c ft_options_double.c\
ft_options_push.c ft_pushtob.c ft_shortest_passa.c ft_shortest_passb.c ft_shortthreea.c ft_ss_rr_rrr_or.c ft_lst1.c\
get_next_line.c get_next_line_utils.c
LIST_PS = main.c pushswap.c
LIST_CH = ft_checker.c
OBJ = $(addprefix $(DIR_OBJ)/, $(LIST:.c=.o))
OBJ_CH = $(addprefix $(DIR_OBJ)/, $(LIST_CH:.c=.o))
OBJ_PS = $(addprefix $(DIR_OBJ)/, $(LIST_PS:.c=.o))

all : $(NAME_PS) $(NAME_CH)

$(NAME_CH) : ./libft/libft.a $(OBJ) $(OBJ_CH)
	gcc -Wall -Werror -Wextra $(OBJ) $(OBJ_CH) -L./libft -lft -o $(NAME_CH)

$(NAME_PS) : ./libft/libft.a $(OBJ) $(OBJ_PS)
	gcc -Wall -Werror -Wextra $(OBJ) $(OBJ_PS) -L./libft -lft -o $(NAME_PS)

./libft/libft.a : libft

libft :
	$(MAKE) bonus -C ./libft

$(DIR_OBJ)/%.o : %.c ./push_swap.h
	mkdir -p $(DIR_OBJ)
	gcc -Wall -Werror -Wextra -c $< -o $@

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(DIR_OBJ)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME_CH)
	rm -f $(NAME_PS)

re : fclean all

.PHONY : all clean fclean re libft
