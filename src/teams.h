#include <string>
#include <vector>
#ifndef TEAMS
#define TEAMS

typedef struct SetResults {
  int number_set = 1;
  std::string winner;
  std::string looser;
  bool is_draw;
} SetResults;

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
  std::string name;
  std::string country;
  std::string team_captain;
  int olympic_medals;
  std::vector<Player> players;
  int points_won = 0;
} Team;

#endif

// 1 Juan Mendoza 05/06/1999 1, 2 Gisela López 01/09/1998 2. 
