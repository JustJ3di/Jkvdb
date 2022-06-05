#include "object.h"


int main()
{
    int a = 2;
    method *me = new_obj("ciao", &a, TYPE_INT);

    printf("%s\n", me->get_key(me->self));
    printf("%d\n", me->get_int_value(me->self));

    me->set_int(me->self, 10);

    printf("%d\n", me->get_int_value(me->self));


    destroy(me);

    return 0;
}
