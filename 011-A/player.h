#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Person {
protected:
    string name, surname;
public:
    Person(const string& n, const string& s);
    virtual ~Person();
    string getFullName() const;
};

class Player : public Person {
private:
    int number;
    float pointsPerGame, reboundsPerGame, assistsPerGame;
    static int totalPlayers;
public:
    Player(const string& n, const string& s, int num, float ppg, float rpg, float apg);
    ~Player();
    void print() const;
    float getPointsPerGame() const;
    static int getTotalPlayers();
};

int readPlayersFromFile(vector<Player>& players, const string& filename);
Player bestScorer(const vector<Player>& players);

#endif // PLAYER_H
