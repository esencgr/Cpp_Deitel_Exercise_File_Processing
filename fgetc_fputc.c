#include <stdio.h>
int main(){

    // fprintf( fp, "string", variables );
    // fscanf( fp, "string", identifiers );
    // ch = fgetc( fp ); get a char of file in ordered and when the end of file

    char ch;
    FILE *fp;

    fp = fopen( "testdata_0.txt", "r" );
    while (!feof( fp )) {
        ch = fgetc( fp );
        printf( "%c", ch );
    }
    fclose( fp );

    fp = fopen( "testdata_0.txt", "a" );
    char c;
    scanf( "%s", &c );
    fprintf( fp, "%c", c );
    fclose( fp );

    return 0;
}
