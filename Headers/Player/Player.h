#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <irrlicht.h>
#include <Newton.h>

#include "../Platform/Snake.h"
#include "../Platform/Thread.h"

using namespace std;

namespace Players{

class Player{

	private:
		string _name;
		int _score;
		int _wins;
		int _numberGames;
		
		platform::Snake *_snake;
		platform::Thread *_thread;

		void createThread();

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
		
		void createSnake(irr::core::vector3df __initialPosition, irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW);
		platform::Snake* getSnake();

		bool operator==(Player &__player) const;
			
	};
};

#endif /*PLAYER_H_*/
