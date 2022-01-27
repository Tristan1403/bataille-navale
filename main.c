#include <stdio.h>

#define  MAX_TAB 10

#define NOMBRE_SCORE_MAX 10

#define MAX_CHAR_NAME 50

#include <stdlib.h>

#include <conio.h>

#include <string.h>

#define DECAL 49

void aide();

void aide_page3();

void aide_page2();

int montableau[MAX_TAB][MAX_TAB];

int coupJouer[MAX_TAB][MAX_TAB];

void score();

char demander_nom();

void clear();

void int_tableau();

void afficher_tableau();

void score();

void attaquer();

void aide();

void accueil();

void jouer();

typedef enum { //voici une structure qui permet de creér mes propres variable
    ACCUEIL,
    AIDE,
    JEU,
    SCORE,
    QUITTER,
    AIDE2,
    AIDE3
} m_prog;

m_prog main_machine = ACCUEIL;// commence dnas la fonction accueil

void clear_buffer() {// permet de clear le buffer
    while (getchar() != '\n');

}


void init_coup() {// permet d'initier un coup
    for (int i = 0; i < MAX_TAB; i++) {
        for (int y = 0; y < MAX_TAB; y++) {
            coupJouer[y][i] = 0;
        }
    }
}

void demander_couper(char monchoix[2]) {// permet de demander le prochain coup
    printf("Merci de donner votre choix : ");

    scanf("%s", monchoix);
    clear();
}

void score() { //  voici le menu score
    clear();
    clear_buffer();
    printf("Voice le menu score appuyer sur une touche pour quitter !");
    getch(); // permet de demander n'importe quel touche
    main_machine = ACCUEIL;

}

void tableau_ordi(int montableau[MAX_TAB][MAX_TAB]) {// initie les bateaux
    montableau[1][1] = 1;
    montableau[3][1] = 2;
    montableau[3][2] = 2;
    montableau[5][1] = 3;
    montableau[5][2] = 3;
    montableau[5][3] = 3;
    montableau[7][1] = 4;
    montableau[7][2] = 4;
    montableau[7][3] = 4;
    montableau[7][4] = 4;
    montableau[0][8] = 5;
    montableau[1][8] = 5;
    montableau[2][8] = 5;
    montableau[3][8] = 5;
    montableau[4][8] = 5;

}

void int_tableau(int montableau[MAX_TAB][MAX_TAB]) { //initie un tableau
    for (int y = 0; y < MAX_TAB; y++) {
        for (int x = 0; x < MAX_TAB; x++) {
            montableau[x][y] = 0;
        }
    }
}


void afficher_tableau() { // affiche le tableau visible par l'utilisateur

    printf("   1  2  3  4  5  6  7  8  9  10\n");
    for (int y = 0; y < MAX_TAB; y++) {
        switch (y) {
            case 0:
                printf("A  ");
                break;
            case 1:
                printf("B  ");
                break;
            case 2:
                printf("C  ");
                break;
            case 3:
                printf("D  ");
                break;
            case 4:
                printf("E  ");
                break;
            case 5:
                printf("F  ");
                break;
            case 6:
                printf("G  ");
                break;
            case 7:
                printf("H  ");
                break;
            case 8:
                printf("I  ");
                break;
            case 9:
                printf("J  ");
                break;
        }
        for (int x = 0; x < MAX_TAB; x++) {
            printf("%i  ", coupJouer[y][x]);
        }
        printf("\n");
    }
}

void clear() { // fonction qui permet de clear mon ecran
#ifdef __unix__
    system("clear");
#elif defined(_WIN32) || defined(WIN32)
    system("cls");
#else
    system("clear");
#endif
}

void aide() { //voici l'aide du jeu
    clear();
    printf("----------------------------------------------\n");
    printf("|    Aide\t\t\t\t     |\n");
    printf("|   ------\t\t\t\t     |\n");
    printf("|  vous trouverez un tuto video ici:\t     |\n");
    printf("|\t\t\t\t\t     |\n");
    printf("----------------------------------------------\n");

    int ch1, ch2;


    printf("fleche du haut pour la suite!\n"
           "fleche de bas pour evenir en arriere!\n"
           "appuyer sur Q pour quitter !\n");

    ch1 = getch();

    ch2 = 0;

    switch (ch1) { // si on tape Q ou q quitte le menu aide
        case 'q':
        case 'Q':
            main_machine = ACCUEIL;
            break;

        case 0xE0:

            ch2 = getch();

            switch (ch2) {

                case 72: // permet d'aller dans aide 2 quand on press up
                    printf("UP WAS PRESSED\n");
                    main_machine = AIDE2;
                    break;

                    case 80: // permet d'aller dans aide 3 quand on press up
                    printf("DOWN WAS PRESSED\n");
                    main_machine = AIDE3;
                    break;


                default:
                    main_machine = AIDE; // créer une boucle en cas d'une autre touche
                    break;

            }
            break;
    }
}


void aide_page2() {
    clear();
    printf("-Un zodiaque de 1 case\n"
           "-Une vedette rapide de 2 cases\n"
           "-Un croiseur de 3 cases\n"
           "-Un cuirasse de 4 cases\n"
           "-Un porte-avion de 5 cases\n\n");
    int ch1, ch2;

    printf("fleche du haut pour la suite!\n"
           "fleche de bas pour evenir en arriere!\n"
           "appuyer sur Q pour quitter !\n");

    ch1 = getch();

    ch2 = 0;

    switch (ch1) {
        case 'q':
        case 'Q':
            main_machine = ACCUEIL;
            break;

        case 0xE0:

            ch2 = getch();

            switch (ch2) {

                case 72:
                    printf("UP WAS PRESSED\n");
                    main_machine = AIDE3;
                    break;

                case 80:
                    printf("DOWN WAS PRESSED\n");
                    main_machine = AIDE;
                    break;


                default:
                    main_machine = AIDE2;
                    break;

            }
            break;
    }
}


void aide_page3() {
    clear();
    printf("-Deux bateaux ne peuvent pas se toucher\n"
           "-Un bateau ne peut pas etre en contact avec le bord de la grille par plus que 1 case\n\n");
    int ch1, ch2;


    printf("fleche du haut pour la suite!\n"
           "fleche de bas pour evenir en arriere!\n"
           "appuyer sur Q pour quitter !\n");

    ch1 = getch();

    ch2 = 0;

    switch (ch1) {
        case 'q':
        case 'Q':
            main_machine = ACCUEIL;
            break;

        case 0xE0:

            ch2 = getch();

            switch (ch2) {

                case 72:
                    printf("UP WAS PRESSED\n");
                    main_machine = AIDE;
                    break;

                case 80:
                    printf("DOWN WAS PRESSED\n");
                    main_machine = AIDE2;
                    break;


                default:
                    main_machine = AIDE3;
                    break;

            }
            break;
    }
}


void accueil() { // voici le menu acceuil ou l'on commence
    clear();
    int nombre_acceuil;//mettre en haut quand il y a la fonction
    do {
        printf("Accueil\n");
        printf("-----------------------------\n");
        printf("|\tBataille Navale\t    |\n");
        printf("-----------------------------\n");
        printf("|\t1.Aide\t\t    |\n");
        printf("|\t2.Jouer\t\t    |\n");
        printf("|\t3.Scores\t    |\n");
        printf("|\tvotre choix ?\t    |\n");
        printf("-----------------------------\n");
        scanf("%d", &nombre_acceuil);
    } while (nombre_acceuil < 1 || nombre_acceuil > 3);

    switch (nombre_acceuil) { // permet de choisir
        case 1:
            clear();
            main_machine = AIDE;
            break;
        case 2:;
            clear();
            main_machine = JEU;
            break;
        case 3:
            clear();
            main_machine = SCORE;
            break;
    }
}


void jouer() { // cette fonction et la fonction pour jouer au jeu
    int montableau[MAX_TAB][MAX_TAB];
    int colone = 0;
    char choix[3];
    char temp_name[MAX_CHAR_NAME];
    int score = 50;

    printf("Quel est votre nom ?\n");//demande de nom
    scanf("%s", temp_name);
    printf("\n");
    int_tableau(montableau);
    tableau_ordi(montableau);

    while (choix[0] != '0') {//quand on tape 0 on va vers l'acceuil
        afficher_tableau();
        demander_couper(choix);
        printf("Vous avez choisi : %s\n", choix);
        printf("Votre col : %c et votre ligne : %c\n", choix[0], choix[1]);

        switch (choix[0]) {
            case 'a':
            case 'A':
                // ici on est sur la col 0
                colone = 0;
                break;
            case 'b':
            case 'B':
                colone = 1;
                break;
            case 'c':
            case 'C':
                colone = 2;
                break;
            case 'd':
            case 'D':
                colone = 3;
                break;
            case 'e':
            case 'E':
                colone = 4;
                break;
            case 'f':
            case 'F':
                colone = 5;
                break;
            case 'g':
            case 'G':
                colone = 6;
                break;
            case 'h':
            case 'H':
                colone = 7;
                break;
            case 'i':
            case 'I':
                colone = 8;
                break;
            case 'j':
            case 'J':
                colone = 9;
                break;
            case '0':
                break;
        }
        int ligne = choix[1] - DECAL;
        if (ligne == 0) {
            if (choix[2] == '0') {
                ligne = 9;
            }
        }
        if (montableau[colone][ligne] > 10) { // si la valeur cache de la case, elle a recu un +10
            printf("deja touche\n");
        } else if (montableau[colone][ligne] >= 1 && montableau[colone][ligne] <= 5) {// permet au case avec une case de bateau d'être détecter
            coupJouer[colone][ligne] = 1;
            montableau[colone][ligne] = montableau[colone][ligne] + 10;
            if (montableau[1][1] == 11) {
                printf("toucher couler !\n");
                montableau[1][1] = 100;// gagne la valeur 100 pour qu'elle puisse ce differencier d'avant
            } else if (montableau[3][1] + montableau[3][2] == 24) {
                printf("toucher couler !\n");
                montableau[3][1] = 100;
            } else if (montableau[5][1] + montableau[5][2] + montableau[5][3] == 39) {
                printf("toucher couler !\n");
                montableau[5][1] = 100;
            } else if (montableau[7][1] + montableau[7][2] + montableau[7][3] + montableau[7][4] == 56) {
                printf("toucher couler !\n");
                montableau[7][1] = 100;
            } else if (montableau[0][8] + montableau[1][8] + montableau[2][8] + montableau[3][8] + montableau[4][8] ==
                       75) {
                printf("toucher couler !\n");
                montableau[0][8] = 100;
            } else if (montableau[colone][ligne] > 10) {
                printf("toucher ! \n");
            }
        } else {
            printf("rate !\n");
            coupJouer[colone][ligne] = 9;
            score = score - 1;
            if (score == 0) {
                break;
            }

        }
        if (montableau[1][1] + montableau[3][1] + montableau[5][1] + montableau[7][1] + montableau[0][8] == 500) {
            break;
        }

    }
    if (montableau[1][1] + montableau[3][1] + montableau[5][1] + montableau[7][1] + montableau[0][8] == 500) {// permet de gagner
        clear();
        clear_buffer();
        printf("Victoire!");
        printf("Bravo %s vous avez fait un score de %d", temp_name, score);
        getch();
        main_machine = SCORE;
    } else if (score == 0) { // permet de perdre
        char quitter = 3;
        clear();
        clear_buffer();
        printf("Defaite!");
        getch();
        main_machine = SCORE;
    } else {
        main_machine = ACCUEIL;
        clear();
        clear_buffer();
    }
}

int main() { // voici le main avec les variables créer
    while (main_machine != QUITTER) {
        switch (main_machine) {
            case ACCUEIL:
                accueil();
                break;
            case AIDE:
                aide();
                break;
            case JEU:
                jouer();
                break;
            case SCORE:
                score();
                break;
            case AIDE2:
                aide_page2();
            case AIDE3:
                aide_page3();
            default:
                break;
        }
    }
}