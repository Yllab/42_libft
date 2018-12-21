# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:02:29 by hbally            #+#    #+#              #
#    Updated: 2018/12/20 17:49:17 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	libft.a

SRCSDIR   			=	srcs

OBJSDIR   			=	objs

SRCS_RAW			:=	ft_atoi.c 				\
						ft_bzero.c 				\
						ft_isalnum.c 			\
						ft_isalpha.c 			\
						ft_isascii.c 			\
						ft_isdigit.c			\
						ft_isprint.c			\
						ft_itoa.c				\
						ft_memalloc.c		 	\
						ft_memccpy.c	 		\
						ft_memchr.c 			\
						ft_memcmp.c 			\
						ft_memcpy.c 			\
						ft_memdel.c 			\
						ft_memmove.c	 		\
						ft_memset.c 			\
						ft_putchar.c	 		\
						ft_putchar_fd.c 		\
						ft_putendl.c	 		\
						ft_putendl_fd.c 		\
						ft_putnbr.c 			\
						ft_putnbr_fd.c	 		\
						ft_putstr.c 			\
						ft_putstr_fd.c	 		\
						ft_strcat.c				\
						ft_strchr.c 			\
						ft_strclr.c 			\
						ft_strcmp.c 			\
						ft_strcpy.c 			\
						ft_strdel.c 			\
						ft_strdup.c 			\
						ft_strequ.c 			\
						ft_striter.c	 		\
						ft_striteri.c	 		\
						ft_strjoin.c	 		\
						ft_strlcat.c	 		\
						ft_strlen.c 			\
						ft_strmap.c 			\
						ft_strmapi.c	 		\
						ft_strncat.c	 		\
						ft_strncmp.c	 		\
						ft_strncpy.c	 		\
						ft_strnequ.c	 		\
						ft_strnew.c 			\
						ft_strnstr.c	 		\
						ft_strrchr.c	 		\
						ft_strsplit.c			\
						ft_strstr.c 			\
						ft_strsub.c 			\
						ft_strtrim.c	 		\
						ft_tolower.c	 		\
						ft_toupper.c	 		\
						ft_lstadd.c				\
						ft_lstdel.c				\
						ft_lstdelone.c			\
						ft_lstiter.c			\
						ft_lstmap.c				\
						ft_lstnew.c				\
						ft_str_realloc.c		\
						ft_memrealloc.c			\
						ft_int_swap.c			\
						ft_atol.c				\
						ft_sqrt.c

SRCS				=	$(SRCS_RAW:%.c=$(SRCSDIR)/%.c)

OBJS  				:=	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

DEPENDENCIES		=	$(OBJS:%.o=%.d)

INCLUDES			=	-I includes

CC					=	gcc

CFLAGS				+=	-Wall -Werror -Wextra

all					:	$(NAME)

$(NAME)				: 	$(OBJS)
						ar rc $@ $(OBJS)
						ranlib $@

-include $(DEPENDENCIES)

$(OBJS)				: 	$(OBJSDIR)/%.o : $(SRCSDIR)/%.c
						@mkdir -p objs
						$(CC) -o $@ $(CFLAGS) $(INCLUDES) -MMD -c $<

.PHONY				:	clean
clean				:
						rm -f $(OBJS) $(DEPENDENCIES)
						rm -rf $(OBJSDIR)

.PHONY				:	fclean
fclean				:	clean
						rm -f $(NAME)

.PHONY				:	re
re					:	fclean all
