# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phelen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/14 08:15:42 by phelen            #+#    #+#              #
#    Updated: 2020/11/14 10:50:49 by phelen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
HDRS	=	libft.h

SRCS	=	ft_is_functions_part_1.c \
			ft_is_functions_part_2.c \
			ft_mem_functions_part_1.c \
			ft_mem_functions_part_2.c \
			ft_str_functions_part_1.c \
			ft_str_functions_part_2.c \
			ft_str_functions_part_3.c \
			ft_put_functions.c \
			ft_to_functions.c \
			ft_atoi_itoa_calloc_bzero.c \
			ft_split.c

B_SRCS	=	ft_lst_functions_part_1.c \
			ft_lst_functions_part_2.c

SDIR	=	./
ODIR	=	objs/
FLGS	=	-Wall -Wextra -Werror
CMPL	=	gcc

OBJS	=	$(addprefix $(ODIR), $(SRCS:.c=.o))
B_OBJS	=	${B_SRCS:.c=.o}

$(ODIR)%.o : $(SDIR)%.c
	mkdir -p $(ODIR)
	$(CMPL) $(FLGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

bonus: $(OBJS) $(B_OBJS)
	ar rc $(NAME) $(OBJS) $(B_OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus