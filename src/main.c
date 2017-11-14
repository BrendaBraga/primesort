/*BRENDA BRAGA DE QUEIROZ
 *RA: 164930
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //popen

int volatile primo; 
 
void primos(int x){
    int i, d;
    int numdiv = 0;
    if(x==0 || x==1){
        primo = 0; //0 significa que nao eh primo
	return;
    }
    if(x==2 || x==3){
        primo = 1;
        return; 
    }
    
    if((x%2) == 0){
        primo = 0;
        return;
    }
    else{
        for(i = 1; i <= x; i++){
          d = x % i; 
          if( d == 0 ){
              numdiv += 1; 
              if(numdiv >2){
              	primo = 0;
              	return; 
			  }
          }
        if(numdiv == 2){
            primo = 1; //1 significa que o numero eh primo
        }
    }
    }
}
int main() {
    int x, j; //pega os numeros da entrada um a um
    int vet[200000] , i=0 , flag =1;
    FILE *resposta;
    //para cada caractere lido, verificar se é primo ou não
    while(flag){
    	
        scanf("%d", &x);//pega um elemento do vetor
		if(x==-1){
            flag = 0;
        }        
		else{
            primos(x);
			if(primo == 0){
                vet[i] = x;//coloca no vetor vet todos os nao primos
   				i++;
            }
    	}
    }

    if((resposta = popen("sort -n -r", "w")) == NULL){
	perror("popen");
	exit(1);
    }

    for(j=0; j<i; j++){
	fprintf(resposta, "%d\n", vet[j]);
    }

    pclose(resposta);
    
    return 0;
}
