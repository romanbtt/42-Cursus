IMAGE = ft_server_image
CONTAINER = ft_server


docker-build:
		docker build -t $(IMAGE) .

docker-run:
		docker container run --name $(CONTAINER) -p 80:80 -p 443:443 -d $(IMAGE)

docker-run-off:
		docker container run --name $(CONTAINER) -e AUTO_INDEX=off -p 80:80 -p 443:443 -d $(IMAGE)

all: docker-build docker-run

docker-stop:
		docker container stop $(CONTAINER)

docker-rm: docker-stop
		docker container rm $(CONTAINER)

docker-rmi: docker-rm
		docker image rm $(IMAGE)

docker-exec:
		docker container exec -it $(CONTAINER) bash

autoindex-on:
		docker container exec $(CONTAINER) bash /root/autoindex.sh on

autoindex-off:
		docker container exec $(CONTAINER) bash /root/autoindex.sh off

clean: docker-rm docker-rmi