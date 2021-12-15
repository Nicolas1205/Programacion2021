#include "./play.h"
#include "./load_teams.h"
#include "./teams.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

const int TOTAL_SETS = 3;

std::vector<Team> select_teams(std::vector<Team> &teams) {
  std::vector<Team> teams_playing(2);
  for (int i = 0; i < 2; i++) {
    bool selected = 0;
    while (!selected) {
      std::cout << "Seleccione el id del equipo " << i + 1 << '\n';
      int id, pos;
      std::cin >> id;
      pos = search_team_id(teams, id);
      if (pos != -1) {
        teams_playing[i] = teams[pos];
        selected = 1;
        continue;
      }
      std::cout << "Este id no existe\n";
    }
  }
  return teams_playing;
}

SetResults play_set(std::vector<Team> &teams_playing, int number_set) {
  srand(time(NULL));
  std::cout << "******** Se esta Jugando el Set " << number_set + 1
            << "********\n";

  int turn_of = 0;

  while (teams_playing[0].points_won < 25 ||
         teams_playing[1].points_won < 25) { // Empieza el Set
    int points_won = rand() % 10;
    teams_playing[turn_of].points_won += points_won;
    if (!points_won) {
      std::cout << "El equipo " << teams_playing[turn_of].name
                << " no ha ganado puntos\n";
    } else {
      std::cout << "El equipo " << teams_playing[turn_of].name << " ha ganado "
                << points_won << '\n';
    }
    turn_of = turn_of == 0 ? 1 : 0;
  }

  // Resultados
  auto [winner, looser] =
      teams_playing[0].points_won > teams_playing[1].points_won
          ? std::make_pair(teams_playing[0].name, teams_playing[1].name)
          : std::make_pair(teams_playing[1].name, teams_playing[0].name);

  bool is_draw =
      teams_playing[0].points_won == teams_playing[1].points_won ? true : false;

  teams_playing[0].points_won = 0;
  teams_playing[1].points_won = 0;
  SetResults set_results{number_set, winner, looser, is_draw};

  return set_results;
}

void show_match_results(std::vector<SetResults> match_results) {
  for (int i = 0; i < TOTAL_SETS; i++) {
    std::cout << "************* RESULTADOS FINALES *************\n";
    std::cout << "************* SET " << i + 1 << " **************\n";
    if (!match_results[i].is_draw) {
      std::cout << "El ganador fue: " << match_results[i].winner << '\n';
      std::cout << "El perdedor fue: " << match_results[i].looser << '\n';
    } else {
      std::cout << "Fue un empate\n";
    }
  }
}

std::vector<SetResults> play(std::vector<Team> teams_playing) {
  std::vector<SetResults> match_results;
  // Empieza el juego
  for (int number_set = 0; number_set < TOTAL_SETS; number_set++) {
    SetResults set_results = play_set(teams_playing, number_set);
    match_results.push_back(set_results);
  }

  return match_results;
}
