#include "./teams.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

void show_teams(Team team) {
  std::cout << "******* Equipos *********\n";
  std::cout << team.name << '\n';
  std::cout << team.country << '\n';
  std::cout << team.team_number << '\n';
  std::cout << "Jugadores: \n";
  std::cout << "Capitan: " << team.team_captain << '\n';

  for (int i = 0; i < team.players.size(); i++) {
    std::cout << "Nombre: " << team.players[i].name << '\n';
  }
}

void list_teams(std::vector<Team> &teams) {
  for_each(teams.begin(), teams.end(), show_teams);
}
