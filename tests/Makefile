# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbally <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/10 16:52:30 by hbally            #+#    #+#              #
#    Updated: 2019/05/10 16:54:05 by hbally           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BINDIR				=	.

SRCSDIR   			=	src

OBJSDIR   			=	objs

NAME				=	$(BINDIR)/libft_tests.out

SRCS_RAW			:=	custom_tests.c					\
						basic_tests.c					\
						compare.c						\
						main.c

SRCS				=	$(SRCS_RAW:%.c=$(SRCSDIR)/%.c)

OBJS  				:=	$(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

DEPENDENCIES		=	$(OBJS:%.o=%.d)

INCLUDES			=	-I inc							\
						-I libft/inc

CC					=	gcc

CFLAGS				+=	-Wall -Werror -Wextra

all					:	$(NAME)

.PHONY				:	libs
libs				:
						make -C libft

$(NAME)				: 	libs $(OBJS)
						$(CC) -o $@ $(CFLAGS) -L./libft -lft $(OBJS)

.PHONY				:	run
run					:	all
						$(NAME)

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
						rm -f $(BIN)

.PHONY				:	re
re					:	fclean all
