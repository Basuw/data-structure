#include "exo.h"

void global(){
    Arbre a1,a2,a3,a4,a5,a6,a7,b1,b2,b3,b4,b5,b6,b7;
    a1=e(arbNouv(),1,arbNouv());
    a2=e(arbNouv(),5,arbNouv());
    a3=e(arbNouv(),9,arbNouv());
    a4=e(arbNouv(),13,arbNouv());
    a5=e(a1,3,a2);
    a6=e(a3,11,a4);
    a7=e(a5,7,a6);
    affichArbre(a7,0);
    printf("---nn---\n");
    printf("%d\n",nn(a7));
    printf("---nf---\n");
    printf("%d\n",nf(a7));
    b1=e(arbNouv(),1,arbNouv());
    b2=e(arbNouv(),5,arbNouv());
    b3=e(arbNouv(),9,arbNouv());
    b4=e(arbNouv(),13,arbNouv());
    b5=e(b2,3,b1);
    b6=e(b4,11,b3);
    b7=e(b6,8,b5);
    printf("---H---\n");
    printf("%d\n",h(a7));
    printf("---Egal---\n");
    bool a=egalArb(a7,b7);
    if (a) printf("OUIII");
    else printf("NOON");
    printf("\n---Extr G---\n");
    Arbre g=eg(a7);
    Arbre d=ed(a7);
    affichArbre(g,0);
    printf("---Extr D---\n");
    affichArbre(d,0);
    // printf("---Insert F---\n\n");
    // Arbre f=insertF(b6,1);
    // affichArbre(f,0);
    printf("\n\n---Recherche---\n\n");
    Arbre r1=rech(a7,5);
    affichArbre(r1,0);
    printf("\n\n---Insert R---\n\n");
    affichArbre(a7,0);
    printf("\n");
    Arbre ir=insR(a7,12);
    affichArbre(ir,0);
    printf("\n\n---Supp---\n\n");
    Arbre sp=sup(a7,11);
    affichArbre(sp,0);
    printf("\n\n---Trie---\n\n");
    affichArbre(a7,0);
    if(trie(a7))printf("Trié\n");
    else printf("Pas Trié\n");
    printf("\n\n---Deseq---\n\n");
    printf("%d\n",deseq(b7));
    printf("\n\n---Rotation---\n\n");
    

}

void testroationdrt(){

    // affichArbre(a,0);
    // printf("\n\n");
    // a=rd(a);
    // affichArbre(a,0);
    // printf("\n\n");
    // a=rg(a);
    // affichArbre(a,0);
}

void testroationGD(){
    Arbre a=arbNouv();
    a=insertF(a,20);
    a=insertF(a,10);
    a=insertF(a,30);
    a=insertF(a,5);
    a=insertF(a,17);
    a=insertF(a,15);
    a=insertF(a,18);
    affichArbre(a,0);
    printf("\n\n");
    a=rgd(a);
    affichArbre(a,0);
}

void testroationDG(){
    Arbre a=arbNouv();
    a=insertF(a,20);
    a=insertF(a,10);
    a=insertF(a,30);
    a=insertF(a,25);
    a=insertF(a,45);
    a=insertF(a,23);
    a=insertF(a,27);
    affichArbre(a,0);
    printf("\n\n");
    a=rdg(a);
    affichArbre(a,0);
}

void testreeq(){
    Arbre a=arbNouv();
    for(int i=1; i<30;i++){
        a=insF(a,i);
    }
    affichArbre(a,0);
}

int main(void){
    // testroationGD();
    // printf("\n~~~~~~\n\n");
    // testroationDG();
    // global();
    testreeq();
    return 0;
}
