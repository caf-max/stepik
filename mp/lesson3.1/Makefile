all: build_server build_client build_echo_server

build_echo_server:
	gcc -ggdb -O0 -o echo_server echo_server.c

build_server:
	gcc -ggdb -O0 -o server server.c

build_client:
	gcc -ggdb -O0 -o client client.c

