#ifndef OBJECT
#define OBJECT

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef enum{

    TYPE_INT,
    TYPE_STRING,
    TYPE_FLOAT

}kind;

/*entity*/
typedef struct object Object;


typedef struct operation method;

/*method*/

typedef kind (*get_type_t)(Object *);
typedef int32_t (*get_int_value_t)(Object *);
typedef const char *(*get_string_value_t)(Object *);
typedef float (*get_float_value_t)(Object *);
typedef const char *(*get_key_t)(Object *);
typedef void (*set_key_t)(Object *, const char *);
typedef void (*set_string_t)(Object *,const char *);
typedef void (*set_int_t)(Object *, int32_t);
typedef void (*set_float_t)(Object *, float);


kind _get_type(Object *);
const char *_get_key(Object *obj);
const char *_get_string(Object *obj);
int32_t _get_int(Object *obj);
float _get_float(Object *obj);
void _set_int(Object *, int);
void _set_key(Object *, const char *);
void _set_string(Object *, const char *);
void _set_float(Object *, float);

struct operation{

    Object *self;
    get_type_t get_type;
    get_float_value_t get_float_value;
    get_int_value_t get_int_value;
    get_key_t get_key;
    get_string_value_t get_string_value;
    set_key_t set_key;
    set_int_t set_int;
    set_string_t set_string;
    set_float_t set_float;

};

#ifndef SIZE_INT
    #define SIZE_INT sizeof(int32_t)
#endif

#ifndef SIZE_FLOAT
    #define SIZE_FLOAT sizeof(float)
#endif

#ifndef SIZE_STRING
    #define SIZE_STRING(string)     \
         strlen(string) + 1
#endif

method *new_obj(const char *, void *, kind type);
void destroy(method *);


method *method_of(Object*);





#endif