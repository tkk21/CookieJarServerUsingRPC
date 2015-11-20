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
    if ( (client = clnt_create(server, COOKIE_JAR, COOKIE_JAR_VERSION, "udp")) == (CLIENT *)NULL){
        clnt_pcreateerror(server);
        exit(2);
    }

    while (1){
        sleepRand();
        print_info(); printf("Request for a cookie\n");
        struct CookieRequest request = {JudyNum};
        a = request_cookie_1(&request, client);
    
        if (*a == 1){
            print_info(); printf("I got a cookie <:\n");
        
         }
        else if (*a == -1){
            print_info(); printf("I didn't get a cookie ;-;\n");
        
        }
        else if (*a == -2){
            print_info(); printf("No more cookie for you >:(\n");
            break;
        }
        else {
             fprintf(stderr, "invalid b value sent to the server\n");
        }
    }
    clnt_destroy(client);
    return 0;
}
