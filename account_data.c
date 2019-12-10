#include <stdio.h>

// fread( void *ptr, each_element_size, read_element_size, FILE *file );
// fwrite( void *ptr, each_element_size, read_element_size, FILE *file );

struct custom_data{
    int no;
    char name[ 15 ];
    double salary;
};

int main(){

    FILE *f_ptr;
    struct custom_data custom = { 0, "", 0.0 };

    if ((f_ptr = fopen( "account.txt", "w+" )) == NULL)
        printf( "The file is not opened !\n" );

    else{
        printf( "Enter custom no (Q -> 0) : \n?" );
        fscanf( stdin, "%d", &custom.no );

        while ( custom.no != 0 ){
            printf( "Enter name - salary : \n?" );
            fscanf( stdin, "%s%lf", custom.name, &custom.salary );

            // fprintf( f_ptr, "%d %s %lf", custom.no, custom.name, custom.salary );

            fseek( f_ptr, (( custom.no - 1 ) * sizeof( struct custom_data )), SEEK_SET );
            fwrite( &custom, sizeof( struct custom_data ), 1, f_ptr );

            printf( "\nEnter custom no : \n?" );
            fscanf( stdin, "%d", &custom.no );
        }

        fclose( f_ptr );
    }


    if ((f_ptr = fopen( "account.txt", "r" )) == NULL)
        printf( "The file is not opened !\n" );

    else{
        printf( "%s\t %s\t %s\n", "no", "name", "account" );

        while ( !feof( f_ptr )){

            if ( custom.no != 0 )
                printf( "%d\t%s\t%lf\n", custom.no, custom.name, custom.salary );

            // fscanf( f_ptr, "%d%s%lf", &custom.no, &custom.name, &custom.salary );
            fread( &custom, sizeof( struct custom_data ), 1, f_ptr );
        }

        fclose( f_ptr );
    }


    return 0;
}
