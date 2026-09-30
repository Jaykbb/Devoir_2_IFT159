// Code créé par Jayk Béland Brisson et Noah Carriere

#include <iostream>
#include <string>
#include "generer.h"

int main() {

	// Initialiser les parametres des monstres
	int nbr_mstr = 0;
	std::string nom_mstr;
	int nbr_c_mstr;
	int frc_mstr;
	int rst_mstr;

	// Generer un numero qui est associe a un monstre.
	nbr_mstr = generer(4);
	if (nbr_mstr == 1)
	{
		nom_mstr = "Bete";
		nbr_c_mstr = 5;
		frc_mstr = 2;
		rst_mstr = 3;
	}
	else if (nbr_mstr == 2)
	{
		nom_mstr = "Dragon";
		nbr_c_mstr = 9;
		frc_mstr = 4;
		rst_mstr = 8;
	}
	else if (nbr_mstr == 3)
	{
		nom_mstr = "Geant";
		nbr_c_mstr = 11;
		frc_mstr = 6;
		rst_mstr = 12;
	}
	else if (nbr_mstr == 4)
	{
		nom_mstr = "Mort Vivant";
		nbr_c_mstr = 3;
		frc_mstr = 15;
		rst_mstr = 2;
	}

	std::cout << nom_mstr << "\n";
	std::cout << nbr_c_mstr << "\n";
	std::cout << frc_mstr << "\n";
	std::cout << rst_mstr << "\n";

	return 0;
}
