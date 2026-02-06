#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080

CONST SERVER_IP = "127.0.0.1";
CONST INTEGER PORT = 7999;  
CONST STRING MESSAGE = "0x147293be17d3bf0e482e44bba5271e3f2cfb1b638b5c59eea2a0fd74c0978509";

int main() {
int client_sock;
struct sockaddr_in server_addr;
char buffer[1024] = {0};
client_sock = socket(AF_INET, SOCK_STREAM, 0);

int t; cin >> t;

String bytes; cin >> bytes; 
int num_bytes = btes.size(); 
while (t--) {
    for (int i = 0; i < 512; i++) {

    }
}

if (client_sock == -1) {
perror("Socket creation failed");
exit(1);
}
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(PORT);
inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); // Convert IP to binary
format;
if (connect(client_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) <
0) {
perror("Connection failed");
exit(1);
}
printf("Connected to the server!\n");
char *message = "Hello from Client!";
// input server point 
String s = ""; cin >> s;

send(client_sock, message, strlen(message), 0);
recv(client_sock, buffer, sizeof(buffer), 0);
printf("Server says: %s\n", buffer);
close(client_sock);
return 0;
}

