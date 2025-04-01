/*
Author: DAYVIAN PENA
Course: CSCI-135
Instructor: Enxhi 
Assignment: Project 3 

This is our profemon cpp file
in this file we define the class variables 
and its functions
*/

#include <iostream>
#include <string>
#include "profemon.hpp"
#include "skill.hpp"

using namespace std;

Profemon::Profemon(){
profemon_name = "Undefined";
}
Profemon::Profemon(std::string name, double max_health, Specialty specialty){
profemon_name = name;
profemon_mhealth = max_health;
profemon_specialty = specialty;
profemon_requirements = 50;
profemon_cexperience = 0;
profemon_lvl = 0;
}

string Profemon::getName(){
    return profemon_name;
}
Specialty Profemon::getSpecialty(){
    return profemon_specialty;
}
int Profemon::getLevel(){
    return profemon_lvl;
}
double Profemon::getMaxHealth(){
    return profemon_mhealth;
}
void Profemon::setName(std::string name){
    profemon_name = name;
}
void Profemon::levelUp(int exp){
    profemon_cexperience +=  exp;
    while(profemon_cexperience >= profemon_requirements){
        profemon_lvl++;
        profemon_cexperience -= profemon_requirements;
        if(profemon_specialty == ML){
            profemon_requirements += 10;
        }
        else if(profemon_specialty == SOFTWARE){
            profemon_requirements += 15;
        }
        else if (profemon_specialty == HARDWARE)
            profemon_requirements += 20;
        
    
    }
}
bool Profemon::learnSkill(int slot, Skill skill){
if(slot == 0 || slot == 1 || slot == 2){
    if(skill.getSpecialty() == profemon_specialty){
        arraySkill[slot] = skill;
        return true;
    }
}
return false;
}

// void Profemon::printProfemon(bool print_skills){
//     cout<<profemon_name<<" "<<"["<<profemon_specialty<<"]"<<" "<<"|"<<" "<<"lvl"<<" "<< profemon_lvl<<" "<<"|"<<" "<<"exp"<<" "<<profemon_cexperience<<"/"<<profemon_requirements<<" "<<"|"<<" "<<"hp"<<" "<<profemon_mhealth<<endl;
//     if(print_skills == true){
//         for(int i = 0; i<3; i++){
//             if(arraySkill[i].getName() != "undefined"){
//                 cout<<"    "<<arraySkill[i].getName()<<" ["<<arraySkill[i].getTotalUses()<<"] : "<<arraySkill[i].getDescription()<<endl;
//             }
//         }
//     }
// }


void Profemon::printProfemon(bool print_skills)
{
    string types[] = {"ML", "SOFTWARE", "HARDWARE"};

    cout << profemon_name + " [" << types[profemon_specialty] << "] | lvl " << profemon_lvl << " | exp " << profemon_cexperience << '/' << profemon_requirements << " | hp " << profemon_mhealth << endl;
    
    if(print_skills)
    {
        for(int i = 0; i < 3; i++)
        {
            if(arraySkill[i].getName() != "Undefined")
            {
                Skill cur = arraySkill[i];
                cout << "    " << cur.getName() << " [" << cur.getTotalUses() << "] : " << cur.getDescription() << endl;
            }
        }
    }
}

