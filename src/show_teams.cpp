#include "./show_teams.h"
#include "./teams.h"
#include <algorithm>
#include <iostream>

void show_teams_names(Team team) { std::cout << team.name << '\n'; }

void show_teams(std::vector<Team> teams) {
  std::cout << "Gracias por participar: \n";
  for_each(teams.begin(), teams.begin(), show_teams_names);
}
