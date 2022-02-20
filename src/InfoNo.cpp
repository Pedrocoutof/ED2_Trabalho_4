#include "InfoNo.h"

InfoNo::InfoNo()
{
    review_id = "";
    posID = -1;
}

InfoNo::~InfoNo() {}

InfoNo::InfoNo(string review_id, int posID)
{
    this->review_id = review_id;
    this->posID = posID;
}
