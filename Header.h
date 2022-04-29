#ifndef HEADER_H
#define HEADER_H

//Declaring Functions
void Menu();
void displayText(std::string FileName);
void CreateList(std::string FileName , std::string strArr[]);
std::string GeneratingCharacter();
void SaveData();
void LoadCharacter();

std::string ReadFile(std::string FileName);
void ResetFile(std::string Filename);

#endif
