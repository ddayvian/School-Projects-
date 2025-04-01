/*
Author: DAYVIAN PENA
Course: CSCI-135
Instructor: Enxhi 
Assignment: Project 3 S

This is our skill class, for project 3
In here were naming all of our functions, for class Skill
Both its private and public
*/

#include <iostream>
#include <string>
#ifndef SKILL_H
#define SKILL_H
using namespace std;

class Skill{
    private:
        string skill_name;
        string skill_description;
        int skill_uses;
        int skill_specialty;
    public:
        Skill();
        Skill(std::string name, std::string description, int speciality, int uses);
        string getName();
        string getDescription();
        int getTotalUses();
        int getSpecialty();
        void setName(string name);
        void setDescription(string description);
        void setTotalUses(int uses);
        bool setSpecialty(int specialty);


};

#endif