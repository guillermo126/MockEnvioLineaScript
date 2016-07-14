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
//static const char* DEFINICION_VARIABLES = "variables a";


int main(int argc, char *argv[]) {
	printf("hola1\n");
	int socketParaServidor = crearSocketCliente(PUERTO);
	printf("hola2\n");
	mensaje_UMC_CPU mensajeAEnviar;
	printf("hola3\n");
//	char* DEFINICION=malloc(strlen(DEFINICION_VARIABLES));
//	DEFINICION ="variables a";
	char* DEFINICION_VARIABLES = "variables a";


	mensajeAEnviar.texto=DEFINICION_VARIABLES;
	mensajeAEnviar.protocolo=INSTRUCCION;
	mensajeAEnviar.parametro=0;
	mensajeAEnviar.valor=4;
	mensajeAEnviar.tamanoMensaje=0;

	printf("hola4\n");
	enviarMensajeUMC_CPU(socketParaServidor,&mensajeAEnviar);
	printf("hola5\n");
	printf("la instruccion es: %s\n",mensajeAEnviar.texto);

	close(socketParaServidor);

	return 0;
}

