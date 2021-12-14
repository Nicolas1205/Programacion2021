#include "./list_players.h"
#include "./teams.h"
#include <algorithm>
#include <iostream>
#include <vector>

void show_players(Team team) {
  std::cout << "Numero de Equipo: " << team.team_number << '\n';
  for (int i = 0; i < team.players.size(); i++) {
    std::cout << "Nombre del Jugador: " << team.players[i].name << '\n';
  }
}

void list_players(std::vector<Team> &teams) {
  for_each(teams.begin(), teams.end(), show_players);
}
