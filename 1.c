#include <stdio.h>
#include <math.h>

double fact(double termos) {  
  if(termos >= 1)
    return termos * fact(termos - 1);
  else
    return 1;
}

double formula(double k) {
  
  double div = pow(fact(k),2)/(pow(k,2) * fact(2 * k));
  return div;
  
}

double num_termos(double erro) {
  
  double n = 0.0;
  
  do {

    n++;
    
  } while((18 * formula(n)) > erro);
  
  return n;
  
}

double somatorio(double termos) {

  double sum = 0.0;

  do {
    
    sum += formula(termos);
    --termos;
    
  } while(termos > 1.0);

  return sum;
  
}
  
int main() {
  
  double soma = 0.0, expoente_erro = 0.0, n_termos = 0.0, erro = 0.0;
  int expoente = 0;
  
  printf("Expoente erro: ");
  scanf("%lf", &expoente_erro);
  expoente = fabs(expoente_erro) + 1; 

  erro = pow(10.0, expoente_erro);
  printf("Erro = %.*f\n", expoente-1, erro);
  n_termos = num_termos(erro);
  printf("Número de termos para o erro considerado = %.0f\n", n_termos);
  
  soma = somatorio(n_termos);
  printf("Somatório = %.*f\n", expoente, soma);

  return 0;
    
}
