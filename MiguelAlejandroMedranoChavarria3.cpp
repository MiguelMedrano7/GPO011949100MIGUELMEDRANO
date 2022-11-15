#include<iostream>
#include<conio.h>
#include<string.h>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>

using namespace std;

int* numart, * year, registros, n = 1;
string* nombre, * clasf, * caract, * descp, * gnr;
float* preu, * iva, * total;

void alta();
void modificar();
void eliminar();
void lista();
void archivo();

int main()
{
	setlocale(LC_ALL, "spanish"); //Para que el programa corra en español
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	int opcion;

	printf("\t ***Chatows Games*** \n");
	printf("1.-Agregar Articulo \n2.-Modificar Articulo \n3.-Eliminar Articulo \n4.-Lista de Articulos \n5.-Limpiar pantalla \n6.-Salir \n");
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1: //Agregar Articulo
		alta();
		system("pause");
		return main();
		break;

	case 2: //Modificar Articulo
		modificar();
		system("pause");
		return main();
		break;

	case 3: //Eliminar Articulo
		eliminar();
		system("pause");
		return main();
		break;

	case 4:  // Lista de Articulos
		lista();
		system("pause");
		return main();
		break;

	case 5:   //Limpiar Pantalla
		system("cls");
		return main();
		break;

	case 6:  //Salir y guardar en texto
		archivo();
		exit(1);
		system("pause");
		break;

	default:   //En caso de que el usuario ingrese una opcion que no este entre el 1 al 6
		printf("Opcion incorrecta \nIngresa una opcion valida");
		system("pause");
		return main();
		break;
	}
}

void alta()
{
	printf("Cuantos registros quieres dar de alta: \n");
	scanf_s("%d", &registros);
	if (registros > 0)
	{
		numart = new int[registros];
		year = new int[registros];
		nombre = new string[registros];
		clasf = new string[registros];
		caract = new string[registros];
		gnr = new string[registros];
		descp = new string[registros];
		preu = new float[registros];
		iva = new float[registros];
		total = new float[registros];

		for (int i = 0; i < registros; i++)
		{
			printf("Ingresa el numero del articulo: \n");
			scanf_s("%d", &numart[i]);
			do
			{
				if (numart[i] != numart[i - n])
				{
					n = n + 1;
				}
				else
				{
					printf("Este articulo ya esta ocupado \n");
					printf("Ingresa el nuevo numero de articulo: \n");
					scanf_s("%d", numart[i]);
				}
			} while (n < registros);
			printf("Ingresa el año de lanzamiento: \n");
			scanf_s("%d", &year[i]);
			printf("Ingresa el nombre del juego: \n");
			cin.ignore();
			getline(cin, nombre[i]);
			printf("Ingresa la clasificacion del juego: \n");
			getline(cin, clasf[i]);
			printf("Ingresa las caracteristicas del juego: \n");
			getline(cin, caract[i]);
			printf("Ingresa el genero del juego: \n");
			getline(cin, gnr[i]);
			printf("Ingresa la descripcion del juego: \n");
			getline(cin, descp[i]);
			printf("Ingresa el precio del juego: \n");
			scanf_s("%f", &preu[i]);
			iva[i] = preu[i] * .16;
			total[i] = preu[i] + iva[i];
			printf("---------------------------------------------------- \n\n");  //separadores para que se vea mas ordenado



			if (i == (registros - 1))
			{
				break;

			}
		}
	}
	else
	{
		printf("El valor ingresado no es valido \n");
	}
}

void modificar()
{
	int mod;

	printf("Ingresa el numero de articulo a modificar: \n");
	scanf_s("%d", &mod);
	if (mod > 0)
	{
		for (int i = 0; i < registros; i++)
		{
			if (mod == numart[i])
			{
				printf("Ingresa el año de lanzamiento: \n");
				scanf_s("%d", &year[i]);
				printf("Ingresa el nombre del juego: \n");
				cin.ignore();
				getline(cin, nombre[i]);
				printf("Ingresa la clasificacion del juego: \n");
				getline(cin, clasf[i]);
				printf("Ingresa las caracteristicas del juego: \n");
				getline(cin, caract[i]);
				printf("Ingresa el genero del juego: \n");
				getline(cin, gnr[i]);
				printf("Ingresa la descripcion del juego: \n");
				getline(cin, descp[i]);
				printf("Ingresa el precio del juego: \n");
				scanf_s("%f", &preu[i]);
				iva[i] = preu[i] * .16;
				total[i] = preu[i] + iva[i];
			}
		}
	}
	else
	{
		printf("Opcion invalida \n");
	}

}

void eliminar()
{
	int elm;
	printf("Ingresa el numero de articulo a eliminar: \n");
	scanf_s("%d", &elm);

	for (int i = 0; i < registros; i++)
	{
		if (elm == numart[i])
		{
			numart[i] = 0;
		}
	}

}

void lista()
{
	int op2 = 0;
	string busc;

	printf("Buscar por \n1.-Clasificacion \n2.-Genero \n3.-Ver todos \n4.-Salir \n");
	scanf_s("%d", &op2);

	switch (op2)
	{

	case 1:
		printf("Ingresa la clasificacion a buscar: \n");
		cin.ignore();
		getline(cin, busc);
		for (int i = 0; i < registros; i++)
		{
			if (clasf[i] == busc)
			{
				printf("Numero articulo: %d \n", numart[i]);
				printf("Año: %d \n", year[i]);
				printf("Nombre: %s \n", nombre[i].c_str());
				printf("Clasificacion: %s \n", clasf[i].c_str());
				printf("Genero: %s \n", gnr[i].c_str());
				printf("Caracteristicas: %s \n", caract[i].c_str());
				printf("Descripcion: %s \n", descp[i].c_str());
				printf("Precio: %f \n", preu[i]);
				printf("Iva: %f \n", iva[i]);
				printf("Total: %f \n", total[i]);
			}
		}
		break;

	case 2:
		printf("Ingresa el genero a buscar: \n");
		cin.ignore();
		getline(cin, busc);
		for (int i = 0; i < registros; i++)
		{
			if (gnr[i] == busc)
			{
				printf("Numero articulo: %d \n", numart[i]);
				printf("Año: %d \n ", year[i]);
				printf("Nombre: %s \n", nombre[i].c_str());
				printf("Clasificacion: %s \n", clasf[i].c_str());
				printf("Genero: %s \n", gnr[i].c_str());
				printf("Caracteristicas: %s \n", caract[i].c_str());
				printf("Descripcion: %s \n", descp[i].c_str());
				printf("Precio: %f \n", preu[i]);
				printf("Iva: %f \n", iva[i]);
				printf("Total: %f \n", total[i]);
			}
		}
		break;

	case 3:
		for (int i = 0; i < registros; i++)
		{
			if (numart[i] != 0)
			{
				printf("Numero articulo: %d \n", numart[i]);
				printf("Año: %d \n ", year[i]);
				printf("Nombre: %s \n", nombre[i].c_str());
				printf("Clasificacion: %s \n", clasf[i].c_str());
				printf("Genero: %s \n", gnr[i].c_str());
				printf("Caracteristicas: %s \n", caract[i].c_str());
				printf("Descripcion: %s \n", descp[i].c_str());
				printf("Precio: %f \n", preu[i]);
				printf("Iva: %f \n", iva[i]);
				printf("Total: %f \n", total[i]);
			}
		}

	case 4:
		break;

	default:
		printf("Opcion incorrecta \nIngresa una opcion valida \n");
		return lista();
		break;
	}
}

void archivo()
{
	ofstream archivo;
	string nombredelarchivo;

	nombredelarchivo = "CHATOWSGAMES";
	archivo.open(nombredelarchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		printf("ERROR NO SE GENERO EL ARCHIVO \n");
		system("pause");
		exit(1);
	}

	archivo << "\t\t INFORMACION \n";
	for (int i = 0; i < registros; i++)
	{
		if (numart[i] != 0)
		{
			archivo << "Registro " << i + 1 << endl;
			archivo << "Numero articulo: " << numart[i] << endl;
			archivo << "Año: " << year[i] << endl;
			archivo << "Nombre: " << nombre[i].c_str() << endl;
			archivo << "Clasificacion: " << clasf[i].c_str() << endl;
			archivo << "Genero: " << gnr[i].c_str() << endl;
			archivo << "Caracteristicas: " << caract[i].c_str() << endl;
			archivo << "Descripcion: " << descp[i].c_str() << endl;
			archivo << "Precio: " << preu[i] << endl;
			archivo << "Iva: " << iva[i] << endl;
			archivo << "Total: " << total[i] << endl;
		}
	}

	archivo.close();
}