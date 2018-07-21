//
//  Pathogen.h
//  InfectivitySimulator
//
//  Created by Daniel Lindfors on 01/06/14.
//  Copyright (c) 2014 Daniel Lindfors. All rights reserved.
//

#ifndef InfectivitySimulator_Pathogen_h
#define InfectivitySimulator_Pathogen_h

class Individual;

class Pathogen {
	
private:
    
	static float contagionProbability;
	static float deceaseProbability;
    static int minDaysInfecting;
	static int maxDaysInfecting;
	static int pathogenCounter;
    static bool attributesSet;
	
    int daysInfectingHost;
    
	Individual* host;
	bool alive;
    
    Pathogen(Individual* host);
    
public:
	static void setAttributes(float conProb, float decProb, float recProb, int minDays, int maxDays);
	Pathogen makeNewPathogen(Individual* host);
	void attack(Individual* host);
	void nextDay();
	Individual* getHost();
	bool isAlive();
	static void kill(Pathogen* pathogen);
};

float Pathogen::contagionProbability;
float Pathogen::deceaseProbability;
int Pathogen::minDaysInfecting;
int Pathogen::maxDaysInfecting;
int Pathogen::pathogenCounter;
bool Pathogen::attributesSet;

#endif
