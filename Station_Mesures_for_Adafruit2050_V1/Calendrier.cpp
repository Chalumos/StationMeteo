// Fichier Calendrier.cpp
// Fonction de manipulation de date et heure dans un calendrier
// Savoir si une année est bissextile
// Définir le jour de la semaine depuis la date jj.mm.aa
// Calculer l'heure locale en fonction de l'heure UTC, du fuseau horaire et de la correction heure Eté - hiver

#include <Arduino.h>
#include "Calendrier.h"

/*--------------------------------------------------------------------------------------------*/
// Fonctions de manipulation de calendrier
/*--------------------------------------------------------------------------------------------*/
// Une année est bissextile si :
//  - Elle est divisible par 4 et n'est pas divisible par 100
//  - Elle est divisible par 400
// Valeur retournée : 1 année bissextile; 0 : année non bissextile
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Calcul du jour de la semaine en fonction de la date
// Entrées :
//  jour : valeur sur {1,...,31}
//  mois : valeur sur {1,...,12}
//  annee : valeur sur {1583,...,9999}. On ne prend en compte que les années 2000 à 2099 
//    dans l'ensemble {00,...,99} soient 2000 à 2099
// Sortie : le jour de la semaine. 
// cf. https://fr.wikibooks.org/wiki/Curiosit%C3%A9s_math%C3%A9matiques/Trouver_le_jour_de_la_semaine_avec_une_date_donn%C3%A9e
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Calcul de l'heure locale en fonction de l'heure UTC
// MàJ de la date locale en fonction de la correction GMT et de la correction Eté-Hiver
// Correction_GMT : correction horaire en fonction du fuseau horaire au format hh:mm:00
// Correction_Ete_Hiver : correction heure été - hiver
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
