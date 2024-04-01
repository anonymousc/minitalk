FLAGS = -Wextra -Wall -Werror

CC = cc

CLIENT = client

SERVER = server

all : $(CLIENT) $(SERVER) 

	@echo "\033[0;32menjoy\033[0m"

$(CLIENT) : 
	@$(CC) $(FLAGS) client.c minitalk_utils.c -o $(CLIENT) 
	@echo "\033[0;32mcompiling the client...\033[0m"
	@sleep 2 

$(SERVER) : 

	@echo "\033[0;32mcompiling the server...\033[0m"
	@sleep 2 
	@$(CC) $(FLAGS) server.c minitalk_utils.c -o $(SERVER)

clean : 
	@rm -rf server client
	@echo "\033[1;31mremoving the ELF files\033[0m"

re : clean all
