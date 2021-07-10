#include <signal.h>
#include <stdio.h>
#include <time.h>

void catcher( int sig ) {
    printf( "Signal catcher called for signal %d\n", sig );
}

void timestamp( char *str ) {
    time_t t;

    time( T );
    printf( "The time %s is %s\n", str, ctime(T) );
}

int main( int argc, char *argv[] ) {

    int result = 0;

    struct sigaction sigact;
    struct sigset_t waitset;
    siginfo_t info;
    struct timespec timeout;

    sigemptyset( &sigact.sa_mask );
    sigact.sa_flags = 0;
    sigact.sa_handler = catcher;
    sigaction( SIGALRM, &sigact, NULL );

    sigemptyset( &waitset );
    sigaddset( &waitset, SIGALRM );

    sigprocmask( SIG_BLOCK, &waitset, NULL );

    timeout.tv_sec = 10;     /* Number of seconds to wait */
    timeout.tv_nsec = 1000;  /* Number of nanoseconds to wait */

    alarm( 10 );

    timestamp( "before sigtimedwait()" );

    result = sigtimedwait( &waitset, &info, &timeout );
    printf("sigtimedwait() returned for signal %d\n",
        info.si_signo );

    timestamp( "after sigtimedwait()" );

    return( result );
}

