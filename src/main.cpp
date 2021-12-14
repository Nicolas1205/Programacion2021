#include "./exit.h"
#include "./list_players.h"
#include "./list_teams.h"
#include "./load_players.h"
#include "./load_teams.h"
#include "./play.h"
#include "./show_menus.h"

#include <algorithm>
#include <iostream>
#include <map>

int main() {
  int option;
  std::vector<Team> teams;
  std::pair<Team, Team> teams_playing;
  std::map<int, bool> teams_numbers;
  std::vector<int> v(10, 0);
  Results results;

  while (option != 6) {
    show_main_menu();
    std::cin >> option;
    switch (option) {
    case 1:
      load_team(teams, teams_numbers);
    case 2:
      // load_players(teams, search_team);
    case 3:
      // list_teams(teams);
    case 4:
      // list_players(teams);
    case 5:
      // teams_playing = select_teams(teams);
      // results = play(teams);
      // show_results(play(teams));
    case 6:
      // exit(results);
      break;
    }
  }
}
