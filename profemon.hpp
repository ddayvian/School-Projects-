/*
Author: DAYVIAN PENA
Course: CSCI-135
Instructor: Enxhi 
Assignment: Project 3 S

This is our profemon class, for project 3
In here were naming all of our functions, for class Skill
Both its private and public
*/

#ifndef PROFEMON_H
#define PROFEMON_H
#include <iostream>
#include <string>
#include "skill.hpp"

using namespace std;
enum Specialty{ML, SOFTWARE, HARDWARE};

class Profemon{
    private:
        string profemon_name;
        int profemon_lvl;
        int profemon_requirements;
        int profemon_cexperience;
        int profemon_mhealth;
        Specialty profemon_specialty;
        Skill arraySkill[3];
    public:
        Profemon();
        Profemon(std::string name, double max_health, Specialty specialty);
        std::string getName();
        Specialty getSpecialty();
        int getLevel();
        double getMaxHealth();
        void setName(std::string name);
        void levelUp(int exp);
        bool learnSkill(int slot, Skill skill);
        void printProfemon(bool print_skills);


};

#endif