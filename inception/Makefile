all: up

.PHONY: up

up:
	@sudo docker compose -f ./src/docker-compose.yml up --build

down:
	@sudo docker compose -f ./src/docker-compose.yml down

status:
	@sudo docker ps

clean:
	@sudo docker compose -f ./src/docker-compose.yml down -v --rmi all
	@sudo rm -rf /home/inception-user/data/mariadb/* /home/inception-user/data/wordpress/*

re: clean up

prune: clean
	@sudo docker system prune -af