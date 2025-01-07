#◉────▣───▢◇▢───▣────◉•◉───▣───▢   Colors:   ▢───▣───◉•◉───▣────▢◇▢───▣───◉#

BLACK   := \033[0;30m
RED     := \033[0;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
MAGENTA := \033[0;35m
CYAN    := \033[0;36m

CURRENT_COLOR := \033[0;34m
RESET   := \033[0m

#◉───▣───▢◇▢───▣───◉•◉───▣───▢   Variables:   ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

NAME        := pipex
CC          := cc
CFLAGS      := -Wall -Wextra -Werror 
RM          := rm -rf

VALGRIND := valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-limit=no --log-file=test/valgrind_outputs/valgrind_output_$(shell date +%Y%m%d_%H%M%S).log -s

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ Libft Variables ▢───▣───◉•◉───▣───▢◇▢───▣──◉#

LIBFT_DIR	:= libft/
LIBFT		:= $(LIBFT_DIR)/libft.a
INCLUDES_LIBFT := -I$(LIBFT_DIR)

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ push_swap srcs ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

PIPEX_SRCS	:= pipex.c pipex_utils.c

PIPEX_OBJS	:= $(PIPEX_SRCS:.c=.o)

#◉───▣───▢◇▢───▣───◉•◉───▣───▢     rules      ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_DEPS)
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(PIPEX_OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(PIPEX_OBJS) -L$(LIBFT_DIR) -lft $(INCLUDES_LIBFT) 
	@echo "$(CURRENT_COLOR) $(NAME) created.\n$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_LIBFT) -c $< -o $@ 

clean:
	$(RM) $(PIPEX_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(CURRENT_COLOR)All object files have been cleaned.\n$(RESET)"

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(CURRENT_COLOR) $(NAME) and libft.a: have been cleaned.\n$(RESET)"

re: fclean all

#◉───▣───▢◇▢───▣───◉•◉───▣───▢    Valgrind    ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

valgrind: all

	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──Running Valgrind..──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──$(RESET)"
#	@-$(VALGRIND) ./pipex infile "grep a1" "wc -l" outfile
	@-$(VALGRIND) ./$(NAME) infile "ls -l" "wc -w" outfile
	@test/hs_files/./open_valgrind_log.sh
	@echo "$(CURRENT_COLOR)➵⤐╌╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣── Valgrind completed. Check valgrind_output.log for details. ─╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣╌╌─$(RESET)"
	
clean_valgrind:
	test/hs_files/./clean_valgrind.sh

#◉───▣───▢◇▢───▣───◉•◉───▣───▢   Norminette   ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

norm:
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Checking Norminette: ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"
	@norminette libft $(PIPEX_SRCS) pipex.h
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Norminette completed. Check your output for details. ─╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣╌╌─$(RESET)"

#◉───▣───▢◇▢───▣───◉•◉───▣───▢   Format   ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

format: 
	c_formatter_42 $(PIPEX_SRCS) pipex.h

#◉───▣───▢◇▢───▣───◉•◉───▣───▢      Test      ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

test: all
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Starting test: ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"
	@test/hs_files/./test_pipex.sh
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── End of test. ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"

clean_test:
	test/hs_files/./clean_test.sh

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ Phony targets  ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

.PHONY: all clean fclean re valgrind clean_valgrind clean_test format norm test 
