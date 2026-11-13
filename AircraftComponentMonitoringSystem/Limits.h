#pragma once
#include <string>
#include <vector>

//UML Class Diagram: <<datatype>> Limits

struct Limits {
	double min = 0.0;                         //min/max: numeric limits for operating range
    double max = 0.0;
	std::vector<std::string> validStates;     //validStates: valid states for non-numeric readings 
};