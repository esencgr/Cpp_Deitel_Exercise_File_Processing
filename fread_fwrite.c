#include <stdio.h>
int main(){

    // fread( void *ptr, each_element_size, read_element_size, FILE *file );
    // fwrite( void *ptr, each_element_size, read_element_size, FILE *file );

    FILE *fp;
    char buffer[ 11 ];

    if (fp = fopen( "testdata_0.txt", "r" )) {
        fread( buffer, 1, 10, fp );
        buffer[ 10 ] = 0;
        fclose( fp );
        printf( "first 10 char : \n%s\n", buffer );
    }
    else
        printf( "dont opened file");


    FILE *fs;
    char stock[ 3 ] = { '2','1','1' };
    
    fs = fopen( "testdata_1.txt", "w" );
    fwrite( stock, 1, 3, fs );
    fclose( fs );

    return 0;
}
