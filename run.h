#ifndef RUN_H
#define RUN_H

#include <fstream>
#include <iostream>
#include "dsstring.h"
#include "dsvector.h"
#include "tweet.h"
using namespace std;

class Run
{
private:
    void runTweets(char * argv[], Vector<tweet>&);
    void printFile(char * argv[], Vector<tweet>&);
    void addVector(Vector<tweet>&, Vector<String>&, int);
    void log(char * argv[], Vector<tweet>&);
    void estimate(char * argv[], Vector<tweet>&);
    double sumScore(Vector<tweet>&, Vector<String>&);
public:
    Run();
    void runTrainingTweets(char * argv[]);
    void runDefine(char * argv[]);
};

#endif // RUN_H
