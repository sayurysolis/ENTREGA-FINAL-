#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<stdlib.h>
#include <vector>

using namespace std;

void Agregar();
void Lista();
void Archivo();
void Eliminar();
void Modificar();

int jgo, * juego, * genero, * cdj, * anio, * prunt, * total, * subt;
string* nombre, * gene, * cara;
int main()
{
    int opc;
    cout << "1.- AGREGAR ARTICULO" << endl;
    cout << "2.- LISTA DE ARTICULOS" << endl;
    cout << "3.- LIMPIAR PANTALLA" << endl;
    cout << "4.- MODIFICAR ARTICULO" << endl;
    cout << "5.- ELIMINAR ARTICULO" << endl;
    cout << "6.- SALIR" << endl;

    cin >> opc;

    switch (opc)
    {
    case 1:
        Agregar();
        return main();
        break;

    case 2:
        Lista();
        return main();

    case 3:
        system("cls");
        return main();
        break;

    case 4:
        Modificar();
        return main();
        break;

    case 5:
        Eliminar();
        return main();
        break;

    case 6:
        Archivo();
        break;
    }
}

void Agregar()
{
    cout << "Escriba cuantos juegos desea registrar" << endl;
    cin >> jgo;
    prunt = new int[jgo];
    anio = new int[jgo];
    cdj = new int[jgo];
    subt = new int[jgo];
    total = new int[jgo];
    gene = new string[jgo];
    cara = new string[jgo];
    nombre = new string[jgo];

    for (int i = 0; i < jgo; i++)
    {
        cout << "ID del juego : " << i << endl;
        while (getchar() != '\n');
        cout << "Ingrese nombre del juego : " << endl;
        getline(cin, nombre[i]);
        cout << "Ingrese el genero del juego : " << endl;
        getline(cin, gene[i]);
        cout << "Ingrese descripcion del juego : " << endl;
        getline(cin, cara[i]);
        cout << "Ingrese la cantidad de juegos en existencia : " << endl;
        cin >> cdj[i];
        cout << "Ingrese precio unitario del juego : " << endl;
        cin >> prunt[i];
        cout << "Ingrese el anio de lanzamiento: " << endl;
        cin >> anio[i];
    }
}

void Lista()
{
    for (int i = 0; i < jgo; i++)
    {
        if (jgo == 0)
        {
            cout << "Registro eliminado" << i + 1 << endl;
        }
        else
        {
            cout << "Registro: " << i + 1 << endl;
            cout << nombre[i] << endl;
            cout << gene[i] << endl;
            cout << cara[i] << endl;
            cout << cdj[i] << endl;
            cout << prunt[i] << endl;
            subt[i] = cdj[i] * prunt[i];
            cout << subt[i] << endl;
            total[i] = (subt[i] * .16) + subt[i];
            cout << total[i] << endl;
            cout << anio[i] << endl;
        }
    }
}

void Archivo()
{
    ofstream archivo;
    string nombrearchivo;
    string texto;
    int texto2;

    nombrearchivo = "juegos";

    archivo.open(nombrearchivo.c_str(), ios::out);

    if (archivo.fail())
    {
        cout << "Error no se pudo crear el archivo";
        exit(1);
    }

    archivo << "prunt" << "\t";
    archivo << "anio" << "\t";
    archivo << "cdj" << "\t";
    archivo << "subt" << "\t";
    archivo << "total" << "\t";
    archivo << "gene" << "\t";
    archivo << "cara" << "\t";
    archivo << "nombre" << "\t";

    for (int i = 0; i < jgo; i++)
    {
        if (anio[i] == 0)
        {

        }
        else
        {
            texto = nombre[i];
            archivo << texto << "\t" << "\t";
            texto = gene[i];
            archivo << texto << "\t" << "\t";
            texto = cara[i];
            archivo << texto << "\t" << "\t";
            texto2 = cdj[i];
            archivo << texto << "\t" << "\t";
            texto2 = prunt[i];
            archivo << texto << "\t" << "\t";
            subt[i] = cdj[i] * prunt[i];
            texto2 = subt[i];
            archivo << texto << "\t" << "\t";
            total[i] = (subt[i] * .16) + subt[i];
            texto2 = total[i];
            archivo << texto << "\t" << "\t";
            texto2 = anio[i];
            archivo << texto << "\t" << "\t";
        }
    }
    archivo.close();
}

void Eliminar()
{
    int j;
    cout << "Ingrese el juego a eliminar ";
    cin >> j;
    j = j - 1;
    for (int i = j; i == j; i++)
    {
        cout << "Eliminar juego : " << j + 1 << endl;

        prunt[i] = 0;
        anio[i] = 0;
        cdj[i] = 0;
        subt[i] = 0;
        gene[i] = " ";
        cara[i] = " ";
        nombre[i] = " ";
    }
}

void Modificar()
{
    int j, opcion;
    cout << "Ingrese el juego a modificar";
    cin >> j;
    j = j - 1;
    cout << "ingrese que desea modificar " << endl;
    cout << " 1. - Nombre del juego" << endl;
    cout << "2. - genero " << endl;
    cout << "3. - Cantidad de juegos en exitencia" << endl;
    cout << "4. - Precio unitario" << endl;
    cout << "5. - anio de lanzamiento" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n');
            cout << "Ingrese nombre del juego: " << endl;
            getline(cin, nombre[i]);
        }
        break;
    case 2:
        for (int i = j; i == j; i++)
        {
            while (getchar() != '\n');
            cout << "Ingrese el genero: " << endl;
            getline(cin, gene[i]);
            cout << "Ingrese descripcion del juego: " << endl;
            getline(cin, cara[i]);
        }
        break;
    case 3:
        for (int i = j; i == j; i++)
        {
            cout << "Ingrese la cantidad del juegos existentes : " << endl;
            cin >> cdj[i];
        }
        break;
    case 4:
        for (int i = j; i == j; i++)
        {
            cout << "Ingrese precio unitario del juego: " << endl;
            cin >> prunt[i];
        }
        break;
    case 5:
        for (int i = j; i == j; i++)
        {
            for (int anio = 1000; anio < 2023; anio++)
                cout << "anio de lanzamiento: " << endl;
            cin >> anio[i];
        }
    }
}
