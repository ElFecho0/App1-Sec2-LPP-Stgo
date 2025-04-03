#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 100
#define MAX_STUDENTS 100

typedef struct {
    int name;
    int age;
    char grade[MAX_NAME_LENGTH];
} Student;

int read_csv(const char *filename, Student students[], int max_students) {
   FILE *file = fopen("datos.csv", "r");
   if (!file) {
       perror("Failed to open file");
       return -1;
   }

   char line[MAX_LINE_LENGTH];
   int count = 0;

   // Read the header line
   if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
       perror("Failed to read header");
       fclose(file);
       return -1;
   }

   // Read the rest of the lines
   while (fgets(line, MAX_LINE_LENGTH, file) != NULL && count < max_students) {
       Student s;
       char *token = strtok(line, ",");
       
       if (token != NULL) s.name = atoi(token);

       token = strtok(NULL, ",");
       if (token != NULL) s.age = atoi(token);

       token = strtok(NULL, ",");
       if (token != NULL) strncpy(s.grade, token, MAX_NAME_LENGTH);

       students[count++] = s;
   }

   fclose(file);
   return count;
}

int main() {
   Student students[MAX_STUDENTS];
   int num_students = read_csv("students.csv", students, MAX_STUDENTS);

   if (num_students < 0) return 1;

   printf("Read %d students from CSV:\n", num_students);
   for (int i = 0; i < num_students; i++) {
       printf("Name: %i, Age: %i, Grade: %s\n", students[i].name, students[i].age, students[i].grade);
   }

   return 0;
}
