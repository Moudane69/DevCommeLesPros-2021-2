#include "Cesar.h"
#include <string.h>
#include <stddef.h>
#include <stdlib.h>


char* chiffre_Cesar( char* clair,char const cle)         // Texte en clair qui sera modifié.

{   

    int i = 0 ; 
    int a , b , c ;
    size_t taille = strlen(clair);
    char * resultat =(char *)malloc(taille+1);
    int decalage = cle-'a';
    
     for( i=0 ; i<taille ; i++){


        if(clair[i] <='Z' && clair[i] >='A'){

                a = (clair[i] - 'A' + decalage );
                b = 'Z' - 'A' + 1 ;// nombre totale des alphabets;
                c = a % b ; // pour voir si il y'a suffisemment de places .
                if (decalage < 0)
                {
                    resultat[i] ='Z'+c+1 ;
                }else{
                    resultat[i] ='A'+ c;
                };

        }else if(clair[i] <= 'z' && clair[i] >= 'a'){
        
                a = (clair[i] - 'a' + decalage );
                b = 'z' - 'a' + 1 ;// nombre totale des alphabets;
                c = a % b ; // pour voir si il y'a suffisemment de places .
                if (decalage < 0)
                {
                    resultat[i] ='z'+c+1 ;
                }else{
                    resultat[i] ='a'+ c;
                };

                
        }else{
        
                resultat[i] = clair[i];
        } 
    }


    resultat[taille]='\0';
    return resultat;

}

char* dechiffre_Cesar(
    char* chiffre,      // Texte chiffré qui sera modifié.
    char const cle)
{
    return NULL;
}
