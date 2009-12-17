#include "../Headers/Base/Frame.h"
#include "../Headers/FilesMan/ConfScore.h"
#include "../Headers/FilesMan/ConfFrame.h"
#include "../Headers/Platform/GUIManagement.h"
#include "../Headers/Platform/Game.h"
#include "../Headers/Player/GroupPlayers.h"

#include <iostream>

using namespace base;
using namespace file;
using namespace std;

int main() {

	base::Frame *frame = new Frame(800, 600, 32, false, false,false, false);

	Players::GroupPlayers group;
	file::ConfScore *conf = new ConfScore(frame->getDevice());
	file::ConfFrame *conf_1 = new ConfFrame(frame->getDevice());

	conf_1->setArchiveWrite("conf/config_video.xml");
	conf_1->writeConfigurations(L"800", L"600", L"32", L"0", L"0", L"0", L"0");

	Players::Player player;
	player.setName("Henrique");
	player.setNumberGames(10);
	player.setScore(30);
	player.setWins(40);

	Players::Player player_2;
	player_2.setName("Carlos");
	player_2.setNumberGames(60);
	player_2.setScore(2);
	player_2.setWins(70);

	//Write players into xml
	conf->setArchiveWrite("conf/config_players.xml");
	conf->writePlayer(player);
	conf->writePlayer(player_2);
	conf->closeXML();

	//Read players and insert into arrayList of players
	conf->setArchiveRead("conf/config_players.xml");
	group.addPlayer(conf->readPlayer());
	group.addPlayer(conf->readPlayer());

	std::cout << "Nome: " << group.getAllPlayers()->get(0).getName() << std::endl;
	std::cout << "Score: " << group.getAllPlayers()->get(0).getScore() << std::endl;
	std::cout << "Jogos: " << group.getAllPlayers()->get(0).getNumberGames() << std::endl;
	std::cout << "Vitorias: " << group.getAllPlayers()->get(0).getWins() << std::endl;

	std::cout << "Nome: " << group.getAllPlayers()->get(1).getName() << std::endl;
	std::cout << "Score: " << group.getAllPlayers()->get(1).getScore() << std::endl;
	std::cout << "Jogos: " << group.getAllPlayers()->get(1).getNumberGames() << std::endl;
	std::cout << "Vitorias: " << group.getAllPlayers()->get(1).getWins() << std::endl;

}
