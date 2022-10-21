#include <string>

class CTable
{
private:
    std::string s_name;
    int* table;
    int tableLength;

public:
    CTable();
    CTable(std::string sName, int iTableLen);
    CTable(CTable& pcOther);
    ~CTable();
    void vSetName(std::string sName);
    bool bSetNewSize(int iTableLen);
    CTable* pcClone();
    int igetSize();
};
