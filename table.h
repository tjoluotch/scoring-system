//
//  table.h
//

#ifndef table_h
#define table_h

#include "record.h"

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>

// hold a table of information concerning players and their respective records.
class table {
   
public:
    // associative container has key of type string to represent players name,
    // record as value to represent that player's respective scores
    std::map<std::string, record> pl_WScores;
    
    // default table constructor - initialises the table object with no parameters
    explicit table();
    
    // member function to add a new score for the named player
    void add_score(const std::string &name, double score);
    
    // member function that returns the total number of players for whom a score has been recorded.
    int num_players() const;
    
    // member function that returns the names of the n players with the highest recent averages, in order with the highest first
    std::vector<std::string> print_best_recent(int n) const;
    
    // member function returns the average of the best scores of all the players
    double average_best() const;
    
    // member function returns the name of the player with the highest overall average
    std::string best_overall() const;
    
    // member function returns the number of novice players - players with less than 10 scores
    int novice_count() const;
    
};

#endif /* table_h */
