#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <vector>
#include "notebookitem.h"

using namespace std;

class Notebook {
public:
    Notebook();
    ~Notebook();
    NotebookItem getItem(int id);
    vector<NotebookItem> getItems();
    void updateItem(NotebookItem &item);
    void deleteItem(int id);
    size_t getCount();
    string getVersion();
private:
    vector<NotebookItem> _items;
    int _incrementId;
    NotebookItem createItemCopy(NotebookItem item);
};

#endif // NOTEBOOK_H
