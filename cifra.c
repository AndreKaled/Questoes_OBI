#include <stdio.h>

#define TAM 50

char converteMinusculo(char letra){

	if(letra>='A'&&letra<='Z')		letra+= 33;

	return letra;

}

char buscaProxVogal(char x){

	x = converteMinusculo(x);

	

	int a=0,b=0,contAntes=0,contDepois=0;

	char letra = x;

	

	while(true){

		if(letra=='a'||letra=='e'||letra=='i'||letra=='o'||letra=='u'){

			a=letra;

			break;

		}

		letra++;

		contDepois++;

	}

	letra = x;

	while(true){

		if(letra=='a'||letra=='e'||letra=='i'||letra=='o'||letra=='u'){

			b=letra;

			break;

		}

		letra--;

		contAntes++;

	}

	if(contAntes<=contDepois){

		return b;

	}else{

		return a;

	}

}

char proxConsoante(char x){

	x = converteMinusculo(x);

	while(x!='z'){

		x++;

		if(!(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')){

			break;

		}

	}

	return x;

}

main(){

    char sInput[TAM], cifrado[TAM];

    scanf("%s", &sInput);

	int cont=0;

	for(int i=0; i<TAM;){

		if(!(sInput[cont]=='a'||sInput[cont]=='e'||sInput[cont]=='i'||sInput[cont]=='o'||sInput[cont]=='u')){

			cifrado[i]=sInput[cont];

			cifrado[i+1]=buscaProxVogal(sInput[cont]);

			cifrado[i+2]=proxConsoante(sInput[cont]);

			i+=3;

		}else{

			cifrado[i]=sInput[cont];

			i++;

		}

		cont++;

	}

	

	printf("%s", cifrado);

	

}
