#include <stdio.h>

struct moto{
	
	char nombre[10];
	int escape;
	int suspension;
	int cilindros;
	int llantas;
	int frenosceram;
	int horquilla;
	int chasiscarb;
	int cadena;
	int valvulas;
	int aperturavalv;
	int precio1;
	int precio2;
	int precio3;
	int precio4;
	int precio5;
	int precio6;
	int precio7;
	int precio8;
	int precio9;
	int precio10;
	
	
};

int main(){
	
	FILE * pmoto;
 
      struct moto marca[4];	
	 int contador = 0,i,opcion,config;
	 float total = 0;
	 char eleccion;
	
	
	pmoto = fopen("motos.txt","r");
	
	 if(pmoto == NULL){
        	printf("No se ha podido encontrar los ficheros \n");
        	return 0;
		}
	

	while(fscanf(pmoto,"%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n",marca[contador].nombre, &marca[contador].escape, &marca[contador].suspension, &marca[contador].cilindros, &marca[contador].llantas, &marca[contador].frenosceram, &marca[contador].horquilla, &marca[contador].chasiscarb, &marca[contador].cadena, &marca[contador].valvulas, &marca[contador].aperturavalv, &marca[contador].precio1, &marca[contador].precio2, &marca[contador].precio3, &marca[contador].precio4, &marca[contador].precio5, &marca[contador].precio6, &marca[contador].precio7 , &marca[contador].precio8, &marca[contador].precio9,&marca[contador].precio10) != EOF){
	
	
	contador++;
	
	}
	
	fclose(pmoto);
		
		printf("------------------------------------------- \n");
		printf("------------------------------------------- \n");
	    printf("--------BIENVENIDOS A DEVIL ENGINE--------- \n");
		printf("------------------------------------------- \n");
	    printf("------------------------------------------- \n");
		printf("- Aqui pudes configurar tu moto a tu gusto- \n \n");
	
	for(i=0;i<3;i++){	
		printf("--------> %s \n \n",marca[i].nombre);
		printf("1. Tubos de escape de titanio -----> %d existencias = %d euros \n",marca[i].escape, marca[i].precio1);
		printf("2. Suspension de competicion -----> %d exsistencias = %d euros \n",marca[i].suspension,marca[i].precio2);
		printf("3. Cilindros de competicion -----> %d exsistencias = %d euros \n",marca[i].cilindros,marca[i].precio3);
		printf("4. Llantas cromadas -----> %d exsistencias = %d euros \n",marca[i].llantas,marca[i].precio4);
		printf("5. Frenos ceramicos -----> %d exsistencias = %d  euros \n",marca[i].frenosceram,marca[i].precio5);
		printf("6. Horquilla delantera electrica -----> %d exsistencias = %d euros \n",marca[i].horquilla,marca[i].precio6);
		printf("7. Chasis de carbono -----> %d exsistencias = %d  euros \n",marca[i].chasiscarb,marca[i].precio7);
		printf("8. Cadena reforzada -----> %d exsistencias = %d  euros \n",marca[i].cadena,marca[i].precio8);
		printf("9. Valvulas deportivas -----> %d exsistencias = %d  euros \n",marca[i].valvulas,marca[i].precio9);
	    printf("10. Opcion de apertura de valvulas -----> %d exsistencias = %d euros \n \n",marca[i].aperturavalv,marca[i].precio10);
		}
		
	printf("Elige una opcion para configurar tu moto Yamaha---> 1  ,  Honda---> 2  ,  Kawasaki---> 3 \n");
	scanf("%d",&opcion);
		
	FILE * pconfiguracion;
	pconfiguracion = fopen("Configuracion escogida.txt","w");
		
	switch(opcion){
		case 1:
			fprintf(pconfiguracion,"-----YAMAHA----- \n");
	do{		
		printf("--------> %s \n \n",marca[0].nombre);
		printf("1. Tubos de escape de titanio -----> %d = %d euros \n",marca[0].escape, marca[0].precio1);
		printf("2. Suspension de competicion -----> %d = %d euros \n",marca[0].suspension,marca[0].precio2);
		printf("3. Cilindros de competicion -----> %d = %d euros \n",marca[0].cilindros,marca[0].precio3);
		printf("4. Llantas cromadas -----> %d = %d euros \n",marca[0].llantas,marca[0].precio4);
		printf("Elige tus opciones a anadir: \n");
	   
	   	fflush(stdin);
		
			scanf("%d",&config);
			
		if(config == 1 && marca[0].escape != 0){
			total=total+marca[0].precio1;
			fprintf(pconfiguracion,"Tubos de escape de titanio = %d€ \n",marca[0].precio1);
			marca[0].escape=0;
		    }
		else if(config == 2 && marca[0].suspension != 0){
			
				total=total+marca[0].precio2;
				fprintf(pconfiguracion,"Suspension de competicion = %d€ \n",marca[0].precio2);
				marca[0].suspension=0;
		        }
		else if(config == 3 && marca[0].cilindros != 0){
			
				total=total+marca[0].precio3;
				fprintf(pconfiguracion,"Cilindros de competicion = %d€ \n",marca[0].precio3);
				marca[0].cilindros=0;
	            }
		else if(config == 4 && marca[0].llantas != 0){
			
				total=total+marca[0].precio4;
				fprintf(pconfiguracion,"Llantas cromadas = %d€ \n",marca[0].precio4);
				marca[0].llantas=0;
		        }
		else if(config == 4 && marca[0].llantas == 0 || config == 3 && marca[0].cilindros == 0 || config == 2 && marca[0].suspension == 0 || config == 1 && marca[0].escape == 0){
				printf("Has elegido esta configuracion antes... ¡Elige otra! \n");		
			    }
			
	fflush(stdin);
	
	printf("Desea anadir otra mejora? \n");
	printf("S (si) / N (no) \n");
	scanf("%c",&eleccion);
				
    }while(eleccion == 's' || eleccion == 'S');
		
	printf("Tu configuracion se ha guardado en un documento de tecto llamado (Configuracion escogida) \n");
	printf("Es el resguardo de tu compra realizada con exito \n");
	printf("Muchas gracias por confiar en nosotros, ¡Hasta la proxima! \n");
			
	fprintf(pconfiguracion,"Total a pagar = %.2f€",total);
			
	break;
					 
	case 2:
	fprintf(pconfiguracion,"-----HONDA----- \n");
	do{
		
	    printf("--------> %s \n \n",marca[1].nombre);
		printf("1. Tubos de escape de titanio -----> %d = %d euros \n",marca[1].escape, marca[1].precio1);
		printf("2. Frenos ceramicos -----> %d = %d  euros \n",marca[1].frenosceram,marca[1].precio5);
		printf("3. Horquilla delantera electrica -----> %d = %d euros \n",marca[1].horquilla,marca[1].precio6);
		printf("4. Chasis de carbono -----> %d = %d  euros \n",marca[1].chasiscarb,marca[1].precio7);
		printf("Elige tus opciones a anadir: \n");
	   
	   	fflush(stdin);
		
		scanf("%d",&config);
			
		if(config == 1 && marca[1].escape != 0){
			
			total=total+marca[1].precio1;
			fprintf(pconfiguracion,"Tubos de escape de titanio = %d€ \n",marca[1].precio1);
			marca[1].escape=0;
				
		   }
		else if(config == 2 && marca[1].frenosceram != 0){
			
				total=total+marca[1].precio5;
				fprintf(pconfiguracion,"Frenos ceramicos = %d€ \n",marca[1].precio5);
				marca[1].frenosceram=0;	
		        }
		else if(config == 3 && marca[1].horquilla != 0){
			
				total=total+marca[1].precio6;
				fprintf(pconfiguracion,"Horquilla delantera electrica = %d€ \n",marca[1].precio6);
				marca[1].horquilla=0;
		        }
		else if(config == 4 && marca[1].chasiscarb != 0){
			
				total=total+marca[1].precio7;
				fprintf(pconfiguracion,"Chasis de carbono = %d€ \n",marca[1].precio7);
				marca[1].chasiscarb=0;	
		        }
		else if(config == 4 && marca[1].chasiscarb == 0 || config == 3 && marca[1].horquilla == 0 || config == 2 && marca[1].frenosceram == 0 || config == 1 && marca[1].escape == 0){
					printf("Has elegido esta configuracion antes... ¡Elige otra! \n");
					
		        }
			
				fflush(stdin);
				
				printf("Desea anadir otra mejora? \n");
				printf("S (si) / N (no) \n");
				scanf("%c",&eleccion);
				
			}while(eleccion == 's' || eleccion == 'S');
			
			printf("Tu configuracion se ha guardado en un documento de tecto llamado (Configuracion escogida) \n");
			printf("Es el resguardo de tu compra realizada con exito \n");
			printf("Muchas gracias por confiar en nosotros, ¡Hasta la proxima! \n");
			
			fprintf(pconfiguracion,"Total a pagar = %.2f€",total);
			
			break;
			
			case 3:
				
		fprintf(pconfiguracion,"-----KAWASAKI----- \n");
		do{
		
		printf("--------> %s \n \n",marca[2].nombre);
		printf("1. Tubos de escape de titanio -----> %d = %d euros \n",marca[2].escape, marca[2].precio1);
		printf("2. Cadena reforzada -----> %d = %d  euros \n",marca[2].cadena,marca[2].precio8);
		printf("3. Valvulas deportivas -----> %d = %d  euros \n",marca[2].valvulas,marca[2].precio9);
	    printf("4. Opcion de apertura de valvulas -----> %d = %d euros \n \n",marca[2].aperturavalv,marca[2].precio10);
		printf("Elige tus opciones a anadir: \n");
	   
	   	fflush(stdin);
		
			scanf("%d",&config);
			
			if(config == 1 && marca[2].escape != 0){
			
				total=total+marca[2].precio1;
				fprintf(pconfiguracion,"Tubos de escape de titanio = %d€ \n",marca[2].precio1);
				marca[2].escape=0;
			    }
			else if(config == 2 && marca[2].cadena != 0){
			
				    total=total+marca[2].precio8;
				    fprintf(pconfiguracion,"Cadena reforzada = %d€ \n",marca[2].precio8);
				    marca[2].cadena=0;
			        }
			else if(config == 3 && marca[2].valvulas != 0){
				    total=total+marca[2].precio9;
				    fprintf(pconfiguracion,"Valvulas deportivas = %d€ \n",marca[2].precio9);
				    marca[2].valvulas=0;
	                }
	        else if(config == 4 && marca[2].aperturavalv != 0){
			
				   total=total+marca[2].precio10;
				   fprintf(pconfiguracion,"Opcion de apertura de valvulas = %d€ \n",marca[2].precio10);
				   marca[2].aperturavalv=0;
			       }
		    else if(config == 4 && marca[2].aperturavalv == 0 || config == 3 && marca[2].valvulas == 0 || config == 2 && marca[2].cadena == 0 || config == 1 && marca[2].escape == 0){
					printf("Has elegido esta configuracion antes... ¡Elige otra! \n");
				    }
			
		   fflush(stdin);
				
			printf("Desea anadir otra mejora? \n");
			printf("S (si) / N (no) \n");
			scanf("%c",&eleccion);		
		}while(eleccion == 's' || eleccion == 'S');
			
		printf("Tu configuracion se ha guardado en un documento de tecto llamado (Configuracion escogida) \n");
		printf("Es el resguardo de tu compra realizada con exito \n");
		printf("Muchas gracias por confiar en nosotros, ¡Hasta la proxima! \n");
				
		fprintf(pconfiguracion,"Total a pagar = %.2f€",total);
			
		break;			
		}
			
		fclose(pconfiguracion);
		 	
	return 0;	
}
