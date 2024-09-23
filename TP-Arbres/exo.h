#include <stdio.h>
#include <stdbool.h>

typedef struct maillon
{
    struct maillon *g;
    struct maillon *d;
    int v;
}Maillon, *Arbre;

typedef struct
{
    Arbre g;
    Arbre d;
}Couple;




void global(void);


Arbre arbNouv(void);
Arbre e(Arbre a, int r, Arbre b);
bool vide(Arbre a);
void affichArbre(Arbre a, int i);
void affichRac(int v, int i);
Arbre ad(Arbre a);
Arbre ag(Arbre a);
int r(Arbre a);
int h(Arbre a);
int max(int a, int b);
int nn(Arbre a);
int nf(Arbre a);
bool f(Arbre a);
Arbre eg(Arbre a);
Arbre ed(Arbre a);
Arbre insertF(Arbre a, int x);
bool egalArb(Arbre a, Arbre b);
Arbre rech(Arbre a, int x);
Arbre insR(Arbre a, int x);
Couple couper(Arbre a, int x);
Arbre sup(Arbre a, int x);
Arbre oterMax(Arbre a);
bool trie(Arbre a);
int deseq(Arbre a);
Arbre rd(Arbre a);
Arbre rg(Arbre a);
Arbre rdg(Arbre a);
Arbre rgd(Arbre a);
Arbre reeq(Arbre a);
Arbre insF(Arbre a, int x);
