#include "saleman.h"
void saleman::changeValueCell()
{
    char tmp;
    do
    {
        std::system("cls");
        std::cout << calc_prog;
        tmp = calc_prog.moveInCell();
    } while (tmp != 'q');
}
void saleman::changeMatrix()
{
    std::cout << "Type numbers of objects: ";
    std::cin >> this->objects;
    matrix<v_cell> temp_to_create(this->objects);
    calc_prog = temp_to_create;
}
saleman::saleman()
{
    menu();
}
void saleman::menuPrint()
{
    system("cls");
    std::cout << "1.Enter Manually\n"
              << "2.Enter From Notepad\n"
              << "3.Calculate\n"
              << "4.User Manual\n"
              << "5.Quit\n";
}
void saleman::enterManuallyPrint()
{
    putchar('\a');
    system("cls");
    std::cout << "1.Create NeW And Enter Value\n"
              << "2.Modify Value\n"
              << "3.Back\n";
}
void saleman::enterManuallyMenu()
{
    char tmp;
    do
    {
        enterManuallyPrint();
        tmp=getch();
        switch (tmp)
        {
        case '1':
            changeMatrix();
        case '2':
            changeValueCell();
            break;
        }
    } while (tmp!='3');
    
}
void saleman::menu()
{
    char choose;
    do
    {
        system("cls");
        menuPrint();
        choose = getch();
        switch (choose)
        {
        case '1':
            enterManuallyMenu();
            break;
        case '2':
            /* code */
            break;
        case '3':
            switch (this->objects)
            {
            case 0:
            case 1:
                ERROR();
                break;

            default:
                solveProblem();
                break;
            }
            break;
        case '4':
            std::cout<<"test";
            system("pause");
            break;
        }
    } while (choose != '5');
}
void saleman::ERROR()//tymczasowe rozwiązanie
{
    putchar('\a');
    std::cout<<"ERROR PRESS ANY KEY TO CONTINUE\n";
    this->pressAnyKey = getch();
}
