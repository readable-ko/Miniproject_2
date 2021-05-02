#include <stdio.h>
#include <string.h>
#include "crudfuction.h"

int main() {
  Animal alist[100];
        alist[0].age = -1;
        alist[0].sex = 'K';
        alist[0].gratuity = -1;

        int count = 0,index =0, menu;
        int delok;

        //count = loadData(alist);
        index = count;

        while(1) {
                menu = selectMenu();
                if(menu == 0) break;
                if(menu == 2 || menu == 3 || menu == 4)
                        if(count == 0) continue;

                if(menu == 1) count += createAnimal(&alist[index++]);
                else if(menu == 2) listAnimal(alist, index);
                else if(menu == 3) {
                        int num = selectNumber(alist, index);
                        if(num > 0)
                                updateAnimal(&alist[num-1]);
                }
                else if(menu == 4) {
                        int num = selectNumber(alist, index);
                        if(num > 0) {
                                printf("정말로 삭제하시겠습니까?(삭제 1번) :");
                                scanf("%d",&delok);
                                if(delok == 1) {
                                        deleteAnimal(&alist[num-1]);
                                        count--;
                                }
                        }
                }
                else if(menu == 5) {
                        //saveData(alist,index);
                }
                else if(menu == 6) {
                        printf("\n1. 종별로 검색\n");
                        printf("2. 이름으로 검색\n");
                        printf("3. 나이로 검색\n");
                        printf("4. 성별로 검색\n");
                        printf("숫자를 입력해주세요 : ");
                        scanf("%d", &delok);
                        switch(delok) {
                                case 1: printf(" 종별로 검색 함수"); break;
                                case 2: printf("이름으로 검색 함수"); break;
                                case 3: printf("나이로 검색 함수"); break;
                                case 4: printf("성별로 검색 함수"); break;
                                default: break;
                        }

                }
        }
        printf("프로그램이 종료되었습니다.\n");
        return 0;
}
