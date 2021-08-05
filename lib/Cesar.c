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
    int decalage = cle-'a'; // dans la table ascii les lettre Majuscules viennent avant les  minusculs
    
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

char cesar(char caractere, int decalage, char debut, char fin){
    //fixons le décalage du nouveau caractère depuis le début de l'alphabet
    
    int a= (caractere-debut+decalage );
    int b=(fin-debut+1 ) ; // nombre totale des caracteres dans l'intervalle renseigné dans les paramettres d'entrées
    int nouv_decalage= a%b; 
    //nous devrons commencer de la fin de l'alphabet  si le nouveau décalage est négatif
       
        if (nouv_decalage < 0)
        {
            return fin + 1 + nouv_decalage;

        }else{
            
            return debut + nouv_decalage ;
        }
    
}

char* dechiffre_Cesar(char* chiffre, char const cle)     // Texte chiffré qui sera modifié.
{
                    int i = 0 ;                 
                    size_t taille = strlen(chiffre);
                    char * resultat =(char *)malloc(taille+1);
                    int decalage = cle-'a';// dans la table ascii les lettre Majuscules viennent avant les  minusculs
                    
                    for( i=0 ; i<taille ; i++){


                        if(chiffre[i] <='Z' && chiffre[i] >='A'){

                                resultat[i] = cesar(chiffre[i], (-1)*decalage,'A','Z');
                                

                        }else if(chiffre[i] <= 'z' && chiffre[i] >= 'a'){
                        
                                resultat[i] = cesar(chiffre[i], (-1)*decalage, 'a', 'z');
                            

                                
                        }else{
                        
                                resultat[i] = chiffre[i];
                        } 
                    }


                    resultat[taille]='\0';
        return resultat;
   
}

