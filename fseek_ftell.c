#include <stdio.h>
int main(){

    // SEEK_SET -> cursor in head of file
    // SEEK_CUR -> cursor in still state
    // SEEK_END -> cursor in end of file

    // fseek( fp, cursor_shifting_value, state_before_shifting ); --> used for cursor shifting
    // ftell( fp );                                               --> used for learn cursor state

    FILE *f;
    f = fopen( "testdata_2.txt", "w" );
    fputs( "bilgisayar kavramları", f );
    fseek( f, 5, SEEK_CUR);
    fputs( "end", f ),
    fclose( f );

    FILE *fs;
    fs = fopen( "testdata_3.txt", "w" );
    fprintf( fs ,"bilgisayar kavramlari" );
    printf( "how many character : %d " ,ftell( fs ));
    fclose( fs );
    
    return 0;
}
