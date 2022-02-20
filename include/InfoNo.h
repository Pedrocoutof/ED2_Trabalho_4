#ifndef INFONO_H
#define INFONO_H

#include <iostream>
using namespace std;
#include <string>


class InfoNo
{
    public:
        string review_id;
        int posID;

        InfoNo();
        InfoNo(string review_id, int posID);
        virtual ~InfoNo();

    private:
};

#endif // INFONO_H
