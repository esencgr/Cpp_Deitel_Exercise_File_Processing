#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

string reverse( string str ){
     int s = str.size(  );

     char *p = &str[ 0 ] + ( s-1 );
     char *q = &str[ 0 ];
     
     // char *p = &str[ 0 ];
     // for (; *p != '\0';)
     //     p++;
     // p--;

     while ( p > q ){
         char temp = *p;
         *p = *q;
         *q = temp;
         p--;
         q++;
     }

     return str;
}

int main(){

    ifstream input( "testdata_3.txt" );
    ofstream output( "testdata_3_out.txt" );
    string s;

    while (getline( input, s )){
        cout << reverse( s ) << endl;
        output << reverse( s ) << endl;
    }
    input.close();
    output.close();

    return 0;
}
