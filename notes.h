#include <vector>
#include <string>
using namespace std;

class Notes {
private:
    vector<string> happy;
    vector<string> sad;
    vector<string> angry;
    vector<string> depressed;

public:
    int randomNumber(string type){

    }
    
    string getNote(string type,);
    
    string deleteNote();

    vector<string> type(string type){
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
};