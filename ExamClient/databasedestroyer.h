#ifndef DATABASEDESTROYER_H
#define DATABASEDESTROYER_H

class Database;

class DatabaseDestroyer
{
public:
    DatabaseDestroyer() : databasePointer(nullptr) {}
    ~DatabaseDestroyer();
    void initialize(Database* p);

private:
    Database* databasePointer;
};

#endif // DATABASEDESTROYER_H
