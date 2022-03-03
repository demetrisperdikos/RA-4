#include <iostream>
#include <sstream>
#include <map>
#include <cstring>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <ctype.h>


using namespace std;



int main(int argc, char *argv[]){
    
// strings decleration
    string word/*empty string*/;
    string maximum /*empty string for the max key*/;
    string stLine /*empty string - the line current*/;
    string name /*empty string*/;
    
// int decleration

    int counter = 0;
    int allLines = 0/*variable for total time*/;
    int allCharacters = 0 /*variable for total characters*/;
    int maximumValue = 0 /*int for max value*/;

    map<char, int> store /*map to store*/;



//  if meaning argument count is not 0 
    if(argc!=0/*!= means not equal*/){
        cout << "Number of characters in the file: " << allCharacters << endl;
        cout << "Punctuation characters in the file and their occurrences:"<< endl << endl;

        for (map<char, int /*the map is now with iterator*/>::iterator iter = store.begin(); iter != store.end(); ++iter){
            if (iter->second > maximumValue){
                maximum = iter /*going iterator to first*/->first;
                maximumValue = iter/*going iterator to second*/->second;
            }
            cout << iter->first/*going iterator to first*/ << ": " << iter->second/*going iterator to second*/ << endl;
        }
        
        
        // statements and results
        cout << "\nThe punctuation character with maximum occurrences is " << "\"" << maximum;
        cout << "\" " << "found " << maximumValue << " times.\n";
    }





   else if (argc == 2 /*argument count is 2*/){
        
        name = argv[1] /*names file to the arg value*/;
        std::ifstream myfile(name);
        
        if (!myfile){
            cout << "File cannot be opened: " << name /*tells user that file is not opening*/;
            cout << endl;
            exit(0) /*closes everything*/;
        }
        
         if (myfile.is_open()/*if the file opens*/){
             
            while (getline(myfile, stLine) /*as long as file has line available*/){
                allLines ++ /*adds to total ammount of lines*/;
                
                stringstream iss(stLine);
                
                while (iss >> word){
                    while (counter < word.length()){
                        allCharacters++/*all characters adds one*/;
                        
                        if (!isalnum(word[counter])){
                            store[word[counter]] ++ /*adds to the map*/;
                        }
                    
                        counter++ /*adds to counter*/;
                    }
                }
            }

            if (allCharacters == 0 /*this means that every character checked was null*/){
                cout << "File is empty." << endl;
                exit(0) /*exits everything*/;
            }
            myfile.close() /*closes file*/;
        }
        
    }





// else is so if its none of those it says file not found
    else{
        cout << "No file is found." << endl /*tell user that file was not found since none was found*/;
        exit(0);
    }
    
    
    
    
    
    return 0;
}