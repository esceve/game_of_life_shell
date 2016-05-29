/*
** game_of_life.c for game_of_life in /home/esceve/Documents/C/game_of_life
** 
** Made by Clement Scherpereel
** Login esceve <clement.scherpereel@outlook.fr>
** 
** Started on  Fri May 27 10:58:51 2016 Clement Scherpereel
** Last update Sun May 29 02:25:38 2016 Clement Scherpereel
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<time.h>
#include		<unistd.h>
#define			v 50


void create_map(int map[v][v]);
void mapping(int map[v][v]);
void afficher_map(int map[v][v]);
int test_end_game(int map[v][v]);
void test_cellule( int map[v][v]);

int		main(void)
  {
    int		map[v][v];
    create_map(map);
    while(test_end_game(map) != 0)
    {
    afficher_map(map);
    printf("\ntest : %d\n", test_end_game(map));
    test_cellule(map);
    usleep(100000);
    }
    afficher_map(map);
    printf("FIN DU JEUX TOUT LE MONDE EST MORT\n\n");
    return(EXIT_SUCCESS);
  }

void		create_map( int tab[v][v] )
  {
    int		i;
    int		j;

    srand(time(NULL));
    for(i = 0; i < v; i++)
      {
	for( j = 0; j < v; j++ )
	  {
	    if(rand()%100<20)
	      {
		tab[i][j] = 1;
	      }
	    else
	      {
		tab[i][j] = 0;
	      }
	  }
      }
  }

void		afficher_map( int tab[v][v] )
  {
    int		i;
    int		j;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for( i = 0; i < v; i++ )
      {
	for( j = 0; j < v; j++ )
	  {
	    printf("%c", tab[i][j]== 1 ? 'X' : ' ' );
	  }
	printf("\n");
      }
  }

int		test_end_game( int tab[v][v] )
  {
    int		i;
    int		j;
    int		verif;

    verif = 0;

    for( i = 0; i < v; i++ )
    {
      for( j = 0; j < v; j++ )
      {
	if( tab[i][j] == 1 )
	   {
	     verif++;
	   }
      }
    }
    return verif;
  }

void		test_cellule(int tab[v][v])
  {
    int		i;
    int		j;
    int		voisin;

    for( i = 0; i < v; i++ )
      {
	for( j = 0; j < v; j++ )
	  {
            voisin = 0;
            //haut
            if(j > 0 && tab[i][j-1]==1)
	      voisin++;
            //bas
            if(j < v - 1 && tab[i][j+1]==1)
	      voisin++;
            //gauche
            if(i > 0 && tab[i-1][j]==1)
	      voisin++;
            //droite
            if(i < v - 1 && tab[i+1][j]==1)
	      voisin++;
            //haut gauche
            if(i > 0 && j > 0 && tab[i-1][j-1]==1)
	      voisin++;
            //haut droite
            if(i < v - 1 && j > 0 && tab[i+1][j-1]==1)
	      voisin++;
            //bas droite
            if(i < v - 1 && j < v - 1 && tab[i+1][j+1]==1)
	      voisin++;
            //bas gauche
            if(i > 0 && j < v - 1 && tab[i-1][j+1]==1)
	      voisin++;
	    if(voisin == 3)
	      {
		tab[i][j] = 1;
	      }
	    if( voisin < 2 )
	      tab[i][j] = 0;
	    if( voisin > 3 ) 
	      tab[i][j] = 0;
	  }
      }
  }
