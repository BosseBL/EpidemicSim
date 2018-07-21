//
//  Population.h
//  InfectivitySimulator
//
//  Created by Daniel Lindfors on 01/06/14.
//  Copyright (c) 2014 Daniel Lindfors. All rights reserved.
//

#ifndef InfectivitySimulator_Population_h
#define InfectivitySimulator_Population_h

class Population {
private:
    int n;
    Individual** individuals;
public:
	Population(int n);
	void nextDay();
	void updateIndividuals();
};


#endif
