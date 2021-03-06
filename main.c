/*
 * main.c
 *
 *  Created on: Jun 12, 2013
 *      Author: emanuel
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "handle_input.h"

#include "algorithm1.h"
//#include "algorithm2.h"

int main(int argc, char *argv[])
{
	int algorithm, seed;
	char operation;
	char *filename_in, *filename_out, *filename_key;


	/*nao alocar nada antes desse ponto,
	 * pois handle input pode dar exit(1)
	 * ocasionado leak memory
	 */
	handleInput(argc, argv);


	//argc e argv estao ok nesse ponto!
	algorithm = atoi(argv[1]);
	operation = argv[2][0];
	filename_key = argv[3];



	//algoritmo 1
	if(algorithm == 1)
	{
		if(operation == 'K')
		{
			//gera chave
			seed = atoi(argv[4]);
			chaos_genkey(filename_key, seed);
		}


		filename_in = argv[4];
		filename_out = argv[5];

		if(operation == 'E')
		{
			chaos_enc(filename_in, filename_out, filename_key);

		}

		if(operation == 'D')
		{
			//desencripta
			chaos_dec(filename_in, filename_out, filename_key);

		}


	}

	//algoritmo 2
	if(algorithm == 2)
	{
		if(operation == 'K')
		{

			//gera chave
			seed = atoi(argv[4]);
			chaos_genkey(filename_key, seed);
		}




		filename_in = argv[4];
		filename_out = argv[5];

		char * args[6];
		args[0] = "/bin/java";
		args[1] = "Rc4";
		args[2] = filename_in;
		args[3] = filename_out;
		args[4] = filename_key;
		args[5] = NULL;




		//abre arquivos e entrada e saida
		if(operation == 'E')
		{
			//encripta
			execve("/bin/java", args, NULL);

		}

		if(operation == 'D')
		{
			//encripta
			execve("/bin/java", args, NULL);

		}



	}


	return 0;
}

