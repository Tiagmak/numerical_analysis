#include <stdio.h>
#include <math.h>

// função que calcula o valor de F(x)
long double formula( long double x )
{
      return ( pow( x, 2 ) - x - sin( x + 0.15 ) );
}

// função que calcula a derivada de F(x)
long double derivative( long double x )
{
      return ( 2 * x - 1 - cos( x + 0.15 ) );
}

// método de aproximação de newton
long double newton( long double f, long double f_line )
{
      return ( f / f_line );
}

int main( void )
{
      // iterações
      int i = 1;
      // limite
      long double lim_inferior, lim_superior, x_inicial, x_next, xi;
      scanf( "%Lf", &lim_inferior );
      scanf( "%Lf", &lim_superior );
      x_inicial = lim_inferior;
      // erro absoluto                          
      long double erro_absoluto = 5e-8;
      // erro inicial
      long double erro_iter = fabs( newton( formula( x_inicial ), derivative( x_inicial ) ));

      xi = x_inicial;
      x_next = x_inicial;
      while( erro_iter > erro_absoluto )
      {
            xi = x_next;
            x_next = xi - newton( formula( xi ), derivative( xi ) );
            erro_iter = fabs( newton( formula( x_next ), derivative( x_next ) ));
            ++i;
      }

      printf( "x = %.9Lf\n", x_next );
      printf( "número de iterações = %d\n", i );
}

