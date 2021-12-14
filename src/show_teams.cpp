#include "./show_teams.h"
#include <algorithm>
#include <iostream>

void show_teams_names(Team team) { std::cout << team.olympic_medals << '\n'; }

void show_teams(std::vector<Team> teams) {
  for_each(teams.begin(), teams.begin(), show_teams_names);
}
