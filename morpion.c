#include <stdio.h>

// Signes joueurs
const char signe1='X';
const char signe2='O';

//Prototypes des fonctions secondaires
void initGrid(char grid[3][3]);
void printGrid(char grid[3][3]);
void initPlayer(char players[2][50], char signs[2]);
int checkGame(char grid[3][3]);
char fillGrid(int currentPlayer, char grid[3][3], char players[2][50], char signs[2]);

//Fonction principale
int main()
{
	//Déclaration
    char grid[3][3];
	char players[2][50]; //numéro du joueur | nom du joueur
	char signs[2]; //signe1 | signe2
	int currentPlayer; //0: joueur1 | 1: joueur2
	int round; //Compte le nombre de tour

	//Initialisation
	currentPlayer=0; //Le joueur 1 commencera
	round=0;
    initGrid(grid);
    initPlayer(players, signs);
	printf("\n");

	//Traitement
	do {
		round++;
		if (round==10) //Force la sortie de la boucle while une fois que toutes les cases sont remplies
		{
			break;
		}
		printGrid(grid); //Affiche la grille avant remplissage
		fillGrid(currentPlayer, grid, players, signs); //Remplissage de la grille
		if(currentPlayer==0)
		{
			currentPlayer=1;
		}
		else if(currentPlayer==1)
		{
			currentPlayer=0;
		}
		checkGame(grid); //Verifie si un joueur a gagné
	    printf("\n");
	} while((checkGame(grid)!=1)&&(checkGame(grid)!=2));

	//Conclusion
	printGrid(grid); //Affiche la grille finale
	if ((checkGame(grid)==1)||(checkGame(grid)==2)) //Cas où un joueur a gagné
	{
		printf("La partie est finie, %s gagne. Vous pouvez presser la touche Entrer.\n", players[checkGame(grid)-1]);
	}
	else if (checkGame(grid)==3) //Cas de match nul
	{
		printf("La partie est finie, match nul. Vous pouvez presser la touche Entrer.\n");
	}
    return 0;
}

//Initialisation de la grille
void initGrid(char grid[3][3])
{
	int i;  // Ligne
	int j;  // Colonne
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			grid[i][j]='_';
		}
	}
}

//Affichage de la grille
void printGrid(char grid[3][3])
{
	int i;  // Ligne
	int j;  // Colonne
	printf("  1 2 3 \n");
	for(i=0; i<3; i++)
	{
		printf("%i ", i+1);
	    for(j=0; j<3; j++)
	    {
			printf("%c ", grid[i][j]);
	    }
	    printf("\n");
	}
	printf("\n");
}

//Initialisation des joueurs
void initPlayer(char players[2][50], char signs[2])
{

	printf("Le joueur 1 commencera la partie.\n");
    printf("Joueur 1, entrez votre nom :\n");
    scanf("%s",&players[0][0]);
    signs[0]=signe1;
    while(getchar()!='\n');

    printf("Joueur 2, entrez votre nom :\n");
    scanf("%s",&players[1][0]);
    signs[1]=signe2;
    while(getchar()!='\n');

    printf("Joueur 1 est %s et joue avec %c \n", players[0], signs[0]);
    printf("Joueur 2 est %s et joue avec %c \n", players[1], signs[1]);
}

//Vérification de l'avancement de la partie et de la victoire
int checkGame(char grid[3][3])
{
	int i;  // Ligne
	int j;  // Colonne
	int verifResult;

	//Verif pour le match nul
	verifResult=3;

	//Verif pour le signe1
	if( ((grid[0][0]==signe1)&&(grid[0][1]==signe1)&&(grid[0][2]==signe1))/*ligne1*/||
	((grid[1][0]==signe1)&&(grid[1][1]==signe1)&&(grid[1][2]==signe1))/*ligne2*/||
	((grid[2][0]==signe1)&&(grid[2][1]==signe1)&&(grid[2][2]==signe1))/*ligne3*/||
	((grid[0][0]==signe1)&&(grid[1][0]==signe1)&&(grid[2][0]==signe1))/*colonne1*/||
	((grid[0][1]==signe1)&&(grid[1][1]==signe1)&&(grid[2][1]==signe1))/*colonne2*/||
	((grid[0][2]==signe1)&&(grid[1][2]==signe1)&&(grid[2][2]==signe1))/*colonne3*/||
	((grid[0][0]==signe1)&&(grid[1][1]==signe1)&&(grid[2][2]==signe1))/*diagonale1*/||
	((grid[0][2]==signe1)&&(grid[1][1]==signe1)&&(grid[2][0]==signe1))/*diagonale2*/)
	{
		verifResult=1;
	}

	//Verif pour le signe2
	if( ((grid[0][0]==signe2)&&(grid[0][1]==signe2)&&(grid[0][2]==signe2))/*ligne1*/||
	((grid[1][0]==signe2)&&(grid[1][1]==signe2)&&(grid[1][2]==signe2))/*ligne2*/||
	((grid[2][0]==signe2)&&(grid[2][1]==signe2)&&(grid[2][2]==signe2))/*ligne3*/||
	((grid[0][0]==signe2)&&(grid[1][0]==signe2)&&(grid[2][0]==signe2))/*colonne1*/||
	((grid[0][1]==signe2)&&(grid[1][1]==signe2)&&(grid[2][1]==signe2))/*colonne2*/||
	((grid[0][2]==signe2)&&(grid[1][2]==signe2)&&(grid[2][2]==signe2))/*colonne3*/||
	((grid[0][0]==signe2)&&(grid[1][1]==signe2)&&(grid[2][2]==signe2))/*diagonale1*/||
	((grid[0][2]==signe2)&&(grid[1][1]==signe2)&&(grid[2][0]==signe2))/*diagonale2*/)
	{
	    verifResult=2;
	}

	return verifResult;
}

//Remplissage de la grille
char fillGrid(int currentPlayer, char grid[3][3], char players[2][50], char signs[2])
{
    int colonne;
	int ligne;
    printf("%s, veuillez saisir la colonne et la ligne (valeur entre 1 et 3).\n", players[currentPlayer]);
	do {
		do{
			scanf("%d",&colonne);
			if (colonne<1 || colonne>3)
			{
				printf("Valeur incorrect. Saisissez a nouveau la colonne (valeur entre 1 et 3).\n");
			}
		} while(colonne<1 || colonne>3);

		do{
			scanf("%d",&ligne);
			if (ligne<1 || ligne>3)
			{
				printf("Valeur incorrect. Saisissez a nouveau la ligne (valeur entre 1 et 3).\n");
			}
		} while(ligne<1 || ligne>3);

		if(grid[ligne-1][colonne-1]!='_')
		{
			printf("Case occupee. Saisissez a nouveau la colonne et la ligne (valeur entre 1 et 3).\n");
		}
	} while(grid[ligne-1][colonne-1]!='_');
	grid[ligne-1][colonne-1]=signs[currentPlayer];
}
