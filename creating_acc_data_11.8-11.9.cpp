/*
Run the program of Exercise 14.7 using the files of test data created in Exercise 14.8. Print the new master file. Check that
the accounts have been updated correctly.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
using namespace std;

void printOutput( ofstream&, int, const char *, const char *, double );

int main(){

   const char *firstNames[] = { "Walter", "Alice", "Alan", "Mary", "Steve", "Gina", "Tom", "Cindy", "Ilana", "Pam" },
              *lastNames[] = { "Red", "Blue", "Yellow", "Orange", "Purple", "Green", "Violet", "White", "Black", "Brown" };

   ofstream outOldMaster( "coldmast.txt" ),
            outTransaction( "ctransmast.txt" );

   //create data for coldmast.txt -- outOldMaster
   srand( time( 0 ));
   cout << " ------ Contents of oldmast.txt ------ " << endl;
   for (int i = 1; i < 11; i++){
        int value1 = rand() % 10, value2 = rand() % 50;
        outOldMaster << ( i * 100 ) << " " << firstNames[ i - 1 ] << " " << lastNames[ i - 1 ] << " "
                     << ( value1 * 100 ) / ( value2 / 3 + 3.43 ) << endl;
        cout << ( i * 100 ) << " " << firstNames[ i - 1 ] << " " << lastNames[ i - 1 ] << " "
                     << ( value1 * 100 ) / ( value2 / 3 + 3.43 ) << endl;
   }

   //create data for ctransmast.txt -- outTransaction
   cout << " ------ Contents of ctransmast.txt ------ " << endl;
   for (int z = 1; z < 11; z++){
        int value = 25 - rand() % 50;
        outTransaction << ( z * 100 ) << " " << ( value * 100 ) / ( 2.667 * ( 1 + rand() % 10 )) << endl;
        cout << ( z * 100 ) << " " << ( value * 100 ) / ( 2.667 * ( 1 + rand() % 10 )) << endl;
   }

   outTransaction.close();
   outOldMaster.close();

   ifstream inOldMaster( "coldmast.txt" ),
            inTransaction( "ctransmast.txt" );
   ofstream outNewMaster( "cnewmast.txt" );

   int m_account, t_account;
   double m_balance, t_balance;
   char m_firstname[ 20 ], m_lastname[ 20 ];

   if ( !inOldMaster ) {
       cerr << "Unable to open oldmast.txt\n";
       exit( EXIT_FAILURE );
   }

   if ( !inTransaction ) {
       cerr << "Unable to open trans.txt\n";
       exit( EXIT_FAILURE );
   }

   if ( !outNewMaster ) {
       cerr << "Unable to open newmast.txt\n";
       exit( EXIT_FAILURE );
   }


   cout << "\nProcessing ... " << endl;
   inTransaction >> t_account >> t_balance;
   inOldMaster >> m_account>> m_firstname >> m_lastname >> m_balance;
   do {

       if ( m_account != t_account ) {
          cout << "Unmatched transaction record for account " << t_account << '\n';
          inTransaction >> t_account >> t_balance;
       }

       if ( m_account == t_account ) {
          m_balance += t_balance;
          // printOutput( outNewMaster, m_account m_firstname, m_lastname, m_balance );
          outNewMaster << m_account<< " " << m_firstname << " " << m_lastname << " " << m_balance << endl;
          cout << m_account<< " " << m_firstname << " " << m_lastname << " " << m_balance << endl;
       }

       inTransaction >> t_account >> t_balance;
       inOldMaster >> m_account>> m_firstname >> m_lastname >> m_balance;

   } while(!inTransaction.eof( ));

   inTransaction.close();
   outNewMaster.close();
   inOldMaster.close();

   return 0;
}
