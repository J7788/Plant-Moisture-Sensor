#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
using namespace std;
int main(){
    struct sockaddr_in addy;
    //Creating the socket and address
    addy.sin_family = AF_INET;
    addy.sin_addr.s_addr = htonl(INADDR_ANY);
    addy.sin_port = htons(1492);

    int socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0){
        perror("Error while creating socket");
        exit(EXIT_FAILURE);
    }
    //Binding the socket to port number 1492
    if(bind(socket_fd, (struct sockaddr*)&addy, sizeof(addy)) > 0){
        perror("Error while binding socket");
        exit(EXIT_FAILURE);
    }


    //Turn on listening for the server
    if(listen(socket_fd, 5) < 0){
        perror("Error while listening");
        exit(EXIT_FAILURE);
    }

    //Accepting a new connection
    struct sockaddr_in client;
    unsigned int client_sock_len;

    int new_sock = accept(socket_fd, (struct sockaddr*)&client, &client_sock_len);
    char buffer[256];

    //Reading the data from the connection
    if(read(new_sock, buffer, 255) < 0){
        perror("read");
        exit(EXIT_FAILURE);
    }
    buffer[256] = '\0';
    printf(buffer);

    //Writing a return message to the connection
    char return_message[256] = "This is a return message to the esp8266"; 
    if(write(new_sock, return_message, 256) < 0){
        perror("write");
        exit(EXIT_FAILURE);
    }

    return 0;
}