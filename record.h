//
//  record.h
//

#ifndef record_h
#define record_h

#include <string>
#include <deque>
#include <iostream>
#include <algorithm>

class record {
public:
    std::deque<double> scores; 
    // deque container holding scores
    
public:
    // default record constructor
    record();
    //record constructor with parameter taking one score
    record(double score);
    
    // member function records a new score for the player
    void add_score(double score);
    
    // member fuction returns the best score ever added to the record
    double best_score() const;
    
    // member fuction returns the average of all scores added to the record
    double overall_average() const;
    
    // member fuction returns the average of the last 10 scores added to the record
    double recent_average() const;
    
    // member function returns whether fewer than 10 scores have been recorded
    bool novice() const;
        
};

#endif /* record_h */
