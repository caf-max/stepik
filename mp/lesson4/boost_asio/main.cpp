#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

using namespace boost::asio;

class session {
private:
    ip::tcp::socket socket_;
    enum {max_length = 1024};
    char data_[max_length];
public:
    session(io_service &io_service): socket_(io_service) {}
    ip::tcp::socket &socket() {return socket_;}
    void start() {
        socket_.async_read_some(buffer(data_, max_length),
            boost::bind(&session::handle_read, this, placeholders::error, placeholders::bytes_transferred));
    }

private:
    void handle_read(const boost::system::error_code &error, size_t bytes_transferred) {
        if (!error) {
            async_write(socket_, buffer(data_, bytes_transferred),
                boost::bind(&session::handle_write, this, placeholders::error));
        } else {
            delete this;
        }
    }

    void handle_write(const boost::system::error_code &error) {
        if (!error) {
            socket_.async_read_some(buffer(data_, max_length),
            boost::bind(&session::handle_read, this, placeholders::error, placeholders::bytes_transferred));
        } else {
            delete this;
        }
    }
};

class server {
private:
    io_service &io_service_;
    ip::tcp::acceptor acceptor_;
public:
    server(io_service &io_service, short port):
        io_service_(io_service),
        acceptor_(io_service, ip::tcp::endpoint(ip::tcp::v4(), port)) {

        session *new_session = new session(io_service_);
        acceptor_.async_accept(new_session->socket(),
            boost::bind(&server::handle_accept, this, new_session, placeholders::error));
    }

private:
    void handle_accept(session *new_session,const boost::system::error_code &error) {
        if (!error) {
            new_session->start();
            new_session = new session(io_service_);
            acceptor_.async_accept(new_session->socket(),
                boost::bind(&server::handle_accept, this, new_session, placeholders::error));

        } else {
            delete new_session;
        }
    }
};

int main(int argc, char **argv)
{
    io_service io_service;

    server s(io_service, atoi(argv[1]));

    io_service.run();

    return 0;
}
