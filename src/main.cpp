#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

// ====================== Clase Herramienta ======================
class Herramienta {
private:
    string nombre;
    string tipo;
    string estado;

public:
    Herramienta(string n = "", string t = "", string e = "Disponible")
        : nombre(n), tipo(t), estado(e) {}

    void mostrarInfo() const {
        cout << "Herramienta: " << nombre << " | Tipo: " << tipo << " | Estado: " << estado << endl;
    }

    void cambiarEstado(string nuevoEstado) {
        estado = nuevoEstado;
    }

    string getNombre() const { return nombre; }
};

// ====================== Clase Tecnico ======================
class Tecnico {
private:
    string nombre;
    int id;
    string nivel;

public:
    Tecnico(string n = "", int i = 0, string nv = "Básico")
        : nombre(n), id(i), nivel(nv) {}

    void mostrarInfo() const {
        cout << "Técnico: " << nombre << " | ID: " << id << " | Nivel: " << nivel << endl;
    }

    string getNombre() const { return nombre; }
};

// ====================== Clase base EquipoElectronico ======================
class EquipoElectronico {
protected:
    string codigo;
    string tipo;
    string marca;

public:
    EquipoElectronico(string c = "", string t = "", string m = "")
        : codigo(c), tipo(t), marca(m) {}

    virtual void mostrarInfo() const {
        cout << "Equipo: " << tipo << " | Marca: " << marca << " | Código: " << codigo << endl;
    }

    virtual string analizarFalla() = 0; // Método polimórfico puro
};

// ====================== Clase derivada Computador ======================
class Computador : public EquipoElectronico {
public:
    Computador(string c, string m) : EquipoElectronico(c, "Computador", m) {}

    string analizarFalla() override {
        return "Posible falla: sobrecalentamiento o error del sistema operativo.";
    }
};

// ====================== Clase derivada FuentePoder ======================
class FuentePoder : public EquipoElectronico {
public:
    FuentePoder(string c, string m) : EquipoElectronico(c, "Fuente de Poder", m) {}

    string analizarFalla() override {
        return "Posible falla: cortocircuito o fusible quemado.";
    }
};

// ====================== Clase Mantenimiento ======================
class Mantenimiento {
private:
    string fecha;
    string tipoFalla;
    Herramienta herramienta;
    Tecnico tecnico;

public:
    Mantenimiento(string f, string falla, Herramienta h, Tecnico t)
        : fecha(f), tipoFalla(falla), herramienta(h), tecnico(t) {}

    void mostrarResumen() const {
        cout << "\n===== REPORTE DE MANTENIMIENTO =====" << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Falla detectada: " << tipoFalla << endl;
        herramienta.mostrarInfo();
        tecnico.mostrarInfo();
        cout << "====================================" << endl;
    }
};

// ====================== Clase Sistema ======================
class Sistema {
private:
    vector<Herramienta> herramientas;
    vector<Tecnico> tecnicos;
    vector<Mantenimiento> mantenimientos;

public:
    Sistema() {
        herramientas.push_back(Herramienta("Multímetro", "Medición", "Disponible"));
        herramientas.push_back(Herramienta("Cautín", "Soldadura", "En uso"));
        tecnicos.push_back(Tecnico("Greidy Agreda", 101, "Avanzado"));
        tecnicos.push_back(Tecnico("Sergio Quevedo", 102, "Intermedio"));
    }

    void limpiarPantalla() {
        system("cls");
    }

    void pausar() {
        cout << "\nPresiona una tecla para continuar...";
        system("pause>nul");
    }

    void mostrarLogo() {
        limpiarPantalla();
        cout << "\n\n";
        string logo[] = {
            "████████╗███████╗ ██████╗██╗  ██╗██████╗ ██████╗  █████╗ ██╗██████╗ ",
            "╚══██╔══╝██╔════╝██╔════╝██║  ██║██╔══██╗██╔══██╗██╔══██╗██║██╔══██╗",
            "   ██║   █████╗  ██║     ███████║██║  ██║██████╔╝███████║██║██║  ██║",
            "   ██║   ██╔══╝  ██║     ██╔══██║██║  ██║██╔══██╗██╔══██║██║██║  ██║",
            "   ██║   ███████╗╚██████╗██║  ██║██████╔╝██║  ██║██║  ██║██║██████╔╝",
            "   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═════╝ "
        };

        for (int i = 0; i < 6; i++) {
            cout << logo[i] << endl;
            Sleep(200);
        }
        cout << "\n        SISTEMA DE MANTENIMIENTO ELECTRÓNICO\n";
        Sleep(1000);
        cout << "------------------------------------------------------------\n";
        Sleep(800);
    }

    void menuPrincipal() {
        mostrarLogo();

        int opcion;
        do {
            limpiarPantalla();
            cout << "====================================\n";
            cout << "     SISTEMA TECHREPAIR - MENU\n";
            cout << "====================================\n";
            cout << "1. Ver herramientas\n";
            cout << "2. Ver técnicos\n";
            cout << "3. Diagnosticar equipo\n";
            cout << "4. Registrar mantenimiento\n";
            cout << "5. Salir\n";
            cout << "====================================\n";
            cout << "Selecciona una opción: ";
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
            case 1: mostrarHerramientas(); break;
            case 2: mostrarTecnicos(); break;
            case 3: diagnosticarEquipo(); break;
            case 4: registrarMantenimiento(); break;
            case 5:
                cout << "\nSaliendo del sistema..." << endl;
                Sleep(1000);
                break;
            default:
                cout << "\nOpción inválida. Intenta nuevamente.\n";
                Sleep(1200);
            }

        } while (opcion != 5);
    }

    void mostrarHerramientas() {
        limpiarPantalla();
        cout << "\n=== LISTA DE HERRAMIENTAS ===\n";
        for (auto& h : herramientas)
            h.mostrarInfo();
        pausar();
    }

    void mostrarTecnicos() {
        limpiarPantalla();
        cout << "\n=== LISTA DE TECNICOS ===\n";
        for (auto& t : tecnicos)
            t.mostrarInfo();
        pausar();
    }

    void diagnosticarEquipo() {
        limpiarPantalla();
        cout << "\n=== DIAGNOSTICO DE EQUIPO ===\n";
        cout << "Seleccione tipo de equipo:\n1. Computador\n2. Fuente de poder\nOpción: ";
        int op; cin >> op;
        cin.ignore();

        string marca;
        cout << "Marca del equipo: ";
        getline(cin, marca);

        EquipoElectronico* equipo = nullptr;
        if (op == 1) equipo = new Computador("C001", marca);
        else if (op == 2) equipo = new FuentePoder("F002", marca);
        else {
            cout << "Opción inválida.\n";
            pausar();
            return;
        }

        equipo->mostrarInfo();
        cout << equipo->analizarFalla() << endl;
        delete equipo;
        pausar();
    }

    void registrarMantenimiento() {
        limpiarPantalla();
        string fecha, falla;
        cout << "\n=== REGISTRO DE MANTENIMIENTO ===\n";
        cout << "Fecha (dd/mm/aaaa): ";
        getline(cin, fecha);
        cout << "Descripción de la falla: ";
        getline(cin, falla);

        Herramienta herramienta = herramientas[0];
        Tecnico tecnico = tecnicos[0];
        Mantenimiento nuevo(fecha, falla, herramienta, tecnico);
        mantenimientos.push_back(nuevo);

        cout << "\nMantenimiento registrado con éxito.\n";
        nuevo.mostrarResumen();
        pausar();
    }
};

// ====================== Función principal ======================
int main() {
    SetConsoleOutputCP(65001);
    Sistema sistema;
    sistema.menuPrincipal();
    return 0;
}
