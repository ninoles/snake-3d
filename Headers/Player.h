#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

using namespace std;

namespace Players{

class Player{

	private:
		string _name;
		int _score;
		int _wins;
		int _numberGames;
		
	public:
		
		Player(string __name,int __score, int __wins, int __numberGames);
		Player();
		
		void setName(string __name);
		string getName();
		
		void setScore(int __score);
		int getScore();
		
		void setWins(int __wins);
		int getWins();
		
		void setNumberGames(int __numberGames);
		int getNumberGames();
		
		bool operator==(Player &__player) const;
			
	};
};

#endif /*PLAYER_H_*/
