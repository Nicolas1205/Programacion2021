#include "./list_players.h"
#include "./teams.h"
#include <algorithm>
#include <iostream>
#include <vector>

bool comp(std::pair<int, Player> a, std::pair<int, Player> b) {
  if (a.first > b.first)
    return 1;
  return 0;
}

void show_players(std::pair<int, Player> player) {
  std::cout << "******* Jugadores Ordenados Por Id *********\n";
  std::cout << "Id: " << player.second.player_number << '\n';
  std::cout << "Nombre: " << player.second.name << '\n';
  std::cout << "Apellido: " << player.second.last_name << '\n';
  std::cout << "Fecha de Nacimiento: " << player.second.birth << '\n';
  std::cout << "Numero de Equipo: " << player.second.team_number << '\n';
  std::cout << "*****************************************\n";
}

void list_players(std::vector<std::pair<int, Player>> players_ids) {

  sort(players_ids.begin(), players_ids.end(), comp);
  for_each(players_ids.begin(), players_ids.end(), show_players);
}
