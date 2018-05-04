

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "altera_avalon_pio_regs.h"

void swit(int x);
void imp(int vector);
void impDraw();

int main()
{
	//Insert this in the input stream to simulate a draw game: 001002012111122220
	int meas = 3;
	int stop = 0;

	char use[meas][meas];
	int uno;
	int dos;
	for (uno = 0; uno < meas; uno++) {
		for ( dos = 0; dos < meas; dos++) {
			use[uno][dos] = '0';

		}
	}

	int retur = 0, retur1 = 0;

	int rec1x=0;
	int rec2x=0;

	char li="";
	char li2="";
	int var=-1,var2=-1;

	do {



		if (stop ==9 ){
			alt_putstr("empatou\n");
			impDraw();

		}
		stop+=1;

		do {



			alt_putstr("digite a linha de x\n");

			while(0 > var){
				li=alt_getchar();
				var=li - '0';
			}

			alt_putstr("digite a coluna de x\n");
			while(0 > var2){

				li2=alt_getchar();

				var2=li2 - '0';
			}

			if(use[var][var2] == '0'){
				retur = 1;
			}
			else {
				alt_putstr("Está ocupado este espaço\n");
				var=-1;
				var2=-1;
			}
		} while (retur != 1);

		retur = 0;

		use[var][var2] = 'x';
		var=-1;
		var2=-1;


		func(use);
		if (stop == 9){
			alt_putstr("empatou\n");
			impDraw();

		}

		/////vez do bolinha
		do {



			alt_putstr("digite a linha de o\n");

			while(0 > var){
				li=alt_getchar();
				var=li - '0';
			}




			alt_putstr("digite a coluna de o\n");
			while(0 > var2){

				li2=alt_getchar();

				var2=li2 - '0';
			}


			if (use[var][var2] == '0'){
				retur1 = 1;
			}
			else{
				alt_putstr("Está ocupado este espaço\n");
				var=-1;
				var2=-1;
			}

		} while (retur1 != 1);

		retur1 = 0;

		use[var][var2] = 'o';
		var=-1;
		var2=-1;
		stop++;




		func(use);


	} while (stop != 100);

	return 0;

}


void swit(int x){
	switch(x){

	case 1:{//primeira linha
		imp(7);
	}
	case 2:{///ultima linha
		imp(448);
	}
	case 3:{///lateral esquerda
		imp(292);
	}
	case 4:{//lateral direita
		imp(73);
	}
	case 5:{//diagonal principal
		imp(84);
	}
	case 6:{//diagonal secundária
		imp(273);
	}
	case 7:{///coluna do meio
		imp(146);
	}
	case 8:{//linha do meio
		imp(56);
	}
	}


}

void imp(int vector){
	while (1){
		IOWR_ALTERA_AVALON_PIO_DATA(0x3020,vector);
		usleep(350000);
		IOWR_ALTERA_AVALON_PIO_DATA(0x3020,0);
		usleep(350000);
	}

}

void func(char use[3][3]){

	int impmx = 0;
	int bug = 0;
	int meas=3;
	int tres;
	int quatro;
	for (tres = 0; tres < meas; tres++) {

		for (quatro = 0; quatro < meas; quatro++) {

			if (impmx == meas) {
				impmx = 0;
				alt_putstr("\n");
			}
			if (impmx != meas) {
				printf("%c",use[tres][quatro]);
				impmx++;
			}
			bug++;
			if (bug == meas * meas) {
				alt_putstr("\n");
			}

		}
	}

	bug = 0;

	int k = 0;

	/// primeira linha
	int cinco;
	for (cinco = 0; cinco < meas; cinco++) {

		if (use[0][cinco] == 'x') {

			k++;
			if (k == meas) {
				swit(1);
				alt_putstr("end");
				exit(0);
			}

		}

	}

	k = 0;

	//ultima linha
	int seis;
	for (seis = 0; seis < meas; seis++) {

		if (use[meas-1][seis] == 'x') {
			k++;
			if (k == meas) {
				swit(2);
				alt_putstr("end");
				exit(0);
			}

		}

	}
	k = 0;

	///coluna do meio
	int vinte;
	for (vinte = 0; vinte < meas; vinte++) {

		if (use[vinte][1] == 'x') {
			k++;
			if (k == meas) {
				swit(7);
				alt_putstr("end");
				exit(0);
			}

		}

	}
	k = 0;



	///linha do meio
	int trinta;
	for (trinta = 0; trinta < meas; trinta++) {

		if (use[1][trinta] == 'x') {
			k++;
			if (k == meas) {
				swit(8);
				alt_putstr("end");
				exit(0);
			}

		}

	}
	k = 0;

	//lateral esquerda
	int sete;
	for (sete = 0; sete < meas; sete++) {

		if (use[sete][0] == 'x') {
			k++;

			if (k == meas) {
				swit(3);
				alt_putstr("end");
				exit(0);
			}

		}

	}
	k = 0;

	//lateral direita
	int oito;
	for (oito = 0; oito < meas; oito++) {

		if (use[oito][meas - 1] == 'x') {
			k++;
			if (k == meas) {
				swit(4);
				alt_putstr("end");
				exit(0);
			}

		}

	}
	k = 0;

	//diagonal principal
	int nove;
	for (nove = 0; nove < meas; nove++) {

		if (use[nove][nove] == 'x') {
			k++;
			if (k == meas) {
				swit(5);
				alt_putstr("end");
				exit(0);
			}

		}

	}
	k = 0;

	//diagonal secundária
	int vardsec = 0;
	vardsec = meas;
	int dez;
	for (dez = 0; dez < meas; dez++) {

		if (use[vardsec - 1][dez] == 'x') {
			k++;

			if (k == meas) {
				swit(6);
				alt_putstr("end");
				exit(0);
			}

		}

		vardsec--;

	}
	vardsec = 0;
	k = 0;

	/////////////////////////////////////////////// do bolinha


	/// primeira linha
	int onze;
	for (onze = 0; onze < meas; onze++) {

		if (use[0][onze] == 'o') {
			k++;
			if (k == meas) {
				swit(0);
				alt_putstr("end");
				exit(0);
			}

		}

	}

	k = 0;

	///coluna do meio
	int quarenta;
	for (quarenta = 0; quarenta < meas; quarenta++) {

		if (use[quarenta][1] == 'o') {
			k++;
			if (k == meas) {
				swit(7);
				alt_putstr("end");
				exit(0);
			}

		}

	}
	k = 0;

	///linha do meio
	int cincoenta;
	for (cincoenta = 0; cincoenta < meas; cincoenta++) {

		if (use[1][cincoenta] == 'o') {
			k++;
			if (k == meas) {
				swit(8);
				alt_putstr("end");
				exit(0);
			}

		}

	}
	k = 0;

	//ultima linha
	int doze;
	for (doze = 0; doze < meas; doze++) {

		if (use[meas-1][doze] == 'o') {
			k++;
			if (k == meas) {
				swit(2);
				alt_putstr("end");
				exit(0);
			}

		}

	}
	k = 0;

	//lateral esquerda
	int treze;
	for (treze = 0; treze < meas; treze++) {

		if (use[treze][0] == 'o') {
			k++;

			if (k == meas) {
				swit(3);
				alt_putstr("end");
				exit(0);
			}

		}

	}
	k = 0;

	//lateral direita
	int katorze;
	for (katorze = 0; katorze < meas; katorze++) {

		if (use[katorze][meas - 1] == 'o') {
			k++;
			if (k == meas) {
				swit(4);
				alt_putstr("end");
				exit(0);
			}

		}

	}
	k = 0;

	//diagonal principal
	int kinze;
	for (kinze = 0; kinze < meas; kinze++) {

		if (use[kinze][kinze] == 'o') {
			k++;
			if (k == meas) {
				swit(5);
				alt_putstr("end");
				exit(0);
			}

		}

	}
	k = 0;

	//diagonal secundária
	vardsec = 0;
	vardsec = meas;
	int six;
	for (six = 0; six < meas; six++) {

		if (use[vardsec - 1][six] == 'o') {
			k++;

			if (k == meas) {
				swit(6);
				alt_putstr("end");
				exit(0);
			}

		}

		vardsec--;

	}
	vardsec = 0;
	k = 0;











}

void impDraw(){

	while(1){
		while (1){
			IOWR_ALTERA_AVALON_PIO_DATA(0x3020,1023);
			usleep(350000);
			IOWR_ALTERA_AVALON_PIO_DATA(0x3020,0);
			usleep(350000);
		}
	}

}



