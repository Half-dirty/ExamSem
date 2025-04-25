#include "databasedestroyer.h"
#include "database.h"

DatabaseDestroyer::~DatabaseDestroyer()
{
    delete databasePointer;
}

void DatabaseDestroyer::initialize(Database* p)
{
    databasePointer = p;
}
