.SUFFIXES: .cpp .o .hpp .h .tpp
.PHONY : all clean re

#CCX = c++ 
CCX = clang++
RM = rm -rf

OBJ_DIR = objs/

ifndef TARGET
	TARGET = a.out
endif
ifndef SRCS
	SRCS =
endif
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

#CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
CXXFLAGS = -stdlib=libc++ -std=c++98 -pedantic -Wall -Wextra -Werror -Wshadow -Wno-shadow

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
