//Programa camino más corto entre planetas
//EXCELTIC
//DAVID RUBIO MATEOS (2º DAM COLEGIO SANTO DOMINGO SAVIO)
//This work is licensed under a Creative Commons Attribution-NonCommercial 4.0 International License.
//Algortimo basado en Dijkstra.
#include <stdlib.h>
#include <stdio.h>

struct viaje {
	int numero;
	int previo;
	int tiempo;
	int marcado;
};
typedef struct viaje viaje_t;
char planetas [10]={'A','B','C','D','E','F','G','H','I','J'};
int transforma (char);
struct nodo {
	int dato;
	struct nodo * nextnodo;
};
typedef struct nodo nodo_t;
int isEmpty( nodo_t * );
int insert( nodo_t **, int, viaje_t * );
void quit( nodo_t **, int );
int pop( nodo_t ** );
void printQueue( nodo_t * );

void dijkstra( int N, int **A, int a, int b ) {
	viaje_t *ViajeActual;
	int i, i0, j, peso;
	int *ruta;
	nodo_t *Cola = NULL;
	if ( ( ViajeActual = malloc( N * sizeof( viaje_t ) ) ) == NULL ) return;
	if ( a < 0 || a > N - 1 ) return;
	if ( b < 0 || b > N - 1 ) return;
	for ( i = 0; i < N; i++ ) {
		ViajeActual[i].numero = i;
		if ( i != a ) {
			ViajeActual[i].previo = -1;
			ViajeActual[i].tiempo = -1;
			ViajeActual[i].marcado = 0;
		}
		else {
			ViajeActual[i].previo = -1;
			ViajeActual[i].tiempo = 0;
			ViajeActual[i].marcado = 0;
		}
	}
	insert( &Cola, a, ViajeActual );
	while ( !isEmpty( Cola ) ) {
		i0 = pop( &Cola );
		for ( i = 0; i < N; i++ ) {
			if ( A[i0][i] > 0 && ViajeActual[i].marcado == 0 ) {
				if ( ViajeActual[i].tiempo == -1 ) {
					ViajeActual[i].tiempo = ViajeActual[i0].tiempo + A[i0][i];
					insert( &Cola, i, ViajeActual );
				}
				else if ( ViajeActual[i0].tiempo + A[i0][i] < ViajeActual[i].tiempo ) {
					ViajeActual[i].tiempo = ViajeActual[i0].tiempo + A[i0][i];
					quit( &Cola, i );
					insert( &Cola, i, ViajeActual );
				}
				ViajeActual[i].previo = i0;
			}
		}
		ViajeActual[i0].marcado = 1;
	}
	int longitud = 2;
	i = b;
	while ( ( i = ViajeActual[i].previo ) != a ) longitud++;
	if ( ( ruta = malloc( longitud * sizeof(int) ) ) == NULL ) return;
	ruta[longitud - 1] = b;
	i = b;
	j = 0;
	for ( j = 1; j < longitud; j++ ) {
		i = ViajeActual[i].previo;
		ruta[longitud - j - 1] = i;
	}
	printf( "\n================================================================\n" );
	printf( "\nRuta mas rapida entre el planeta %c y el planeta %c:\n\n", planetas[a], planetas[b] );
	for ( i = 0; i < longitud; i++ ) {
		printf( "%c", planetas[ruta[i]]);
		if ( i < longitud - 1 ) printf( " - " );
	}
	printf( "\n\nTiempo del viaje: %d\n\n", ViajeActual[b].tiempo );

	free( ruta );
	free( ViajeActual );
}

int main () {
    //Cabecera letras star wars
    printf( "========================================================================================================\n\n\n" );
    printf( "                                  8888888888  888    88888\n" );
    printf( "                                 88     88   88 88   88  88\n" );
    printf( "                                  8888  88  88   88  88888\n" );
    printf( "                                     88 88 888888888 88   88\n" );
    printf( "                              88888888  88 88     88 88    888888\n\n" );
    printf( "                              88  88  88   888    88888    888888\n" );
    printf( "                              88  88  88  88 88   88  88  88\n" );
    printf( "                              88 8888 88 88   88  88888    8888\n" );
    printf( "                               888  888 888888888 88   88     88\n" );
    printf( "                                88  88  88     88 88    8888888\n\n\n" );
    printf( "========================================================================================================\n" );
    printf( "\nBienvenido a bordo del Halcon Milenario. Le habla el comandante Han Solo. Espero que tenga una estancia \n" );
    printf( "comoda a lo largo del viaje\n" );
    printf( "\nCon esta consola, seras capaz de ayudarme a viajar a traves de La Galaxia en el menor tiempo posible.\n" );
    printf( "\nEmpecemos!\n" );
    printf( "\nPrimero tienes que introducir el planeta de origen y el planeta de destino.\n" );
	int i, j;
	//cantidad de nodos
	int numNodos = 10;
	//se define la matriz
	int **distancias;
	if ( ( distancias = (int **) malloc( numNodos * sizeof(int *) ) ) == NULL ) return 1;
	for ( i = 0; i < numNodos; i++ )
		if ( ( distancias[i] = (int *) malloc( numNodos * sizeof(int) ) ) == NULL ) return 1;
	for ( i = 0; i < numNodos; i++ )
		for ( j = 0; j < numNodos; j++ )
			distancias[i][j] = 0;
	//metemos los datos de distancia entre planetas
   distancias[0][1] = 5;
   distancias[0][9] = 4;
   distancias[1][0] = 5;
   distancias[1][2] = 4;
   distancias[1][3] = 5;
   distancias[1][4] = 6;
   distancias[2][1] = 4;
   distancias[2][3] = 3;
   distancias[2][4] = 3;
   distancias[3][1] = 5;
   distancias[3][2] = 3;
   distancias[3][5] = 10;
   distancias[3][8] = 3;
   distancias[4][1] = 6;
   distancias[4][2] = 3;
   distancias[4][3] = 10;
   distancias[4][5] = 3;
   distancias[4][7] = 5;
   distancias[5][4] = 3;
   distancias[5][6] = 1;
   distancias[6][5] = 1;
   distancias[7][4] = 5;
   distancias[7][8] = 2;
   distancias[7][9] = 4;
   distancias[8][3] = 3;
   distancias[8][7] = 2;
   distancias[9][0] = 4;
   distancias[9][7] = 4;
    char origen, destino;
    int numeroOrigen,numeroDestino;
	do{
        do{
        printf("Planeta Origen:");
        scanf(" %c", &origen);
        }while (transforma(origen) == -1 );
        do{
        printf("Planeta Destino:");
        scanf(" %c", &destino);
        }while (transforma(destino) == -1 );
        //cambia de letra a numero
        numeroOrigen = transforma(origen);
        numeroDestino = transforma(destino);
        if(numeroOrigen == numeroDestino)
            printf("El planeta de origen y el planeta de destino, es el mismo!!\n");
	}while(transforma(destino) == transforma(origen));
	//llama al algoritmo
	if (transforma(destino) != transforma(origen))
	dijkstra( numNodos, distancias, numeroOrigen, numeroDestino );
	system("pause");
	printf("\e[1;1H\e[2J");
	 printf( "   _____              _          __\n");
     printf( "  |  _  |            | |        / _|\n");
     printf( "  | | | |_   _  ___  | | __ _  | |_ _   _  ___ _ __ ______ _\n");
     printf( "  | | | | | | |/ _ \\ | |/ _` | |  _| | | |/ _ \\ '__|_  / _` |\n");
     printf( "  \\ \\/' / |_| |  __/ | | (_| | | | | |_| |  __/ |   / / (_| |\n");
     printf( "   \\_/\\_\\\\__,_|\\___| |_|\\__,_| |_|  \\__,_|\\___|_|  /___\\__,_|\n");
     printf( "   _\n");
     printf( "  | |                                              ____\n");
     printf( "  | |_ ___    __ _  ___ ___  _ __ ___  _ __   __ _ _ __   ___\n");
     printf( "  | __/ _ \\  / _` |/ __/ _ \\| '_ ` _ \\| '_ \\ / _` | '_ \\ / _ \\ \n");
     printf( "  | ||  __/ | (_| | (_| (_) | | | | | | |_) | (_| | | | |  __/\n");
     printf( "  \\__ \\___|  \\__,_|\\___\\___/|_| |_| |_| .__/ \\__,_|_| |_|\\___|\n");
     printf( "                                      | |\n");
     printf( "                                      |_|\n");
	// se libera memoria
	for ( i = 0; i < numNodos; i++ )
		free( distancias[i] );
	free( distancias );
	return 0;
}

int transforma (char planeta){
		int numero = 0;
		switch (planeta) {
			case 'A': numero = 0;
			break;
			case 'B': numero = 1;
			break;
			case 'C': numero = 2;
			break;
			case 'D': numero = 3;
			break;
			case 'E': numero = 4;
			break;
			case 'F': numero = 5;
			break;
			case 'G': numero = 6;
			break;
			case 'H': numero = 7;
			break;
			case 'I': numero = 8;
			break;
			case 'J': numero = 9;
			break;
			case 'a': numero = 0;
			break;
			case 'b': numero = 1;
			break;
			case 'c': numero = 2;
			break;
			case 'd': numero = 3;
			break;
			case 'e': numero = 4;
			break;
			case 'f': numero = 5;
			break;
			case 'g': numero = 6;
			break;
			case 'h': numero = 7;
			break;
			case 'i': numero = 8;
			break;
			case 'j': numero = 9;
			break;
			default: printf("\nPlaneta no valido. Intentalo otra vez:\n");
			    numero = -1;
		}
		return numero;
}

//Si la cola está vacia
int isEmpty( nodo_t * head ) {
	return head == NULL;
}

//inserta en la cola
int insert( nodo_t ** frontPtr, int nodeNumber, viaje_t * ViajeActual ) {
	nodo_t *newPtr, *currentPtr, *prevPtr;
	if ( ( newPtr = malloc( sizeof( nodo_t ) ) ) == NULL ) return 1;
	currentPtr = *frontPtr;
	prevPtr = NULL;
	while ( currentPtr != NULL && ViajeActual[currentPtr->dato].tiempo < ViajeActual[nodeNumber].tiempo ) {
		prevPtr = currentPtr;
		currentPtr = currentPtr->nextnodo;
	}
	newPtr->dato = nodeNumber;
	if ( currentPtr != NULL )
		newPtr->nextnodo = currentPtr;
	else
		newPtr->nextnodo = NULL;
	if ( prevPtr != NULL )
		prevPtr->nextnodo = newPtr;
	else
		*frontPtr = newPtr;
	return 0;
}

void quit( nodo_t ** frontPtr, int dato ) {
	nodo_t *prevPtr = NULL, *currPtr = *frontPtr;
	while ( currPtr != NULL && currPtr->dato != dato ) {
		prevPtr = currPtr;
		currPtr = currPtr->nextnodo;
	}
	if ( currPtr == NULL ) return;
	if ( prevPtr != NULL )
		prevPtr->nextnodo = currPtr->nextnodo;
	else
		*frontPtr = currPtr->nextnodo;
	free( currPtr );
}

int pop( nodo_t **frontPtr ) {
	nodo_t *auxPtr;
	int dato;
	if ( *frontPtr != NULL ) {
		auxPtr = *frontPtr;
		*frontPtr = (*frontPtr)->nextnodo;
		dato = auxPtr->dato;
		free( auxPtr );
		return dato;
	}
	else
		return 0;
}

void printQueue( nodo_t *queue ) {
	nodo_t *currPtr = queue;
	if ( currPtr == NULL ) {
		printf( "(vacio)\n" );
		return;
	}
	while ( currPtr != NULL ) {
		printf( "%d", currPtr->dato );
		if ( currPtr->nextnodo != NULL ) printf( " -> " );
		currPtr = currPtr->nextnodo;
	}
	printf( "\n" );
}