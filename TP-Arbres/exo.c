#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exo.h"

Arbre arbNouv(void){
    return NULL;
}

bool vide(Arbre a){
    return a==NULL;
}


Arbre e(Arbre a, int r, Arbre b){
    Maillon *m;
    m=(Maillon*)malloc(sizeof(Maillon));
    if (m==NULL)
    {
        printf("pb malloc");
        exit(1);
    }
    m->g=a;
    m->d=b;
    m->v=r;
    return m;
}

Arbre ad(Arbre a){
    if (vide(a)) exit(1);
    return a->d;
}
Arbre ag(Arbre a){
    if (vide(a)) exit(1);
    return a->g;
}

int r(Arbre a){
    if (vide(a)) exit(1);
    return a->v;
}
int h(Arbre a){
    if (vide(a)) return -1;
    return 1+max(h(ad(a)),h(ad(a)));
}

int max(int a, int b){
    if(a>=b)return a;
    return b;
}


void affichArbre(Arbre a, int i){
    if (vide(a)) return;
    affichArbre(ad(a),i+1);
    affichRac(r(a),i);
    affichArbre(ag(a),i+1);    
}
void affichRac(int v, int i){
    for (int i1=0; i1 < i; i1++)
    {
        printf("---");
    }
    printf("%d\n",v);
}


int nn(Arbre a){
    if (vide(a))
    {
        return 0;
    }
    return 1+nn(ad(a))+nn(ag(a));
}

int nf(Arbre a){
    if (vide(a))
    {
        return 0;
    }
    if (f(a))
    {
        return 1;
    }
    return nf(ad(a))+nf(ag(a));
}

bool f(Arbre a){
    if (vide(a->d)&&vide(a->g))
    {
        return true;
    }
    return false;
}

Arbre eg(Arbre a){
    if (vide(a)) exit(1);
    if (vide(ag(a)))
    {
        return e(arbNouv(),r(a),arbNouv()) ;   
    }
    return eg(ag(a));

}
Arbre ed(Arbre a){
    if (vide(a)) exit(1);
    if (vide(ad(a)))
    {
        return e(arbNouv(),r(a),arbNouv()) ;   
    }
    return ed(ad(a));

}
bool egalArb(Arbre a, Arbre b){
    if(vide(a)&&vide(b))return true;
    if(vide(a)||vide(b))return false;
    return r(a)==r(b)&&egalArb(ad(a),ad(b))&&egalArb(ag(a),ag(b));

}

Arbre insertF(Arbre a, int x){
    if (vide(a)) return e(arbNouv(),x,arbNouv());
    if (r(a)==x) return a;
    if (x<r(a))
    {
        a->g=insertF(a->g,x);
        return a;
    }
    a->d=insertF(a->d,x);
    return a;
}

Arbre rech(Arbre a, int x){
    if(vide(a))return a;
    if(x==r(a))return a;
    if (x<r(a))
    {
        return rech(ag(a),x);
    }
    return rech(ad(a),x);
}

Arbre insR(Arbre a, int x){
    Couple c;
    c=couper(a,x);
    return e(c.g,x,c.d);
}

Couple couper(Arbre a, int x){
    Couple c,f;
    if (vide(a))
    {
        c.g=arbNouv();
        c.d=arbNouv();
        return c;
    }
    if (x==r(a))
    {
        c.d=ad(a);
        c.g=ag(a);
        return c;
    }
    if (x<r(a))
    {
        f=couper(ag(a),x);
        c.d=e(f.d,r(a),ad(a));
        c.g=f.g;
        return c;
    }
    f=couper(ad(a),x);
    c.g=e(ag(a),r(a),f.g);
    c.d=f.d;
    return c;
}

Arbre sup(Arbre a, int x){
    if(vide(a))return a;
    if (r(a)==x)
    {
        if(vide(ad(a)))return ag(a);
        if(vide(ag(a)))return ad(a);
        return e(oterMax(ag(a)),r(ed(ag(a))),ad(a));//max de ag(a) devient la racine du nouvel arbre, enleve donc le ed(ag(a)) 
    }
    if (x<r(a))
    {
        a->g=sup(a->g,x);
        return a;
    }
    a->d=sup(a->d,x);
    return a;   
}

Arbre oterMax(Arbre a){// return ag sans son max
    if(vide(ad(a))) return ad(a);
    a->d=oterMax(a->d);//passe une seule par ici car appelé lorsque r(a)==x
    return a;
}

bool trie(Arbre a){
    bool b1,b2,b3;
    if(vide(a)) return true;
    if (vide(ag(a))) b1=true;
    else b1=r(ed(ag(a)))<r(a);
    if (vide(ad(a))) b2=true;
    else b2=r(eg(ad(a)))>r(a);
    if(vide(ag(a))&&vide(ad(a))) return true;
    else b3=trie(ag(a))&&trie(ad(a));
    return b1&&b2&&b3;
}

int deseq(Arbre a){
    if(vide(a))return 0;
    return h(ag(a))-h(ad(a));
}

Arbre rd(Arbre a){//r(ag(a)) qui devient racine - impossible si vide(ag)
    if(vide(a)) return a;
    if (vide(ag(a)))
    {
        printf("opé interdite");
        exit(1);
    }
    return e(ag(ag(a)),r(ag(a)),e(ad(ag(a)),r(a),ad(a)));
}

Arbre rg(Arbre a){//r(ad(a)) qui devient racine - impossible si vide(ad)
    if(vide(a))return a;
    if (vide(ad(a)))
    {
        printf("opé interdite");
        exit(1);
    }
    return e(e(ag(a),r(a),ag(ad(a))),r(ad(a)),ad(ad(a)));   
}

Arbre rgd(Arbre a){//rotation gauche de ag(a) puis rd a
    if(vide(a))return a;
    return rd(e(rg(ag(a)),r(a),ad(a)));
}
Arbre rdg(Arbre a){//rotation droite de ad(a) puis rg a
    if(vide(a))return a;
    return rg(e(ag(a),r(a),rd(ad(a))));
}

Arbre reeq(Arbre a){
    if(vide(a))return a;
    if(deseq(a)==2&&deseq(ag(a))>=0)return rd(a);
    if(deseq(a)==-2&&deseq(ad(a))<=0)return rg(a);
    if(deseq(a)==2&&deseq(ag(a))==-1)return rgd(a);
    if(deseq(a)==-2&&deseq(ad(a))==1)return rdg(a);
    return a;
}

Arbre insF(Arbre a, int x){
    if(vide(a))return e(arbNouv(),x,arbNouv());
    if(r(a)==x)return a;
    if(r(a)<x){
        a->g= insF(ag(a),x);   
        return reeq(a);
    } 
    a->d= insF(ad(a),x);   
    return reeq(a);
}