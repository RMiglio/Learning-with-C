#include<iostream>

enum class Tipo
{
	ep1, ep2, ef

};

struct Nota
{
	int valor;
	Tipo tipo;
	Nota* sgtnota;
};

struct Alumno
{
	std::string codigo;
	std::string carrera;
	Alumno* sgtAlumno;
	Nota* notas;
};


struct Seccion
{
	int numero;
	std::string carrera;
	Alumno* alumnos;

};

Seccion seccion610; // var global 



void registrar_alumno(std::string codigo, std::string carrera) 
{
	//creamos nuevo alumno
	Alumno* nuevoAlumno = new Alumno(); //crear puntero alumno
	(*nuevoAlumno).codigo = codigo;
	nuevoAlumno->carrera = carrera;
	nuevoAlumno->notas = nullptr;
	nuevoAlumno->sgtAlumno = nullptr;

	//agregar a lista de alumnos
	if (seccion610.alumnos == nullptr) 
	{
		//no hay alumnos registrados
		seccion610.alumnos = nuevoAlumno;
	}
	else
	{
		//ya hay alumnos creados
		Alumno* pAlumno = seccion610.alumnos;
		//pAlumno es una var pivot, que apuntará los valores confome se muevea la lista
		while (pAlumno->sgtAlumno !=nullptr)
		{
			pAlumno = pAlumno->sgtAlumno; //rota entre los valores de la lista
		}
		pAlumno->sgtAlumno = nuevoAlumno; //cuando llega al final
	}
}

void registrar_nota(std::string codigo, int valor, Tipo tipo) 
{
	//buscar alumno
	Alumno* pAlumno = seccion610.alumnos;
	while (pAlumno != nullptr)
	{
		if (pAlumno->codigo==codigo) // SI E EL CODIGO QUE TE ESTA BUSCANDO
		{
			//Econtre al alumno
			//Registrar nota
			Nota* nuevaNota = new Nota(); //crear puntero nota
			nuevaNota->valor = valor;
			nuevaNota->tipo = tipo;
			nuevaNota->sgtnota = nullptr;

			if (pAlumno->notas == nullptr)
			{
				//NO TIENE NOTAS REGISTRADAS
				pAlumno->notas = nuevaNota;
			}
			else
			{
				//SI TIENE NOTAS REGISTRADAS
				Nota* pNota = pAlumno->notas;
				while (pNota->sgtnota != nullptr)
				{
					pNota = pNota->sgtnota; // RECORRER VALORES Y ROTA LA LISTA ENLAZADA
				}
				pNota->sgtnota = nuevaNota;

			}
		}
		pAlumno = pAlumno->sgtAlumno;
	}
}

float Calcular_nota_prom(Alumno* alumno)
{
	Nota* pNota = alumno->notas;
	float nota = 0.0f;
	while (pNota != nullptr)
	{
		if (pNota->tipo == Tipo::ep1)
		{
			nota += pNota->valor * 0.3f;
		}
		else if (pNota->tipo == Tipo::ep2)
		{
			nota += pNota->valor *0.3f;
		}
		else if (pNota->tipo == Tipo::ef)
		{
			nota += pNota->valor * 0.4f;
		}
		pNota = pNota->sgtnota;
	}
	return nota;
}

float Calcular_prom()
{
	float notasTotales = 0.0f;
	int cantidadNotas = 0;

	Alumno* pAlumno = seccion610.alumnos;
	while (pAlumno != nullptr)
	{
		float promedio = Calcular_nota_prom(pAlumno);
		notasTotales += promedio; // es igual a declarar: notasTotales = notasTotales + promedio
		cantidadNotas++;
	
		pAlumno = pAlumno->sgtAlumno;
	}
	return notasTotales / cantidadNotas;
}

//ejercicio extra 
//imprimir lo sgt 
//codigo: Carrera: Nota total 

void imprimir_alumno()
{
	Alumno* pAlumno = seccion610.alumnos;

	while (pAlumno != nullptr)
	{				
		std::cout << "Codigo: " << pAlumno->codigo
			<< " "
			<< "Carrera: " << pAlumno->carrera
			<< " " << std::endl;
						
	pAlumno = pAlumno->sgtAlumno;
		
	}
	std::cout << "el prom de alumnos es: " << Calcular_prom() << std::endl;
}

void imprimir_NotasIndv(std::string codigo)
{
	Alumno* pAlumno = seccion610.alumnos;
	while (pAlumno != nullptr)
	{
		if (pAlumno->codigo==codigo)
		{
			std::cout << "prom de alumno: " << codigo << " es " << Calcular_nota_prom(pAlumno) << std::endl;
		}
		pAlumno = pAlumno->sgtAlumno;
	}	
}



int main()
{
	
	registrar_alumno("20001111", "Ing.Sistemas");
	registrar_alumno("20003333", "Comunica");
	registrar_alumno("20004444", "Industrial");
	
	registrar_nota("20001111", 15, Tipo::ep1);
	registrar_nota("20001111", 16, Tipo::ep2);
	registrar_nota("20001111", 13, Tipo::ef);
	
	registrar_nota("20003333", 20, Tipo::ep1);
	registrar_nota("20003333", 16, Tipo::ep2);
	registrar_nota("20003333", 02, Tipo::ef);
	
	
	registrar_nota("20004444", 20, Tipo::ep1);
	registrar_nota("20004444", 13, Tipo::ep2);
	registrar_nota("20004444", 18, Tipo::ef);
	
	imprimir_alumno();
	
	imprimir_NotasIndv("20001111");
	imprimir_NotasIndv("20004444");
	imprimir_NotasIndv("20003333");	
	
	return 0;

}