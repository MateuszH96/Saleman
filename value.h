#ifndef VALUE_H
#define VALUE_H
#include <iostream>
class v_cell
{
private:
    double cell;
    double cell_value;
public:
    v_cell();
    v_cell &operator=(double value);
    v_cell &operator=(const v_cell &value);
    bool operator<(const v_cell &value);
    bool operator>(const v_cell &value);
    void setCellValue(double value);
    double getCell();
    double getCellValue();
    friend std::ostream &operator<<(std::ostream &out, const v_cell &a);
    friend std::istream & operator>>(std::istream &in, v_cell &a);
    bool operator==(double a);
    bool operator!=(double a);
};


#endif