#include "notebook.h"
#include "notebookitem.h"

Notebook::Notebook()
{
    _items = *new vector<NotebookItem>();
    _incrementId = 0;
}

Notebook::~Notebook()
{
    _items.clear();
}

NotebookItem Notebook::getItem(int id)
{
    NotebookItem result;
    for (auto item: _items)
    {
        if (item.getId() == id)
        {
            result = createItemCopy(item);
            break;
        }
    }
    return result;
}

vector<NotebookItem> Notebook::getItems()
{
    auto items = *new vector<NotebookItem>();
    for (size_t i = 0; i < _items.size(); i++)
    {
        auto item = _items.at(i);
        auto itemCopy = createItemCopy(item);
        items.push_back(itemCopy);
    }
    return items;
}

void Notebook::updateItem(NotebookItem &item)
{
    bool isUpdated = false;

    auto id = item.getId();
    if (id > 0)
    {
        // Try to find exists record by id
        for (size_t i = 0; i < _items.size(); i++)
        {
            auto entity = _items.at(i);
            if (entity.getId() == id)
            {
                entity.merge(item);
                isUpdated = true;
                break;
            }
        }
    }

    // Insert record
    if (isUpdated)
    {
        return;
    }

    auto copyItem = createItemCopy(item);
    auto newId = ++_incrementId;
    copyItem.setId(newId);
    _items.push_back(copyItem);

    item.setId(newId);
}

void Notebook::deleteItem(int id)
{
    for (size_t i = 0; i < _items.size(); i++)
    {
        NotebookItem item = _items.at(i);
        if (item.getId() == id)
        {
            _items.erase(_items.begin() + static_cast<long>(i));
            break;
        }
    }
}

size_t Notebook::getCount()
{
    return _items.size();
}

string Notebook::getVersion()
{
    return "1.0";
}

NotebookItem Notebook::createItemCopy(NotebookItem item)
{
    NotebookItem result = *new NotebookItem();
    result.setId(item.getId());
    result.setName(item.getName());
    return result;
}
