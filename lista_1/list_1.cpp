#include <iostream>
#include <string>
#include "FuncConsts.h"
#include "CTable.h"

void v_alloc_table_fill_34(int iSize)
{
    if (iSize <= 0)
    {
        std::cout << "Unvalid data \n";
        return;
    }

    int* table;
    table = new int[iSize];

    for (int i = 0; i < iSize; i++)
    {
        table[i] = TAB_FILL_34;
    }

    std::cout << "Content of the table: \n";

    for (int i = 0; i < iSize; i++)
    {
        std::cout << table[i] << ' ';
    }
    std::cout << "\n";

    delete table;
}

bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) 
{
    if (iSizeX <= 0 || iSizeY <= 0)
        return false;

    *piTable = new int * [iSizeX];
    for (int i = 0; i < iSizeX; i++)
    {
        (*piTable)[i] = new int [iSizeY];
    }
    return true;
}

bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) 
{
    if (iSizeX <= 0 || iSizeY <= 0) 
        return false;
        
    for (int i = 0; i < iSizeX; i++)
    {
        delete (*piTable)[i];
    }

    delete *piTable;
    return true;
}

// ta procedura faktycznie modyfikuje obiekt
void v_mod_tab(CTable* pcTab, int iNewSize)
{
    pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable pcTab, int iNewSize)
{
    pcTab.bSetNewSize(iNewSize);
}


int main()
{
    v_alloc_table_fill_34(5);

    int** pi_table;
    b_alloc_table_2_dim(&pi_table, 5, 3);
    b_dealloc_table_2_dim(&pi_table, 5, 3);

    CTable* c_tab1;
    c_tab1 = new CTable();
    CTable* c_tab2;
    c_tab2 = new CTable("Dominik", 7);

    c_tab1->vSetName("Adam");
    c_tab1->bSetNewSize(15);
    c_tab2->bSetNewSize(23);

    CTable c_tab_to_clone;
    CTable* pc_new_tab;
    pc_new_tab = c_tab_to_clone.pcClone();

    CTable static_tab("Marek", 20);

    // w tym momencie tworzy sie kopia obiektu, dlatego tez jest printowana: kopia i...
    v_mod_tab(static_tab, 21);
    std::cout << "Size of the table: " << static_tab.igetSize() << " (modulation through copy) \n";
    // po wykonaniu od razu usuwana

    v_mod_tab(&static_tab, 22);
    std::cout << "Size of the table: " << static_tab.igetSize() << " (modulation through reference) \n";

    // znowu kopia
    v_mod_tab(*c_tab1, 30);
    std::cout << "Size of the table: " << c_tab1->igetSize() << " (modulation through copy) \n";

    v_mod_tab(c_tab1, 50);
    std::cout << "Size of the table: " << c_tab1->igetSize() << " (modulation through reference) \n";

    delete c_tab1;
    delete c_tab2;
    delete pc_new_tab;
}