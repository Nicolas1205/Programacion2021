#include "./teams.h"
#include <map>
#include <string>
#include <vector>

#ifndef LOAD_PLAYERS

#define LOAD_PLAYERS

void load_player(std::vector<Team> &teams,
                 std::vector<std::pair<int, Player>> &players_ids);

#endif
