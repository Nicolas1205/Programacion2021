#include "load_teams.h"
#include "teams.h"
#include <iostream>
#include <map>
#include <vector>

const std::vector<std::string> messages = {
    "\nNumero del Equipo:", "\nPais: ", "\nNombre Capitan del Equipo: ",
    "\nCantidad de Medallas Olimpicas: "};

int get_team_number(std::map<int, bool> &teams_numbers) {
  int team_number = -1;
  while (!teams_numbers.at(team_number)) {
    std::cout << "\nEste equipo ya esta registrado!!\n";
    std::cout << messages[0];
    std::cin >> team_number;
  }
  teams_numbers.at(team_number) = true;
  return team_number;
}

std::string get_team_country() {
  std::string country;
  while (!country.empty()) {
    std::cout << messages[1];
    std::cin >> country;
  }
  return country;
}

std::string get_team_captain() {
  std::string team_captain;
  while (!team_captain.empty()) {
    std::cout << messages[2];
    std::cin >> team_captain;
  }
  return team_captain;
}

int get_medals() {
  int medals;
  while (medals < 0) {
    std::cout << messages[3];
    std::cin >> medals;
  }
  return medals;
}

Team load_team(std::vector<Team> &teams, std::map<int, bool> &teams_numbers) {

  Team new_team{
      get_team_number(teams_numbers),
      get_team_country(),
      get_team_captain(),
      get_medals(),
  };
  return new_team;
}
