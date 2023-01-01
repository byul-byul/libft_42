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

SRCS	=	ft_is_funcs.c \
			ft_mem_funcs.c \
			ft_str_funcs.c \
			ft_put_funcs.c \
			ft_to_funcs.c \
			ft_calloc.c \
			ft_split.c

B_SRCS	=	ft_lst_funcs.c \

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