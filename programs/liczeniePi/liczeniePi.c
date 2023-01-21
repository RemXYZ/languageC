//# MORE: https://www.dartmouth.edu/~rc/classes/soft_dev/C_simple_ex.html
//# WIECEJ O ALGORYTMIE: https://www.mathematica.pl/?przyblizenie-liczby-pi-metoda-monte-carlo.,191#:~:text=Wystarczy%20zatem%20wygenerować%20równomiernie%20rozłożony,im%20więcej%20punktów%20zostanie%20wygenerowanych.
void liczeniePi() {
    int n=0;
    int i,count=0; /* # of points in the 1st quadrant of unit circle */
    double pi;

    printf("Enter the number of iterations used to estimate pi: ");
    scanf("%d",&n);
    count=0;
    for ( i=0; i<n; i++) {
        //# MORE ABOUT RAND_MAX: 
        //  https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm#:~:text=RAND_MAX%20is%20a%20constant%20whose,to%20be%20at%20least%2032767.
        double x = (double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;
        double z = x*x+y*y; // czyli wzór na okrąg
        if (z<=1) count++;
    }
    // count to punkt wśrodku koła podzielone przez liczbę prób 
    pi=4*((double)count/n);
    printf("Przyblizona wartoc PI wynosi %g \n",pi);
}
