.SUFFIXES: .cpp .o .hpp .h .tpp
.PHONY : all clean re

CCX = c++ 
RM = rm -rf

OBJ_DIR = objs/

ifndef TARGET
	TARGET = a.out
endif
ifndef SRCS
	SRCS =
endif
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

CXXFLAGS =  -Wall -Wextra -Werror
#CXXFLAGS = -Wall -Wextra -Werror -stdlib=libc++ -std=c++98 -pedantic

all : $(TARGET)

clean :
	$(RM) $(OBJ_DIR)
	$(RM) $(TARGET)

re : clean
	make all

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJS) : | $(OBJ_DIR)

$(addprefix $(OBJ_DIR), %.o): %.cpp
	$(CCX) -c $< -o $@ 	$(CXXFLAGS)

$(TARGET) : $(OBJS)
	$(CCX) -o $@ $^ $(CXXFLAGS)
