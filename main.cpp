#include <iostream>
#include "notes.h"
using namespace std;

int main(){
    Notes note;
    note.loadNotes();
    string line = "";
    bool read = false;
    bool write = false;
    bool deleteNote = false;

    while(true){
        cout << "Hi there, do you want to read, write, or delete a note: ";
        getline(cin, line);

        if(line == "read"){
            read = true;
            break;
        } else if (line == "write") {
            write = true;
            break;
        } else if (line == "delete"){
            deleteNote = true;
            break;
        } else {
            cout << "Sorry, incorrect input. Try again." << endl;
        }
    }
    
    cout << endl;

    string output;
    if(read){
        while(true){
            
            cout << "Your options: " << endl;
            cout << "Happy: 0" << endl;
            cout << "Sad: 1" << endl;
            cout << "Angry: 2" << endl;
            cout << "Depressed: 3" << endl;
            cout << "What do you want to read: ";
            getline(cin, line);
            cout << endl;

            if(line == "0"){
                output = note.getNote("happy");
                break;
            } else if (line == "1"){
                output = note.getNote("sad");
                break;
            } else if (line == "2") {
                output = note.getNote("angry");
                break;
            } else if (line == "3") {
                output = note.getNote("depressed");
                break;
            } else {
                cout << "I'm sorry, that is an invalid option. Try again." << endl;
            }
        } 

        cout << output << endl << endl;
        
    } else if(write){
        while(true){
            cout << "Your options: " << endl;
            cout << "Happy: 0" << endl;
            cout << "Sad: 1" << endl;
            cout << "Angry: 2" << endl;
            cout << "Depressed: 3" << endl;
            cout << "What do you want to write: ";
            getline(cin, line);
            cout << endl;

            if(line == "0"){
                note.writeNote("happy");
                break;
            } else if (line == "1"){
                note.writeNote("sad");
                break;
            } else if (line == "2") {
                note.writeNote("angry");
                break;
            } else if (line == "3") {
                note.writeNote("depressed");
                break;
            } else {
                cout << "I'm sorry, that is an invalid option. Try again." << endl;
            }
        }

    } else if(deleteNote){
        note.deleteNote();
    }

    note.updateFiles();
}