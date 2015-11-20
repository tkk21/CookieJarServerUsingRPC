#include "Helpers.h"

int cookieCount = 20;
int tina_cookie_consumed = 0;

char* getCookieRequestName(int b){
    if (b == JudyNum){
        return "Judy";
    }
    else if (b == TinaNum){
        return "Tina";
    }
    else {
        fprintf(stderr, "error: invalid b value received \n");
        return "Error";
    }
}

int *request_cookie_1_svc (struct CookieRequest *request, struct svc_req *req){
    static int a;
    int b = request->b;
    print_info(); printf("%s requests a cookie\n", getCookieRequestName(b));
    fflush(NULL);
    if (cookieCount <= 0){
        //ran out of cookie
        
        //-2 if cookie is empty
        a = -2;
        return (&a);
    }
    if (b == JudyNum){
        if (tina_cookie_consumed <2){
            // Do not allow Judy another cookie, she has to wait
            
            //-1 if it is Judy and Judy cannot get a cookie at this point of time
            a = -1;
            return (&a);
        }
        else {
            // Tiny has had two cookies since the last time Judy got one
            // Allow Judy a cookie
            cookieCount--;
            tina_cookie_consumed = 0;

            //1 if the cookie is sucessfully returned
            a = 1;
            return (&a);
        }
    } 
    else if (b == TinaNum){

        cookieCount--;
        tina_cookie_consumed++;

        //1 if the cookie is successfully returned
        a = 1;
        return (&a);
    }
    else {
        //error condition
        a = -3;
        return (&a);
    }
}
