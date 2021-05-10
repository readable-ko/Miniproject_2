//This is the header file of the crud fuction.
#ifndef __CRUDFUNCTION_H__
#define __CRUDFUNCTION_H__

typedef struct {
 char name[50];
 int age;
 char breed[50];
 char sex;
 int gratuity;
} Animal;

int selectMenu();
int createAnimal(Animal *a);
void readAnimal(Animal a);
int updateAnimal(Animal *a);
int deleteAnimal(Animal *a);

void listAnimal(Animal *alist, int count);
int selectNumber(Animal *alist, int count);

#endif
