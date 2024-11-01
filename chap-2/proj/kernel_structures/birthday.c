#include <linux/types.h>

struct birthday {
    int day;
    int month;
    int year;
    struct list_head_list;
}

int main(){
    static LIST_HEAD(birthday list);
    struct birthday *person;

    person = kmalloc(sizeof(*person), GFP KERNEL);
    person->day = 2;
    person->month= 8;
    person->year = 1995;
    INIT_LIST_HEAD(&person->list);

    return 0;
}