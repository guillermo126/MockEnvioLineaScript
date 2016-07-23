#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdint.h>
#include <errno.h>
#include <sw_sockets.h>
#include <stdio.h>
#include <tiposDato.h>
#define PUERTO 7100
#define PACKAGESIZE 1024
static const char* DEFINICION_VARIABLES = "variables a";

void mostrarPCB(pcb* unPCB) {
 printf("\nIDENTIFICADOR:%d\n", unPCB->identificador);
 printf("CANTIDAD_DE_INSTRUCCIONES: %d\n", unPCB->cant_instrucciones);
 printf("CANTIDAD_DE_NIVELES_DE_STACK: %d\n", unPCB->cantidadDeNivelesStack);
 printf("INDICE_DE_STACK: %d\n", list_size(unPCB->indiceDeStack));
 printf("PAGINA_DE_CODIGO: %d\n", unPCB->paginaDeCodigo);
 printf("PAGINA_DE_STACK: %d\n", unPCB->paginaDeStack);
 printf("PROGRAM_COUNTER:%d\n", unPCB->program_counter);
 printf("QUANTUM: %d\n", unPCB->quantum);
 printf("TAMAÑO ETIQUETAS: %d\n", unPCB->tamano_etiquetas);
}





int main(int argc, char *argv[]) {
	printf("hola1\n");
	int socketParaServidor = crearSocketCliente(PUERTO);
	printf("hola2\n");
	mensaje_UMC_CPU mensajeAEnviar;
	mensaje_CPU_NUCLEO mensajeARecibir;

	pcb unPcb;




//	malloc(strlen("variables a"))

//	   int len=strlen(DEFINICION_VARIABLES);

//	   strcpy(mensajeAEnviar.texto,DEFINICION);


	recibirmensajeCPU_NUCLEO(socketParaServidor, &mensajeARecibir,
				&unPcb);

	if(mensajeARecibir.protocolo== FINALIZAR){
		printf("llego finalizar");

	}

	printf("el valor del parametro es:%s\n",mensajeARecibir.parametro);

	printf("el valor del tamanioParametro es:%d\n",mensajeARecibir.tamanioParametro);
	printf("el valor del valor es:%d\n",mensajeARecibir.valor);


	mostrarPCB(&unPcb);
	printf("hola4\n");

	printf("hola5\n");

	sleep(5);

	close(socketParaServidor);

	return 0;
}

