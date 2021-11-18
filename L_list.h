#ifndef ODLIST_H_
#define ODLIST_H_
#include <iostream>
template <class T>
class L_list
{
private:
    //Variables
    typedef struct list
    {
        struct list *next;
        T data;
    } List;

    List *head;

    unsigned int size_list = 0;
    //Functions
    void addStop(T data)
    {
        List *t = new List;
        t->next = new List;
        t = throughTheList(t);
        List *tmp = new List;
        tmp->next = NULL;
        tmp->data = data;
        t->next = tmp;
    }

    List *throughTheList(List *tmp)
    {

        if (this->head->next != NULL)
        {
            List *t = new List;
            t = this->head;
            while (t)
            {
                tmp = t;
                t = t->next;
            }
            delete t;
        }
        else
        {
            tmp = this->head;
        }
        return tmp;
    }
    /////////////////////////////////////////////////////////////////////////
public:
    L_list()
    {
        this->head = new List;
        this->head->next = new List;
        this->head->next = NULL;
    }
    ~L_list()
    {
        delList();
        delete this->head->next;
        delete this->head;
    }
    unsigned int numOfEl()
    {
        return this->size_list;
    }
    void addAtTheBeginning(T data)
    {
        List *t = new List;
        List *tmp = new List;
        tmp = this->head->next;
        t->data = data;
        t->next = tmp;
        this->head->next = t;
        size_list++;
    }

    void addAtTheEnd(T data)
    {
        if (this->head->next != NULL)
        {
            List *t = new List;
            List *tmp = new List;
            t->data = data;
            t->next = NULL;
            tmp = throughTheList(tmp);
            tmp->next = t;
            size_list++;
        }
        else
        {
            this->addAtTheBeginning(data);
        }
    }
    void addAtFontEl(T data_search, T data)
    {
        List *tmp = new List;
        tmp->next = new List;
        tmp->data = data;
        List *t = new List;
        t->next = new List;
        t = this->head;
        addStop(data_search);
        while (t->next->data != data_search)
            t = t->next;
        if (t->next->next != NULL)
        {
            tmp->next = t->next;
            t->next = tmp;
        }
        delLastEl();
        t = NULL;
        delete t;
        size_list++;
    }
    void addBehindEl(T data_search, T data)
    {
        List *t = new List;
        List *tmp = new List;
        tmp->data = data;
        t = this->head->next;
        while (t->data != data_search)
            t = t->next;
        tmp->next = t->next;
        t->next = tmp;
        t = NULL;
        tmp = NULL;
        delete t;
        delete tmp;
        size_list++;
    }
    bool find_element(T data_search)
    {
        List *t=new List;
        t=this->head->next;
        if(this->head->next!=NULL)
        {
            while (t)
            {
                if(t->data==data_search)
                {
                    return true;
                }
                t=t->next;
            }    
        }
        return false;
    }
    void delFirstEl()
    {
        List *t = new List;
        t = this->head;
        List *tmp = new List;
        tmp = this->head->next;
        t->next = t->next->next;
        delete tmp;
        t = NULL;
        delete t;
        size_list--;
    }
    void delLastEl()
    {
        if (this->head->next != NULL)
        {
            List *t = new List;
            t = this->head;
            while (t)
            {
                if (t->next->next == NULL)
                {
                    delete t->next->next;
                    delete t->next;
                    break;
                }
                t = t->next;
            }
            t->next = NULL;
            t = NULL;
            delete t;
            size_list--;
        }
    }
    void delList()
    {
        if (this->head->next != NULL)
        {
            List *tmp = new List;
            tmp->next = new List;
            tmp = this->head->next;
            this->head->next = NULL;
            while (tmp)
            {
                List *to_delete = new List;
                to_delete->next = new List;
                to_delete = tmp;
                tmp = tmp->next;
                delete to_delete->next;
                delete to_delete;
            }
            delete tmp;
            size_list = 0;
        }
    }
    void delEl(T data_search)
    {
        if (this->head->next != NULL)
        {
            List *tmp = new List;
            List *t = new List;
            t = this->head->next;
            addStop(data_search);
            while (t->next->data != data_search)
            {
                t = t->next;
            }
            if (t->next->next != NULL)
            {
                tmp = t->next;
                t->next = t->next->next;
            }
            delLastEl();
            tmp = NULL;
            t = NULL;
            delete tmp;
            delete t;
        }
    }
    void wypisz_liste()
    {
        List *t = new List;
        t = this->head;
        t = t->next;
        while (t)
        {
            std::cout << t->data << '\n';
            t = t->next;
        }
        delete t;
    }
};
#endif