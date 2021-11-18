#include "value.h"
v_cell::v_cell()
{
    this->cell = 0;
    this->cell_value = 0;
}
v_cell &v_cell::operator=(double value)
{
    this->cell = value;
    return *this;
}
v_cell &v_cell::operator=(const v_cell &value)
{
    this->cell = value.cell;
    this->cell_value=value.cell_value;
    return *this;
}
void v_cell::setCellValue(double value)
{
    this->cell_value = value;
}
double v_cell::getCell() { return this->cell; }
double v_cell::getCellValue() { return this->cell_value; }
std::ostream &operator<<(std::ostream &out, const v_cell &a)
{
    out << a.cell;
    return out;
}
std::istream &operator>>(std::istream &in, v_cell &a)
{
    in >> a.cell;
    return in;
}
bool v_cell::operator==(double a)
{
    if (this->cell == a)
    {
        return true;
    }
    return false;
}
bool v_cell::operator!=(double a)
{
    return !(*this == a);
}
bool v_cell::operator<(const v_cell &value)
{
    if(this->cell<value.cell) return true;
    return false;
}
bool v_cell::operator>(const v_cell &value)
{
    return !(v_cell::operator<(value));
}