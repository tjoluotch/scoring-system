    //
    //  table.cpp
    //

    #include "table.h"
    #include "record.h"
   



    using namespace std;

    // default constructor for table takes no parameters
    table::table() {

    }

    // register the player's name and
    // add the 'score' member function to the record.
    void table::add_score(const string &name, double score) {
    // adding the players name and score to map pl_WScores.
    pl_WScores[name].add_score(score);
    }

    //return the total number of players in the table
    int table::num_players() const {
        // if 0 players have been recorded in the table return 0
        if (pl_WScores.size() == 0) {
            return 0;
        } else
        // return size of map pl_WScores, as the is equated the the amount of players
        // in the table.
        return pl_WScores.size();
    }

// member function that returns a boolean vaule regarding the highest of two vector pairs double elements.
bool sort_by_rec_avg(const pair<string, double> &a, const pair<string, double> &b) {
    return (a.second < b.second);
}

// member function that returns the names of the n players with the highest
// recent averages, in order with the highest first
    vector<std::string> table::print_best_recent(int n) const {
    
    // create a vector pair which contains names and associated best recent averages
    vector<pair<string, double>> namesWithBR;
    // create a vector which contains the player's names
    vector<string> names;
    
    //create a double data member temp to hold each player's recent average
    double temp = 0.0;
    // define a const ierator for the map containing the player's names
    // and their records.
    typedef map<string, record>::const_iterator iter;
     // iterate through each player and their record in the map
    for (iter p = pl_WScores.cbegin(); p != pl_WScores.cend(); ++p) {
        // if current player doesn't have any scores their recent average is 0.
        if (p->second.scores.size() == 0) {
            temp = 0;
        }
        // if current player's amount of scores are less than 10 then
        // take their overall average instead.
        if(p->second.scores.size() < 10){
            temp = p->second.overall_average();
        } else
        // get the current player's reecent average and store it in
        // temp data member.
        temp = p->second.recent_average();
        // add the current player's name and recent average to the vector pair container.
        namesWithBR.push_back(make_pair(p->first, temp));
    }
        // sort vector pair according to sort_by_rec_avg bool member function,
        // which sorts according to which recent average is greater.
        sort(namesWithBR.begin(), namesWithBR.end(), sort_by_rec_avg);
        // loop from 0 to the best recent amount wanted - n
        for (unsigned int i = 1; i < (n + 1); ++i) {
            // add current player's name from vector pair containing names with best recent average
            // to the names vector.
            names.push_back(namesWithBR[pl_WScores.size()-i].first);
        }
        // return the vector names.
        return names;
    }

// member function returns the average of the best scores of all the players
double table::average_best() const {
    // create data member that will hold the total of all of the players best scores.
    double totalOfHighScores = 0.0;
    // defiine an iterator for the map containing players names and their
    // respective records.
    typedef map<string, record>::const_iterator iter;
    // iterate through each player and their respective records
    for (iter p = pl_WScores.cbegin(); p != pl_WScores.cend(); ++p) {
        // sum each players best score value so that there is a total
        totalOfHighScores += p->second.best_score();
    }
    // data member containing the amount of players
    unsigned int size = pl_WScores.size();
    // return all of the players best scores divided by the amount of players.
    return totalOfHighScores / size ;
}

// member function that returns a boolean vaule regarding the highest of two vector pairs double elements
bool sort_by_avg (const pair<string, double> &a, const pair<string, double> &b) {
    return (a.second < b.second);
}

// member function returns the name of the player with the highest overall average
string table::best_overall() const {
    // create a vector pair which will hold the player's names
    // and their average scores.
    vector<pair<string, double>> namesWAvg;
    // create an empty data member of type string to eventually
    // hold the name of the player with the highest overall average
    string best = "";
    // create a data member which will hold the players average
    double temp = 0.0;
    // define an iterator for the map containing players names and their
    // respective records.
    typedef map<string, record>::const_iterator iter;
    // iterate through each player and their respective records
    for (iter p = pl_WScores.cbegin(); p != pl_WScores.cend(); ++p) {
        // hold the current player's overall average in temp
        temp = p->second.overall_average();
        // add the current player's name and their overall average to the vector pair
        namesWAvg.push_back(make_pair(p->first, temp));
    }
    // sort the vector pair according to boolean member fucntion sortbyavg
    sort(namesWAvg.begin(), namesWAvg.end(), sort_by_avg);
    // place the name of the player who's at the 0 index into data member best.
    best = namesWAvg[pl_WScores.size()-1].first;
    
    // return the player's name who is in the data member best.
    return best;
}

// member function used as boolean condition to check if the current player's record
// makes him a novice.
// Takes pair of string and record as a parameter so that it matches the map pl_WScores
// which is made up of the string type as the key, and record type as the value.
bool noviceForTable(pair<string, record> p) {
    // return whether the current player matches the novice method in record.
    return p.second.novice();
}

// member function returns the number of novice players - players with less than 10 scores
int table::novice_count() const {
    // use the count if algorithm to increment if the player's record fulfills the noviceForTable
    // boolean member function.
    // return this value.
    return count_if(pl_WScores.cbegin(),pl_WScores.cend() , noviceForTable);
}


