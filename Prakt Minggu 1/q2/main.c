#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[30];
    int age;
} Student;

int isYounger(Student, Student);

int main()
{
    Student student1 = {"Dukhaan",19};
    Student student2 = {"Rakha",20000};

    if (isYounger(student1, student2)){
        printf("%s lebih muda dari %s\n",student1.name,student2.name);
    } else printf("%s lebih tua dari %s\n",student1.name,student2.name);

    return 0;
}

int isYounger(Student s1, Student s2){
    if(s1.age < s2.age){
        return 1;
    }else {
        return 0;
    }
}
