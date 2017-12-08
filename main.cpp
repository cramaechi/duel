//Program that simulates 10,000 duels between 3 marksman duelists. Only one man
//is left standing. At the end, the program outputs the winning probabilities 
//of each duelist.
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool continueDuel(int life1, int life2, int life3);
//Precondition: life1, life2, and life3 is either 0 or 1.
//Postcondition: Returns true if at least two of the parameters equals 1.

void charlieFires(int& target1, int& target2, int life);
//Precondition: Both target1, target2, and life == 1 ||
//0.
//Postcondition: The values of target1 or target2 are possibly set to 0.

void aaronFires(int& target1, int& target2, int life);
//Precondition: Both target1, target2, and life == 1 ||
//0. firstFire is set == true.
//Postcondition: The values of target1 or target2 are possibly set to 0.
//firstFire == false.

void bobFires(int& target1, int& target2, int life);
//Precondition: Both target1, target2, and life == 1 ||
//0.
//Postcondition: The values of target1 or target2 are possibly set to 0.

void reviveDuelists(int& life1, int& life2, int& life3);
//Precondition: Two of the first three formal parameters are equal to zero.
//firstFire == false.
//Postcondition: life1, life2, and life3 are set equal to 1. 
//firstFire == true;

void updateDuelistWinningProbability(double& wP1, double& wP2, double& wP3, int l1, int l2, int l3);
//Precondition: wP1, wP2, and wP3 >= 0. Two of the last three formal parameters are
//equal to zero.
//Postcondition: One of the first three formal parameters is incremented.

int main()
{
    srand(time(NULL));

    //Three flags that determine if a duelist is alive or not.
    int aLife = 1, bLife = 1, cLife = 1;

    //The winning probabilities for each of the duelists.
    double aWP = 0, bWP = 0, cWP = 0;

    for(int i = 1; i <= 10000; i++)
    {	
        do
        {
            aaronFires(cLife, bLife, aLife);
            bobFires(cLife, aLife, bLife);
            charlieFires(bLife, aLife, cLife);
        }while(continueDuel(aLife, bLife, cLife));


        updateDuelistWinningProbability(aWP, bWP, cWP, aLife, bLife, cLife);
        reviveDuelists(aLife, bLife, cLife);
    }

    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<"Aarons winning probability: "<<(aWP/10000.0)*100<<"%\n\n";
    cout<<"Bobs winning probability: "<<(bWP/10000.0)*100<<"%\n\n";
    cout<<"Charlies winning probability: "<<(cWP/10000.0)*100<<"%\n\n";

    return 0;
}

bool continueDuel(int life1, int life2, int life3)
{
    if (life1 == 1 && life2 == 1)
        return true;
    else if(life1 == 1 && life3 == 1)
        return true;
    else if(life2 == 1 && life3 == 1)
        return true;
    else
        return false;
}

void charlieFires(int& target1, int& target2, int life)
{
    double accuracy = 1.0, random = (RAND_MAX - rand())/static_cast<double>(RAND_MAX);

    if (life == 0)
        return;
    else if (random <= accuracy && target1 == 1)
        target1 = 0;
    else if (random <= accuracy && target1 == 0 && target2 == 1)
        target2 = 0;
    else 
        return;
}

void aaronFires(int& target1, int& target2, int life)
{
    double accuracy = 1/3.0, random = (RAND_MAX - rand())/static_cast<double>(RAND_MAX);

    if (life == 0)
        return;
    else if (random <= accuracy && target1 == 1)
        target1 = 0;
    else if (random <= accuracy && target1 == 0 && target2 == 1)
        target2 = 0;
    else 
        return;
}

void bobFires(int& target1, int& target2, int life)
{
    double accuracy = 1/2.0, random = (RAND_MAX - rand())/static_cast<double>(RAND_MAX);

    if (life == 0)
        return;
    else if (random <= accuracy && target1 == 1)
        target1 = 0;
    else if (random <= accuracy && target1 == 0 && target2 == 1)
        target2 = 0;
    else 
        return;
}

void reviveDuelists(int& life1, int& life2, int& life3)
{
    life1 = 1;
    life2 = 1;
    life3 = 1;
}

void updateDuelistWinningProbability(double& wP1, double& wP2, double& wP3, int l1, int l2, int l3)
{
    if (l1 == 1)
        ++wP1;
    else if (l2 == 1)
        ++wP2;
    else if (l3 == 1)
        ++wP3;
    else
        return;
}
