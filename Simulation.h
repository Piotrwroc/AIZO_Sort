#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>

template<typename T>
class Simulation
{
public:
	void simulation_mode(T* tab);
	const char* mode_name(int mode);
	const char* var_name();
};

#endif SIMULATION_H