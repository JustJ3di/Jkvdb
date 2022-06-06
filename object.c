#include "object.h"



struct object{

    kind type;
    char *key;
    union{

        int32_t t_int;
        char *t_string;
        float t_float;

    };

};



#ifndef SIZE_OBJECT
    #define  SIZE_OBJECT sizeof(struct object)
#endif

#ifndef SIZE_METHOD
    #define SIZE_METHOD sizeof(struct operation)
#endif

const char *_get_key(Object *obj){
    return obj->key;
}

const char *_get_string(Object *obj){
    return obj->t_string;
}

int32_t _get_int(Object *obj){
    return obj->t_int;
}

float _get_float(Object *obj){
    return obj->t_float;
}

void _set_int(Object *self, int value){


    if (self->type == TYPE_STRING)
    {
        free(self->t_string);
    }

    self->type = TYPE_INT;
    self->t_int = value;
        
}
void _set_key(Object *self, const char *key){

    if(self->key){
        free(self->key);
    }
    self->key = malloc(SIZE_STRING(key));
    if(!self->key)exit(EXIT_FAILURE);
    strcpy(self->key, key);

}
void _set_string(Object *self, const char *string){

    if (self->type == TYPE_STRING)
    {
        self->type = TYPE_STRING;
        self->t_string = realloc(self->t_string, SIZE_STRING(string));
        if(!self->t_string)exit(EXIT_FAILURE);
        strcpy(self->t_string, string);
        return;
    }
    

    self->type = TYPE_STRING;
    self->t_string = malloc(SIZE_STRING(string));
    if(!self->t_string)exit(EXIT_FAILURE);
    strcpy(self->t_string, string);

}
void _set_float(Object *self, float value){


    if (self->type == TYPE_STRING)
    {
        free(self->t_string);
    }

    self->type = TYPE_FLOAT;
    self->t_float = value;   

}


kind _get_type(Object *obj){
    return obj->type;
}


method *method_of(Object *new){

    return (method *)((Object *)new+1);

}


method *new_obj(const char *key, void *ele, kind type){

    Object *new = malloc(SIZE_OBJECT + SIZE_METHOD);
    new->key = malloc(SIZE_STRING(key));
    strcpy(new->key, key);

    new->type = type;
    switch (type)
    {
    case TYPE_FLOAT:
        new->t_float = *((float *)ele);
        break;
    case TYPE_INT:
        new->t_int = *((int *)ele);
        break;
    case TYPE_STRING:
        new->t_string = malloc(SIZE_STRING(ele));
        strcpy(new->key, ele);
        break;
    }

    method *meth = method_of(new);
    meth->self = new;
    meth->get_key = _get_key;
    meth->get_int_value = _get_int;
    meth->get_string_value = _get_string;
    meth->get_float_value = _get_float;
    meth->set_int = _set_int;
    meth->set_float = _set_float;
    meth->set_key = _set_key;
    meth->set_string = _set_string;

    return meth;

}

void destroy(method *meth){

    Object *me = meth->self;

    if (me->type == TYPE_STRING)
    {
        free(me->t_string);
    }
    
    free(me->key);

    free(me);

}