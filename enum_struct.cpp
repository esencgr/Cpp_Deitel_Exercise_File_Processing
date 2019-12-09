#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

enum months{ OCAK = 1, SUBAT, MART, NISAN, MAYIS, HAZIRAN,
             TEMMUZ, AGUSTOS, EYLUL, EKIM, KASIM, ARALIK };

int main(){

    enum months month;
    string month_name[] = { " ", "jan", "feb", "mar", "apr", "may", "jun", "jul",
                                 "aug", "sep", "oct", "nov", "dec" };

    for ( int month = OCAK; month <= ARALIK; month++ ){
        cout << month << "  " << month_name [ month ] << endl;
    }

    return 0;
}
