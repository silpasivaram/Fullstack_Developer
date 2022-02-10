#include <iostream>

class Engine
{
public:
	Engine()
	{
		//std::cout << "\nEngine Class Called..\n";
	};
	
	virtual float GetEfficiency(float EffInput, float EffOutput) = 0;
	

};

class InternalCombustineEngine : public Engine
{
public:
	InternalCombustineEngine()
	{
		//std::cout << "\nInternalCombustineEngine Class Called..\n";
	};
	float GetEfficiency(float EffInput, float EffOutput)
	{
		if (EffInput==0)
			throw std::exception("division by zero");
		return(EffOutput / EffInput);
		
	}

};

class ExteralCombustineEngine : public Engine
{
public:
	ExteralCombustineEngine()
	{
		//std::cout << "\nExteralCombustineEngine Class Called..\n";
	};
	float GetEfficiency(float EffInput, float EffOutput)
	{
		if (EffInput == 0)
			throw std::exception("division by zero");
		return(EffOutput / EffInput);
	}

};
class PetrolEngine : public InternalCombustineEngine
{

};
class DieselEngine : public InternalCombustineEngine
{

};
class SteamEngine : public ExteralCombustineEngine
{

};

