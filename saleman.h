#ifndef SALEMAN_H
#define SALEMAN_H
#include "matrix.h"
#include "value.h"
class saleman
{
private:
    int objects=0;
    char pressAnyKey;
    matrix<v_cell>calc_prog;
protected:
    void changeValueCell();
    void menuPrint();
    void menu();                    //nie skończone
    void solveProblem();           //nie skończone
    void changeMatrix();           
    void ERROR();                   //nie skończone
    void enterManuallyPrint();    
    void enterManuallyMenu();     
public:
    saleman();
};
#endif