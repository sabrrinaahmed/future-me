#include <iostream>
#include "notes.h"
using namespace std;

int main(){
    string line = "";
    bool read = false;
    bool write = false;

    while(true){
        cout << "Hi there, do you want to read or write a note: ";
        getline(cin, line);

        if(line == "read"){
            read = true;
            break;
        } else if (line == "write") {
            write = true;
            break;
        } else {
            cout << "Sorry, incorrect input. Try again." << endl;
        }
    }
    
    cout << endl;

    bool happy = false;
    bool sad = false;
    bool angry = false;
    bool depressed = false;
    if(read){
        while(true){
            cout << "Your options: " << endl;
            cout << "Happy : 1" << endl;
            cout << "Sad : 2" << endl;
            cout << "Angry : 3" << endl;
            cout << "Depressed : 4" << endl;
            cout << "What do you want to read: ";
            getline(cin, line);
            cout << endl;

            if(line == "1"){
                happy = true;
                break;
            } else if (line == "2"){
                sad = true;
                break;
            } else if (line == "3") {
                angry = true;
                break;
            } else if (line == "4") {
                depressed = true;
                break;
            } else {
                cout << "I'm sorry, that is an invalid option. Try again." << endl;
            }
        }
        
    }
    
}