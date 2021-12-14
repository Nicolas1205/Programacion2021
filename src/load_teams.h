#include "./teams.h"
#include <map>
#include <string>
#include <vector>

#ifndef LOAD_TEAMS
#define LOAD_TEAMS

Team load_team(std::vector<Team> &teams, std::map<int, bool> &teams_numbers);

#endif
