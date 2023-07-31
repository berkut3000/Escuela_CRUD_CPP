
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

    Alumno(int semester = 1)
        : Semester(semester)
    {
        copy(begin(ASSIGNMENTS), end(ASSIGNMENTS), begin(Assig));
    }

    int Semester;
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
        cout << "Semestre:" <<this->Semester << endl;
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

    Alumno alumno1(2);
    Alumno alumno2(1);

    alumno1.create("Antonio Perez", 16, 'M');
    alumno1.display();
    alumno2.create("Citlali Alavrez", 15, 'F');
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
