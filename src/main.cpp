#include "./list_players.h"
#include "./list_teams.h"
#include "./load_players.h"
#include "./load_teams.h"
#include "./play.h"
#include "./show_menus.h"
#include "./show_teams.h"

#include <algorithm>
#include <iostream>
#include <map>

int main() {
  int option;
  std::vector<Team> teams;
  std::vector<Team> teams_playing;
  std::vector<int> players_ids;

  while (option != 6) {
    show_main_menu();
    std::cin >> option;
    switch (option) {
    case 1:
      teams = load_team(teams);
      break;
    case 2:
      load_player(teams, players_ids);
      break;
    case 3:
      list_teams(teams);
      break;
    case 4:
      list_players(teams);
      break;
    case 5:
      teams_playing = select_teams(teams);
      play(teams_playing);
      // show_results(play(teams));
    case 6:
      // show_teams(teams);
      break;
    }
  }
}
