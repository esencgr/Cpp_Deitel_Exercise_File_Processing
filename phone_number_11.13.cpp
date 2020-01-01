#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

void word( const int * const  );

int main(){

    int phone_number[ 7 ] = { 0 };
    cout << "Enter a phone number (digits 2 through 9) " << "in the form: xxx-xxxx\n";

    // loop 8 times: 7 digits plus hyphen
    // hyphen is is not placed in phoneNumber
    for (int u = 0, v = 0; u < 8; u++){
        char i = cin.get();
           if (isdigit( i ))
               phone_number[ v++ ] = i - 48 ;
    }
    word( phone_number );

    return 0;
}

void word( const int * const n ){
    ofstream file( "phone.txt " );
    const char *phone[ 10 ] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY" };

    if ( !file ){
       cerr << "\"phone.dat\" could not be opened.\n";
       exit( EXIT_FAILURE );
    }

    // output all possible combinations
    int count = 0;
    for (int i1 = 0; i1 <= 2; i1++)
        for (int i2 = 0; i2 <= 2; i2++)
            for (int i3 = 0; i3 <= 2; i3++)
                for (int i4 = 0; i4 <= 2; i4++)
                    for (int i5 = 0; i5 <= 2; i5++)
                        for (int i6 = 0; i6 <= 2; i6++)
                            for (int i7 = 0; i7 <= 2; i7++){
                                file << phone[ n[ 0 ] ][ i1 ]
                                     << phone[ n[ 1 ] ][ i2 ]
                                     << phone[ n[ 2 ] ][ i3 ]
                                     << phone[ n[ 3 ] ][ i4 ]
                                     << phone[ n[ 4 ] ][ i5 ]
                                     << phone[ n[ 5 ] ][ i6 ]
                                     << phone[ n[ 6 ] ][ i7 ] << " ";
                                 if ( ++count % 9 == 0 )
                                     file << "\n";
                            }

    file << "\nPhone number is ";
    for ( int i = 0; i < 7; ++i ){
         if ( i == 3 )
             file << '-';

         file << n[ i ];
    }
    file.close();
}
