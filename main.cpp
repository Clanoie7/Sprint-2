#include <iostream>
#include <cstring>
#include <fstream>

#include "catch.h"
#include "dsstring.h"
#include "dsvector.h"
#include "run.h"
#include "tweet.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc >1&&strcmp(argv[1], "-t") == 0)
    {
        return Catch::Session().run();
    }
    else if (argc > 1 && strcmp(argv[1]), "-c" == 0)
    {
        Run test;
        test.runDefine(argv);
    }
    else
    {
        cout<<"Error. Incorrect flag, check again" <<endl;
        return 1;
    }
    return 0;
}
