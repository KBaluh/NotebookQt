#include "notebookitem.h"

NotebookItem::NotebookItem()
{

}

NotebookItem::~NotebookItem()
{
}

int NotebookItem::getId()
{
    return _id;
}

void NotebookItem::setId(int id)
{
    _id = id;
}

string NotebookItem::getName()
{
    return _name;
}

void NotebookItem::setName(string name)
{
    _name = name;
}

void NotebookItem::merge(NotebookItem item)
{
    setId(item.getId());
    setName(item.getName());
}
