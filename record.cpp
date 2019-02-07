//
//  record.cpp
//

#include "record.h"

#include <string>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

// default constructor for record which takes no values as the parameter
record::record() : scores() {
   
}
// record constructor that takes data member of type double as a prameter
// and adds this value to the scores container.
record::record(double x) : scores() {
    // add value x to the scores deque.
    scores.push_back(x);
}

 // member function records a new score for the player.
void record::add_score(double score) {
     // new score added to the deque
    scores.push_back(score);
}

// member fuction returns the best score ever added to the record
double record::best_score() const {
   // create data member size representing amount of scores.
    unsigned const size = scores.size();
    // if no scores have been added to the record then return 0
    if (size == 0) {
        return 0;
    }
    // data member that will hold the best score.
    double best = 0.0;
    // define an iterator to go through the deque which has scores
    typedef deque<double>::const_iterator iter;
    // iterate through each score
    for (iter t = scores.cbegin(); t != scores.cend(); ++t) {
        // if the current score is greater than best,
        // current score becomes the best.
        if (*t > best) {
            best = *t;
        }
    }
    // return value of best.
    return best;
}

// member fuction returns the average of all scores added to the record.
double record::overall_average() const {
    // data member representing the number of scores.
    unsigned const size = scores.size();
    // if number of scores is 0, return overall_average
    // as 0.
    if (size == 0) {
        return 0;
    }
    // data member that will hold total of all scores
    double sum = 0.0;
    // define a const iterator for scores container
    typedef deque<double>::const_iterator iter;
    // iterate through each score in the deque
    for (iter t = scores.cbegin(); t != scores.cend(); ++t) {
        // sum current score to sum variable, so that
        // sum represents all scores totaled.
        sum += *t;
    }
    // return total of the scores divided by the amount of scores.
    return sum / size;
}

// member fuction returns the average of the last 10 scores added to the record.
double record::recent_average() const {
    // create data member of type int denoting the 10th index from last score
    unsigned int element = scores.size()- 10;
    // data member sum
    double sum = 0;
    // define const iterator
    typedef deque<double>::const_iterator iter;
    // find the 10th index from the last score
    iter q = find(scores.cbegin(), scores.cend(), scores[element]);
    
    // if no scores have been entered return 0.
    if (scores.size() == 0) {
        return 0;
    }
    // else if amount of scores entered are less than 10 return the overall average.
    else if (scores.size() < 10) {
        return overall_average();
    } else
    // iterate through from the 10th index back to the final score - always final 10
    for (q ; q != scores.cend(); ++q) {
        // total of all of the values
        sum += *q;
    }
    // return sum divided by 10.
    return sum / 10;
}

// member function returns whether fewer than 10 scores have been recorded.
bool record::novice() const {
    // if amount of scores are greater than 10 return false,
    // else return true.
    if (scores.size() > 10) {
        return false;
    } else
        return true;
}

