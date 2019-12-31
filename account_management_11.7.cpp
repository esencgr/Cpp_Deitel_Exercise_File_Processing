/*
--> Exercise 14.3 asked the reader to write a series of single statements. Actually, these statements form the core of an important
type of file processing program, namely, a file-matching program. In commercial data processing, it is common to have several files
in each application system. In an accounts receivable system, for example, there is generally a master file containing detailed information
about each customer such as the customer's name, address, telephone number, outstanding balance, credit limit, discount
terms, contract arrangements, and possibly a condensed history of recent purchases and cash payments.

--> As transactions occur (e.g., sales are made and cash payments arrive), they are entered into a file. At the end of each business
period (a month for some companies, a week for others, and a day in some cases) the file of transactions (called "trans.dat" in
Exercise 14.3) is applied to the master file (called "oldmast.dat" in Exercise 14.3), thus updating each account's record of purchases
and payments. During an updating run, the master file is rewritten as a new file ("newmast.dat"), which is then used at the
end of the next business period to begin the updating process again.

--> File-matching programs must deal with certain problems that do not exist in single-file programs. For example, a match does
not always occur. A customer on the master file may not have made any purchases or cash payments in the current business period,
and therefore no record for this customer will appear on the transaction file. Similarly, a customer who did make some purchases or
cash payments may have just moved to this community, and the company may not have had a chance to create a master record for
this customer.

--> Use the statements from Exercise 14.3 as a basis for writing a complete file-matching accounts receivable program. Use the
account number on each file as the record key for matching purposes. Assume that each file is a sequential file with records stored
in increasing order by account number.

--> When a match occurs (i.e., records with the same account number appear on both the master and transaction files), add the
dollar amount on the transaction file to the current balance on the master file, and write the "newmast.dat" record. (Assume
purchases are indicated by positive amounts on the transaction file and payments are indicated by negative amounts.) When there is
a master record for a particular account but no corresponding transaction record, merely write the master record to "newmast.
dat". When there is a transaction record but no corresponding master record, print the message "Unmatched transaction
record for account number …" (fill in the account number from the transaction record).
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void printOutput( ofstream&, int, const char *, const char *, double );

int main(){

   int masterAccount, transactionAccount;
   double masterBalance, transactionBalance;
   char masterFirstName[ 20 ], masterLastName[ 20 ];

   ifstream inOldMaster( "aoldmast.txt" ),
            inTransaction( "atransmast.txt" );
   ofstream outNewMaster( "anewmast.txt" );

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

   // cout << "Processing...\n";
   // inTransaction >> transactionAccount >> transactionBalance;

   // while ( !inTransaction.eof() ) {
   //     inOldMaster >> masterAccount >> masterFirstName >> masterLastName >> masterBalance;
   //
   //     if ( masterAccount != transactionAccount ) {
   //        cout << "Unmatched transaction record for account " << transactionAccount << '\n';
   //        inTransaction >> transactionAccount >> transactionBalance;
   //     }
   //
   //     if ( masterAccount == transactionAccount ) {
   //        masterBalance += transactionBalance;
   //        printOutput( outNewMaster, masterAccount, masterFirstName, masterLastName, masterBalance );
   //     }
   //
   //     inTransaction >> transactionAccount >> transactionBalance;
   // }

   cout << "Processing ... " << endl;
   inTransaction >> transactionAccount >> transactionBalance;
   inOldMaster >> masterAccount >> masterFirstName >> masterLastName >> masterBalance;
   do {

       if ( masterAccount != transactionAccount ) {
          cout << "Unmatched transaction record for account " << transactionAccount << '\n';
          inTransaction >> transactionAccount >> transactionBalance;
       }

       if ( masterAccount == transactionAccount ) {
          masterBalance += transactionBalance;
          printOutput( outNewMaster, masterAccount, masterFirstName, masterLastName, masterBalance );
          // outNewMaster << masterAccount << " " << masterFirstName << " " << masterLastName << " " << masterBalance << endl;
          // cout << masterAccount << " " << masterFirstName << " " << masterLastName << " " << masterBalance << endl;
       }

       inTransaction >> transactionAccount >> transactionBalance;
       inOldMaster >> masterAccount >> masterFirstName >> masterLastName >> masterBalance;

   } while(!inTransaction.eof( ));

   inTransaction.close();
   outNewMaster.close();
   inOldMaster.close();

   return 0;
}
void printOutput( ofstream &oRef, int mAccount, const char *mfName, const char *mlName, double mBalance ){
     oRef << mAccount << ' ' << mfName << ' ' << mlName << ' ' << ' ' << mBalance << '\n';
     cout << mAccount << ' ' << mfName << ' ' << mlName << ' ' << ' ' << mBalance << '\n';
 }
