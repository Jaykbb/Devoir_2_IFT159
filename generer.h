//
//  generer.h
//  D2_DongeonsDragons
//
//  Created by Marie-Flavie Auclair-Fortier on 2020-07-03.
//  Copyright © 2020 Marie-Flavie Auclair-Fortier. All rights reserved.
//

#ifndef generer_h
#define generer_h

#include <random>  // Permet d'utiliser les fonctions de generation de nombres aleatoires
#include <climits>
#include <assert.h>
#include <chrono>

/**
* \ brief Genere une valeur entre 1 et une valeur maximale
* \ param [in] e_nombre : valeur entiere maximale a generer
* \ return Valeur generee
*/
int generer(int e_nombre)
{
    assert(e_nombre>0);
    
    unsigned int seed {(unsigned int) std::chrono::system_clock::now().time_since_epoch().count()};
    
//    seed=0; // a enlever pour avoir du vrai aleatoire
    
    // 0. Creation du generateur de nombres aleatoires, avec une racine a seed (une seule fois)
    static std::mt19937 generateur(seed);
    
    // 1. Creation d'une distribution uniforme pour l'intervalle specifie
    std::uniform_int_distribution<> distribution(1, e_nombre);
    
    // 2. Generation d'un nombre aleatoire selon la distribution uniforme
    return distribution(generateur);
}

#endif /* generer_h */
