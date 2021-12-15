#include "load_teams.h"
#include "teams.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

const std::vector<std::string> messages = {
    "\nNumero del Equipo: ", "\nNombre del Equipo: ", "\nPais: ",
    "\nNombre Capitan del Equipo: ", "\nCantidad de Medallas Olimpicas: "};

int search_team_id(std::vector<Team> &teams, int id) {
  for (int i = 0; i < teams.size(); i++) {
    if (teams[i].team_number == id) {
      return i;
    }
  }
  return -1;
}

int get_team_id(std::vector<Team> &teams) {
  int id;
  std::cout << messages[0];
  std::cin >> id;
  while (search_team_id(teams, id) != -1) {
    std::cout << "\nEste equipo ya esta registrado!!\n";
    std::cout << messages[0];
    std::cin >> id;
  }
  return id;
}

bool comp_teams(Team a, Team b) {
  if (a.olympic_medals > b.olympic_medals)
    return 1;
  return 0;
}

std::vector<Team> load_team(std::vector<Team> teams) {

  int id = get_team_id(teams);

  std::cout << messages[1];
  std::string name;
  std::cin >> name;

  std::string country;
  std::cout << messages[2];
  std::cin >> country;

  std::string captain;
  std::cout << messages[3];
  std::cin >> captain;

  int medals;
  std::cout << messages[4];
  std::cin >> medals;

  Team new_team{id, name, country, captain, medals};
  teams.push_back(new_team);

  sort(teams.begin(), teams.end(), comp_teams);

  return teams;
}
