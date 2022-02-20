#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{

    int numero;
    char auteur[30];
    char editeur[30];
    char titre[100];
    int stock;
    float prix;

} TypeLivre ;

void Ajouter( FILE *librairie , int taille){
    
    int i = 0 ; 
   TypeLivre L ; 

     printf("\n\t---Livre N°---");
     printf("\n\tNumero :");
      scanf("%d",&L.numero);
      fflush(stdin);

     printf("\n\tAuteur :"); 
      gets(L.auteur);
      fflush(stdin);

     printf("\n\tEditeur :");
      gets(L.editeur);
      fflush(stdin);

     printf("\n\tTitre :");
      gets(L.titre);

     printf("\n\tStock : ");
      scanf("%d",&L.stock);

     printf("\n\tPrix : ");
      scanf("%f",&L.prix);
     
         //printf("\n Est-ce que Vous voullez Ajoutez le livre dans lib ?");
         fwrite(&L,sizeof(TypeLivre),1,librairie);
         
}

void DisplayLib(FILE *librairie){
    
     int i=0;
     TypeLivre L ;
     
         puts("\tContenu du Librairie :");
        //puts("\t| Position | Numero | Auteur | Editeur | Titre | Stock | Prix |");
         rewind(librairie);
         while(fread(&L, sizeof(TypeLivre),1,librairie)==1){
            i++;  //printf("\t|   (%d)    |  N(%d) | %s    | %s    | %s    |   %d  |  %.2f  |\n",i,L.numero,L.auteur,L.editeur,L.titre,L.stock,L.prix);
             puts("---------------------------------------------------------------------------------------------------------------------");
             printf("|  Position (%d)  |  Numero(%d)  |  Auteur : %s |  Editeur : %s |  Titre : %s |  Stock : %d  |  Prix : %.2f  |",i,L.numero,L.auteur,L.editeur,L.titre,L.stock,L.prix);
        } 

} 
      

int  Taille(FILE *librairie ){

   int i=0;
   TypeLivre L;

     rewind(librairie);
     while(fread(&L, sizeof(TypeLivre),1,librairie)==1){
       i++;
     }

     return i ;

}

int ChercheParNum(FILE *librairie , int numero){

  int i=0;
  TypeLivre L;
     rewind(librairie);
     while(fread(&L, sizeof(TypeLivre),1,librairie)==1){
         i++;
         if(numero == L.numero){
             return i;
         }
     }
      return -1;

}

void AfficherParNumero(FILE *librairie){

     int i = 0;
     int test = 0;
     int numero;
     TypeLivre L;

     choix:  printf("\nSaisir Le numero de livre :");
             scanf("%d",&numero);

     rewind(librairie);
     while(fread(&L, sizeof(TypeLivre),1,librairie)==1){
         i++;
         if(numero == L.numero){
             test = 1; 
             puts("\t| Position | Numero | Auteur | Editeur | Titre | Stock | Prix |");
             printf("\t|   (%d)    |  N(%d)  | %s | %s | %s |   %d  |  %.2f  |\n",i,L.numero,L.auteur,L.editeur,L.titre,L.stock,L.prix);
             break;
         } 
     }

     if(test == 0){
         printf("Ce numero n'existe pas!!!");
         goto choix;
     }

}

void AfficherPlusCher(FILE *librairie){

     int i=0;
     int pos=0;
     float max;
     TypeLivre L , MAX;

     while(fread(&L, sizeof(TypeLivre),1,librairie)==1){
		if(i=0){
			max = L.prix;
		    MAX = L;
		}
		else if( max < L.prix ){
			 max = L.prix;
		   	 MAX = L;
			 pos = i;
		}
		i++;
	 }

     puts("\tLes Informations de livre le plus cher :");
     puts("---------------------------------------------------------------------------------------------------------------------^n");
     printf("|  Position (%d)  |  Numero(%d)  |  Auteur : %s |  Editeur : %s |  Titre : %s |  Stock : %d  |  Prix : %.2f  |",i,MAX.numero,MAX.auteur,MAX.editeur,MAX.titre,MAX.stock,MAX.prix);

}
void Afficher_Auteur(FILE *librairie){

     int i=0;
     int test=0;
     char auteur[30];
     TypeLivre L;


         printf("\nSaisir Le Nom d'Auteur :");fflush(stdin);
         gets(auteur);
             
     rewind(librairie);
       puts("\tContenu du Librairie :");
     while(fread(&L, sizeof(TypeLivre),1,librairie)==1){
         i++;
         if( strcmp( auteur , L.auteur ) == 0 ){
             test = 1; 
             puts("---------------------------------------------------------------------------------------------------------------------\n");
             printf("|  Position (%d)  |  Numero(%d)  |  Auteur : %s |  Editeur : %s |  Titre : %s |  Stock : %d  |  Prix : %.2f  |",i,L.numero,L.auteur,L.editeur,L.titre,L.stock,L.prix);
        } 
     }

     if(test == 0){
         printf("Ce auteur n'existe pas!!!");
     }

}

void ChargerLivres(FILE *librairie , TypeLivre *L , int taille){

     int i;

        
       fread(L,sizeof(TypeLivre),taille,librairie);
       /*for(i=0 ; i<taille ; i++){
          while(fread(&l, sizeof(TypeLivre),1,librairie)==1){
             *(L+i) = l ;
          } 
        } */
     puts("\tContenu du Librairie Tableau :");
        for(i=0 ; i<taille ; i++){
            puts("---------------------------------------------------------------------------------------------------------------------\n");
            printf("|  Position (%d)  |  Numero(%d)  |  Auteur : %s |  Editeur : %s |  Titre : %s |  Stock : %d  |  Prix : %.2f  |\n",i+1,(L+i)->numero,(L+i)->auteur,(L+i)->editeur,(L+i)->titre,(L+i)->stock,(L+i)->prix);
        }
}

void TrieParOrdre(TypeLivre *L, int taille){

	int i;
    int j;
    TypeLivre swap;

	for(i=0;i<taille-1;i++){
		for(j=i+1;j<taille;j++){
			if(strcmp(((L+i)->titre),(L+i+1)->titre) > 0){ 
				 swap=*(L+j);
				 *(L+j)=*(L+i);
			     *(L+i)=swap;
		    }
	    }
    }
   
    puts("----Affichage de tableau :");
    for(i=0 ; i<taille ; i++){
         puts("---------------------------------------------------------------------------------------------------------------------\n");
         printf("|  Position (%d)  |  Numero(%d)  |  Auteur : %s |  Editeur : %s |  Titre : %s |  Stock : %d  |  Prix : %.2f  |\n",i+1,(L+i)->numero,(L+i)->auteur,(L+i)->editeur,(L+i)->titre,(L+i)->stock,(L+i)->prix);
    }

}

void Menu(){

         printf("\n\t\t--------------------------------------------------");
         printf("\n\t\t\t MENU :                                         ");
         printf("\n\t\t--------------------------------------------------");
		 printf("\n\t\t   VEUILLEZ CONFIRMER VOTRE CHOIX PAR ENTREE      ");
	     printf("\n\t\t    1-Ajouter Un Livre                            ");
     	 printf("\n\t\t    2-Afficher Contenu de Librairie               ");
     	 printf("\n\t\t    3-Afficher Le Nombre des Livre dans Librairie ");
         printf("\n\t\t    4-Chercher Un Livre par son numero            ");
     	 printf("\n\t\t    5-Afficher Les infos d'un Livre (Par numero)  ");
         printf("\n\t\t    6-Afficher Les infos de livre le plus cher    ");
     	 printf("\n\t\t    7-Afficher Les infos des livres d'un Auteur   ");
     	 printf("\n\t\t    8-Charger  Les livres dans un Tableau         ");
     	 printf("\n\t\t    9-Trie Tableau des livres par ordre croissant ");
		 printf("\n\t\t    10-Recopie les livres trie dans un fichier    ");
     	 printf("\n\t\t    11-Stocker la list des livres d'un editeur    ");
		 printf("\n\t\t--------------------------------------------------");
         printf("\n\t\tVotre choix :");

}

void RecLivsTrie(FILE *Trie , TypeLivre *L , int taille){
	
	 int i;
	 
	 TrieParOrdre( L , taille);
     puts("\n\tPress any key to continue:");getch();system("cls");

	 fwrite(L,sizeof(TypeLivre),taille,Trie);
      puts("----Affichage de Fichier :");
      DisplayLib(Trie);
}

void StocLvrsAuteur(FILE *librairie , FILE *auteur ){

     int i=0;
     int test;
     char nom[30];
     TypeLivre L;

         printf("\nSaisir Le Nom d'Auteur :");fflush(stdin);
          gets(nom);
             
     rewind(librairie);
      //stockage les livres d'un auteur 
     while(fread(&L, sizeof(TypeLivre),1,librairie)==1){
         if( strcmp( nom , L.auteur ) == 0 ){
             i++;
             test = 1; 
             fwrite(&L,sizeof(TypeLivre),1,auteur);         
         } 
     }

     if(test == 0){
         printf("Ce auteur n'existe pas!!!");

     }else {
         rewind(librairie);
         printf("\nLe nombre des livre de %s : %d\n",nom,i);
         DisplayLib(librairie);
     }

}

 int main(){

     int i;
     int choix ;
     int taille;
     int numero;
     TypeLivre *L;
     FILE *Trie;
     FILE *auteur;
     FILE *librairie ;
     
     librairie = fopen("librairie.bin","a+b");

    if( librairie ){ 
     
     do{ 
         taille=Taille( librairie );
         puts("\n\tPress any key to continue:");getch();
         system("cls");
         Menu();
     	 scanf("%d",&choix);
         system("cls"); 
         switch (choix)
         {
            case 1 : {
                 librairie = fopen("librairie.bin","a+b");
                 Ajouter(librairie , taille);
            }break;

            case 2 : {
                 rewind(librairie);
                 DisplayLib( librairie );
            }break;

            case 3 : {
                 rewind(librairie);
                 printf("\nTaille : %d ",taille);
            }break;

            case 4 : {

                 printf("\nSaisir Le numero de livre :");
                 scanf("%d",&numero);
                
                 if(ChercheParNum( librairie ,  numero) !=-1){
                     printf("\nLa position de ce livre est : %d",ChercheParNum( librairie ,  numero));
                 }else printf("Ce numero n'existe pas!!!");
    
            }break;

            case 5 : {
                 rewind(librairie);
                 AfficherParNumero(librairie);
                
            }break;

            case 6 : {
                 rewind(librairie);
                 AfficherPlusCher(librairie);
            }break;
            
            case 7 : {
                 rewind(librairie);
                 Afficher_Auteur(librairie);
            }break;

            case 8 : {
                 librairie = fopen("librairie.bin","rb");
                 L = (TypeLivre *)malloc(sizeof(TypeLivre)*taille);
                 if( L && librairie ){
                 rewind(librairie);
                 ChargerLivres(librairie , L , taille); 
                 }
            }break;
            
            case 10 :
			    if(L){
                     Trie = fopen("Trie.bin","a+b");
                     rewind(librairie);
				     RecLivsTrie( Trie , L , taille);  
                     fclose(Trie);        
			    }else puts("il faut d'abord creer un tableau!!!");
			    break;

            case 9 : {
                  if(L)
                     TrieParOrdre( L, taille);
                  else puts("il faut d'abord creer un tableau!!!");
            }break;

            case 11 : {
                 rewind(auteur);
                 rewind(librairie);
                 auteur = fopen("auteur.bin","a+b");
                 if( auteur )
                     StocLvrsAuteur(librairie , auteur );
               
            }break;
      
         default:
              printf("\nChoix errone!!!");
            break;
         }

       }while(choix!=0);

    }

 free(L);
 fclose(Trie);
 fclose(auteur);
 fclose(librairie);
   return 0;
}


