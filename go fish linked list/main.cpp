#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  Hand aliceHand, bobHand;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }
  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    string val = line;
  //  cout << val << endl;
    aliceHand.addCard(val);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    string val = line;
    //cout << val << endl;
    bobHand.addCard(val);
  }
  cardFile2.close();

  Hand active = aliceHand;
  Hand opponent = bobHand;
  string match = hasMatch(active, opponent);

  while(match != "NULL"){
    searchAndDestroy(active, opponent, match);
    if(active.getHead() == aliceHand.getHead()){
      cout << "Alice picked matching card " << match << '\n'; 
      active = bobHand;
      opponent = aliceHand;
    }else{
      cout << "Bob picked matching card " << match << '\n'; 
      active = aliceHand;
      opponent = bobHand;
    }
    match = hasMatch(active, opponent);
  }
  cout << "\nAlice's cards:\n";
  aliceHand.printHand();
  cout << "\nBob's cards:\n";
  bobHand.printHand();

  bobHand.clearHand();
  aliceHand.clearHand();
  return 0;
}
