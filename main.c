#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n          = 250; //minions killed per team
    int souls      = 0;   //souls collected per minion death
    int nosoul     = 0;   //soul didnt drop per minion death
    int nofarmgold = 6;   //in ARAM when a minion dies you get 6 gold
    int farmgold   = 18;  //in ARAM casters are 17 gold and melee are 20
    int soulgold   = 8;   //Senna gets 8 gold upon collecting a soul
    int gold       = 0;   //total gold
    int num        = 0;   //number generated randomly
    int tests      = 10;  //number of tests you want to try

    int nfGold[tests];  //no farm gold array
    int nfSouls[tests]; //no farm souls array

    int fGold[tests];  //farm gold array
    int fSouls[tests]; //farm souls array

    srand(time(NULL));
    
    printf("\n On average a team kills 250 minions in a 20 minute ARAM game\n\n");
    
    printf(" With 0 cs: \n");
    for(int j = 0; j < tests; j++){
        souls = 0;
        nosoul = 0;
        for(int i = 0; i < n; i++){
            num = rand() % 101; //generate number from 0 to 100
            if(num <= 26) souls++; //27% chance
            else nosoul++;
        }
        gold = (souls*(nofarmgold+soulgold)) + (nosoul*nofarmgold);
        nfGold[j] = gold;
        nfSouls[j] = souls;
        printf(" %d gold, %d souls \n",gold,souls);
    }

    //reset variables
    souls = 0;
    nosoul = 0;
    gold = 0;
    srand(time(NULL));
    
    printf("\n On average Senna kills 44 minions in a 20 minute ARAM game (According to MurderBridge.com)\n");
    
    printf("\n With 44 cs: \n");
    for(int j = 0; j < tests; j++){
        souls = 0;
        nosoul = 0;
        //44 minion kills
        for(int i = 0; i < 44; i++){
            num = rand() % 101; //generate number from 0 to 100
            if(num <= 3)  souls++; //2.777% = 3% chance
            else nosoul++;
        }
        gold = (souls*(farmgold+soulgold)) + (nosoul*farmgold);
        //printf(" %d gold, %d souls \n",gold,souls);
        //206 minions not killed
        for(int i = 0; i < 206; i++){
            num = rand() % 101; //generate number from 0 to 100
            if(num <= 26)  souls++; //27% chance
            else nosoul++;
        }
        gold += (souls*(nofarmgold+soulgold)) + (nosoul*nofarmgold);
        fGold[j] = gold;
        fSouls[j] = souls;
        printf(" %d gold, %d souls \n",gold,souls);
    }

    int golddiff = 0;
    for(int i = 0; i < tests; i++)
      golddiff += nfGold[i]-fGold[i];
    golddiff /= tests;
    printf("\n Average gold diff if you dont farm: %d \n",golddiff);  
    
    int souldiff = 0;
    for(int i = 0; i < tests; i++)
      souldiff += (nfSouls[i]-fSouls[i]);
    souldiff /= tests;
    printf("\n Average soul diff if you dont farm: +%d \n",souldiff);  

    return 0;
}
