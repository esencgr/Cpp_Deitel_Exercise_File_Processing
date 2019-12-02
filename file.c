#include <stdio.h>

int main(){

    // fprintf( fp, "string", variables );
    // fscanf( fp, "string", identifiers );

    int a = 12, d;
    float b = 13.6, e, f;
    char c = 's', new_c;

    FILE *outfile, *infile;

    outfile = fopen( "testdata.txt", "w" );     // write mode --> write to file
    fprintf( outfile, "%d %f %c", a*2, b, c );
    printf( "%d %f %c \n", a, b, c );
    fclose( outfile );

    infile = fopen( "testdata.txt", "r" );       // read mode --> read the console
    fscanf( infile, "%c %f %f", &new_c, &e, &f );
    printf( "%d %f %f \n", new_c, e, f );
    fclose( infile );
    
    return 0;
}
