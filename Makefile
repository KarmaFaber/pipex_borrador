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

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ pipex srcs ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

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
	@-$(VALGRIND) ./pipex infile "ls -l" "wc -l" outfile
	@test/hs_files/./open_valgrind_log.sh
	@echo "$(CURRENT_COLOR)➵⤐╌╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣── Valgrind completed. Check valgrind_output.log for details. ─╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣╌╌─$(RESET)"
	
clean_valgrind:
	test/hs_files/./clean_valgrind.sh

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ Sanitizers ▢───▣───◉•◉───▣───▢◇▢───▣───◉#
#◉──▢◇▢───▣───◉•◉────▢Sanitizer  All▢────◉•◉───▣───▢◇▢──◉#

san_all: run_asan run_lsan run_tsan run_usan

#◉──▢◇▢───▣───◉•◉────▢AddressSanitizer ▢────◉•◉───▣───▢◇▢──◉#

asan: $(PIPEX_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -fsanitize=address -g $(PIPEX_SRCS) -o $(NAME) -L$(LIBFT_DIR) -lft $(INCLUDES_LIBFT)
	@echo "$(CURRENT_COLOR) $(NAME) compiled with AddressSanitizer.\n$(RESET)"

run_asan: asan
	@echo "$(CURRENT_COLOR)➵ Running with AddressSanitizer: $(RESET)"
	./$(NAME) infile "ls -l" "wc -l" outfile
	@echo "$(CURRENT_COLOR)➵ AddressSanitizer run completed.$(RESET)"

#◉──▢◇▢───▣───◉•◉────▢UndefinedBehaviorSanitizer ▢────◉•◉───▣───▢◇▢──◉#

usan: $(PIPEX_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -fsanitize=undefined -g $(PIPEX_SRCS) -o $(NAME) -L$(LIBFT_DIR) -lft $(INCLUDES_LIBFT)
	@echo "$(CURRENT_COLOR) $(NAME) compiled with UndefinedBehaviorSanitizer.\n$(RESET)"

run_usan: usan
	@echo "$(CURRENT_COLOR)➵ Running with UndefinedBehaviorSanitizer: $(RESET)"
	./$(NAME) infile "ls -l" "wc -l" outfile
	@echo "$(CURRENT_COLOR)➵ UndefinedBehaviorSanitizer run completed.$(RESET)"

#◉──▢◇▢───▣───◉•◉────▢LeakSanitizer ▢────◉•◉───▣───▢◇▢──◉#

lsan: $(PIPEX_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -fsanitize=leak -g $(PIPEX_SRCS) -o $(NAME) -L$(LIBFT_DIR) -lft $(INCLUDES_LIBFT)
	@echo "$(CURRENT_COLOR) $(NAME) compiled with LeakSanitizer.\n$(RESET)"

run_lsan: lsan
	@echo "$(CURRENT_COLOR)➵ Running with LeakSanitizer: $(RESET)"
	./$(NAME) infile "ls -l" "wc -l" outfile
	@echo "$(CURRENT_COLOR)➵ LeakSanitizer run completed.$(RESET)"

#◉──▢◇▢───▣───◉•◉────▢ThreadSanitizer ▢────◉•◉───▣───▢◇▢──◉#

tsan: $(PIPEX_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -fsanitize=thread -g $(PIPEX_SRCS) -o $(NAME) -L$(LIBFT_DIR) -lft $(INCLUDES_LIBFT)
	@echo "$(CURRENT_COLOR) $(NAME) compiled with ThreadSanitizer.\n$(RESET)"

run_tsan: tsan
	@echo "$(CURRENT_COLOR)➵ Running with ThreadSanitizer: $(RESET)"
	./$(NAME) infile "ls -l" "wc -l" outfile
	@echo "$(CURRENT_COLOR)➵ ThreadSanitizer run completed.$(RESET)"

#◉───▣───▢◇▢───▣───◉•◉───▣───▢   Norminette   ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

norm:
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Checking Norminette: ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"
	@norminette libft $(PIPEX_SRCS) pipex.h
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Norminette completed. Check your output for details. ─╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣╌╌─$(RESET)"

	
#◉───▣───▢◇▢───▣───◉•◉───▣───▢      Test      ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

test_all: norm test valgrind san_all

test: all
#añadir infile y contenido al infile
	@touch infile
	@echo "hola \na1 \na1 \na2" > infile
	@echo "   "
#revisar que *.sh tienen permisos en /test/sh_files/
	@echo "Ensuring all scripts in /test/hs_files/ have execution permissions..."
	@find test/hs_files/ -name "*.sh" ! -perm -111 -exec chmod +x {} \;
#startr test common commands:
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Starting tests: common commands: ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"
	@test/hs_files/./test_pipex.sh
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── End of tests: common commands. ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"
	@echo "   "
#startr test special_cases commands:
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Starting tests: special_cases command: ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"
	@test/hs_files/./special_cases.sh
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── End of tests: special_cases command. ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"
	@echo "   "

clean_test:
	@test/hs_files/./clean_test.sh
	@test -f errors.log && rm errors.log || true
	@test -f infile && rm infile || true
	@test -f outfile && rm outfile || true

fclean_test: fclean clean_test

fclean_all: fclean clean_test clean_valgrind
	
#◉───▣───▢◇▢───▣───◉•◉───▣───▢ Phony targets  ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

.PHONY: all clean fclean re norm test test_all valgrind san_all run_asan run_usan run_lsan run_tsan clean_valgrind clean_test fclean_all fclean_test