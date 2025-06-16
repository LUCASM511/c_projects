enum ValueType {
	VAL_NUMBER,
	VAL_OBJ,
} ValueType;

struct Value {
	double number;
	Obj * obj;
}as;

/* MACROS */

#define IS_NUMBER(value) ((value).type == VAL_NUMBER)
// macros for working with Obj values
#define IS_OBJ(value) ((value).type == VAL_OBJ)

#define AS_BOOL(value) ((value).as.boolean)


#define IS_OBJ(value) ((value).type == VAL_OBJ)

// this evaluates to true if the given Value is an Obj
#define AS_OBJ(value) ((value).as.obj)
#define AS_BOOL(value) ((value).as.boolean)


#define NUMBER_VAL(value) ((Value){VAL_NUMBER, {.number = value}})
// it extracts the Obj pointer from the value
#define OBJ_VAL(object) ((Value){VAL_OBJ, {.obj = (Obj*)object}})
