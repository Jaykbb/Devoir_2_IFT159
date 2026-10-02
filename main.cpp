// Code créé par Jayk Béland Brisson et Noah Carriere

//brief Ce programmme simule des tours de combats entre un monstre et un personnage.
//author   Jayk Béland Brisson et Noah Carrière
//date     30 septembre 2026
//version  1.0

#include <iostream>
#include <string>
#include "generer.h"

int main() {

	// Initialiser les parametres du monstre
	int nbr_mstr;
	std::string nom_mstr;
	int nbr_c_mstr;
	int frc_mstr;
	int rst_mstr;

	// Initialiser les points de vie
	int pts_vie_mstr = 100;
	int pts_vie_per = 100;

	// Initialiser les parametres du personnage
	int nbr_dee;
	int nbr_face_d;
	int nbr_face_a;

	// Initialiser le compteur 
	int compteur = 0;

	// Generer un numero qui est associe a un monstre.
	nbr_mstr = generer(4);

	// Selon la valeur generer, un monstre est choisi
	// Chaque choix affect les valeurs predeterminer de chaque monstre au variable du monstre choisi
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

	// Mettre a l'ecran le monstre choisi
	std::cout << "Vous affronter le " << nom_mstr << "\n";
	std::cout << "\n";

	// Demande a l'utilisateur de entrer les valeurs du personnage
	std::cout << "Nombre de coups fait par le joueur?\n";
	std::cin >> nbr_dee;
	std::cout << "Quantite de dommages maximale du joueur?\n";
	std::cin >> nbr_face_d;
	std::cout << "Quantite de resistance maximale du joueur?\n";
	std::cin >> nbr_face_a;
	
	// La boucle qui calcule les nouveaux points de vie apres chaque tours.
	do 
	{
		// Initialiser les degats du personnage.
		int degats_pers = 0;
		// Initialiser les degats du monstre.
		int degats_mstr = 0;

		// Affecter le nombre generer au variable de l'armure du personnage
		int armure_pers = generer(nbr_face_a);

		// Affecter le nombre generer au variable de l'armure du monstre
		int armure_mstr = generer(rst_mstr);

		// Calculer les degats totales fait par le personnage
		for (int i = 0; i < nbr_dee; i++)
		{
			degats_pers += generer(nbr_face_d);
		}

		// Calculer les degats totales par le monstre
		for (int i = 0; i < nbr_c_mstr; i++)
		{
			degats_mstr += generer(frc_mstr);
		}

		// Calculer les degats apres la soustraction de l'armure
		int degat_tot_pers = degats_pers - armure_mstr;
		int degat_tot_mstr = degats_mstr - armure_pers;

		// Valider si les degats du personnage sont negative
		// Si oui, les points de vie du monstre ne change pas
		// Sinon on calcule les nouveau points de vie du monstre.
		if (degat_tot_pers < 0 )
		{
			pts_vie_mstr = pts_vie_mstr;
		}
		else
		{
			pts_vie_mstr = pts_vie_mstr - degat_tot_pers;
		}

		// Valider si les degats du monstre sont negative
		// Si oui, les points de vie du personnage ne change pas
		// Sinon on calcule les nouveau points de vie du personnage.
		if (degat_tot_mstr < 0)
		{
			pts_vie_per = pts_vie_per;
		}
		else
		{
			pts_vie_per = pts_vie_per - degat_tot_mstr;
		}

		// Valider que les points de vie du monstre et du personnage ne sont pas en bas de 0
		// Si oui on les affect a 0 pour ne pas avoir des points de vie negatif.
		if (pts_vie_mstr < 0)
		{
			pts_vie_mstr = 0;
		}

		if (pts_vie_per < 0)
		{
			pts_vie_per = 0;
		}
		
		// Mettre sur l'ecran les nouveaux points de vie 
		std::cout << "Points de vie personnage: " << pts_vie_per << "\n";
		std::cout << "Points de vie monstre: " << pts_vie_mstr << "\n";
		std::cout << "\n";
		
		// Mettre a jour le compteur
		compteur += 1;

		// Notre condition verifie que les deux points de vie son superieur a 0
		// Si oui un autre tour commence, sinon le combat arrete ici.
	} while (pts_vie_mstr > 0 && pts_vie_per > 0);


	// Affiche le nombre totale de tours.
	std::cout << "Nombre totale de tours: " << compteur;

	return 0;
}
