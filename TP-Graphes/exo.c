#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo.h"

Graphe grapheNouv(){
    return NULL;
}

List listNouv(){
    return NULL;
}

Graphe adjt(Graphe g, int x){//insertion tete
    Maillong *m,
    m=(Maillong*)malloc(sizeof(Maillong));
    if(m==NULL){
        printf("Pb de malloc");
        exit(1);
    }
    m->v=x;
    m->succ=listNouv();
    m->suiv=g;
    return m;
}

bool vide(Graphe g){// graph vide 
    return g==NULL;
}

Graphe adjs(Graphe g, int s){// ajoute sommet de manière trié
    if(vide(g))return adjt(g,s);
    if(s<g->v)return adjt(g,s);
    if(s==g->v)return g;
    g->suiv=adjs(g->suiv,s);
    return g;
}

bool exs(Graphe g, int x){// existence d'un noeud  
    if(vide(g)) return false;
    if(x==g->v)return true;
    if(x<g->v)return false;
    return exs(g->suiv,x);

}

Graphe adja(Graphe g, int x, int y){// ajoute arc
    Maillong * aux=g;
    if(vide(g)) return g;
    if(!exs(g,x)||!exs(g,y))return g;
    while(g->suiv!=x){
        g=g->suiv;
    }
    g->succ=insert(g->succ,y);
    return aux;
}

Graphe supa(Graphe g, int x, int y){
    Maillong *aux=g;
    if(!exa(g,x,y))return g;
    while(g->suiv!=x)g=g->suiv;
    g->succ=remove(g->succ,y);
    return aux;
}

bool exa(Graphe g, int x, int y){// Exist of an arc
    if(vide(g))return false;
    if(x==g->v&&in(g->succ,y))return true;
    if(x<g->v)return false;
    return exa(g->suiv, x, y);
}
int de(Graphe g, int x){// degré sortant du point x dans g
    if(vide(g))return 0;
    if(!exs(g,x))return 0;
    while(x!=g->v)g=g->suiv;
    return length(g->succ);
}

int di(Graphe g, int x){//degré inté
    int cpt=0;
    while(!vide(g)){
        if(in(g->succ,x))cpt++;
        g=g->suiv;
    }
    return cpt;
}

Graphe sups(Graphe g, int x){ // Supression of a sommet x in g
    if(di(g,x)!=0||de(g,x)!=0)return g;// cant't remove a sommet if it has arcs
    return sups1(g,x);
}

Graphe sups1(Graphe g, int x){// Recursive part sups
    if(vide(g))return g;
    if(x<g->v)return g;
    if(x==g->v) return supst(g);
    g->suiv=sups1(g->suiv,x);
    return g;
}

Graphe supst(Graphe g){// Suppresion of the sommet in head
    Maillong *m;
    m=g;
    g=g->suiv;
    free(m);
    return g;
}

List insert(List l, int x){ // Insert on the head
    Maillonl *m;
    m=(Maillonl*)malloc(sizeof(Maillonl));
    m->v=x;
    m->suiv=l;
}

bool in(List l, int x){// verify if val in list 
    if(l==NULL)return false;
    if(l->v==x)return true;
    return in(l->suiv,x);
}

int length(List l){// lenght of the list l
    if(l==NULL)return -1;
    return 1+(l->suiv);
}

List remove(List l, int x){ //remove x in the list l
    if(l->v==x){
        return l->suiv;
    }
    if(l->suiv==NULL){
        return l;
    }
    if(l->suiv->v==x){
        l->suiv=l->suiv->suiv;
        return l;
    }
    remove(l->suiv,x);
}

void Afficher(Graphe g){
    FILE *f;
    Graphe aux=g;
    List l1;
    f=fopen("graphe.txt","w");
    if(f==NULL){
        printf("Pb ouverture\n");
        exit(1);
    }
    fprintf(f,"digraph family\n{\n");
    while(!vide(g)){}
}