#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <stdio.h>
#include <string.h>
#include "crud.h"

int loadData(Animal s[]);
void saveData(Animal s[], int count);
void searchName(Animal *s, int count);
void searchType(Animal *s, int count);
void searchAge(Animal *s, int count);

#endif