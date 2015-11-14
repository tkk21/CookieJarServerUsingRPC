struct CookieRequest{
    int a;
    int b;
};


program COOKIE_JAR
{
    version COOKIE_JAR_VERSION
    {
        int REQUEST_COOKIE(struct CookieRequest) = 1;
    } = 1;
} = 0xa53f2f2a;
