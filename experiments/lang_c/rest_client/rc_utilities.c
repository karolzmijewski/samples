#include <string.h>
#include <stdio.h>

int opterr = 1,
    optind = 1,
    optopt,
    optreset;
char *p_optarg;

#define BADCH   (int)'?'
#define BADARG  (int)':'
#define EMSG    ""

int getopt(int nargc,
           char * const nargv[],
           const char *p_ostr) {
    static char *p_place = EMSG;
    const char *p_oli;
    if (optreset || !*p_place) {
        optreset = 0;
        if (optind >= nargc || *(p_place = nargv[optind]) != '-') {
            p_place = EMSG;
            return (-1);
        }
        if (p_place[1] && *++p_place == '-') {
            ++optind;
            p_place = EMSG;
            return (-1);
        }
    }
    if ((optopt = (int)*p_place++) == (int)':' ||
        !(p_oli = strchr(p_ostr, optopt))) {
        if (optopt == (int)'-')
            return (-1);
        if (!*p_place)
            ++optind;
        if (opterr && *p_ostr != ':')
            (void)printf("illegal option -- %c\n", optopt);
        return (BADCH);
    }
    if (*++p_oli != ':') {
        p_optarg = NULL;
        if (!*p_place)
            ++optind;
    } else {
        if (*p_place)
            p_optarg = p_place;
        else if (nargc <= ++optind) {
            p_place = EMSG;
            if (*p_ostr == ':')
                return (BADARG);
            if (opterr)
                (void)printf("option requires an argument -- %c\n", optopt);
            return (BADCH);
        } else {
            p_optarg = nargv[optind];
        }
        p_place = EMSG;
        ++optind;
    }
    return (optopt);
}
