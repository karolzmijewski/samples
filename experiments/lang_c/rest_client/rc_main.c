#include <stdio.h>
#include <curl/curl.h>
#include "rc_helper.h"

#ifdef _WIN32
#include "rc_utilities.h"
#else
#include <unistd.h>
#endif

int main(int argc, char *argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "tprslh")) != -1) {
        switch (opt) {
            case 't': start(); break;
            case 'p': stop(); break;
            case 'r': restart(); break;
            case 's': status(); break;
            case 'l': log(); break;
            case 'h':
            default:
                fprintf(stderr, "Usage: %s [-tprsl] ("
                        "-t [start] "
                        "-p [stop] "
                        "-r [restart] "
                        "-s [status] "
                        "-l [log])\n", argv[0]);
                return -1;
        }
    }
    return 0;
}
