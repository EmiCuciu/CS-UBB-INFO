#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <string.h>

int main() {
  int c;
  struct sockaddr_in server;
  uint16_t a, b, suma;

  c = socket(AF_INET, SOCK_STREAM, 0);
  if (c < 0) {
    printf("Eroare la crearea socketului client\n");
    return 1;
  }


  int port;
  printf("Introduceti portul: ");
  scanf("%d", &port);

  char ip[50];
  printf("Introduceti ip-ul: ");
  scanf("%s", ip);

  memset(&server, 0, sizeof(server));
  server.sin_port = htons(port);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(ip);

  if (connect(c, (struct sockaddr*)&server, sizeof(server)) < 0) {
    printf("Eroare la conectarea la server\n");
    return 1;
  }

  printf("a = ");
  scanf("%hu", &a);
  printf("b = ");
  scanf("%hu", &b);
  a = htons(a);
  b = htons(b);
  send(c, &a, sizeof(a), 0);
  send(c, &b, sizeof(b), 0);
  recv(c, &suma, sizeof(suma), 0);
  suma = ntohs(suma);
  printf("Suma este %hu\n", suma);
  close(c);
}