LIBRARY = libftprintf.a

SRCS = ft_printf_c

BONUSSRCS = ft_printf_bonus.c

OBJS := ${SRCS:.c=.o}

BONUSOBJS := ${BONUSSRCS:.c=.o}

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

.c.o:
	cc -c $(FLAGS) -I $(HEADER) $< -o ${<:.c=.o}

all:	$(LIBRARY)

$(LIBRARY):	$(OBJS)
	ar rc $(LIBRARY) $(OBJS)

bonus:	$(OBJS) $(BONUSOBJS)
	ar rc $(LIBRARY) $(OBJS) $(BONUSOBJS)

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean:	clean
	rm -f $(LIBRARY)

re:	fclean all