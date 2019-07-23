#include <iostream>
#include "notebook.h"

using namespace std;

int main()
{
    cout << "Initializing Notebook.." << endl;
    Notebook notebook = *new Notebook();
    cout << "\t- Notebook v"<< notebook.getVersion() << endl;

    NotebookItem helloItem = *new NotebookItem();
    helloItem.setName("Hello Nootebok!");
    notebook.updateItem(helloItem);

    auto secondItem = *new NotebookItem();
    secondItem.setName("Second item");
    notebook.updateItem(secondItem);
    secondItem.setName("Second item v2");
    notebook.updateItem(secondItem);
    auto secondItemId = secondItem.getId();

    NotebookItem thirdItem;
    thirdItem.setName("Have a nice day!");
    notebook.updateItem(thirdItem);

    notebook.deleteItem(secondItemId);
    cout << "\t- Notebook items count: " << notebook.getCount() << endl << endl;

    auto items = notebook.getItems();

    cout << "Notebook items" << endl;
    cout << "id" << "\tname" << endl;
    cout << "--" << "\t----" << endl;
    for (auto item: items)
    {
        cout << item.getId() << "\t" << item.getName() << endl;
    }
    return 0;
}
