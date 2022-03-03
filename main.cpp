#include <iostream>
#include "notes.h"
using namespace std;

int main(){
    Notes note;
    
    note.loadNotes();

    note.choice();

    note.updateFiles();
}