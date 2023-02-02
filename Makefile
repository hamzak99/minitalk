server = server
client = client

client_bon = client_bon
server_bon = server_bon

NAME_B = checker
flags = -Wall -Wextra -Werror


srcC = client.c ft_itoi.c ft_atoi.c  funct.c
srcS = server.c ft_itoi.c ft_atoi.c  funct.c

srcBC =  client_bonus.c ft_itoi.c ft_atoi.c  funct.c
srcBS =  server_bonus.c ft_itoi.c ft_atoi.c  funct.c

NAME = minitalk

%.o: %.c
	cc $(flags) -c $< -o $@

objc = $(srcC:.c=.o)
objs = $(srcS:.c=.o)

objBc = $(srcBC:.c=.o)
objBs = $(srcBS:.c=.o)

$(NAME): $(client) $(server)

all: $(NAME)

$(client): $(objc)
	cc $(flags) $(objc) -o client

$(server): $(objs)
	cc $(flags) $(objs) -o server

bonus: $(server_bon) $(client_bon)

server_bon: $(objBs)
	cc $(flags) $(objBs) -o $(server_bon)
client_bon:$(objBc)
	cc $(flags) $(objBc) -o $(client_bon)

clean: 
	rm -rf $(objc) $(objs)
	rm -rf $(objBc) $(objBs)

fclean:	clean
	rm -rf $(server) $(client)
	rm -rf $(client_bon) $(server_bon)

re: clean all

.PHONY: clean all re fclean $(NAME)