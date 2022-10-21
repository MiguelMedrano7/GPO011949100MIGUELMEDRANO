#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>


using namespace std;



struct empresa
{
	//Declaracion de variables

	int idcontrato, NumArt;
	string proveedor, NomVid, Clas, Cara, Des, Genero, Lanz;
	float subtotal, iva, total;
};


int main()
{
	empresa compras[3];
	int opcion, busqueda, opcion2;

	do
	{
		printf("\t ***Gamer's Stuff *** \n");
		printf("1.-Agregar Articulo \n2-. Modificar Articulo \n3-. Eliminar Articulo \n4-. Lista de articulos vigentes \n5-. Limpiar pantalla \n6-. Salir\n");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		case 1:
			//Capturar y guardar los datos por posicion
			for (int i = 0; i < 3; i++)
			{
				compras[i].idcontrato = 20220000 + i;
				printf("ID CONTRATO: %d \n", compras[i].idcontrato);
				int salida = 1;

				do
				{
					printf("Ingresa el Numero de Articulo \n");
					scanf_s("%d", &compras[i].NumArt);
				} while (compras[i].NumArt == compras[i - 1].NumArt || compras[i].NumArt == compras[i - 2].NumArt);


				//Proveedor 
				printf("Ingresa el proveedor \n");
				cin.ignore();
				getline(cin, compras[i].proveedor);
				printf("Ingresa el nombre del videojuego \n");
				cin.ignore();
				getline(cin, compras[i].NomVid);
				printf("Ingresa el a�o de lanzamiento \n");
				cin.ignore();
				getline(cin, compras[i].Lanz);
				printf("Ingresa la clasificacion del videojuego \n");
				cin.ignore();
				getline(cin, compras[i].Clas);
				printf("Ingresa las caracteristicas del juego \n");
				cin.ignore();
				getline(cin, compras[i].Cara);
				printf("Ingresa una descripcion \n");
				cin.ignore();
				getline(cin, compras[i].Des);
				printf("Ingresa el genero \n");
				cin.ignore();
				getline(cin, compras[i].Genero);
				printf("Ingresa el subtotal \n");
				scanf_s("%f", &compras[i].subtotal);
				compras[i].iva = compras[i].subtotal * .16;
				compras[i].total = compras[i].subtotal + compras[i].iva;
			}
			break;

		case 2:
			system("cls");
			printf("Ingresa el articulo a modificar \n");
			system("pause");
			return main();

			break;


		case 3:// No hace nada
			printf("Ingresa el Numero del Articulo");
			scanf_s("%d", &busqueda);

			//Imprimir los datos por posicion 
			for (int i = 0; i < 3; i++)
			{
				if (busqueda == compras[i].NumArt)
				{
					compras[i].NumArt = 0;
				}
			}
			break;

		case 4:

			printf("1.-Lista de Articulos \n2.-Busqueda por Clasificacion \n3-. Busqueda por Genero\n");
			scanf_s("%d", &opcion2);

			switch (opcion2)
			{
			case 1:

				for (int i = 0; i < 3; i++)
				{
					printf("ID CONTRATO: %d \n", compras[i].idcontrato);
					printf("Nombre del Videojuego: %s\n", compras[i].NomVid.c_str());
					printf("Num de articulo: %d \n", compras[i].NumArt);
					printf("Proveedor %s", compras[i].proveedor.c_str());
					printf("A�o de lanzamiento: %s\n", compras[i].Lanz.c_str());
					printf("Clasificacion del juego: %s\n", compras[i].Clas.c_str());
					printf("Caracteristicas del juego: %s\n", compras[i].Cara.c_str());
					printf("Descripcion del juego: %s\n", compras[i].Des.c_str());
					printf("Genero del juego: %s\n", compras[i].Genero.c_str());
					printf("Subtotal: %f \n", compras[i].subtotal);
					printf("iva: %f \n", compras[i].iva);
					printf("Total: %f \n", compras[i].total);
				}
				break;

			case 2:
				string Genero;
				for (int i = 0; i < 3; i++)
				{
					printf("Ingresa el genero del juego\n");
					scanf_s("%s", &Genero);

					if (Genero == compras[i].Genero.c_str())
					{

						printf("ID CONTRATO: %d \n", compras[i].idcontrato);
						printf("Nombre del Videojuego: %s\n", compras[i].NomVid.c_str());
						printf("Num de articulo: %d \n", compras[i].NumArt);
						printf("Proveedor %s", compras[i].proveedor.c_str());
						printf("A�o de lanzamiento: %s\n", compras[i].Lanz.c_str());
						printf("Clasificacion del juego: %s\n", compras[i].Clas.c_str());
						printf("Caracteristicas del juego: %s\n", compras[i].Cara.c_str());
						printf("Descripcion del juego: %s\n", compras[i].Des.c_str());
						printf("Genero del juego: %s\n", compras[i].Genero.c_str());
						printf("Subtotal: %f \n", compras[i].subtotal);
						printf("iva: %f \n", compras[i].iva);
						printf("Total: %f \n", compras[i].total);


					}
					else
					{
						printf("El genero seleccionado no existe\n");
						break;
					}

				}
				break;

			}


		case 5:

			system("cls");
			break;

		case 6:
			printf("Saliendo del programa...\n");
			break;

		default:
			printf("Ingresa un nuevo digito\n");
			break;

		}
	} while (opcion != 6);
	system("pause");
}
