#include <stdio.h>
struct data{
    int no;
    char name[ 30 ];
    float salary;
};

int choise( void );
void create( FILE * );
void update( FILE * );
void add( FILE * );
void delete( FILE * );

int main(){

    FILE *fptr;
    int the_choise;

    if ((fptr = fopen( "file_sys.txt", "r" )) == NULL)
        printf( "The file is not opened !\n" );

    else{
        while ((the_choise = choise( )) != 5){
            switch( the_choise ){
                case 1:
                    create( fptr );
                break;
                case 2:
                    update( fptr );
                break;
                case 3:
                    //add( fptr );
                break;
                case 4:
                  //  delete( fptr );
                break;
            }
        }
        fclose( fptr );
    }

    return 0;
}

int choise( void ){
    int enter;

    printf( " \t1 - CREATE\n "
            " \t2 - UPDATE\n "
            " \t3 - ADD   \n "
            " \t4 - CREATE\n "
            " \t5 - QUIT  \n" );
    scanf( "%d", &enter );

    return enter;
}

/* create formatted text file for printing */
void create( FILE *f_read ){
    FILE *f_write;                                // accounts.txt file pointer
    struct data custom = { 0, "", 0.0 };

    if (( f_write = fopen( "file_sys_new.txt", "w" )) == NULL)
        printf( "The file is not opened !\n" );

    else{
        rewind( f_write );                         // sets pointer to beginning of file
        fprintf( f_write, "%s\t%s\t%s\n", "no", "name", "salary" );

        while (!feof( f_read )){                  // copy all records from random-access file into text file.
            fread( &custom, sizeof( struct data ), 1, f_read );
            if ( custom.no != 0 )                 // write single record to text file
                fprintf( f_write, "%d\t%s\t%lf\n", custom.no, custom.name, custom.salary );
        }

        fclose( f_write );
    }
}

/* update balance in record */
void update( FILE *f_ptr ){
    int account;
    double update;
    struct data custom = { 0, "", 0.0 };

    printf( "enter account no for update (1-100):" );
    scanf( "%d", &account );

    fseek( f_ptr, ( account - 1 ) * sizeof( struct data ), SEEK_SET );   // move file pointer to correct record in file
    fread( &custom, sizeof( struct data ), 1, f_ptr ); /* read record from file */

        if ( custom.no == 0 )
            printf( "account is not available.\n" );

        else{
            printf( "enter debt (+) and payment (-)" );
            scanf( "%d \n", &update );

            custom.salary += update;
            printf( "%d\t %s\t, %lf\n", custom.no, custom.name, custom.salary );

            fseek( f_ptr, ( account - 1 ) * sizeof( struct data ), SEEK_SET );   // move file pointer to correct record in file
            fwrite( &custom, sizeof( struct data ), 1, f_ptr ); /* read record from file */
        }
}

// /* create and insert record */
// void add( FILE *f_ptr ){
//
// }
//
// /* delete an existing record */
// void delete( FILE *f_ptr ){
//
// }
