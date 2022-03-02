#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

class Notes {
private:
    vector<string> happy;
    vector<string> sad;
    vector<string> angry;
    vector<string> depressed;

public:
    void loadNotes(){
        ifstream happyFile("happy.txt");
        ifstream sadFile("sad.txt");
        ifstream angryFile("angry.txt");
        ifstream depressedFile("depressed.txt");

        while(!happyFile.eof()){
            string line;
            getline(happyFile, line);
            if(line == ""){
                continue;
            }
            happy.push_back(line);
        }
        happyFile.close();

        while(!sadFile.eof()){
            string line;
            getline(sadFile, line);
            if(line == ""){
                continue;
            }
            sad.push_back(line);
        }
        sadFile.close();

        while(!angryFile.eof()){
            string line;
            getline(angryFile, line);
            if(line == ""){
                continue;
            }
            angry.push_back(line);
        }
        angryFile.close();

        while(!depressedFile.eof()){
            string line;
            getline(depressedFile, line);
            if(line == ""){
                continue;
            }
            depressed.push_back(line);
        }
        depressedFile.close();
    }
    
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

        string result;
        if(type == "happy"){
            result = happy[0];
            //happy.erase(happy.begin());
        }
        
        return result;
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
            fstream happyFile;
            happyFile.open("happy.txt", std::ios_base::app);
            happyFile << endl << input;
            happyFile.close();
        } else if(type == "sad"){
            sad.push_back(input);
        } else if(type == "angry"){
            angry.push_back(input);
        } else if(type == "depressed"){
            depressed.push_back(input);
        }
        cout << endl;
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