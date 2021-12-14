#include "./teams.h"
#include <map>
#include <string>
#include <vector>

#ifndef LOAD_TEAMS
#define LOAD_TEAMS

int search_team_id(std::vector<Team> &teams, int id);
int get_team_id(std::vector<Team> &teams);

std::string get_team_country();

std::string get_team_captain();

int get_medals();

std::vector<Team> load_team(std::vector<Team> teams);

#endif
