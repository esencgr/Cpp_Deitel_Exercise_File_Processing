#include <stdio.h>
<<<<<<< HEAD

// fread( void *ptr, each_element_size, read_element_size, FILE *file );
// fwrite( void *ptr, each_element_size, read_element_size, FILE *file );

struct custom_data{
    int no;
    char name[ 15 ];
    double salary;
=======
// fread( void *ptr, each_element_size, read_element_size, FILE *file );
// fwrite( void *ptr, each_element_size, read_element_size, FILE *file );
struct custom_data{
    int no;
    char name[ 15 ];
    float salary;
>>>>>>> 92c1b7ecf18fb1ad8e374d3ac85f9788c6d6451c
};

int main(){

    FILE *f_ptr;
    struct custom_data custom = { 0, "", 0.0 };

<<<<<<< HEAD
    if ((f_ptr = fopen( "account.txt", "w+" )) == NULL)
=======
    if ((f_ptr = fopen( "account.txt", "rb+" )) == NULL)
>>>>>>> 92c1b7ecf18fb1ad8e374d3ac85f9788c6d6451c
        printf( "The file is not opened !\n" );

    else{
        printf( "Enter custom no (Q -> 0) : \n?" );
<<<<<<< HEAD
        fscanf( stdin, "%d", &custom.no );

        while ( custom.no != 0 ){
            printf( "Enter name - salary : \n?" );
            fscanf( stdin, "%s%lf", custom.name, &custom.salary );

            // fprintf( f_ptr, "%d %s %lf", custom.no, custom.name, custom.salary );
=======
        scanf( "%d\n", &custom.no );

        while ( custom.no != 0 ){
            printf( "Enter name - salary : \n?" );
            fscanf( stdin, "%s%lf", &custom.name, &custom.salary );
>>>>>>> 92c1b7ecf18fb1ad8e374d3ac85f9788c6d6451c

            fseek( f_ptr, (( custom.no - 1 ) * sizeof( struct custom_data )), SEEK_SET );
            fwrite( &custom, sizeof( struct custom_data ), 1, f_ptr );

<<<<<<< HEAD
            printf( "\nEnter custom no : \n?" );
            fscanf( stdin, "%d", &custom.no );
=======
            printf( "Enter custom no : \n?" );
            scanf( "%d", &custom.no );
>>>>>>> 92c1b7ecf18fb1ad8e374d3ac85f9788c6d6451c
        }

        fclose( f_ptr );
    }

<<<<<<< HEAD

=======
>>>>>>> 92c1b7ecf18fb1ad8e374d3ac85f9788c6d6451c
    if ((f_ptr = fopen( "account.txt", "r" )) == NULL)
        printf( "The file is not opened !\n" );

    else{
        printf( "%s\t %s\t %s\n", "no", "name", "account" );

<<<<<<< HEAD
        while ( !feof( f_ptr )){

            if ( custom.no != 0 )
                printf( "%d\t%s\t%lf\n", custom.no, custom.name, custom.salary );

            // fscanf( f_ptr, "%d%s%lf", &custom.no, &custom.name, &custom.salary );
            fread( &custom, sizeof( struct custom_data ), 1, f_ptr );
        }
=======
        do{
            fread( &custom, sizeof( struct custom_data ), 1, f_ptr );
            if ( custom.no != 0 )
               printf( "%d\t%s\t%lf\n", &custom.no ,&custom.name, &custom.salary );
        } while ( !feof( f_ptr ));
>>>>>>> 92c1b7ecf18fb1ad8e374d3ac85f9788c6d6451c

        fclose( f_ptr );
    }

<<<<<<< HEAD

    return 0;
}
=======
    return 0;
}

// int main(){
//
//     // fread( void *ptr, each_element_size, read_element_size, FILE *file );
//     // fwrite( void *ptr, each_element_size, read_element_size, FILE *file );
//     struct a_data data = { 0,"",0.0 } ;
//     FILE *f_ptr;
//
//     if ((f_ptr = fopen( "account.txt", "w" )) == NULL)
//         printf( "The file is not opened !\n" );
//
//     else{
//         for (int i = 0; i < 100; i++)
//             fwrite( &data, sizeof( struct a_data ), 1, f_ptr );
//
//         fclose( f_ptr );
//     }
//
//
//
//     return 0;
// }
>>>>>>> 92c1b7ecf18fb1ad8e374d3ac85f9788c6d6451c
