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

    
    method *my = new_obj("", &a, TYPE_INT);

    my->set_key(my->self, "nuovo");
    my->set_string(my->self, "olaaaaa");

    printf("%s\n",my->get_string_value(my->self));

    my->set_float(my->self, 2.3);

    printf("%f\n",my->get_float_value(my->self));

    printf("%d\n", my->get_type(my->self));

    destroy(my);


    return 0;
}
