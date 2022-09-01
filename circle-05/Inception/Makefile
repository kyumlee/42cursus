all:
	docker build ./srcs/requirements/nginx/ -t test
	docker run -p 443:443 --name abc test

clean:
	docker rm abc
	docker rmi test
