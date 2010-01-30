#include "../../Headers/Player/Player.h"

using namespace Players;
using namespace platform;

Player::Player(string __name,int __score, int __wins, int __numberGames){
	_name = __name;
	_score = __score;
	_wins = __wins;
	_numberGames = __numberGames;
	_snake = new Snake();
	_thread = new ThreadSnake();
}

Player::Player(){
	_name = "";
	_score = -1;
	_wins = -1;
	_numberGames = -1;
	_snake = new Snake();
	_thread = new ThreadSnake();
}

void Player::setName(string __name){
	_name = __name;
}

void Player::setNumberGames(int __numberGames){
	_numberGames += __numberGames;
}

void Player::setWins(int __wins){
	_wins += __wins;
}

void Player::setScore(int __score){
	_score += __score;
}

string Player::getName(){
	return _name;
}

int Player::getNumberGames(){
	return _numberGames;
}

int Player::getWins(){
	return _wins;
}

int Player::getScore(){
	return _score;
}

void Player::createSnake(irr::core::vector3df __initialPosition, irr::scene::ISceneManager *__sceneManager, NewtonWorld *__newtonW){
	_snake->createSnake(__initialPosition, __sceneManager, __newtonW);
	createThread();
}

void Player::createThread(){
	_thread->createThread(_snake);
}

platform::Snake* Player::getSnake(){
	return _snake;
}

bool Player::operator ==(Player& __player) const{
	return _name == __player.getName();
}



