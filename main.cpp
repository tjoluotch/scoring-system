//
//  main.cpp
//
#include "record.h"
#include "table.h"

#include <iostream>
#include <deque>
#include <iomanip>
using namespace std;

void read_scores(istream &in, deque<double> &d){
    double x;
    while (in >> x) {
        d.push_back(x);
    }
}

void write_scores(ostream &out, const deque<double> &d){
    out << "scores:\n";
    typedef deque<double>::const_iterator iter;
    for (iter p = d.cbegin(); p != d.cend(); ++p) {
        out << *p << " ";
    }
   out << '\n';
}

int main() {
    record tj(11);
    tj.add_score(1.5);
    tj.add_score(6.1);
    tj.add_score(3);
    tj.add_score(9.2);
    tj.add_score(100.5);
    tj.add_score(33.2);
    tj.add_score(17.87);
    tj.add_score(67);
    tj.add_score(53);
    tj.add_score(42.68);
    tj.add_score(89);
    // 11 scores in record
    cout << "Has Tjay got fewer than 10 scores recorded: " << boolalpha << tj.novice() << '\n';
    cout << "the average of the last 10 scores is: " << tj.recent_average() << '\n'; // should print 33.405
    cout << "best score is: " << tj.best_score() << '\n';
    cout << "the average score is: " << tj.overall_average() << '\n'; //should print 31.368181 or 31.3682
    //read_scores(cin, tj.scores);
    write_scores(cout, tj.scores);
    //table test
    
    table t;
    string n = "Trevor";
    t.add_score(n, 34.5);
    t.add_score(n, 34.5);
    t.add_score(n, 34.5);
    t.add_score(n, 34.5);
    t.add_score(n, 34.5);
    t.add_score(n, 34.5);
    //should return recent_average = 39.25
    
    t.add_score("Jack", 23.3);
    t.add_score("Jack", 23.3);
    t.add_score("Jack", 23.3);
    t.add_score("Jack", 23.3);
    t.add_score("Jack", 23.3);
    t.add_score("Jack", 23.3);
    t.add_score("Jack", 23.3);
    t.add_score("Jack", 23.3);
    t.add_score("Jack", 23.3);
    t.add_score("Jack", 23.3);
    t.add_score("Jack", 23.3);
    t.add_score("Jack", 122.4);
    
    t.add_score("kim", 122.1);
    t.add_score("zhris", 11);
    
    t.num_players();
    
 
    t.print_best_recent(3);
    
    cout << "Average of the best scores by all players: " <<t.average_best() << '\n'; 
    
    t.best_overall();
    
    cout << "Amount of novices: " << t.novice_count() << '\n';
  
    return 0;
}
