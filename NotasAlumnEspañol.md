# Learning-with-C
Aquí está mi toma sobre la tarea de la universidad, crear un codigo que permita registrar alumnos con sus respecticas notas con una sección que los agrupe, a através de estructuras y punteros

Estructuras y clase de enumeración

TIPO = sirve como una clase que mantiene juntos los 3 tipos de exámenes

Nota = contiene los aspectos de las calificaciones, como la puntuación, el tipo de calificación y para el ptr, la siguiente calificación.

Alumno = contiene los aspectos de los alumnos, como identificación, facultad, en cuanto a los ptrs, tenemos el próximo alumno y un puntero a Nota para hacer referencia a la estructura.

Sección = contiene los aspectos de una clase, como su número, departamento y puntero a Alumno para hacer referencia a la estructura. A partir de aquí formamos la variable global sección610.

funciones
- registar_alumno: permite que el código inserte un nuevo alumno, introduciendo su respectivo ID y facultad

- registar_notes: En Ulima actualmente tenemos tres promedios principales que tomamos en cuenta: EP1 EP2 y EF, dos parciales y uno final, y cada uno tiene su valor
 
- Calcular_notas_prom: Aquí tomamos las notas mencionadas para calcular el promedio de dicho alumno.

- Calcular_prom: aquí llamamos a la función anterior para que se ejecute, dándonos a cambio las calificaciones de dicho grupo.
  No solo eso, sino que recibimos el promedio de todos los estudiantes de un grupo actual de la sección 610.

- imprimir_alumnot: mostrar en consola el alumno con su ID y facultad a la que pertenece, así como imprimir el promedio de la seccion610.

- imprimir_NotasIndv: mostrar en consola el promedio de cada alumno
  
Puede que no sea el código más convincente, pero para aprender estos conceptos, es un logro, espero recibir algunos comentarios sobre cómo mejorar esto.


