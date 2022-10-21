#include <iostream>
#include <string>
#include "CTable.h"
#include "CTableConsts.h"


CTable::CTable()
{
    s_name = "My table";
    std::cout << "bezp: " << s_name << "\n";
    table = new int[DEFAULT_TAB_LENGTH];
    tableLength = DEFAULT_TAB_LENGTH;
}

CTable::CTable(std::string sName, int iTableLen)
{
    s_name = sName;
    std::cout << "parametr: " << s_name << "\n";
    table = new int[iTableLen];
    tableLength = iTableLen;
}

CTable::CTable(CTable& pcOther)
{
    s_name = pcOther.s_name + "_copy";
    tableLength = pcOther.tableLength;
    table = new int[tableLength];
    
    for (int i = 0; i < tableLength; i++)
    {
        table[i] = pcOther.table[i];
    }

    std::cout << "kopiuj: " << s_name << "\n";
}

CTable::~CTable()
{
    std::cout << "usuwam: " << s_name << "\n";
    delete table;
}

void CTable::vSetName(std::string sName)
{
    s_name = sName;
    std::cout << "nowe imie: " << s_name << "\n";
}

bool CTable::bSetNewSize(int iTableLen)
{
    if (iTableLen <= 0)
        return false;

    int* tableNewSize;
    tableNewSize = new int[iTableLen];

    if (tableLength <= iTableLen)
    {
        for (int i = 0; i < tableLength; i++)
        {
            tableNewSize[i] = table[i];
        }
    }
    else
    {
        for (int i = 0; i < iTableLen; i++)
        {
            tableNewSize[i] = table[i];
        }
    }

    delete table;
    table = tableNewSize;
    tableLength = iTableLen;

    return true;
}

CTable* CTable::pcClone()
{
    return new CTable(*this);
}

int CTable::igetSize() {
    return tableLength;
}