#include "tweet.h"
#include <iostream>

using namespace std;

tweet::tweet()
{
    score = 0;
    posFreq = 0;
    negFreq = 0;
    sumFreq = 0;
    strTweet = nullptr;
}

tweet::tweet(String sTweet)
{
    strTweet = sTweet;
    score = 0;
    sumFreq = 0;
    posFreq = 0;
    negFreq = 0;
}

tweet::tweet(String sTweet, double wScore)
{
    strTweet = sTweet;
    score = wScore;
    sumFreq = 0;
    posFreq = 0;
    negFreq = 0;
}

tweet::tweet(double wScore, int sFreq, int gFreq, int bFreq, String sTweet)
{
    score = wScore;
    sumFreq = sFreq;
    posFreq = gFreq;
    negFreq = bFreq;
}

tweet::tweet(const tweet& tweets)
{
    score = tweets.score;
    sumFreq = tweets.sumFreq;
    posFreq = tweets.posFreq;
    negFreq = tweets.negFreq;
    strTweet = tweets.strTweet;
}

tweet::~tweet()
{

}

void tweet::addPos()
{
    sumFreq = sumFreq + 1;
    posFreq = posFreq + 1;
}

void tweet::addNeg()
{
    sumFreq = sumFreq + 1;
    negFreq = negFreq + 1;
}

double tweet::getScore()
{
    if (score==0)
        score = (double)(posFreq - negFreq) / (dobule)sumFreq;
    return score;
}

int tweet::getPos()
{
    return posFreq;
}

int tweet::getNeg()
{
    return negFreq;
}

int tweet::getSum()
{
    return sumFreq;
}

String tweet::getStrWord()
{
    return strword;
}

