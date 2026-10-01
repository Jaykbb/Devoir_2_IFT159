// Code créé par Jayk Béland Brisson et Noah Carriere

#include <iostream>
#include <string>
#include "generer.h"

int main() {

	// Initialiser les parametres des monstres
	int nbr_mstr = 0;
	std::string nom_mstr;
	int nbr_c_mstr = 0;
	int frc_mstr = 0;
	int rst_mstr = 0;

	int pts_vie_mstr = 100;
	int pts_vie_per = 100;

	int nbr_dee;
	int nbr_face_d;
	int nbr_face_a;

	int compteur = 1;
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

	std::cout << "Nombre de coups fait par le joueur?\n";
	std::cin >> nbr_dee;
	std::cout << "Quantite de dommages maximale du joueur?\n";
	std::cin >> nbr_face_d;
	std::cout << "Quantite de resistance maximale du joueur?\n";
	std::cin >> nbr_face_a;

	std::cout << "Vous affronter le " << nom_mstr << "\n";
	std::cout << "\n";

	do 
	{
		int degats_pers = 0;
		int armure_pers = generer(nbr_face_a);

		for (int i = 0; i <= nbr_dee; i++)
		{
			degats_pers += generer(nbr_face_d);
		}

		int armure_mstr = generer(rst_mstr);
		int degats_mstr = 0;

		for (int i = 0; i <= nbr_c_mstr; i++)
		{
			degats_mstr += generer(frc_mstr);
		}

		int degat_tot_pers = degats_pers - armure_mstr;
		int degat_tot_mstr = degats_mstr - armure_pers;

		if (degat_tot_pers < 0 )
		{
			pts_vie_mstr = pts_vie_mstr;
		}
		else
		{
			pts_vie_mstr = pts_vie_mstr - degat_tot_pers;
		}

		if (degat_tot_mstr < 0)
		{
			pts_vie_per = pts_vie_per;
		}
		else
		{
			pts_vie_per = pts_vie_per - degat_tot_mstr;
		}

		if (pts_vie_mstr < 0)
		{
			pts_vie_mstr = 0;
		}

		if (pts_vie_per < 0)
		{
			pts_vie_per = 0;
		}

		std::cout << "Points de vie personnage: " << pts_vie_per << "\n";
		std::cout << "Points de vie monstre: " << pts_vie_mstr << "\n";
		std::cout << "\n";
		
		compteur += 1;

	} while (pts_vie_mstr > 0 && pts_vie_per > 0);

	std::cout << "Nombre totale de tours: " << compteur;

	return 0;
}
