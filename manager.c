#include "manager.h"

int loadData(Animal s[]){
        int count = 0;
        FILE *fp;
        fp = fopen("animal.txt", "rt");
        if(fp==NULL)
        {
                printf("\n=> 파일 없음!\n");
                return 0;
        }
        for(; count < 20; count++){
                fscanf(fp, "%s", s[count].name);
                if(feof(fp)) break;
                fscanf(fp, "%d", &s[count].age);
                fscanf(fp, " %c", &s[count].sex);
                fscanf(fp, "%d", &s[count].gratuity);
                fscanf(fp, "%[^\n]", s[count].breed);
}

        fclose(fp);
        printf("=> 로딩 성공!\n");

        return count;
}

void saveData(Animal s[], int count){
        FILE *fp;
        fp = fopen("animal.txt", "wt");

        for(int i = 0; i < count; i++){
                if(s[i].age == -1) continue;
                fprintf(fp, "%s %d %c %d %s\n",s[i].name,s[i].age,s[i].sex,s[i].gratuity,s[i].breed);
        }
        fclose(fp);
        printf("=> 저장됨!");
}

void searchName(Animal *s, int count){
        int scnt = 0;
        char search[20];

        printf("검색할 이름? ");
        scanf("%s", search);

        printf("번호/\t이름\t/\t나이\t/\t품종\t/\t성별\t/\t사례금\t/\n");
        for(int i = 0; i < count; i++){
                if(s[i].age == -1) continue;
                if(strstr(s[i].name, search)){
                        printf("%2d ", i+1);
                        readAnimal(s[i]);
                        scnt++;
                }
        }
        if(scnt == 0) printf("=> 검색된 데이터 없음!");
        printf("\n");
}

void searchType(Animal *s, int count){
        int scnt = 0;
        char search[20];

        printf("검색할 품종? ");
        scanf("%s", search);

        printf("번호/\t이름\t/\t나이\t/\t품종\t/\t성별\t/\t사례금\t/\n");
        for(int i = 0; i < count; i++){
                if(s[i].age == -1) continue;
                if(strstr(s[i].breed, search)){
                        printf("%2d ", i+1);
                        readAnimal(s[i]);
                        scnt++;
                }
        }
        if(scnt == 0) printf("=> 검색된 데이터 없음!");
        printf("\n");
}

void searchAge(Animal *s, int count){
        int scnt = 0;
        int search = 0;

        printf("검색할 나이? ");
        scanf("%d", &search);

        printf("번호/\t이름\t/\t나이\t/\t품종\t/\t성별\t/\t사례금\t/\n");
        for(int i = 0; i < count; i++){
                if(s[i].age == -1) continue;
                if(s[i].age == search){
                        printf("%2d ", i+1);
                        readAnimal(s[i]);
                        scnt++;
                }
        }
        if(scnt == 0) printf("=> 검색된 데이터 없음!");
        printf("\n");
}

