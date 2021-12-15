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
  std::vector<Team> teams_playing(2);
  std::vector<std::pair<int, Player>> players_ids;
  std::vector<bool> options_loaded(5, false);

  while (option != 6) {
    show_main_menu();
    std::cin >> option;
    switch (option) {
    case 1:
      teams = load_team(teams);
      options_loaded[0] = true;
      break;
    case 2:
      if (options_loaded[0]) {
        load_player(teams, players_ids);
        options_loaded[1] = true;
      }
      break;
    case 3:
      if (teams.size() >= 2) {
        list_teams(teams);
        options_loaded[2] = true;
      }
      break;
    case 4:
      if (options_loaded[1]) {
        list_players(players_ids);
        options_loaded[3] = true;
      }
      break;
    case 5:
      // Todas las demas opciones cargadas
      if (std::any_of(options_loaded.begin(), options_loaded.end() - 1,
                      [](bool option) { return option; })) {
        teams_playing = select_teams(teams);
        std::vector<SetResults> results = play(teams_playing);
        show_match_results(results);
        options_loaded[4] = true;
      }

    case 6:
      if (options_loaded[4]) {
        show_teams(teams);
        break;
      }
      option = 0;
    }
  }
}
