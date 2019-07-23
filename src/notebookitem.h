#ifndef NOTEBOOKITEM_H
#define NOTEBOOKITEM_H

#include <string>

using namespace std;

class NotebookItem
{
public:
    NotebookItem();
    ~NotebookItem();

    int getId();
    void setId(int id);

    string getName();
    void setName(string name);

    void merge(NotebookItem item);
private:
    int _id;
    string _name;
};

#endif // NOTEBOOKITEM_H
