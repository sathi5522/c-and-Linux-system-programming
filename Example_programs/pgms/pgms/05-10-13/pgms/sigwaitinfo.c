#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

extern int errno;

void catcher( int sig ) {
    printf( "Signal catcher called for signal %d\n", sig );
}

void timestamp( char *str ) {
    time_t t;
int T;
    time(T);
    printf( "The time %s is %s\n", str, ctime(T) );
}

int main( int argc, char *argv[] ) {

    int result = 0;

    struct sigaction sigact;
    sigset_t waitset;
    siginfo_t info;

    sigemptyset( &sigact.sa_mask );
    sigact.sa_flags = 0;
    sigact.sa_handler = catcher;
    sigaction( SIGALRM, &sigact, NULL );

    sigemptyset( &waitset );
    sigaddset( &waitset, SIGALRM );

    sigprocmask( SIG_BLOCK, &waitset, NULL );

    alarm( 10 );

    timestamp( "before sigwaitinfo()" );

    result = sigwaitinfo( &waitset, &info );

    if( result == 0 )
        printf( "sigwaitinfo() returned for signal %d\n",
                 info.si_signo );
    else {
        printf( "sigwait() returned error number %d\n", errno );
        perror( "sigwait() function failed\n" );
    }

    timestamp( "after sigwaitinfo()" );

    return( result );
}



