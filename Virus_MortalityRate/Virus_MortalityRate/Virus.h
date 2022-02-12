#pragma once
class Virus
{
public:
	virtual float GetMortalityRate(double population, double death)=0;
};

class  CovidVirus :public  Virus
{
public:
	float GetMortalityRate(double population, double death)
	{
		if(population==0)
			throw std::exception("division by zero");
		return(float)(death / population*100);
	}
};

class  HivVirus :public  Virus
{
public:
	float GetMortalityRate(double population, double death)
	{

		if (population == 0)
			throw std::exception("division by zero");
		return(float)(death / population*100);
	}
};

class  BirdFlue :public  Virus
{
public:
	float GetMortalityRate(double population, double death)
	{

		if (population == 0)
			throw std::exception("division by zero");
		return(float)(death / population*100);
	}
};