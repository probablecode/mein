#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main() {
    const char *hostname = "www.example.com";
    const char *service = "http";

    struct addrinfo hints, *result, *rp;
    int status;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;    // IPv4 또는 IPv6 주소 모두 허용
    hints.ai_socktype = SOCK_STREAM;    // TCP 소켓

    status = getaddrinfo(hostname, service, &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    printf("Resolved IP addresses for %s:\n", hostname);

    for (rp = result; rp != NULL; rp = rp->ai_next) {
        char ip[INET6_ADDRSTRLEN];
        void *addr;

        if (rp->ai_family == AF_INET) {
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)rp->ai_addr;
            addr = &(ipv4->sin_addr);
        } else {
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)rp->ai_addr;
            addr = &(ipv6->sin6_addr);
        }

        inet_ntop(rp->ai_family, addr, ip, INET6_ADDRSTRLEN);
        printf("- %s\n", ip);
    }

    freeaddrinfo(result);

    return 0;
}
