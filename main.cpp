#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <iterator>
#include <cstdlib>
#include <algorithm>
#include "record.h"

#define clearScreen system ( "CLS" )

using namespace std;

/**
    Functia menu() din
*/
int menu ()
{
    string  title = "Menu" ;
    string choices[] = {"Enter new record", "Edit a record", "Display all records" ,
    "Delete" ,"Exit", "GitHub Push"};
    cout << '\t' << title << '\n' ;
    cout << '\t' << setfill('-') << setw(title.length()) ;
    for (int i=0; i<6; i++)
        cout << "\n" << i+1 << "\t" << choices[i] << "\n";
    cout << "\nEnter your choice : ";
    return getInt();
}


int main()
{
    char fname[] = "Record.txt";
    // load record from file to vector
    vector<Record> phoneBook = getDataFromFile(fname);
    Record rec;
    int choice = menu();
    while (true){
           clearScreen;
            if (not phoneBook.empty()){
                    sort(phoneBook.begin(),phoneBook.end(),cmp);
           }
           switch(choice){
           case 1:
               rec.getData();
               phoneBook.push_back(rec);
               cout << "\nRecord added.\n" ;
               break;
           case 2:
               phoneBook = editRecord(phoneBook);
               cout << "\nRecord updated.\n" ;
               break;
           case 3:
               displayAll(phoneBook);
               break;
           case 4:
               phoneBook = deleteRecord(phoneBook);
               cout << "\nRecord deleted.\n" ;
               break;
           case 5:
               writeToFile(phoneBook,fname);
               phoneBook.clear();
               return 0;
               break;
            case 6:
                system("./gitpush.sh");
                break;
           default :
               cout << "\nInvalid Choice ! \nRetry :\n" ;
               break;
           }
	   // wait for user
           getchar();
           clearScreen;
           choice = menu();
    }
}
