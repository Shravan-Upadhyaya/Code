#include <stdio.h>
typedef struct 
{
    char name[20];
    int assignment[2];
    int exam;
} Student;
void main() 
{   int totalscore=0;
    float averageGrade;
    Student student={"XYZ",{80,90},85};
    printf("Grades for %s:\n",student.name);
    for (int i=0;i<2;i++) 
    {
        printf("Assignment %d: %d\n",i+1,student.assignment[i]);
    }
    printf("Exam : %d\n",student.exam);
    for (int i=0;i<3;i++) 
    {
        totalscore+=student.assignment[i];
    }
    totalscore+=student.exam;
    averageGrade=(float)totalscore/3;
    printf("\nTotal Score: %d\n", totalscore);
    printf("Average Grade: %.2f\n", averageGrade);
}