//
//  Individual.h
//  InfectivitySimulator
//
//  Created by Daniel Lindfors on 01/06/14.
//  Copyright (c) 2014 Daniel Lindfors. All rights reserved.
//

#ifndef InfectivitySimulator_Individual_h
#define InfectivitySimulator_Individual_h

class Individual {
private:
    
	Pathogen* pathogen;
	bool immune;
	bool alive;
	
public:
	Individual();
	void nextDay();
	void interactWith(Individual* otherIndividual);
	void infectWith(Pathogen* pathogen);
	void recoverFrom(Pathogen* p);
	void dieFrom(Pathogen* p);
	
    bool isAlive();
    bool isImune();
	bool isInfected();
	bool isInfectedWith(Pathogen* p);
};

#endif
