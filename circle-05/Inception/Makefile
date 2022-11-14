all:
	mkdir -p /home/$$USER/data/wordpress
	mkdir -p /home/$$USER/data/database
	docker-compose -f ./srcs/docker-compose.yml up -d

clean:
	docker-compose -f ./srcs/docker-compose.yml down -v

fclean:
	docker-compose -f ./srcs/docker-compose.yml down -v --rmi all --remove-orphans
	sudo rm -rf /home/$$USER/data

re:	fclean all

ps:
	docker-compose -f ./srcs/docker-compose.yml ps

.PHONY: all clean fclean re ps
