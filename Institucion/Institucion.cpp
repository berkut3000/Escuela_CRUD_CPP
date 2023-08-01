
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


// Clase Alumno
class Alumno: public Human {
public:

    Alumno(e_semester semester = E_PRIMER_SEMESTER)
        : Semester(semester)
    {
        copy(begin(ASSIGNMENTS), end(ASSIGNMENTS), begin(Assig));
    }

    e_semester Semester;
    string Assig[MAX_ASSIG];

    void create(string name, int age, char gender)
    {
        this->Id = this->GenerateID();
        this->Name = name;
        this->Age = age;
        this->Gender = gender;
    }

    void display(void)
    {
        cout << "Id:" << this->Id << endl;
        cout << "Nombre:" << this->Name << endl;
        cout << "Edad:" << this->Age << endl;
        cout << "Genero:" <<this->Gender << endl;
        cout << "Semester:" <<this->Semester << endl;
        cout << "Asignaturas:" << endl;

        for (int i = 0; i < MAX_ASSIG; i++)
        {
            cout << to_string(i+1) << "--" << this->Assig[i] << endl;
        }
    }


private:
    int GenerateID()
    {
        int id = rand() % 100;
        return id;
    }
};




// Clase Profesor
class Profesor : public Human {
public:

    Profesor(e_profession prof)
    {
        profession = PROFESIONES[prof];
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

    Alumno alumno1(E_PRIMER_SEMESTER);
    Alumno alumno2(E_TERCER_SEMESTER);

    alumno1.create("Antonio Perez", 16, 'M');
    //alumno1.display();
    alumno2.create("Citlali Alavrez", 15, 'F');
    //alumno2.display();

    Profesor prof1(E_COMP_SCI);
    prof1.create("Manolo", 30, 'M');
    prof1.display();


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
