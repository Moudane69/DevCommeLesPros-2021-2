#include "ROT13.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char* chiffre_ROT13(char* clair){    // Texte en clair qui sera modifié.
                   
                   
                   
                   
                    int a , b ;
                    int i;    
                    size_t taille= strlen(clair);
                    char* resultat = (char*) malloc(1+taille);
                    int decalage ;
                    
                    


                    for( i=0 ; i<taille ; i++){


                        if(clair[i] <='Z' && clair[i] >='A'){
                                            
                                a = (clair[i] - 'A' + 13 );
                                b = 'Z' - 'A' + 1 ;// nombre totale des alphabets;
                                decalage = a % b ; 
                                if (decalage < 0)
                                {
                                    resultat[i] ='Z'+decalage+1 ;
                                }else{
                                    resultat[i] ='A'+ decalage;
                                };

                                }else if(clair[i] <= 'z' && clair[i] >= 'a'){
                        
                                    a = (clair[i] - 'a' + 13 );
                                    b = 'z' - 'a' + 1; // nombre totale des alphabets;
                                    decalage = a % b ; //congruence, pour voir si il y a suffisealent de place 
                                    if (decalage < 0)
                                    {
                                        resultat[i] ='z'+decalage+1 ;
                                    }else{
                                        resultat[i] ='a'+ decalage;
                                    };  

                                
                                }else{
                        
                                        resultat[i] = clair[i];
                                } 
                    }
                
                
                    resultat[taille] = '\0'; // caractere de la fin du chaine
                    
                    
        return resultat;

}

char* dechiffre_ROT13(
    char* chiffre)  // Texte chiffré qui sera modifié.
{
    return NULL;
}
