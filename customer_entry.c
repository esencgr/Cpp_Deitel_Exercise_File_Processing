#include <stdio.h>
#include <stdlib.h>

int main(){

    int no;
    char *name[ 30 ];
    char str[ 30 ];
    float salary;
    FILE *fptr;

    printf(" -----------------WRITING FILE ------------\n" );

    if ((fptr=fopen ("custom.txt", "w")) == NULL) {
        printf( "not opened file\n " );
    }

    else{
        printf( "no - name - salary\n" );
        do {
           scanf( "%d %s %f\n", &no, &name, &salary );
           fprintf( fptr,"%d %s %f\n", no, name, salary );
        } while (!feof( stdin ));
        fclose( fptr );
    }

    printf(" -----------------READING FILE ------------\n" );

    if ((fptr=fopen ("custom.txt", "r")) == NULL) {
        printf( "not opened file\n " );
    }

    else{
        printf( "%s\t %s\t %s\n", "no", "name", "salary" );
        do {
           fscanf( fptr, "%d %s %f\n", &no, &name, &salary );
           printf( "%d\t %s\t %f\n", no, name, salary );
        } while (!feof( fptr ));
        fclose( fptr );
    }

    return 0;
}
