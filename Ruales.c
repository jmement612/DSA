// Create a structure for student that contains the following:
//     studID, studName, studScore

// The name must be a structure also of a firstname, middlname, and lastname.
// The student scores is an array of 5 scores. ( accepts values from 1.0 to 5.0)

// Create an array of 5 students.

// Create a function that will display a student information.
// Create a function that will display all the students in the array. 
// Create a function that will get the average score of a student.
// Create a function that will encode the 5 scores of the student.

#include<stdio.h>
#include<string.h>

#define MAX_SCORE 5
#define MAX_STUDENT 5
#define TRUE 1
#define FALSE 0

typedef char String[20];
typedef int Boolean;

typedef struct {
    String fname;
    String mname;
    String lname;
} Name;

typedef struct {
    int studID;
    Name studName;
    float studScore[MAX_SCORE];
} Student;


void displayStudent(Student s);
void displayStudents(Student studs[], int n);
float getScoreAverage(Student s);
void recordScore(Student *s, float scores[], int n);

Name createName(String fname, String mname, String lname);
Student createStudent(int id, Name name);

Boolean insertFirst(Student list[], int *n, Student s);
Boolean insertLast(Student list[], int *n, Student s);
Student deleteFirst(Student list[], int *n);
Student deleteLast(Student list[], int *n);
int search(Student list[], int n, int id);

int main() {
    Student list[MAX_STUDENT];
    int count = 0;
    float s[5] = {3.0, 3.0, 3.0, 1.0, 5.0};


    list[0] = createStudent(1001, createName("Kyle", "Castro", "Burce"));
    list[1] = createStudent(1002, createName("Sugar", "Librero", "Vender")); //Camae mana mao na sugar
    count = 2;
    // list[2] = createStudent(1003, createName("Christoph", "Gwapo", "Carreon"));
    // list[3] = createStudent(1004, createName("Gwapo", "Gibert", "Kaayo")); 
    // list[4] = createStudent(1005, createName("Fitz", "Napulihan", "Martin")); 


    recordScore(&list[3], s, 5);

    printf("\n\nDisplay One Student:\n");
    displayStudent(list[1]);

    printf("\n\nDisplay All Student:\n");
    displayStudents(list, 5);

    return 0;
}

void displayStudent(Student s) {
    int i;

    printf("%20s: %d\n", "Student ID", s.studID);
    printf("%20s: %s, %s %c.\n", "Student Name", s.studName.lname, s.studName.fname, s.studName.mname[0]);
    printf("%20s: {", "Scores");
    for(i=0; i<MAX_SCORE; ++i) {
        printf("%.2f", s.studScore[i]);
        if(i < MAX_SCORE-1) {
            printf(", ");
        }
    }
    printf("}");
}

void displayStudents(Student studs[], int n) {
    int i, j;
    printf("%10s | %30s | %s\n", "ID", "NAME", "SCORE");
    for(i=0; i<n; i++) {
        printf("%10d | %14s %15s | {", studs[i].studID, studs[i].studName.fname, studs[i].studName.lname);
        for(j=0; j<MAX_SCORE; ++j) {
            printf("%.2f", studs[i].studScore[j]);
            if(j < MAX_SCORE-1) {
                printf(", ");
            }
        }
        printf("}\n");
    }
}

float getScoreAverage(Student s) {
    float sum = 0;
    int i;

    for(i=0; i<MAX_SCORE; ++i) {
        sum += s.studScore[i];
    }

    return sum/MAX_SCORE;
}

void recordScore(Student *s, float scores[], int n) {
    memcpy(s->studScore, scores, sizeof(float)*n);
}

Name createName(String fname, String mname, String lname) {
    Name n;

    strcpy(n.fname, fname);
    strcpy(n.mname, mname);
    strcpy(n.lname, lname);

    return n;
}

Student createStudent(int id, Name name) {
    Student s = {id, name, {5.0, 5.0, 5.0, 5.0, 5.0}}; 

    return s;
}

Boolean insertFirst(Student list[], int *n, Student s) {
    int i;
    if(*n < MAX_STUDENT) {
        for(i=*n; i>0; --i) {
            list[i] = list[i-1];
        }
        list[0] = s;
        (*n)++;
        return TRUE;
    }
    return FALSE;
}

Boolean insertLast(Student list[], int *n, Student s) {
    if(*n < MAX_STUDENT) {
        list[(*n)++] = s;
        return TRUE;
    }
    return FALSE;
}

Student deleteFirst(Student list[], int *n) {
    int i;
    Student deleted = createStudent(0, createName("", "", ""));

    if(*n > 0) {
        deleted = list[0];                                                             
        for(i=0; i < (*n)-1; ++i) {
            list[i] = list[i+1];   
        }
        (*n)--;
    }

    return deleted;
}

Student deleteLast(Student list[], int *n) {
    Student deleted = {0, {"", "", ""}, {0, 0, 0, 0, 0}};

    if(*n > 0) {
        deleted = list[--(*n)];
    }

    return deleted;
}

int search(Student list[], int n, int id);























