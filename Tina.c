#include "Cookie.h"
#include "Helpers.h"

int main (int argc, char**argv){
    CLIENT *client;
    int *a;
    char *server;
    
    if (argc !=2 ){
        fprintf(stderr, "Please type argument so that %s HOSTNAME\n", *argv);
        return 1;
    }
    server = argv[1];
    
    //make the client
    if ( (client = clnt_create(server, DISPLAY_PRG, DISPLAY_VER, "udp")) == (CLIENT *)NULL){
        clnt_pcreateerror(server);
        exit(2);
    }

    while (*a != -2){
        sleepRand();
        print_info(); printf("Request for a cookie\n");
        struct CookieRequest request = {TinaNum};
        a = request_cookie_1(&request, client);
    
        if (*a == 1){
            print_info(); printf("I got a cookie <:\n");
        
         }
        else if (*a == -1){
            print_info(); printf("I didn't get a cookie ;-;\n");
        
        }
        else if (*a == -3) {
             fprintf(stderr, "invalid b value sent to the server\n");
        }
    }
    clnt_destroy(client);
    return 0;
}
