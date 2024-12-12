#include "inmemoryDB.h"

inmemoryDB::inmemoryDB() {

    this->transaction = false;
    this->committed = false;

}

void inmemoryDB::put(string key, int val) {

    if (transaction == false) {
        cout << "No Transaction in Progress" << endl;
        return;
    } else {
        values[key].second = values[key].first;
        values[key].first = val;
        cout << "Put Successful" << endl;
        return;
    }
}

int inmemoryDB::get(string key)
{

    if (values.find(key) == values.end()) {
        cout << "Key does not exist." << endl;
        return 0;
    } else if (committed == false) {
        return 0;
    } else {
        return values[key].first;
    }

    return 0;
}

void inmemoryDB::begin_transaction()
{

    this->committed = false;
    this->transaction = true;

}

void inmemoryDB::commit() {

    this->committed = true;
    this->transaction = false;

}

void inmemoryDB::rollback() {

    if (transaction == true) {
        map<string, pair<int, int>>::iterator it;

        for (it = values.begin(); it != values.end(); it++) {
            it->second.first = it->second.second;
        }
    } else {
        cout << "No transaction in progress" << endl;
    }
}
