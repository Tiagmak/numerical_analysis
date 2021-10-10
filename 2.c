#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double formula(double k)
{
      double div = ((pow((-1), (k-1))) / (pow(k, 2)));
      return div;
}

double sum(double terms_n)
{
      double final = 0.0;

      do
      {
           final += formula(terms_n);
           --terms_n;
      } while (terms_n > 1.0);
      
      final = 12.0 * (final + formula(1.0));

      return final;
}

double terms(double error)
{
      double terms_n = 0.0; 

      do
      {
            terms_n = terms_n + 1.0;
      } while (fabs(12.0 * formula(terms_n)) > error);

      return terms_n;
}

int main(void)
{
      double error = 0.0;
      double sum_final = 0.0;
      double terms_n = 0.0;
      
      
      printf("Erro pretendido? \n");
      scanf("%lf", &error);
      int casas_n = fabs(error) + 1;

      terms_n = terms(pow(10.0, error));
      printf("Número de termos somados: %.0lf \n", terms_n);

      sum_final = sum(terms_n);
      printf("Somatório: %.*lf \n", casas_n ,sum_final);
}