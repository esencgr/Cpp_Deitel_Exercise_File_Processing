#include <iostream>
#include <fstream>
using namespace std;

int main(){

    //open file for writing
    ofstream file_out("size.txt");

    file_out << "DATA TYPES             \t" << "SIZE"  << endl;
    file_out << "char                   \t" << sizeof( char ) << endl;
    file_out << "short int              \t" << sizeof( short int ) << endl;
    file_out << "unsigned short int     \t" << sizeof( unsigned short int ) << endl;
    file_out << "int                    \t" << sizeof( int )   << endl;
    file_out << "unsigned int           \t" << sizeof( unsigned int ) << endl;
    file_out << "unsigned long int      \t" << sizeof( unsigned long int ) << endl;
    file_out << "float                  \t" << sizeof( float ) << endl;
    file_out << "double                 \t" << sizeof( double ) << endl;
    file_out << "long double            \t" << sizeof( long double ) << endl;

    file_out.close();

    ifstream file_in("size.txt");
    string s;
    
    while (getline( file_in, s ))
         cout << s << endl;

    file_in.close();

    return 0;
}
