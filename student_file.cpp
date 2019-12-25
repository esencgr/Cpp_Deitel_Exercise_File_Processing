#include <iostream>
#include <fstream>
using namespace std;

int main(){

    int no[ 2 ];
    string name[ 2 ];
    int year[ 2 ];

    //open file for writing
    ofstream file("D:\\GitHub\\Cpp_deitel_exercise_file_processing\\student.txt");

    for (int i = 0; i < 2; i++){
        cout << " enter no - name - year: ";
        cin >> no[ i ] >> name[ i ] >> year[ i ];
    }

    int count = 0;
    //file << "no\tname\tyear" << endl;
    while (count < 2){
        file << no[ count ] << " " << name[ count ] << " " << year[ count ] << endl;
        count++;
    }

    file.close();

    int num[ 2 ];
    string namee[ 2 ];
    int age[ 2 ];

    //open file for reading
    ifstream file_1("D:\\GitHub\\Cpp_deitel_exercise_file_processing\\student.txt");

    int i = 0;
    while( file_1 ){
        file_1 >> num[ i ] >> namee[ i ] >> age[ i ];
        i++;
    }

    for (int j = 0; j < 2; j++)
        cout << num[ j ] << " " << namee[ j ] << " " << age[ j ] << endl;

    file_1.close();

    return 0;
}
