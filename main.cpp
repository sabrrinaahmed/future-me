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

    

    string output;
    if(read){
        while(true){
            

            if(output != "write"){
                cout << output << endl << endl;
            }

            cout << "Would you like to read another note? [Y,N] ";
            getline(cin, line);
            if(line == "N"){
                cout << endl << endl << "Okay, see you soon!" << endl << endl;
                break;
            }
        } 

        
    } else if(write){
        

    } else if(deleteNote){
        note.deleteNote();
    }

    note.updateFiles();
}