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

