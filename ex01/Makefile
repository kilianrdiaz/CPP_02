NAME    = fixedConstructors2.0
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

SRC     = $(SRC_DIR)/main.cpp $(SRC_DIR)/Fixed.cpp
OBJ     = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile $(INC_DIR)/Fixed.hpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re