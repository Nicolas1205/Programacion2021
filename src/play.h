#include "./teams.h"
#include <string>
#include <vector>

#ifndef PLAY
#define PLAY
typedef struct Results {
  std::string winner;
  std::vector<Player> *players;
  int total_points;
} Results;

std::vector<Team> select_teams(std::vector<Team> &teams);

void show_match_results(std::vector<SetResults> match_results);

std::vector<SetResults> play(std::vector<Team> teams_playing);

#endif
