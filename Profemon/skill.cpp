/*
Author: DAYVIAN PENA
Course: CSCI-135
Instructor: Enxhi 
Assignment: Project 3 

This is our skill cpp file
in this file we define the class variables 
and its functions
*/

#include <iostream>
#include <string>
#include "profemon.hpp"
#include "skill.hpp"

using namespace std;

Skill::Skill(){
    Skill::skill_name = "Undefined";
    Skill::skill_description = "Undefined";
    Skill::skill_uses = -1;
    Skill::skill_specialty = -1;
}
Skill::Skill(std::string name, std::string description, int specialty, int uses){
    skill_name = name;
    skill_description = description;
    skill_specialty = specialty;
    skill_uses = uses;
}

string Skill::getName(){
    return skill_name;
}
string Skill::getDescription(){
    return skill_description;
}
int Skill::getTotalUses(){
    return skill_uses;
}
int Skill::getSpecialty(){
    return skill_specialty;
}
void Skill::setName(string name){
    skill_name = name;
}
void Skill::setDescription(std::string description){
    skill_description = description;
}
void Skill::setTotalUses(int uses){
    skill_uses = uses;
}
bool Skill::setSpecialty(int specialty){
    if(specialty == 0 || specialty == 1 || specialty == 2){
        skill_specialty = specialty;
        return true;
    }
    return false;
}