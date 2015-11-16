SRC	 = main.cpp \
	   RealisticWater.cpp

EXT      = cpp

NAME	 = test

CXXFLAGS = -Wall -Wextra -W -std=c++0x -I/usr/include/irrlicht

LDFLAGS	 = -lIrrlicht

OBJS	 = $(SRC:.$(EXT)=.o)

RM	 = rm -f

CXX	 = clang++

all:	 $(NAME)

$(NAME): $(OBJS)
	 $(CXX) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	 $(RM) $(OBJS) *.swp *~ *#

fclean:  clean
	 $(RM) $(NAME)

re:
	 make -B -j4

.PHONY:  all clean fclean re

