#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <ctime>
#include "Header.h"


using namespace std;



//Text files
const string About = "RPGAbout.txt";
const string CharAttack = "charAttMins.txt";
const string CharAttributes = "charAttributes.txt";
const string CharTypes = "charTypes.txt";
const string SaveCharacter = "savedCharacters.txt";
//Array
const int Stat_Arr = 6;
string CharAttack_Arr[Stat_Arr];
string CharAttributes_Arr[Stat_Arr];
string CharTypes_Arr[Stat_Arr];
string SavedChar = "";
bool LoadData = false;


//Main Program
int main(){

    Menu(); //Menu
    ResetFile(SaveCharacter); //Resets Previously Saved Character File

    return 0;
}

/***********************************************************************************************************************************************************

                                                                  MENU

************************************************************************************************************************************************************/

void Menu(){

    int Exit = false;
    srand(unsigned(time(NULL))); //Random Number

    while(!Exit){
            system("CLS"); // clear screen

// display menu
            cout << "\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "\t\t\t\t\t The Amazing RPG Character Generator " << endl;
            cout << "\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "[1] End Testing the Program" << endl;
            cout << "[2] Display \"About\" Information"<< endl;
            cout << "[3] Read and store data from files" << endl;
            cout << "[4] Generate a random Character" << endl;
            cout << "[5] Save a Character to file" << endl;
            cout << "[6] Load saved Characters from file" << endl;

            int Choice = 0;
            cout << "\nWhich option would you like (1-6): ";
            cin >> Choice;
            cout << "\n\n";

            switch(Choice){
                case 1:
                    cout << "\nThank you for playing... Hope to see you again! \n\n\n";
                    Exit = true;
                    break;
                case 2:
                    displayText(About);
                    break;
                case 3:
                    CreateList(CharAttack, CharAttack_Arr);
                    CreateList(CharTypes, CharTypes_Arr);
                    CreateList(CharAttributes, CharAttributes_Arr);
                    break;
                case 4:
                    GeneratingCharacter();
                    break;
                case 5:
                    SaveData();
                    break;
                case 6:
                    LoadCharacter();
                    break;
                default:
                    cout << "please choose option 1 to 6 \n";
                    break;
            }
        system("pause");
    }
}

/***********************************************************************************************************************************************************

                                                               Display Text

************************************************************************************************************************************************************/

void displayText(string FileName){
    string text = ReadFile(FileName);
    cout << text <<"\n";
}

/***********************************************************************************************************************************************************

                                                               Reading Text

************************************************************************************************************************************************************/


void CreateList(string FileName , string strArr[]){
    string text = "";
    int i = 0;

// Reading Text Files
    ifstream file;
    file.open(FileName);
    cout << "Data loading from " << FileName << "\n";

    if(file.is_open()){
            while(i < Stat_Arr){
                getline(file, text);
                strArr[i] = text;
                i++;
            }
    }
    file.close();
    LoadData = true;
}
/***********************************************************************************************************************************************************

                                                             Generating Character

************************************************************************************************************************************************************/


string GeneratingCharacter(){

//Loading Character
    if (LoadData == false){
            cout << "Load the data first... \n";
            return "";
    }
    else{
            int RandNumber = rand() % 5 + 1;
            string charType = CharTypes_Arr[RandNumber];
            string CharAttack = CharAttack_Arr[RandNumber];
            string StoreChar = "";



// Character Name
            StoreChar += "\t" + charType + "\n";
            StoreChar += "\t~~~~~~~~~~~~~~~~~~~~~~~~~~\n";


            for (int i = 0; i < Stat_Arr; i++){
                int randAttr = rand() % 5 + 1;
                int minAttr = CharAttack[i] - 48; //The value of 0 in ASCII is 48
                int attrVal = randAttr + minAttr;
                string attr = CharAttributes_Arr[i];


                StoreChar += "\t" + attr + ": " + to_string(attrVal) +" [The minimum " + attr + " is " + to_string(minAttr) + " and the random value is " + to_string(randAttr) + " ]\n";
           }

            cout << StoreChar;
            SavedChar = StoreChar;
            return StoreChar;
    }

}
/***********************************************************************************************************************************************************

                                                               Saving Data

************************************************************************************************************************************************************/



void SaveData(){
//save the character
    string ans;
    cout << SavedChar;
    cout << "\nWould you like to save the character?(y/n): ";
    cin >> ans;

    if (ans == "y"|| ans == "Y"){
            ofstream fileToWrite(SaveCharacter, ios::app);
            if (fileToWrite.is_open()){
                    fileToWrite << SavedChar << "\n";
                    cout << "\n[ character saved ]\n\n";
            }
            fileToWrite.close();
    }
}

/***********************************************************************************************************************************************************

                                                             Loading Character

************************************************************************************************************************************************************/

void LoadCharacter(){
    string SavedChar = ReadFile(SaveCharacter);
    cout << SavedChar;
}

string ReadFile(string FileName){
    string text = "";
    ifstream ReadingFile;
    ReadingFile.open(FileName);

    if(ReadingFile.is_open()){
            do{
                string line = "";
                getline(ReadingFile, line); // reads until the end
                text += line + "\n";
            }while(!ReadingFile.eof());
    }

    ReadingFile.close();

    return text;
}

/***********************************************************************************************************************************************************

                                                             Reset File

************************************************************************************************************************************************************/

void ResetFile(string FileName){
    ofstream ResetFile(FileName, ofstream::trunc);
    if (ResetFile.is_open()){
            ResetFile << "";
    ResetFile.close();
    }
}

