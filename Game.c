//Aaron Liu
//5/05/2016
//Game.c first draft

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}
#define V 1
#define H 0


typedef struct _game { 
   int point[6][11]; 
   int line[2][6][11]; 
   int discipline[5][10];
   int dice[5][10];
   
   int KPI[3];
   int campus[3];
   int GO8[3];
   int ARC[3];
   int IP[3];
   int paper[3];
   int student[3][6];
   int mostARC;
   int mostPaper;
   int currentTurn;
   
} game;

int main (int argc, char *argv[]) {
   
}

Game newGame (int discipline[], int dice[]) {
   Game new;
   new = malloc(1500);
   int i = 0;
   int j = 0;
   int count = 0;
   while (i < 5) {
         j = abs(i - 2);
         while (j < 10 - abs(i - 2)) {
         new.discipline[i][j  ] = discipline[count];
         new.discipline[i][j+1] = discipline[count];
         new.dice[i][j  ] = dice[count];
         new.dice[i][j+1] = dice[count];
         count++;
         j += 2;
      }
      i++;
   }
   new.point[2][ 0] = CAMPUS_A;
   new.point[3][10] = CAMPUS_A;
   new.point[0][ 3] = CAMPUS_B;
   new.point[5][ 7] = CAMPUS_B;
   new.point[0][ 8] = CAMPUS_C;
   new.point[5][ 2] = CAMPUS_C;
   new.line[V][2][0] = ARC_A;
   new.line[V][3][9] = ARC_A;
   new.line[V][0][3] = ARC_B;
   new.line[V][5][6] = ARC_B;
   new.line[H][0][8] = ARC_C;
   new.line[H][4][2] = ARC_C;
   
   new.KPI[] = {24, 24, 24};
   new.campus[] = {2, 2, 2};
   new.GO8[] = {0};
   new.ARC[] = {2, 2, 2};
   new.IP[] = {0};
   new.paper[] = {0};
   new.student[][] = {0};
   new.mostARC = NO_ONE;
   new.mostPaper = NO_ONE;
   
   new.currentTurn = -1;
   
   return new;
}

void disposeGame (Game g) {
   free(g);
}

void makeAction (Game g, action a) {
   
}

void throwDice (Game g, int diceScore) {
   g.currentTurn++;
}

int getDiscipline (Game g, int regionID) {
   int r = 0;
   int i = 0;
   int j = 0;
   int count = 0;
   while (i < 5) {
         j = abs(i - 2);
         while (j < 10 - abs(i - 2)) {
         count++;
         if (count == regionID) {
            r = g.discipline[i][j];
         }
         j += 2;
      }
      i++;
   }
   
   return r;   
}

int getDiceValue (Game g, int regionID) {
   int r = 0;
   int i = 0;
   int j = 0;
   int count = 0;
   while (i < 5) {
         j = abs(i - 2);
         while (j < 10 - abs(i - 2)) {
         count++;
         if (count == regionID) {
            r = g.dice[i][j];
         }
         j += 2;
      }
      i++;
   }
   
   return r;   
}

int getMostARCs (Game g) {
   int r = g.mostARC;
   if (r == 0) {
      if (g.ARC[0] != 2) {
         r = UNI_A;
      }
      if (g.ARC[1] != 2) {
         r = UNI_B;
      }
      if (g.ARC[2] != 2) {
         r = UNI_C;
      }
   } else {
      if (g.ARC[g.mostARC - 1] < g.ARC[0]) {
         r = UNI_A;
      }
      if (g.ARC[g.mostARC - 1] < g.ARC[1]) {
         r = UNI_B;
      }
      if (g.ARC[g.mostARC - 1] < g.ARC[2]) {
         r = UNI_C;
      }
   }
   return r;
}

int getMostPublications (Game g) {
   int r = g.mostPaper;
   if (r == 0) {
      if (g.paper[0] != 2) {
         r = UNI_A;
      }
      if (g.paper[1] != 2) {
         r = UNI_B;
      }
      if (g.paper[2] != 2) {
         r = UNI_C;
      }
   } else {
      if (g.paper[g.mostPaper - 1] < g.paper[0]) {
         r = UNI_A;
      }
      if (g.paper[g.mostPaper - 1] < g.paper[1]) {
         r = UNI_B;
      }
      if (g.paper[g.mostPaper - 1] < g.paper[2]) {
         r = UNI_C;
      }
   }
   return r;
}

int getTurnNumber (Game g) {
   return g.currentTurn;
}

int getWhoseTurn (Game g) {
   int r;
   if (g.currentTurn == -1) {
      r = NO_ONE;
   } else {
      r = currentTurn % 3 + 1;
   }
   return r;
}

int getCampus(Game g, path pathToVertex) {
   
}

int getARC(Game g, path pathToEdge) {
   
}

int isLegalAction (Game g, action a) {
   
}

int getKPIpoints (Game g, int player) {
   g.KPI[player - 1] = g.ARC[player - 1]*2 + g.campus[player - 1]*10 + 
                       g.GO8[player - 1]*20 + g.IP[player - 1]*10;
   if (g.mostARC == player) {
      g.KPI[player - 1] += 10;
   }
   if (g.mostPaper == player) {
      g.KPI[player - 1] += 10;
   }
   return g.KPI[player - 1];
}

int getARCs (Game g, int player) {
   return g.ARC[player - 1];
}

int getGO8s (Game g, int player) {
   return g.GO8[player - 1];
}

int getCampuses (Game g, int player) {
   return g.campus[player - 1];
}

int getIPs (Game g, int player) {
   return g.IP[player - 1];
}

int getPublications (Game g, int player) {
   return g.paper[player - 1];
}

int getStudents (Game g, int player, int discipline) {
   return g.student[player - 1][discipline];
}

int getExchangeRate (Game g, int player, int disciplineFrom, int disciplineTo) {
   
}