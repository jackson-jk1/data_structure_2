#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 86400

typedef struct pilha Pilha;

typedef struct time{
    short hora;	
    short minuto;
    short segundo;
} Time;

struct t_timetable{
    char cidade[100];
    Time horario;
    
};

struct pilha{
    int qtd;
    struct t_timetable dados[MAX];
};

Pilha* cria_Pilha(){
    Pilha *fp;
    fp = (Pilha*) malloc(sizeof(struct pilha));
    if(fp != NULL)
        fp->qtd = 0;
    return fp;
}

void libera_Pilha(Pilha* fp){
    free(fp);
}


int put(Pilha* fp, Time t, char *cidade){
    if(fp == NULL)
        return 0;
    if(fp->qtd == MAX)//fila cheia
        return 0;
    if(*cidade == NULL){
        delete(fp, t);
        return 0;
    }
    int k,i = 0;
    while(i < fp->qtd && (fp->dados[i].horario.hora*60*60 + fp->dados[i].horario.minuto*60 + fp->dados[i].horario.segundo < t.segundo  +  t.hora*60*60 + t.minuto*60)){
        i++;
    }
    for(k = fp->qtd-1; k >= i; k--)
        fp->dados[k+1] = fp->dados[k];

    strcpy(fp->dados[i].cidade, cidade);
    fp->dados[i].horario = t;
    fp->qtd++;
    return 1;
	}

int delete_max(Pilha* fp){
     if(fp == NULL)
        return 0;
    if(fp->qtd == 0)
        return 0;
    fp->qtd--;
    return 1;
}

int indice(Pilha* fp, Time t) {
     if(fp == NULL)
        return 0;
    int i = 0;
    while((i < fp->qtd) && (fp->dados[i].horario.hora*60*60 + fp->dados[i].horario.minuto*60 + fp->dados[i].horario.segundo != t.segundo  +  t.hora*60*60 + t.minuto*60))
        i++;
    if(i == fp->qtd)//elemento nao encontrado
        return -1;

    return i;
}


int delete_min(Pilha* fp){
   if(fp == NULL)
        return 0;
    if(fp->qtd == 0)
        return 0;
    int k = 0;
    for(k=0; k< fp->qtd-1; k++)
        fp->dados[k] = fp->dados[k+1];
    fp->qtd--;
    return 1;
}
int size(Pilha* fp){
    if(fp == NULL)
        return -1;
    else
        return fp->qtd;
}
char* get(Pilha* fp, Time t){
   
   int i = indice(fp,t);
    if(i >= 0){
      return fp->dados[i].cidade;
    }
    return NULL;

}

Time select(Pilha* fp, int indice){
    return fp->dados[indice - 1].horario;
}

bool contains(Pilha* fp, Time t){
    int i = indice(fp,t);
    if(i >= 0){
      return true;
    }
    return false;

} 

Time min(Pilha* fp){
    return fp->dados[0].horario;
}
Time max(Pilha* fp){
   return fp->dados[fp->qtd-1].horario;
}
Time ceiling(Pilha* fp,Time t){
   int i = 0;
   while((i < fp->qtd) && (fp->dados[i].horario.hora*60*60 + fp->dados[i].horario.minuto*60 + fp->dados[i].horario.segundo <= t.segundo  +  t.hora*60*60 + t.minuto*60))
   i++;
   return fp->dados[i].horario;
}

Time floor(Pilha* fp,Time t){
   int i = fp->qtd-1;
   while((i >=0 ) && (fp->dados[i].horario.hora*60*60 + fp->dados[i].horario.minuto*60 + fp->dados[i].horario.segundo >= t.segundo  +  t.hora*60*60 + t.minuto*60))
   i--;
   return fp->dados[i].horario;
}

int rank(Pilha* fp,Time t){
   int i = indice(fp,t);
   if(i > 0){
    return i;
   }
   return 0;
 
}

void delete(Pilha* fp,Time t){
     int k,i = 0;
     while((i < fp->qtd) && (fp->dados[i].horario.hora*60*60 + fp->dados[i].horario.minuto*60 + fp->dados[i].horario.segundo != t.segundo  +  t.hora*60*60 + t.minuto*60))
     i++;
     for(k=i; k< fp->qtd-1; k++)
        fp->dados[k] = fp->dados[k+1];
     fp->qtd--;
}
int size_range(Pilha* fp, Time t1, Time t2){
    int time1 =  t1.segundo  +  t1.hora*60*60 + t1.minuto*60;
    int time2 =  t2.segundo  +  t2.hora*60*60 + t2.minuto*60;
    int timeIntervalo,total = 0;
    for (int i = 0; i < fp->qtd; i++)
    {
        timeIntervalo = fp->dados[i].horario.hora*60*60 + fp->dados[i].horario.minuto*60 + fp->dados[i].horario.segundo;
        if(timeIntervalo > time1 && timeIntervalo < time2){
            total++;
        }
       
    }
  
   return total;
}
bool is_Empty(Pilha* fp){
    if(fp == NULL)
        return false;
    return true;
}

void imprime_Pilha(Pilha* fp){
    if(fp == NULL)
        return;
    int i;
    for(i=fp->qtd-1; i >=0 ; i--){
        printf("\nHora: %d:%d:%d \tCidade: %s\n",fp->dados[i].horario.hora,fp->dados[i].horario.minuto,fp->dados[i].horario.segundo,fp->dados[i].cidade);
    }
}

int main(){    
    int menu;
    Pilha* fp = cria_Pilha();
    
    do {
        printf("\n1. put");
        printf("\n2.  get");
        printf("\n3.  delete");
        printf("\n4.  contains");
        printf("\n5.  is_empty");
        printf("\n6.  size");
        printf("\n7.  min");
        printf("\n8.  max");
        printf("\n9.  floor");
        printf("\n10. ceiling");
        printf("\n11.  rank");
        printf("\n12.  select");
        printf("\n13.  delete_min");
        printf("\n14.  delete_max");
        printf("\n15. size_range");
        printf("\n16.  Imprimir a lista");
        printf("\n17.  Sair");
        printf("\n");
        
        scanf("%d", &menu);
        fflush(stdin);
        switch(menu) {
            case 1:
            	{
            		char cidade[100];
            		Time  t;
                    int hora,minuto,segundo;
            		printf("\nhora: ");
                	scanf("%d", &hora);
                	printf("\nminuto: ");
					scanf("%d", &minuto);
                	fflush(stdin);
					printf("\nsegundo: ");
					scanf("%d", &segundo);
                    t.hora = hora;
                    t.minuto = minuto;
                    t.segundo = segundo;
                	fflush(stdin);
                	printf("\nDigite a cidade: ");
                	fflush(stdin);
                	gets(cidade);
                	put(fp, t, cidade);
                	printf("\nT_timetable inserido com sucesso.");
                    fflush(stdin);
            		break;
				}
		    case 2:
				{
					Time  t;
                    int hora,minuto,segundo;
            		printf("\nhora: ");
                	scanf("%d", &hora);
                    fflush(stdin);
                	printf("\nminuto: ");
					scanf("%d", &minuto);
                	fflush(stdin);
					printf("\nsegundo: ");
					scanf("%d", &segundo);
                	fflush(stdin);
                    t.hora = hora;
                    t.minuto = minuto;
                    t.segundo = segundo;
                   
                    printf("\thora: %s\n", get(fp, t));
                    break;

				}
			case 3:
				{
                    Time  t;
                    int hora,minuto,segundo;
                    printf("\nhora: ");
                	scanf("%d", &hora);
                    fflush(stdin);
                	printf("\nminuto: ");
					scanf("%d", &minuto);
                	fflush(stdin);
					printf("\nsegundo: ");
					scanf("%d", &segundo);
                	fflush(stdin);
                    t.hora = hora;
                    t.minuto = minuto;
                    t.segundo = segundo;
					delete(fp, t);
					break;
				}
			case 4:
				{
                    Time  t;
                    int hora,minuto,segundo;
					printf("\nhora: ");
                	scanf("%d", &hora);
                    fflush(stdin);
                	printf("\nminuto: ");
					scanf("%d", &minuto);
                	fflush(stdin);
					printf("\nsegundo: ");
					scanf("%d", &segundo);
                	fflush(stdin);
                    t.hora = hora;
                    t.minuto = minuto;
                    t.segundo = segundo;
                    if(contains(fp, t) == true){
                        printf("\nExiste: ");
                        break;
                    }
					printf("\nnao existe: ");
					break;
				}
                case 5:
				{
            
                    if(is_Empty(fp) == true){
                        printf("\nHa dados: ");
                        break;
                    }
					printf("\nnvazia: ");
					break;
				}
                case 6:
				{
                   printf("\tCidade: %d\n" ,size(fp)); 
                   break;
				}
                case 7:
				{
                   Time  t = min(fp);
                   printf("\nHora: %d:%d:%d",t.hora,t.minuto,t.segundo);
                   break;
                }
                 case 8:
				{ 
                    Time  t = max(fp);
                    printf("\nHora: %d:%d:%d",t.hora,t.minuto,t.segundo);
                    break;
				}
                 case 9:
				{
                    Time  t;
                    int hora,minuto,segundo;
            		printf("\nhora: ");
                	scanf("%d", &hora);
                    fflush(stdin);
                	printf("\nminuto: ");
					scanf("%d", &minuto);
                	fflush(stdin);
					printf("\nsegundo: ");
					scanf("%d", &segundo);
                    fflush(stdin);
                    t.hora = hora;
                    t.minuto = minuto;
                    t.segundo = segundo;
                    Time TimeFloor = floor(fp,t);
                    printf("\nHora: %d:%d:%d",TimeFloor.hora,TimeFloor.minuto,TimeFloor.segundo);
                    break;
                }
                 case 10:
				{ 
                    Time  t;
                    int hora,minuto,segundo;
            		printf("\nhora: ");
                	scanf("%d", &hora);
                    fflush(stdin);
                	printf("\nminuto: ");
					scanf("%d", &minuto);
                	fflush(stdin);
					printf("\nsegundo: ");
					scanf("%d", &segundo);
                    fflush(stdin);
                    t.hora = hora;
                    t.minuto = minuto;
                    t.segundo = segundo;
                    Time TimeCeiling = ceiling(fp,t);
                    printf("\nHora: %d:%d:%d",TimeCeiling.hora,TimeCeiling.minuto,TimeCeiling.segundo);
                    break;
				}
                case 11: {
                    
                    Time  t;
                    int hora,minuto,segundo;
					printf("\nhora: ");
                	scanf("%d", &hora);
                    fflush(stdin);
                	printf("\nminuto: ");
					scanf("%d", &minuto);
                	fflush(stdin);
					printf("\nsegundo: ");
					scanf("%d", &segundo);
                	fflush(stdin);
                    t.hora = hora;
                    t.minuto = minuto;
                    t.segundo = segundo;
                    printf("\nNumero de chaves a menos e de : %d",rank(fp,t));
                    break;
                } case 12: {
                      int indice = 0;
                      scanf("%d", &indice);
                      Time t = select(fp,indice);
                      printf("\nHora: %d:%d:%d",t.hora,t.minuto,t.segundo);
                      break;
                }
                case 13: {
                      delete_min(fp);
                      break;
                }
                case 14: {
                     delete_max(fp);
                    break;
                }
                 case 15: {
                    Time  t;
                    int hora,minuto,segundo;
                    Time t2;
                    int hora2,minuto2,segundo2;
                
					printf("\nhora: ");
                	scanf("%d", &hora);
                    fflush(stdin);
                	printf("\nminuto: ");
					scanf("%d", &minuto);
                	fflush(stdin);
					printf("\nsegundo: ");
					scanf("%d", &segundo);
                	fflush(stdin);
					printf("\nhora: ");
                	scanf("%d", &hora2);
                    fflush(stdin);
                	printf("\nminuto: ");
					scanf("%d", &minuto2);
                	fflush(stdin);
					printf("\nsegundo: ");
					scanf("%d", &segundo2);
                	fflush(stdin);
                    t.hora = hora;
                    t.minuto = minuto;
                    t.segundo = segundo;
                    t2.hora = hora2;
                    t2.minuto = minuto2;
                    t2.segundo = segundo2;
                    printf("\nNumero entre o intevalo e de  : %d", size_range(fp, t, t2));
                    break;

                }
                 case 16: {
                     imprime_Pilha(fp);
                     break;
                }
			     case 17: 
				{
					libera_Pilha(fp);
					return -1;
				}
			default:
				printf("\nOpcao invafpda.");
		}
	} while(menu != 17 );
    return 0;
  }

