#include "Vigenere.h"

#include <stddef.h>
#include <stdio.h>
// Texte en clair qui sera modifié.
char* chiffre_Vigenere( char* clair,char const* cle){
        int a ;
        int b; 
        int c;         
        size_t taille_clair = strlen(clair);
        char* resultat = (char*)malloc(taille_clair+1);
        int compteur;
        size_t taille_cle = strlen(cle);
        int * decalage = (int*)malloc(taille_cle*sizeof(int));
           
    
    
            for(int i=0; i<taille_cle; i++) {
                decalage[i] = cle[i] - 'a';
            }

            compteur = 0;
            for(int i=0; i<taille_clair; i++) {
                if(clair[i] <=  'Z' && clair[i] >= 'A'){
                        a = (clair[i] - 'A' + decalage[compteur%taille_cle] );
                        b = 'Z' - 'A' + 1 ;// nombre totale des alphabets;
                        c = a % b ; // pour voir si il y'a suffisemment de places .
                        if (decalage[compteur%taille_cle] < 0)
                        {
                            resultat[i] ='Z'+c+1 ;
                        }else{
                            resultat[i] ='A'+ c;
                        };
                        compteur++;
                         }else if(clair[i] <=  'z' && clair[i] >= 'a'){
                                a = (clair[i] - 'a' + decalage[compteur%taille_cle] );
                                b = 'z' - 'a' + 1 ;// nombre totale des alphabets;
                                c = a % b ; // pour voir si il y'a suffisemment de places .
                                if (decalage[compteur%taille_cle] < 0)
                                {
                                    resultat[i] ='z'+c+1 ;
                                }else{
                                    resultat[i] ='a'+ c;
                                };
                                    compteur++;
                                }else{ resultat[i] = clair[i];
                                     }
                
                
              }
                resultat[taille_clair] = '\0'; //   caractere de fin du chaine 
                return resultat;
    }





char d_vigenere(char caractere, int decalage, char debut, char fin){
                //fixons le décalage du nouveau caractère depuis le début de l'alphabet
    
        int a= (caractere-debut+decalage );
        int b=(fin-debut+1 ) ; 
        int nouv_decalage= a%b;
                //nous devrons commencer de la fin de l'alphabet  si le nouveau décalage est négatif
        
            if (nouv_decalage < 0)
            {
                return fin + 1 + nouv_decalage;

            }else{
                
                return debut + nouv_decalage ;
            }
    
}


 // Texte chiffré qui sera modifié.
char* dechiffre_Vigenere(char* chiffre,char const* cle)
{
            size_t taille_chiffre = strlen(chiffre);
            size_t taille_cle = strlen(cle);
            int * decalage = (int*)malloc(taille_cle*sizeof(int));
            char* resultat = (char*)malloc(taille_chiffre+1);
            int compteur;
                for(int i=0; i<taille_cle; i++) {
                        decalage[i] = cle[i] - 'a';
                  }

            compteur = 0;
                for(int i=0; i<taille_chiffre; i++) {
                        if(chiffre[i] <=  'Z' && chiffre[i] >= 'A'){
                        resultat[i] = d_vigenere(chiffre[i], -decalage[compteur%taille_cle], 'A', 'Z');
                        compteur++;
                }
                else if(chiffre[i] <=  'z' && chiffre[i] >= 'a'){
                        resultat[i] = d_vigenere(chiffre[i], -decalage[compteur%taille_cle], 'a', 'z');
                        compteur++;
                }
                else {  resultat[i] = chiffre[i];}
            }
            resultat[taille_chiffre] = '\0'; // caractere de la fin du chaine 
            return resultat;

}
void chiffre_Vigenere_flux_texte(
    FILE* chiffre,      // Flux de sortie.
    FILE* clair,        // Flux d'entrée.
    char const* cle)
{
    return;
}

void dechiffre_Vigenere_flux_texte(
    FILE* clair,        // Flux de sortie.
    FILE* chiffre,      // Flux d'entrée.
    char const* cle)
{
    return;
}
