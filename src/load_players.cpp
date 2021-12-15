#include "./load_teams.h"
#include "./teams.h"
#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

const std::vector<std::string> messages = {
    "\nNumero de Jugador: ", "\nNombre: ",           "\nApellido: ",
    "\nNacimiento: ",        "\nNumero de Equipo: ", "\nPosicion: "};

bool comp_players(std::pair<int, Player> a, std::pair<int, Player> b) {
  if (a.first > b.first)
    return 1;
  return 0;
}

int seach_player_id(std::vector<std::pair<int, Player>> &players_ids, int id) {
  for (int i = 0; i < players_ids.size(); i++) {
    if (players_ids[i].first == id)
      return i;
  }
  return -1;
}

int get_id(std::vector<std::pair<int, Player>> &players_ids) {
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

std::string get_birth() {
  std::cout << messages[3];
  std::string birth;
  std::cin >> birth;
  std::regex birth_pattern(
      "^(1[0-2]|0[1-9])/(3[01]|[12][0-9]|0[1-9])/[0-9]{4}$");

  while (std::regex_match(birth, birth_pattern)) {
    std::cout << "El formato de entrada debe de ser mm/dd/yyyy\n";
    std::cout << messages[3];
    std::cin >> birth;
  }
  return birth;
}

std::string get_position() {
  std::cout << messages[5];
  std::string position;
  std::cin >> position;
  while (position != "titular") {
    std::cout
        << "El campo debe ser completado, ya sea con titular o suplente\n";
    std::cout << messages[5];
    std::cin >> position;
  }
  return position;
}

void load_player(std::vector<Team> &teams,
                 std::vector<std::pair<int, Player>> &players_ids) {

  int id = get_id(players_ids);

  std::cout << messages[1];
  std::string name;
  std::cin >> name;

  std::cout << messages[2];
  std::string last_name;
  std::cin >> last_name;

  std::string birth = get_birth();
  std::string position = get_position();

  auto [team_id, pos] = get_teams_id(teams);

  Player new_player{
      id, name, last_name, birth, position, team_id,
  };

  teams[pos].players.push_back(new_player);
  players_ids.push_back({id, new_player});
  sort(players_ids.begin(), players_ids.end(), comp_players);
}
