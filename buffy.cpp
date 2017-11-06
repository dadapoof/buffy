BUFFY.CPP

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

// Prototype Functions
void Intro();
char who_attacks();
void Stake_Buffy(char x, int& vamp_count, int& stake_count, bool& Buffy_alive);
void Stake_Willow(char x, int& vamp_count, int& stake_count, bool& Buffy_alive);
void Stake_Xander(char x, int& vamp_count, int& stake_count, bool& Buffy_alive);
void Spell_Buffy(char attacker, int& vamp_count, int& stake_count, bool& Buffy_alive);
void Spell_Willow(char attacker, int& vamp_count, int& stake_count, bool& Buffy_alive);
void Spell_Xander(char attacker, int& vamp_count, int& stake_count, bool& Buffy_alive);
void Running(int& stake_count, bool& Buffy_alive);


int main()
{

// Declaring and Initializing Variables
char user_input;
int vamp_count = 3, stake_count = 10;
bool Buffy_alive = true;

// Calling the intro function
Intro();

  // Do while loop for the entire program
  do
  {

    cout << "You can either attack with a stake (a), cast a spell (c),";
    cout << " or run away(r)" << endl;
    cin >> user_input;


    // While loop that validates user input
    while (user_input != 'a' && user_input != 'c' && user_input != 'r')
    {
      cout << "Sorry that is not an input... Please try again!" << endl;
      cin >> user_input;
    }

    // If the User wants to attack using a stake
    if (user_input == 'a')
    {
      char attacker = who_attacks();

    // Special case: So that the stakes do not go into the negatives
    if (stake_count < 3)
    {
      cout << "Sorry, you do not have enough stakes to play as Buffy...";
      cout << "You can only play as Willow or Xander!" << endl;
      Stake_Willow(attacker, vamp_count, stake_count, Buffy_alive);
      Stake_Xander(attacker, vamp_count, stake_count, Buffy_alive);
    }

    else
    {
      Stake_Buffy(attacker, vamp_count, stake_count, Buffy_alive);
      Stake_Willow(attacker, vamp_count, stake_count, Buffy_alive);
      Stake_Xander(attacker, vamp_count, stake_count, Buffy_alive);
    }

  }

 // If the user wants to attack with a spell
  else if (user_input == 'c')
  {
    char attacker = who_attacks();

    Spell_Buffy(attacker, vamp_count, stake_count, Buffy_alive);
    Spell_Willow(attacker, vamp_count, stake_count, Buffy_alive);
    Spell_Xander(attacker, vamp_count, stake_count, Buffy_alive);

  }

  // If the user wants to run away
  else if (user_input == 'r')
  {
    cout << "You chose to run!" << endl;
    Running(stake_count, Buffy_alive);
  }

}
while (vamp_count > 0 && Buffy_alive == true && stake_count > 0);


        return 0;
}



//                              FUNCTIONS



// Introduces the rules
// Name: Intro, Type: None, Return: Void
void Intro()
{
 cout << "Welcome to the funnest game you will ever play!" << endl;
 cout << "You are playing as either Buffy, Xander, or Willow." << endl;
 cout << "You must defeat 3 vampires with 10 stakes!" << endl;
}


// Asks the user who they would like to attack as and takes in their input
// Name: who_attacks, Type: None, Return: char
char who_attacks()
{
   char attacker;
   cout << "Who would you like to attack as?" << endl;
   cout << "Enter b for Buffy, w for Willow, or x for Xander!" << endl;
   cin >> attacker;

        return attacker;
}

// Executes what happens if the user decides to attack as buffy with a stake
// Name: Stake_Buffy; Type: char, 2 ints, bool; Return: void
void Stake_Buffy(char x, int& vamp_count, int& stake_count, bool& Buffy_alive)
{

int chance_of_death, kill_vamp;

   // If the user chooses Buffy
   if (x == 'b')
   {

     // Generates a random number between 1 and 10 to use as a percentage
     kill_vamp = rand() % 10 + 1;


     // 80% kills a vampire
     if (kill_vamp > 2)
     {
       vamp_count--;
       cout << "Well done! A vampire was killed!" << endl;
       cout << "There are now " << vamp_count << " vampires." << endl;
     }

     // Generates a random number between 1 and 10 to use as a percentage
     chance_of_death = rand() % 10 + 1;

     // 20% kills buffy
     if (chance_of_death < 3)
     {
       Buffy_alive = false;
       cout << "Oh no!! Buffy died..." << endl;
     }

     if (kill_vamp < 3 && chance_of_death > 2)
     {
       cout << "Nothing happened this round...";
     }

     stake_count -= 3;
     cout << "There are now " << stake_count << " stakes." << endl;

     if (Buffy_alive == true)
     cout << "Buffy is still alive!" << endl;

   }

}
// Executes what happens if the user decides to attack as Willow with a stake
// Name: Stake_Willow; Type: char, 2 ints, bool; Return: void
void Stake_Willow(char x, int& vamp_count, int& stake_count, bool& Buffy_alive)
{

int chance_of_death, kill_vamp;

   // If the user chooses Willow
   if (x == 'w')
   {

     // Generates a random number between 1 and 10 to use as a percentage
     kill_vamp = rand() % 10 + 1;

     // 60% kills a vampire
     if (kill_vamp > 4)
     {
       vamp_count--;
       cout << "Well done! A vampire was killed!" << endl;
       cout << "There are now " << vamp_count << " vampires." << endl;
     }


     // Generates a random number between 1 and 10 to use as a percentage
     chance_of_death = rand() % 10 + 1;

     // 20% kills Buffy
     if (chance_of_death < 3)
     {
       Buffy_alive = false;
       cout << "Oh no!! Buffy died..." << endl;
     }

     if (kill_vamp < 5 && chance_of_death > 2)
     {
       cout << "Nothing happened this round...";
     }

     cout << "There are now " << stake_count << " stakes." << endl;

     if (Buffy_alive == true)
     cout << "Buffy is still alive!" << endl;

   }

}


// Executes what happens if the user decides to attack as Xander with a stake
// Name: Stake_Xander; Type: char, 2 ints, bool; Return: void
void Stake_Xander(char x, int& vamp_count, int& stake_count, bool& Buffy_alive)
{

int chance_of_death, kill_vamp;

   // If the user chooses Xander
   if (x == 'x')
   {

     // Generates a random number between 1 and 10 to use as a percentage
      kill_vamp = rand() % 10 + 1;

     // 30% kills a vampire
     if (kill_vamp > 7)
     {
       vamp_count--;
       cout << "Well done! A vampire was killed!" << endl;
       cout << "There are now " << vamp_count << " vampires." << endl;
     }


     // Generates a random number between 1 and 10 to use as a percentage
     chance_of_death = rand() % 10 + 1;

     // 10% kills Buffy
     if (chance_of_death < 2)
     {
       Buffy_alive = false;
       cout << "Oh no!! Buffy died..." << endl;
     }


     if (kill_vamp < 8 && chance_of_death > 1)
     {
       cout << "Nothing happened this round...";
     }

     stake_count--;
     cout << "There are now " << stake_count << " stakes." << endl;

     if (Buffy_alive == true)
     cout << "Buffy is still alive!" << endl;

   }

}


// Executes what happens if the user decides to attack as buffy with a spell
// Name: Spell_Buffy; Type: char, 2 ints, bool; Return: void
void Spell_Buffy(char x, int& vamp_count, int& stake_count, bool& Buffy_alive)
{

int chance_of_death, kill_vamp;

   // If the user chooses buffy
   if (x == 'b')
   {

     // Generates a random number between 1 and 10 to use as a percentage
     kill_vamp = rand() % 10 + 1;

     // 20% kills a vampire
     if (kill_vamp > 8)
     {
       vamp_count--;
       cout << "Well done! A vampire was killed!" << endl;
       cout << "There are now " << vamp_count << " vampires." << endl;
     }

     // Generates a random number between 1 and 10 to use as a percentage
     chance_of_death = rand() % 10 + 1;

     // 30% kills Buffy
     if (chance_of_death < 4)
     {
       Buffy_alive = false;
       cout << "Oh no!! Buffy died..." << endl;
     }


     if (kill_vamp < 9 && chance_of_death > 3)
     {
       cout << "Nothing happened this round...";
     }

     stake_count--;
     cout << "There are now " << stake_count << " stakes." << endl;

     if (Buffy_alive == true)
     cout << "Buffy is still alive!" << endl;

   }


}


// Executes what happens if the user decides to attack as Willow with a spell
// Name: Spell_Willow; Type: char, 2 ints, bool; Return: void
void Spell_Willow(char x, int& vamp_count, int& stake_count, bool& Buffy_alive)
{

int chance_of_death, kill_vamp;

   // If the user chooses Willow
   if (x == 'w')
   {

     // Generates a random number between 1 and 10 to use as a percentage
     kill_vamp = rand() % 10 + 1;

     // 30% kills a vamp
     if (kill_vamp > 3)
     {
       vamp_count--;
       cout << "Well done! A vampire was killed!" << endl;
       cout << "There are now " << vamp_count << " vampires." << endl;
     }

     // Generates a random number between 1 and 10 to use as a percentage
     chance_of_death = rand() % 10 + 1;

     // 40% kills Buffy
     if (chance_of_death < 5)
     {
       Buffy_alive = false;
       cout << "Oh no!! Buffy died..." << endl;
     }


     if (kill_vamp < 4 && chance_of_death > 4)
     {
       cout << "Nothing happened this round...";
     }

     cout << "There are now " << stake_count << " stakes." << endl;

     if (Buffy_alive == true)
     cout << "Buffy is still alive!" << endl;

   }

}


// Executes what happens if the user decides to attack as Xander with a spell
// Name: Spell_Xander; Type: char, 2 ints, bool; Return: void
void Spell_Xander(char x, int& vamp_count, int& stake_count, bool& Buffy_alive)
{

int chance_of_death, kill_vamp;

   // If the user chooses Xander
   if (x == 'x')
   {

     // Generates a random number between 1 and 10 to use as a percentage
     kill_vamp = rand() % 10 + 1;

     // 10% kills a vampire
     if (kill_vamp > 9)
     {
       vamp_count--;
       cout << "Well done! A vampire was killed!" << endl;
       cout << "There are now " << vamp_count << " vampires." << endl;
     }

     // Generates a random number between 1 and 10 to use as a percentage
     chance_of_death = rand() % 10 + 1;

     // 20% kills a vampire
     if (chance_of_death < 3)
     {
       Buffy_alive = false;
       cout << "Oh no!! Buffy died..." << endl;
     }


     if (kill_vamp < 10 && chance_of_death > 2)
     {
       cout << "Nothing happened this round...";
     }

     cout << "There are now " << stake_count << " stakes." << endl;

     if (Buffy_alive == true)
     cout << "Buffy is still alive!" << endl;

   }

}

// Executes what occurs if the user decides to run
// Name: Running; Type: int, bool; Return: void
void Running(int& stake_count, bool& Buffy_alive)
{
int chance_of_death;

     // Generates a random number between 1 and 10 to use as a percentage
     chance_of_death = rand() % 10 + 1;

     // 10% kills Buffy
     if (chance_of_death < 2)
     {
       Buffy_alive = false;
       cout << "Oh no!! Buffy died..." << endl;
     }


     stake_count++;
     cout << "There are now " << stake_count << " stakes." << endl;

     if (Buffy_alive == true)
     cout << "Buffy is still alive!" << endl;

}
