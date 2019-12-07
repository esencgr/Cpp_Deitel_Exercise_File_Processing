#include <stdio.h>

int main(){

    // fprintf( fp, "string", variables );
    // fscanf( fp, "string", identifiers );

    int a = 12, d;
    float b = 13.6, e;
    char c = 's', f;

    FILE *outfile, *infile;

    outfile = fopen( "testdata_0.txt", "w" );     // write mode --> write to file
    fprintf( outfile, "%d %f %c", a, b, c );
    printf( "%d %f %c", a, b, c );
    fclose( outfile );

    infile = fopen( "testdata.txt_0", "r" );       // read mode --> read to file
    fscanf( infile, "%d %f %c", &d, &e, &f );
    fclose( infile );

    return 0;
}
