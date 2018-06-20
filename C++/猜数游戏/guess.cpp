#include <iostream>
#include <iomanip>

#include "zyrandom.h"
#include "guess.h"

using namespace std;

const int lowest_price = 100;
const int highest_price = 200;
const int guess_count = 6;
static int InitializeBout();

static bool PlayBout(int actual_price, int lower_price, int higher_price, int chances_left);

static bool Again();

static int GetPrice(int lower_price, int higher_price, int chances_left);

static int CheckPrice(int lower_price, int higher_price, int guess_price);

static int JudgePrice(int actual_price, int guess_price);

void PrintWelcomeInfo()
{
  cout << "The program lists a product with price between " << lowest_price << " and " << highest_price << " (RMB Yuan).\n";
  cout << "You give a guess price. If the price you give is " << "correct, you win.\n";
  cout << "You have " << guess_count << " chances.\n";
  cout << "Rise to the challenge to win your bonus...\n";
}

void InitializeGame()
{
  int i, n;
  Randomize();
}

double PlayGame()
{
  int actual_price, lower_price = lowest_price, higher_price = highest_price;
  int chances_left = guess_count;
  int bout_count = 0, prevailed_bout_count = 0;
  while(true)
  {
    cout << endl;
    actual_price = InitializeBout();
    if(PlayBout(actual_price, lower_price, higher_price, chances_left))
      prevailed_bout_count++;
    bout_count++;
    if(!Again())
      break;
  }
  return (double)prevailed_bout_count / (double)bout_count;
}

void PrintGameOverInfo(double prevailed_ratio)
{
  cout << "\nprevailed ratio: " << setw(3) << prevailed_ratio * 100 << "%.\n";
  if(prevailed_ratio >= 0.75)
    cout << "You luckyyyyyyyyyyyyy!\n\n";
  else if(prevailed_ratio >= 0.50)
    cout << "So gooooooood.\n\n";
  else
    cout << "You can do it better. Wish you luck.\n\n";
}

static int InitializeBout()
{
  return GenerateRandomNumber(lowest_price, highest_price);
}

static bool PlayBout(int actual_price, int lower_price, int higher_price, int chances_left)
{
  int guess_price;
  int judge_result;
  while(chances_left > 0){
    guess_price = GetPrice(lower_price, higher_price, chances_left);
    guess_price = CheckPrice(lower_price, higher_price, guess_price);
    chances_left--;
    judge_result = JudgePrice(actual_price, guess_price);
    switch(judge_result){
    case 1:
      if(chances_left > 0){  cout << "\nHigher.\n";  higher_price = guess_price - 1;   }
      else{  cout << "\nYou lose this bout. The actual price is " << actual_price << endl;  return false;  }
      break;
    case -1:
      if(chances_left > 0){  cout << "\nLower.\n";  lower_price = guess_price + 1;  }
      else{  cout << "\nYou lose this bout. The actual price is " << actual_price << endl;  return false;  }
      break;
    default:   cout << "\nYou winnnnnnnnnnnnnnnn!\n";  return true;
    }
  }
  return false;
}

static bool Again()
{
  int t;
  cout << "\nPlay a new game (\"0\" to stop, other numbers to play again)? ";
  cin >> t;
  return t != 0;
}

static int GetPrice( int lower_price, int higher_price, int chances_left )
{
  int t;
  cout << "The actual price is in [" << lower_price << ", " << higher_price << "]. ";
  cout << "Chances left " << chances_left << ".\nYou guess: ";
  cin >> t;
  return t;
}

static int CheckPrice(  int lower_price, int higher_price, int guess_price )
{
  int t = guess_price;
  while( t < lower_price || t > higher_price )
  {
    cout << "Guess price " << t << " is out of the range. ";
    cout << "Please choose one in [" << lower_price << ", " << higher_price
      << "].\nTry again: ";
    cin >> t;
  }
  return t;
}

static int JudgePrice( int actual_price, int guess_price )
{
  int t = guess_price - actual_price;
  if(t > 0)  return 1;  else if(t < 0)  return -1;  else  return 0;
}

