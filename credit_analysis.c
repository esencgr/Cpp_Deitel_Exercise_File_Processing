#include <stdio.h>
#include <stdlib.h>

int main(){

    int no, choose;
    char name[ 30 ];
    float account;
    FILE *fptr;

    if ((fptr = fopen( "credit.txt", "r" )) == NULL)
        printf( "The file is not opened !\n" );

    else{

        printf( "Enter a choose :\n"
                "1- The account of zero arrear \n"    // ( account = 0 )
                "2- The account of have credit \n"  // ( account < 0 )
                "3- The account of have debit  \n"    // ( account > 0 ;)
                "4- Quit \n");

        do {
            printf( "\n?" );
            scanf( "%d", &choose );
            fscanf( fptr, "%d%s%f", &no, &name, &account );

            switch ( choose ){
                case 1:
                     printf( "The account of zero arrear:\n" );
                     while (!feof( fptr )){
                         if ( account == 0 ){
                            printf( "%d\t %s\t %f\n", no, name, account );
                         }
                         fscanf( fptr, "%d%s%f", &no, &name, &account );
                     }
                break;

                case 2:
                     printf( "The account of have credit:\n" );
                     while (!feof( fptr )){
                         if ( account < 0 ){
                            printf( "%d\t %s\t %f\n", no, name, account );
                         }
                         fscanf( fptr, "%d%s%f", &no, &name, &account );
                     }
                break;

                case 3:
                     printf( "The account of have debit:\n" );
                     while (!feof( fptr )){
                         if ( account > 0 ){
                            printf( "%d\t %s\t %f\n", no, name, account );
                         }
                         fscanf( fptr, "%d%s%f", &no, &name, &account );
                     }
                break;

            } // end switch

            rewind( fptr );

        } while (choose != 4); // end while

        printf( "Quit\n" );
        fclose( fptr );
  }                            // end else

  return 0;
}                              //end main
