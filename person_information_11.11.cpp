#include <iostream>
#include <fstream>
using namespace std;

struct person{
    char last_name[ 15 ];
    char first_name[ 15 ];
    char age[ 4 ];
};

int main(){

    //open file for writing
    ofstream file("person_name_age.txt");
    person person_info = { "", "", 0 };

    for (int i = 0; i < 100; i++){
        file << person_info.last_name << person_info.first_name << person_info.age;
    }

    for (int j = 1; j <= 3; j++){
        cout << " enter no - name - year: ";
        cin >> person_info.last_name >> person_info.first_name >> person_info.age;
        file << " lastname: " << person_info.last_name << " firstname : " << person_info.first_name
             << " age : " << person_info.age << endl;
    }

    file.close();

    return 0;
}
