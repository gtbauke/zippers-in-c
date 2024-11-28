#ifndef ADT_H
#define ADT_H

typedef struct
{
  int x;
  int y;
} Point;

typedef struct
{
  char name[50];
  int age;
} Person;

typedef struct
{
  int type;
  union
  {
    Point point;
    Person person;
  };
} Either;

#endif
