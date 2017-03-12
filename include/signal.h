#define SIGABRT 1
#define SIGFPE 2
#define SIGILL 3
#define SIGINT 4
#define SIGSEGV 5
#define SIGTERM 6
#define SIG_DFL 0
#define SIG_IGN 0
static int raise(int sig) { return 0; }

static void (*signal( int sig, void (*handler)(int)))(int) {
    return handler;
}

