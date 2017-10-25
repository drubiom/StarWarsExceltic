//Programa camino más corto entre planetas
//EXCELTIC
//DAVID RUBIO MATEOS (2º DAM COLEGIO SANTO DOMINGO SAVIO)
//This work is licensed under a Creative Commons Attribution-NonCommercial 4.0 International License.
//Algortimo basado en Dijkstra.
#include<stdio.h>
#include <stdlib.h>
#define INFINITO 9999
#define D 10
int solucion[10];

char planetas [10]={'A','B','C','D','E','F','G','H','I','J'};
int transforma (char);
 
void dijkstra(int distancias[D][D],int planetainicio, int planetadestino);
 
int main(){
    int distancias[D][D]= {{0,5,0,0,0,0,0,0,0,4},
		    			{5,0,4,5,6,0,0,0,0,0},
		    			{0,4,0,3,3,0,0,0,0,0},
		    			{0,5,3,0,0,10,0,0,3,0},
		    			{0,6,3,10,0,3,0,5,0,0},
		    			{0,0,0,0,3,0,1,0,0,0},
		    			{0,0,0,0,0,1,0,0,0,0},
		    			{0,0,0,0,5,0,0,0,2,4},
		    			{0,0,0,3,0,0,0,2,0,0},
		    			{4,0,0,0,0,0,0,4,0,0}};
    //Cabecera letras star wars
    printf( "========================================================================================================\n\n\n" );
    printf( "\t\t\t\t    8888888888  888    88888\n\t\t\t\t   88     88   88 88   88  88\n\t\t\t\t    8888  88  88   88  88888\n\t\t\t\t       88 88 888888888 88   88\n" );
    printf( "\t\t\t\t88888888  88 88     88 88    888888\n\n\t\t\t\t88  88  88   888    88888    888888\n\t\t\t\t88  88  88  88 88   88  88  88\n\t\t\t\t88 8888 88 88   88  88888    8888\n" );
    printf( "\t\t\t\t 888  888 888888888 88   88     88\n\t\t\t\t  88  88  88     88 88    8888888\n\n\n" );
    printf( "========================================================================================================\n" );
    printf( "\nBienvenido a bordo del Halcon Milenario. Le habla el comandante Han Solo. Espero que tenga una estancia \ncomoda a lo largo del viaje\n" );
    printf( "\nCon esta consola, seras capaz de ayudarme a viajar a traves de La Galaxia en el menor tiempo posible.\n\nEmpecemos!\n" );
    printf( "\nPrimero tienes que introducir el planeta de origen y el planeta de destino.\n" );
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
	dijkstra( distancias,numeroOrigen, numeroDestino);
	 printf( "   _____              _          __\n  |  _  |            | |        / _|\n");
     printf( "  | | | |_   _  ___  | | __ _  | |_ _   _  ___ _ __ ______ _\n  | | | | | | |/ _ \\ | |/ _` | |  _| | | |/ _ \\ '__|_  / _` |\n");
     printf( "  \\ \\/' / |_| |  __/ | | (_| | | | | |_| |  __/ |   / / (_| |\n   \\_/\\_\\\\__,_|\\___| |_|\\__,_| |_|  \\__,_|\\___|_|  /___\\__,_|\n");
     printf( "   _\n  | |                                              ____\n  | |_ ___    __ _  ___ ___  _ __ ___  _ __   __ _ _ __   ___\n");
     printf( "  | __/ _ \\  / _` |/ __/ _ \\| '_ ` _ \\| '_ \\ / _` | '_ \\ / _ \\ \n  | ||  __/ | (_| | (_| (_) | | | | | | |_) | (_| | | | |  __/\n");
     printf( "  \\__ \\___|  \\__,_|\\___\\___/|_| |_| |_| .__/ \\__,_|_| |_|\\___|\n                                      | |\n                                      |_|\n");
    return 0;
}
 
void dijkstra(int distancias[D][D],int planetainicio, int planetadestino){
    int aux[D][D],distanodo[D],prevnodo[D];
    int visitado[D],contador,distanciamin,proxnodo,i,j,h=0;
    for(i=0;i<D;i++)
        for(j=0;j<D;j++)
            if(distancias[i][j]==0)
                aux[i][j]=INFINITO;
            else
                aux[i][j]=distancias[i][j];
    for(i=0;i<D;i++) {
        distanodo[i]=aux[planetainicio][i];
        prevnodo[i]=planetainicio;
        visitado[i]=0;
    }
    distanodo[planetainicio]=0;
    visitado[planetainicio]=1;
    contador=1;
    while(contador<D-1){
        distanciamin=INFINITO;
        for(i=0;i<D;i++)
            if(distanodo[i]<distanciamin&&!visitado[i]){
                distanciamin=distanodo[i];
                proxnodo=i;
            }
            visitado[proxnodo]=1;
            for(i=0;i<D;i++)
                if(!visitado[i])
                    if(distanciamin+aux[proxnodo][i]<distanodo[i]){
                        distanodo[i]=distanciamin+aux[proxnodo][i];
                        prevnodo[i]=proxnodo;
                    }
        contador++;
    }
        if(planetadestino!=planetainicio) {
            printf( "\n================================================================\n" );
        	printf( "\nRuta mas rapida entre el planeta %c y el planeta %c:\n\n", planetas[planetainicio], planetas[planetadestino]);
            j=planetadestino;
            do{
                j=prevnodo[j];
                //guarda ruta en array solucion
                solucion[h]=j;
                h++;
            }while(j!=planetainicio);
            //imprimo array solucion invertido
            for(int l=h-1;l>=0;l--)
                 printf("%c-",planetas[solucion[l]]);
            printf("%c",planetas[planetadestino]);
            printf( "\n\nTiempo del viaje: %d\n\n", distanodo[planetadestino] );
        }
}

int transforma (char planeta){
		int numero = 0;
		switch (planeta) {
			case 'A': numero = 0;break;
			case 'B': numero = 1;break;
			case 'C': numero = 2;break;
			case 'D': numero = 3;break;
			case 'E': numero = 4;break;
			case 'F': numero = 5;break;
			case 'G': numero = 6;break;
			case 'H': numero = 7;break;
			case 'I': numero = 8;break;
			case 'J': numero = 9;break;
			case 'a': numero = 0;break;
			case 'b': numero = 1;break;
			case 'c': numero = 2;break;
			case 'd': numero = 3;break;
			case 'e': numero = 4;break;
			case 'f': numero = 5;break;
			case 'g': numero = 6;break;
			case 'h': numero = 7;break;
			case 'i': numero = 8;break;
			case 'j': numero = 9;break;
			default: printf("\nPlaneta no valido. Intentalo otra vez:\n");
			    numero = -1;
		}
		return numero;
}
