#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <gmp.h>

int isProbablyPrime(unsigned long n, int accuracy)
{
    // Initialise GNU MP Library variables
    mpz_t test_number;
    mpz_init(test_number);
    mpz_t power;
    mpz_init(power);
    mpz_t n_large;
    mpz_init(n_large);
    mpz_t pow_mod_n;
    mpz_init(pow_mod_n);
    // Seed RNG
    srand(time(NULL));
    int prime = 1;
    mpz_set_ui(n_large, n);
    if (n <= 3) {
        if (n == 1) {
            return 0;
        } else {
            return 1;
        }
    } else if (n % 2 == 0) {
        return 0;
    } else {
        // Call upon eldritch forces
        for (int i = 0; i < accuracy; i++) {
            unsigned long long int a = rand() % ((n-2) + 1 - 2) + 2;;
            mpz_set_ui(test_number, a);
            mpz_pow_ui(power, test_number, n - 1);
            mpz_mod(pow_mod_n, power, n_large);
            if (mpz_get_ui(pow_mod_n) != 1) {
                prime = 0;
                break;
            }
        }
        if (prime) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main(void)
{
    unsigned long n;
    int accuracy = 30;
    printf("Please enter a number to check for primality:\n");
    scanf("%lu", &n);
    if (isProbablyPrime(n, accuracy)) {
        printf("Number is probably prime");
    } else {
        printf("Number is not prime");
    }
}
