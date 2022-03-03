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
    
    void updateFiles(){
        
        ofstream happyFile;
        happyFile.open("happy.txt", std::ofstream::out | std::ofstream::trunc);
        if(happy.size() > 0){
            happyFile << happy[0];
            for(int i = 1; i < happy.size(); i++){
                happyFile << endl << happy[i];
            }
        }
        happyFile.close();

        ofstream sadFile;
        sadFile.open("sad.txt", std::ofstream::out | std::ofstream::trunc);
        if(sad.size() > 0){
            sadFile << sad[0];
            for(int i = 1; i < sad.size(); i++){
                sadFile << endl << sad[i];
            }
        }
        sadFile.close();

        if(angry.size() > 0){
            ofstream angryFile;
            angryFile.open("angry.txt", std::ofstream::out | std::ofstream::trunc);
            if(angry.size() > 0){
            angryFile << angry[0];
            for(int i = 1; i < angry.size(); i++){
                angryFile << endl << angry[i];
            }
        }
            angryFile.close();
        }

        if(depressed.size() > 0){
            ofstream depressedFile;
            depressedFile.open("depressed.txt", std::ofstream::out | std::ofstream::trunc);
            if(depressed.size() > 0){
            depressedFile << depressed[0];
            for(int i = 1; i < depressed.size(); i++){
                depressedFile << endl << depressed[i];
            }
        }
            depressedFile.close();
        }
    }
    
    string getNote(){
        string type;
        prompt();
        cout << "What do you want to read: ";
        getline(cin, type);
        cout << endl;

        while(type != "0" || type != "1" || type != "2" || type != "3"){
            cout << "I'm sorry, that is an invalid option. Try again." << endl;
            prompt();
            cout << "What do you want to read: ";
            getline(cin, type);
            cout << endl;
        }

        string result;
        if(empty(type)){
            string line;
            cout << "There are currently no notes in " << type << "." << endl;
            cout << "Do you want to write a note into it [Y, N]:  ";
            getline(cin, line);
            if(line == "Y"){
                writeNote();
                result = "write";
            } else if (line == "N"){
                cout << endl;
                cout << "Okay, see you soon.";
                exit(0);
            }
        } else {
            if(type == "happy"){
                result = happy[0];
                happy.erase(happy.begin());
            } else if (type == "sad"){
                result = sad[0];
                sad.erase(sad.begin());
            } else if (type == "angry"){
                result = angry[0];
                angry.erase(angry.begin());
            } else if (type == "depressed"){
                result = depressed[0];
                depressed.erase(depressed.begin());
            }
        }
        
        return result;
    }
    
    void deleteNote(){
        prompt();
        cout << "Where do you want to delete from: ";
        string input;
        getline(cin, input);

        cout << endl;
        if(input == "0"){
            for(int i = 0; i < happy.size(); i++){
                cout << i << ": " << happy[i] << endl;
            }
            cout << "Which would you like to delete? ";
            int del;
            cin >> del;
            happy.erase(happy.begin()+del, happy.begin()+del+1);

        } else if(input == "1"){
            for(int i = 0; i < sad.size(); i++){
                cout << i << ": " << sad[i] << endl;
            }
            cout << "Which would you like to delete? ";
            int del;
            cin >> del;
            sad.erase(sad.begin()+del, sad.begin()+del+1);

        } else if (input == "2"){
            for(int i = 0; i < angry.size(); i++){
                cout << i << ": " << angry[i] << endl;
            }
            cout << "Which would you like to delete? ";
            int del;
            cin >> del;
            angry.erase(angry.begin()+del, angry.begin()+del+1);
            
        } else if (input == "3"){
            for(int i = 0; i < depressed.size(); i++){
                cout << i << ": " << depressed[i] << endl;
            }
            cout << "Which would you like to delete? ";
            int del;
            cin >> del;
            depressed.erase(depressed.begin()+del, depressed.begin()+del+1);

        }

        cout << endl << "Note has been deleted." << endl;
    }

    void writeNote(){
        while(true){
            string line;
            prompt();
            cout << "What do you want to write: ";
            getline(cin, line);
            cout << endl;

            while(line != "0" || line != "1" || line != "2" || line != "3"){
                cout << "I'm sorry, that is an invalid option. Try again." << endl << endl;
                prompt();
                cout << "What do you want to write: ";
                getline(cin, line);
                cout << endl;
            }

            cout << "Start writing: ";
            string input;
            getline(cin, input);

            if(line == "0"){
                happy.push_back(input);

            } else if(line == "1"){
                sad.push_back(input);
                
            } else if(line == "2"){
                angry.push_back(input);
                
            } else if(line == "3"){
                depressed.push_back(input);
                
            }
            cout << endl << "Your note has been saved." << endl;

            cout << endl << "Do you want to read, write, or delete another note? [Y,N] ";
            getline(cin, line);
            if(line == "N"){
                break;
            } else {

            }

        }
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

    void prompt(){
        cout << "Your options: " << endl;
        cout << "Happy: 0" << endl;
        cout << "Sad: 1" << endl;
        cout << "Angry: 2" << endl;
        cout << "Depressed: 3" << endl;
    }

    void start(){
        while(true){
            string line;
            cout << "Hi there, do you want to read, write, or delete a note: ";
            getline(cin, line);

            if(line == "read"){
                getNote();
                break;
            } else if (line == "write") {
                writeNote();
                break;
            } else if (line == "delete"){
                deleteNote();
                break;
            } else {
                cout << "Sorry, incorrect input. Try again." << endl;
            }
        }
        cout << endl;

    }
};