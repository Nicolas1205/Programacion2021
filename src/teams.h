#include <string>
#include <vector>
#ifndef TEAMS
#define TEAMS

typedef struct Player {
  int player_number;
  std::string name;
  std::string last_name;
  std::string birth;
  std::string position;
  int team_number;
} Player;

typedef struct Team {
  int team_number;
  std::string country;
  std::string team_captain;
  int olympic_medals;
  std::vector<Player> players;
} Team;

#endif

// 1 Juan Mendoza 05/06/1999 1, 2 Gisela López 01/09/1998 2. 
