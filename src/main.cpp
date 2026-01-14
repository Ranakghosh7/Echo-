#include <iostream>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <unistd.h>     
#include <cstring>      

int main() {
    std::cout << "--- Flux Server Starting ---" << std::endl;

    
    // AF_INET = IPv4, SOCK_STREAM = TCP
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }

    
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on any network interface (WiFi, Ethernet, localhost)
    address.sin_port = htons(8080);       

    
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed. Is the port busy?" << std::endl;
        return -1;
    }

    
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return -1;
    }

    std::cout << "Server is listening on Port 8080..." << std::endl;
    std::cout << "Run 'curl localhost:8080' in another terminal to test!" << std::endl;

    
    while (true) {
        std::cout << "Waiting for connection..." << std::endl;
        
        int new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            std::cerr << "Accept failed" << std::endl;
            continue;
        }

        std::cout << ">> Connection accepted! (ID: " << new_socket << ")" << std::endl;
        
        
        const char* response = 
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: 23\r\n" 
            "\r\n"                  
            "Hello from Flux Server!";
            
        send(new_socket, response, strlen(response), 0);
        
        
        close(new_socket);
    }

    return 0;
}