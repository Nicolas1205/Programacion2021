#include "./load_teams.h"
#include "./teams.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

const std::vector<std::string> messages = {
    "\nNumero de Jugador: ", "\nNombre: ",           "\nApellido: ",
    "\nNacimiento: ",        "\nNumero de Equipo: ", "\nPosicion: "};

int seach_player_id(std::vector<int> &players_ids, int id) {
  for (int i = 0; i < players_ids.size(); i++) {
    if (players_ids[i] == id)
      return i;
  }
  return -1;
}

int get_id(std::vector<int> &players_ids) {
  int id;
  std::cout << messages[0];
  std::cin >> id;

  while (seach_player_id(players_ids, id) != -1) {
    std::cout << "Numero de jugador ya existe\n";
    std::cout << messages[0];
    std::cin >> id;
  }
  return id;
}

std::string get_birth() {
  // TODO: Make  a regex for this
  std::string birth;
  while (!birth.empty()) {
    std::cout << messages[3];
    std::cin >> birth;
  }
  return birth;
}

std::pair<int, int> get_teams_id(std::vector<Team> teams) {
  int id, pos;
  std::cout << messages[4];
  std::cin >> id;
  while (search_team_id(teams, id) == -1) {
    std::cout << "No hay un equipo con este id\n";
    std::cout << messages[4];
    std::cin >> id;
  }
  pos = search_team_id(teams, id);
  return {id, pos};
}

void load_player(std::vector<Team> &teams, std::vector<int> &players_ids) {

  int id = get_id(players_ids);

  std::cout << messages[1];
  std::string name;
  std::cin >> name;

  std::cout << messages[2];
  std::string last_name;
  std::cin >> last_name;

  std::cout << messages[3];
  std::string birth;
  std::cin >> birth;

  std::cout << messages[5];
  std::string position;
  std::cin >> position;

  auto [team_id, pos] = get_teams_id(teams);

  Player new_player{
      id, name, last_name, birth, position, team_id,
  };

  teams[pos].players.push_back(new_player);
  players_ids.push_back(id);
}
