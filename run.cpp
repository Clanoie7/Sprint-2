#include "run.h"

Run::Run()
{

}

void Run::runTrainingTweets(char * argv[])
{
    Vector<tweet> tweets;
    runTweets(argv, tweets);
    printFile(argv, tweets);
}

void Run::runDefine(char *argv[])
{
    Vector<tweet> showResults;
    log(argv, showResults);
    estimate(argv, showResults);
}

void Run::runTweets(char * argv[], Vector<tweet>& tweets)
{
    ifstream tweetData;
    tweetData.open(argv[2]);
    ifstream tweetTar;
    tweetTar.open(argv[3]);
    int counter = 0;
    int counterMax = 10000;

    int tweetNum;
    unsigned int tweetID;
    int tweetType;
    String user;
    String Message;
    char messageArr[2000];
    char byPass;
    tweetData.ignore(256, '\n');
    tweetTar.ignore(256, '\n');

    while (counter < counterMax)
    {
        tweetData>>tweetNum>>byPass>>tweetClass>>byPass>>tweetID;
        for(int i = 0; i != 3; i++)
            tweetData.getline(messageArr, 2000, ',');
        tweetData.getline(messageArr, 2000);
        Message = messageArr;
        Message.lower();
        Vector<String> sortedString;
        Message.dissect(' ', sortedString);
        addVector(tweets, sortedString, tweetType);
        counter++;
    }
    tweetData.close();
    tweetTar.close();
}

void Run::addVector(Vector<tweet> & tweets, Vector<String> & strings, int tweetType)
{
    bool redo;
    for(int i = 0; i<strings.getSize(); i++)
    {
        redo = false;
        for(int m = 0; m < tweets.getSize(); i++)
        {
            if(strings[i] == tweets[j].getStrWord(); i++)
            {
                if(tweetType==4)
                    words[m].addPos();
                else
                    tweets[m].addNeg();
                redo = true;
            }
        }
        if (redo == false)
        {
            tweet c = strings[i];
            if(tweetType==4)
                c.addPos();
            else
                c.addNeg();
            tweets.addToEnd(c);
        }
    }
}

void Run::printFile(char *argv[], Vector<tweet> & tweets)
{
    ofstream wordBank;
    wordBank.open(argv[4]);
    int sum;
    double score;
    for(int i = 0; i < tweets.getSize(); i++)
    {
        sum = tweets[i].getSum();
        score = tweets[i].getScore();
        if (total > 5 && (score < -.5 || score > .5))
            wordBank << tweets[i].getStrWord() << "," <<words[i].getPositive()<< "," << words[i].getNegative()<< "," << total<< "," << wordScore << endl;
    }
    log.close();
}

void Run::log(char * argv[], Vector<tweet>& showResults)
{
    ifstream resultsFile;
    resultsFile.open(argv[3]);
    char textArr [1000];
    String charLine;
    String strWord;
    int counter = 0;
    while (!resultsFile.eof())
    {
        resultsFile.getline(textArr, 1000);
        if(textArr[0] == '\0')
        {
            break;
        }
        charLine = textArr;
        Vector<String> vectorLine;
        charLine.dissect(',', vectorLine);
        strWord = vectorLine[0];
        score = atof(vectorLine[4].cStr());
        tweet c(strWord, score);
        showResults.addToEnd(c);
        counter++;
    }
    resultsFile.close();
}

void Run::estimate(char *argv[], Vector<tweet>& resultsOutput)
{
    ifstream tweetInfo;
    tweetInfo.open(argv[2]);
    ofstream result;
    result.open(argv[4]);
    int tweetNum;
    unsigned int tweetID;
    int tweetType;
    String user;
    String Message;
    char messageArr[2000];
    char byPass;
    double score;

    tweetInfo.ignore(265,'\n');
    while(!tweetInfo.eof())
    {
        tweetInfo>>tweetNum>>byPass>>tweetID>>byPass;
        tweetInfo.getline(messageArr, 2000, ',');
        tweetInfo.getline(messageArr, 2000);
        Message = messageArr;
        Message.lower();
        Vector<String> sortedString;
        Message.dissect(' ', sortedString);
        score = sumScore(resultsOutput, sortedString);
        if (score > 0)
            output << tweetID << ", 4" <<endl;
        else if (score != 0)
            output << tweetID << ", 0" <<endl;
        else
            output << tweetID << ", 4" << endl;
    }
    tweetInfo.close();
    output.close();
}

double Run::sumScore(Vector<tweet>& classifyVec, Vector<String>& stringVec)
{
    int stringVecS = stringVec.getSize();
    int classifyVecS = classifyVec.getSize();
    double score = 0;
    for(int n = 0; n < classifyVecS; n++)
    {
        for(int m = 0; m < stringVecS; m++)
        {
            if(classifyVec[n].getStrWord() == stringVec[i])
                score += classifyVec[j].getSum();
        }
    }
    return score;
}


