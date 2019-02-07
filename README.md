## Scoring System C++

### Description
Implementation of a Scoring system in C++. Receives reports of new scores for players and then ranks players and/or scores according to a variety of measures.

### C++ Std Libraries used
- string
- deque
- iostream
- algorithm

Demonstrated usage of pointer referencing and dereferencing, iterators and algorithms in C++.

## Class Record
### Constructors
#### `record()` set up an empty record (default constructor).
#### `record(double x)` set up a record with one score.
### Methods
#### `void add score(double score)` record a new score for the player.
#### `double best score() const` returns the best score ever added to the record (or 0 if none).
#### `double overall average() const` returns the average of all scores added to the record (or 0 if none)
#### `double recent average() const` returns the average of the last 10 scores added to the record (or 0 if none)
#### `bool novice() const` return whether fewer than 10 scores have been recorded.

## Class Table
### Constructors
#### `table()` set up an empty table (default constructor).
### Methods
#### `void add score(const string &name, double score)` adds a new score for the named player
#### `int num players() const` returns the total number of players for whom a score has been recorded.
#### `vector<string> print best recent(int n) const` returns the names of the n players with the highest recent averages, in order with the highest first.
#### `double average best() const` returns the average of the best scores of all players.
#### `string best overall() const` returns the name of the player with the highest overall average.
#### `int novice count() const` returns the number of novice players. Your implementation should use a library algorithm.
