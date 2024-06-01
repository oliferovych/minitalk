# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/21 18:24:10 by dolifero          #+#    #+#              #
#    Updated: 2024/05/30 16:28:15 by dolifero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Minitalk

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

LIBFT_DIR 		= ./Libft
LIBFT			= $(LIBFT_DIR)/libft.a

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
BOLD_WHITE	=	\033[1;97m
BOLD_GREEN	=	\033[1;92m
NO_COLOR	=	\033[0m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[2;96m
WHITE		=	\033[0;97m

all:			$(LIBFT)
				@echo "\n$(BOLD_CYAN)Starting $(BOLD_WHITE)[${NAME}] $(BOLD_CYAN)compilation..$(DEF_COLOR)\n"
				cc $(CFLAGS) $(LIBFT) server.c -o server
				cc $(CFLAGS) $(LIBFT) client.c -o client
				@echo "\n$(BOLD_GREEN)${NAME} DONE!\n$(DEF_COLOR)"

bonus:			$(LIBFT)
				@echo "\n$(BOLD_CYAN)Starting $(BOLD_WHITE)[${NAME}] bonus $(BOLD_CYAN)compilation..$(DEF_COLOR)\n"
				cc $(CFLAGS) $(LIBFT) bonus/server_bonus.c -o server
				cc $(CFLAGS) $(LIBFT) bonus/client_bonus.c -o client
				@echo "\n$(BOLD_GREEN)${NAME} DONE!\n$(DEF_COLOR)"

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR)

clean:
				@echo "$(CYAN)"
				$(RM) $(LIBFT_DIR)/*.o
				$(RM) -rf $(LIBMLX)/build
				@echo "$(DEF_COLOR)"
				@echo "\n$(BOLD_GREEN)Clean!\n$(DEF_COLOR)"

fclean:
				@echo "$(CYAN)"
				$(RM) -rf server client $(LIBFT_DIR)/*.o $(LIBFT)
				@echo "$(DEF_COLOR)"
				@echo "\n$(BOLD_GREEN)Fclean!\n$(DEF_COLOR)"

re:				fclean all

.PHONY:			all clean fclean re libmlx

