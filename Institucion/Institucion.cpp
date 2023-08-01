
#include <windows.h> 
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <locale.h>
//#include <uuid/uuid.h> // Include the uuid library

using namespace std;

const int MAX_ASSIG = 5;
const string ASSIGNMENTS[MAX_ASSIG] = {
    "Computer Science",
    "Physical Education",
    "Math",
    "Geography",
    "Spanish"
};

typedef enum {
    E_COMP = 0,
    E_PHYS_ED,
    E_MATH,
    E_GEO,
    E_SPA
}e_materias;

const string PROFESIONES[] =
{
    "Default Profession",
    "Msc. Comp Sci",
    "Coach",
    "Phd. Math",
    "Phd. Anthropology",
    "Phd. Literature"
};

typedef enum {
    E_DEFAULT_PROFESSION = 0,
    E_COMP_SCI,
    E_COACH,
    E_PHD_MATH,
    E_PHD_ANTHRO,
    E_PHD_LIT
}e_profession;

typedef enum {
    E_PRIMER_SEMESTER = 1,
    E_SEGUNDO_SEMESTER,
    E_TERCER_SEMESTER,
    E_CUARTO_SEMESTER,
    E_QUINTO_SEMESTER,
    E_SEXTO_SEMESTER
}e_semester;

// Para cambiar colores
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


//Clase humano
class Human {
public:
    // Constructor with default values
    Human(int id = 0, const std::string& name = "", int age = 0, char gender = ' ')
        : Id(id), Name(name), Age(age), Gender(gender) {
    }

    // Public member variables (attributes)
    int Id;
    std::string Name;
    int Age;
    char Gender;


};




// Clase Profesor
class Profesor : public Human {
public:

    Profesor(string name, int age, char gender, string prof)
    {
        this->Id = this->GenerateID();
        this->Name = name;
        this->Age = age;
        this->Gender = gender;
        this->profession = prof;
    };

    string profession;
    int cedula;

    void create(string name, int age, char gender)
    {
        this->Id = this->GenerateID();
        this->Name = name;
        this->Age = age;
        this->Gender = gender;
    }

    void display(void)
    {
        cout << "Nombre:" << this->Name << endl;
        cout << "Genero:" << this->Gender << endl;
        cout << "Edad:" << this->Age << endl;
        cout << "Profesion:" << this->profession << endl;
        cout << "CEDULA:" << this->Id << endl;
    }


private:
    int GenerateID()
    {
        int id = rand() % 10000;
        return id;
    }
};


// Clase materia
class Materia {
public:
    Materia(string nombre, int creditos, Profesor prof) :
        Nombre(nombre), Creditos(creditos), Professor(prof)
    {
        //Nothing, yet
    }

    string Nombre;
    int Creditos;
    Profesor Professor;

    void display()
    {
        cout << "Nombre:" << this->Nombre << endl;
        cout << "Creditos:" << this->Creditos << endl;
        cout << "Profesor:" << this->Professor.Name << endl;
    }

};

Profesor prof_default("Default Default", 1, 'M', PROFESIONES[E_COMP_SCI]);
Materia Default_assig(ASSIGNMENTS[E_COMP], 80, prof_default);

// Clase Alumno
class Alumno : public Human {
public:
    Alumno(string name, int age, char gender, e_semester semester = E_PRIMER_SEMESTER)
        : Semester(semester)
    {
        this->Name = name;
        this->Age = age;
        this->Gender = gender;

    }

    e_semester Semester;
    Materia Assig[MAX_ASSIG] = { Default_assig,Default_assig,Default_assig,Default_assig,Default_assig };
    int dummy;

    void create(string name, int age, char gender)
    {
        this->Id = this->GenerateID();
        this->Name = name;
        this->Age = age;
        this->Gender = gender;
    }

    //void materias(Materia Materias[)

    void display(void)
    {
        cout << "Id:" << this->Id << endl;
        cout << "Nombre:" << this->Name << endl;
        cout << "Edad:" << this->Age << endl;
        cout << "Genero:" << this->Gender << endl;
        cout << "Semester:" << this->Semester << endl;
        cout << "Asignaturas:" << endl;

        for (int i = 0; i < MAX_ASSIG; i++)
        {
            cout << to_string(i + 1) << "--" << this->Assig[i].Nombre << endl;
        }
    }


private:
    int GenerateID()
    {
        int id = rand() % 100;
        return id;
    }
};

///////////// ADMIN  //////////////

class admin { //esta será la clase de sistema de control
public:
    string usuario;
    string clave;

    string user;
    string key;

    void imp();
    admin();

};
admin::admin() {
    usuario = "fer";
    clave = "123";
    bool pase = false;

    do {
        cout << "Ingrese su usuario admin: " << endl;
        cin >> user;
        cout << "Ingrese su clave: " << endl;
        cin >> key;

        if (user == usuario && key == clave) {
            pase = true;
            //            MenuPrincipal();
        }
        else {
            cout << "Datos incorrectos, vuelva a intentarlo " << endl;
            system("pause");
            system("cls");
        }
    } while (pase != true);

};

void admin::imp() {
    cout << endl;
    system("pause");
    system("cls");
}


int main() {

    setlocale(LC_ALL, "spanish");
    bool a;
    a = true;
    int opcion;

    cout << "\t\tBIENVENIDO\n\n";

    //admin admina;
    //    menuPrincipal();
    SetConsoleTextAttribute(hConsole, 11);

    Profesor prof1("Manolo Echeverria", 30, 'M', PROFESIONES[E_COMP_SCI]);
    //prof1.create();
    prof1.display();
    Profesor prof2("Sandra Perez", 29, 'F',PROFESIONES[E_PHD_LIT]);
    //prof2.create();

    prof2.display();


    Materia espanol(ASSIGNMENTS[E_SPA], 80, prof2);
    espanol.display();

    Materia computacion(ASSIGNMENTS[E_COMP], 80, prof1);
    computacion.display();

    Alumno alumno1("Antonio Perez", 16, 'M', E_PRIMER_SEMESTER);
    Alumno alumno2("Citlali Alavrez", 15, 'F', E_TERCER_SEMESTER);

    //alumno1.create();
    alumno1.display();
    //alumno2.create("Citlali Alavrez", 15, 'F');
    alumno2.display();
;
    cin >> opcion;

    system("cls");
    cout << "Men\u00fa Principal" << endl;
    cout << "0. Salir" << endl;
    cout << "1. Registrar Alumno" << endl;
    cout << "2. Registrar Materia" << endl;
    cout << "3. Registrar Profesor" << endl;
    cout << "4. Eliminar Alumno" << endl;
    cout << "5. Eliminar Profesor" << endl;
    cout << "6. Eliminar Materia" << endl;
    cout << "\nIngrese su opci\u00f3n: ";
    cin >> opcion;


    //datosGenerales datosGeneralesa;
    //alumno alumnoa;
    //profesor profesora;
    //materia materiaa;


   /* switch (opcion)
    {
    case 0:
        exit(1);
        break;
    case 1:
        datosGeneralesa.imp();
        alumnoa.imp();
        break;
    case 2:
        materiaa.imp();
        break;
    case 3:
        profesora.imp();
        break;
    default:
        break;
    }*/


    /*

        datosGenerales datosGeneralesa;
        alumno alumnoa;
        profesor profesora;
        materia materiaa;



        if (a != false) {
            admina.imp();
            datosGeneralesa.imp();
            alumnoa.imp();
            profesora.imp();
            materiaa.imp();
        }
        else return 0;
    */

    return 0;



}
