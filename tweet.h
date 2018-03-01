#ifndef TWEET_H
#define TWEET_H

using namespace std;
#include "dsstring.h"

class tweet
{
private:
    double score;
    int posFreq;
    int negFreq;
    int sumFreq;
    String strTweet;

public:
    tweet();
    tweet(String);
    tweet(String, double);
    tweet(double, int, int, int, String);
    tweet(const tweet&);
    ~tweet();
    void addPos();
    void addNeg();
    double getScore();
    int getPos();
    int getNeg();
    int getSum();
    String getStrWord();
};

#endif // TWEET_H
