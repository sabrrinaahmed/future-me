#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Notes {
private:
    vector<string> happy;
    vector<string> sad;
    vector<string> angry;
    vector<string> depressed;

public:
    
    string getNote(string type){
        if(empty(type)){
            string line;
            cout << "There are currently no notes in " << type << "." << endl;
            cout << "Do you want to write a note into it [Y, N]:  ";
            getline(cin, line);
            if(line == "Y"){
                writeNote(type);
            } else if (line == "N"){
                cout << "Okay, see you soon.";
                exit(0);
            }
        }

        vector<string> vect = getVectorByType(type);
        srand(time(NULL));
        int number = rand() % vect.size();
        cout << number << endl;
        return "";
    }
    
    void deleteNote(){
        cout << "What type of note do you want to delete? [happy, sad, angry, depressed]: ";
        string input;
        getline(cin, input);
    }

    void writeNote(string type){
        cout << "Start writing: ";
        string input;
        getline(cin, input);
        if(type == "happy"){
            happy.push_back(input);
        } else if(type == "sad"){
            sad.push_back(input);
        } else if(type == "angry"){
            angry.push_back(input);
        } else if(type == "depressed"){
            depressed.push_back(input);
        }
        cout << "Your note has been saved." << endl;
    }

    vector<string> getVectorByType(string type){
        if(type == "happy"){
            return happy;
        } else if(type == "sad"){
            return sad;
        } else if(type == "angry"){
            return angry;
        } else if(type == "depressed"){
            return depressed;
        }
    }

    bool empty(string type){
        vector<string> vect = getVectorByType(type);
        if(vect.size() == 0){
            return true;
        }
        return false;
    }
};