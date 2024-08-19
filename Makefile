FLAGS = -Wextra -Wall -Werror

CC = cc

CLIENT = client

SERVER = server

sersrc = server.c

clisrc = client.c

sersrcb = server_bonus.c

clisrcb = client_bonus.c

CLIENT_BONUS = client_bonus

UTILS = minitalk_utils.c

SERVER_BONUS = server_bonus


all : $(CLIENT) $(SERVER) 
	@echo "\033[0;32menjoy\033[0m"

$(CLIENT) : $(clisrc)
	@$(CC) $(FLAGS) client.c $(UTILS) -o $(CLIENT) 
	@echo "\033[0;32mcompiling the client...\033[0m"
	@sleep 2 

$(SERVER) : $(sersrc)

	@echo "\033[0;32mcompiling the server...\033[0m"
	@sleep 2 
	@$(CC) $(FLAGS) server.c $(UTILS) -o $(SERVER)

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

$(CLIENT_BONUS) : $(clisrcb)
	@$(CC) $(FLAGS) client_bonus.c $(UTILS) -o $(CLIENT_BONUS) 
	@echo "\033[0;32mcompiling the client...\033[0m"
	@sleep 2 

$(SERVER_BONUS) : $(sersrcb)

	@echo "\033[0;32mcompiling the server...\033[0m"
	@sleep 2 
	@$(CC) $(FLAGS) server_bonus.c $(UTILS) -o $(SERVER_BONUS)

clean : 
	@rm -rf server_bonus client_bonus server client
	@echo "\033[1;31mremoving the ELF files\033[0m"
fclean : clean

re : clean all
