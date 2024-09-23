#include <stdio.h>
#include <stdbool.h>


typedef struct maillonl
{
    int v;
    struct maillonl *suiv;
}Maillonl, *List;

typedef struct maillong
{
    struct maillong *suiv;
    int v;
    List succ;
}Maillong, *Graphe;

Graphe grapheNouv();
List listNouv();
List insert(List l, int x); // Insert on the head
Graphe adjt(Graphe g, int x);//insertion tete (enracienement)
bool vide(Graphe g);// graph vide 
Graphe adjs(Graphe g, int s);// ajoute sommet de manière trié
bool exs(Graphe g, int x);// existence d'un noeud  
Graphe adja(Graphe g, int x, int y);//  insertion arc x : source et y:cible
Graphe supa(Graphe g, int x, int y);// Suppression of arc
bool exa(Graphe g, int x, int y);// Exist of an arc
int de(Graphe g, int x);// degré sortant du point x dans g
int di(Graphe g, int x);//degré inté
Graphe sups(Graphe g, int x); // Supression of a sommet x in g
Graphe sups1(Graphe g, int x);// Recursive part sups
Graphe supst(Graphe g);// Suppresion of the sommet in head and delete from memory
List insert(List l, int x); // Insert on the head
bool in(List l, int x);// verify if val in list 
int length(List l);// lenght of the list l
List remove(List l, int x); //remove x in the list l
void Afficher(Graphe g);
