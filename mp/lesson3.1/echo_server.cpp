#include <iostream>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


class EchoServer
{
	int _sockfd;
	char buff[128];

public:
	EchoServer() {
		_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	}

	void Start(const std::string& ip, short port) {
		struct sockaddr_in sa;
		sa.sin_family = AF_INET;
		sa.sin_port = htons(port);
		sa.sin_addr.s_addr = inet_addr(ip.c_str());
		bind(_sockfd, (struct sockaddr*)(&sa), sizeof(sa));
		listen(_sockfd, SOMAXCONN);

		while(1) {
			int clientfd = accept(_sockfd, 0, 0);
			memset(buff, 0, 128);
			ssize_t rec = recv(clientfd, buff, 128, MSG_NOSIGNAL);
			std::cout << buff << std::endl;
			send(clientfd, buff, rec, MSG_NOSIGNAL);
			close(clientfd);
		}
	}
};

int main(int argc, char **argv)
{
	EchoServer server;
	server.Start("127.0.0.1", 12345);

	return 0;
}

