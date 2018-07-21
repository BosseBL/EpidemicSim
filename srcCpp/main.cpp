//
//  main.cpp
//  InfectivitySimulator
//
//  Created by Daniel Lindfors on 01/06/14.
//  Copyright (c) 2014 Daniel Lindfors. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "Pathogen.h"
#include "Individual.h"
#include "Population.h"
#include "InfectivitySimulator.h"
#include <string.h>
#include <iostream>



Pathogen::Pathogen(Individual* host) {
    daysInfectingHost = nearbyint(rand()*(maxDaysInfecting - minDaysInfecting) + minDaysInfecting);
    host = host;
    pathogenCounter++;
}
void Pathogen::setAttributes(float conProb, float decProb, float recProb, int minDays, int maxDays) {
    contagionProbability = conProb; deceaseProbability = decProb; minDaysInfecting = minDays; maxDaysInfecting = maxDays;
        attributesSet = true;
}

Pathogen Pathogen::makeNewPathogen(Individual* host) {
    if(attributesSet) {
        Pathogen newPathogen(host);
        return newPathogen;
    }
    else return NULL;
}
void Pathogen::attack(Individual* newHost) {
    if(isAlive() && not(newHost->isImune() || newHost->isInfected()) && rand() <= contagionProbability) {
        Pathogen newPathogen(newHost);
        newHost->infectWith(&newPathogen);
    }
}

void Pathogen::nextDay() {
    if(isAlive()) {
        daysInfectingHost--;
        if(daysInfectingHost <= 0) {
            host->recoverFrom(this);
        }
        else if(rand() <= deceaseProbability) {
            host->dieFrom(this);
        }
        else return;
    }
}
Individual* Pathogen::getHost() {
    return host;
}
bool Pathogen::isAlive() {
    return alive;
}
void Pathogen::kill(Pathogen* pathogen) {
    pathogenCounter--;
    pathogen->host = NULL;
    pathogen->alive = false;
    pathogen->daysInfectingHost = 0;
}


Individual::Individual() {
    pathogen = NULL;
    immune = false;
    alive = true;
}
void Individual::nextDay() {
    if(isInfected()) {
        pathogen->nextDay();
    }
}

void Individual::interactWith(Individual* otherIndividual) {
    if(isAlive() && otherIndividual->isAlive() && isInfected()) {
        pathogen->attack(otherIndividual);
    }
}

void Individual::infectWith(Pathogen* pathogen) {
    if(pathogen->getHost() == this) {
        pathogen = pathogen;
    }
}

void Individual::recoverFrom(Pathogen* p) {
    if(isInfectedWith(p)) {
        Pathogen::kill(pathogen);
        pathogen = NULL;
        immune = true;
    }
}
void Individual::dieFrom(Pathogen* p) {
    if(isInfectedWith(p)) {
        Pathogen::kill(pathogen);
        pathogen = NULL;
        immune = false;
        alive = false;
    }
}
bool Individual::isAlive() {
    return alive;
}
bool Individual::isImune() {
    return immune;
}
bool Individual::isInfected() {
    if(pathogen == NULL) return false;
    else return true;
}
bool Individual::isInfectedWith(Pathogen* p) {
    if(pathogen == p) return true;
    else return false;
}

Population::Population(int sqrtPop) {
    n = sqrtPop;
    individuals = new Individual*[n];
    for(int i = 0 ; i < n ; i++ ) {
        for (int j = 0; j < n; j++) {
            individuals[i][j] = *new Individual();
        }
    }
}
void Population::nextDay() {
    updateIndividuals();
}

void Population::updateIndividuals() {
    
    for(int i = 0 ; i < n ; i++ ) {
        for(int j = 0 ; j < n ; j++) {
            individuals[i][j].nextDay();
        }
    }
    
    for(int i = 0 ; i < n ; i++ ) {
        for(int j = 0 ; j < n ; j++) {
            if(!individuals[i][j].isAlive()) continue;
            
            if(i > 0 && j > 0) individuals[i][j].interactWith(&individuals[i-1][j-1]);
            if(j > 0) individuals[i][j].interactWith(&individuals[i][j-1]);
            if(i < n - 1 && j > 0) individuals[i][j].interactWith(&individuals[i+1][j-1]);
            if(i < n - 1) individuals[i][j].interactWith(&individuals[i+1][j]);
            if(i < n - 1 && j < n - 1) individuals[i][j].interactWith(&individuals[i+1][j+1]);
            if(j < n - 1) individuals[i][j].interactWith(&individuals[i][j+1]);
            if(i > 0 && j < n - 1) individuals[i][j].interactWith(&individuals[i-1][j+1]);
            if(i > 0) individuals[i][j].interactWith(&individuals[i-1][j]);
        }
    }
    
}

InfectivitySimulator::InfectivitySimulator() {
    population = new Population(10);
}






int main(int argc, const char * argv[])
{
    srand(time(NULL));
    
    InfectivitySimulator sim = InfectivitySimulator();
    std::string input = "";
    std::cin >> input;
    while(input != "bajs") {
        std::cin >> input;
    }
    exit(0);
}



