#ifndef DUST_DATABASE_H
#define DUST_DATABASE_H
/* includes */

#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

/* structs */
typedef struct attribute_value_s
{
	enum DataType
	{
		INT,
		CHAR,
		BOOL,
		FLOAT,
		TIME,
		MONEY,
		STRING
	} type;

	union 
	{
		int int_value;
		char char_value;
		bool bool_value;
		float float_value;
		time_t time_value;
		float money_value;
		char *string_value;
	} value;
} attribute_value_t;

typedef struct action_s
{
	char *name;
	int (*function)(void); /* idk how to name this */
} action_t;

typedef struct attribute_s
{
	attribute_value_t value;
	uint8_t null_checker;
	uint8_t constrains;
} attribute_t;

typedef struct table_s
{
	int id;
	char *name;
	attribute_t **attributes; /* array of pointers to attributes of table */
	size_t attribute_count;
	time_t creation_datetime;
	time_t modification_datetime;
	attribute_t *primary_key;
	attribute_t **foreign_key;
} table_t;

typedef struct command_s
{
	action_t action;
	table_t *source;
	table_t *destination;
	/* condition with type idk */
} command_t;

typedef struct schema_s
{
	int id;
	char *name;
	table_t **tables; /* array of pointers to tables inside the schema */
	size_t table_count;
	time_t creation_datetime;
	time_t modification_datetime;
} schema_t;

typedef struct database_s
{
	int id;
	char *name;
	table_t **tables; /* array of pointers to tables outside any schema */
	size_t table_count;
	schema_t **schemas; /* array of pointers to schemas */
	size_t schema_count;
	time_t creation_datetime;
	time_t modification_datetime;
} database_t;

/* function prototypes */
int start(void);
int parse(char *);

/* getter-setter function prototypes */

#endif
