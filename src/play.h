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

std::pair<Team, Team> select_teams(std::vector<Team> &teams);

Results play(std::pair<Team, Team> teams_playing);

#endif
