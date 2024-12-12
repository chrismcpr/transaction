#include <iostream>
#include <map>
#include <utility>
using namespace std;

class inmemoryDB {

    private:
    bool transaction;
    bool committed;
    map<string, pair<int,int>> values;

    public:
    inmemoryDB();
    void put(string key, int val);
    int get(string key);
    void begin_transaction();
    void commit();
    void rollback();
};