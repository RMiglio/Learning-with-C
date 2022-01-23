# Learning-with-C
Here lies my  take on the homework my university left us 
For the project above, we were tasked to make a code to register calculate and print the grades of students at ULIMA usings structs and ptrs. Sadly, I'm still figuring out how 
use something other than a global variable to handle the ptr. For now I will be using the global variable seccion610 to make all the moves.
Im leaving here the translations:

Structs and enum class
TIPO = serves as a class that holds together the 3 types of exams 

Nota = holds the aspects of grades, such as the score, the type of grade and for the ptr, the next grade.

Alumno = holds the aspects of students, such as ID, faculty, as for the ptrs, we have next student and a pointer to Nota to reference the struct.

Seccion = holds the aspects of a class, such its number, department and pointer to Alumnos to references the struct. From here we form the global variable seccio610.


Functions
- registrar_alumno = register_student : allows the code to insert a new student, by introducing their respctive ID and faculty

- registrar_notas = register_grade : At Ulima, we currently have three main promedium we take into account: EP1 EP2 and EF, two midterms and one final, and each has its value
 
- Calcular_notas_prom = calculate_grades_GPA: Here we take the mentioned grades to calculate the GPA of said student. 

- Calcular_prom = calculate_ GPA : here we call the previous function to be executed, giving us the grades in return from said group. 
  Not only that, but we receive the OVERALL GPA of all the students from a current group of seccion610.

- imprimir_alumno = print_student : show on console the student with his ID and faculty he belongs to, as well as print the GPA of seccion610.

- imprimir_NotasIndv = print_Grades/Student: show on console the GPA of each student  
  
It may not be the most compelling code, but for learning this kinks, it is quite the achievement, I hope I get some feedback on how to handle this better. 

