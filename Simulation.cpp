#include "Simulation.h"
#include <iostream>

std::vector<double> simulationSimpleStep(double time)
{
	std::vector<double> results;
	std::minstd_rand generator(std::chrono::system_clock::now().time_since_epoch().count());
	std::shuffle(reactions.begin(), reactions.end(), generator);

	results.push_back(time + 100);
	int nbReactions = 0;

	for(Reaction *r : reactions)
	{
		if(r->get2Reac()) //Bi-moléculaire
		{
			int nbChocs = getNbChocs(r->getProba(), r->getReac1()->pop, r->getReac2()->pop, generator); 
			r->getReac1()->pop -= nbChocs;
			r->getReac2()->pop -= nbChocs;
			r->getProduit1()->pop += nbChocs;
			if(r->get2Produits())
			{
				r->getProduit2()->pop += nbChocs;
			}
			nbReactions += nbChocs;
		}
		else //Mono-moléculaire
		{
			int nbReacs = getNbReacs(r->getProba(), r->getReac1()->pop, generator);
			r->getReac1()->pop -= nbReacs;
			r->getProduit1()->pop += nbReacs;
			if(r->get2Produits())
			{
				r->getProduit2()->pop += nbReacs;
			}
			nbReactions += nbReacs;

		}
	}

	for(EspeceMoleculaire *e : especes)
    {
        results.push_back(e->pop);
    }

	results.push_back((double) nbReactions);

	return results;
}


int getNbChocs(double proba, int nEm1, int nEm2, std::minstd_rand rng)
{
	double alpha = 7.4e-7;
	double volume = 4.0 * (M_PI / 3.0) *  pow((double) diametre * 1e-3 / 2, 3.0);
	double nb = proba * alpha * nEm1 * nEm2 / volume;
	int nbChocs = (int) nb;
	double decPart = nb - nbChocs;
	std::uniform_real_distribution<double> distribution(0.0,1.0);
	if(distribution(rng) < decPart)
	{
		nbChocs++;
	}
	return nbChocs;
}

int getNbReacs(double proba, int nEm, std::minstd_rand rng)
{
	double nb = proba * nEm;
	int nbReacs = (int) nb;
	double decPart = nb - nbReacs;
	std::uniform_real_distribution<double> distribution(0.0,1.0);
	if(distribution(rng) < decPart)
	{
		nbReacs++;
	}
	return nbReacs;
}

std::vector<Molecule> initSimulationEntitee(Environnement *env)
{
	std::vector<Molecule> listeMolecules;
	for(auto&& e : especes)
	{
		for(int i = 0; i < e->pop; i++)
		{
			Molecule m(e);
			listeMolecules.push_back(m);
			env->ajoutMolecule(&m);
		}
	}
	return listeMolecules;
}

std::vector<double> simulationEntiteeStep(double time, Environnement *env, std::vector<Molecule> *listeMolecules, bool sens) //true pour debut->fin et false pour fin->debut 
{
	std::vector<double> results;
	std::vector<Molecule> listeMoleculesMaj;
	int nbMol = listeMolecules->size();
	int i = (sens ? 0 : nbMol - 1);
	
	for(; sens ? (i < nbMol) : (i >= 0); sens ? i++ : i--)
	{
		//TODO : Tout le reste
	}
	
	
	
	return results;
}