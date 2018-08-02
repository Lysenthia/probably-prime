#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <gmp.h>
#define ACCURATE 30

int main(void)
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
    // Init and grab variables
    unsigned long n;
    int accuracy = ACCURATE;
    scanf("%lu", &n);
    int prime = 1;
    mpz_set_ui(n_large, n);
    if (n <= 3) {
        if (n == 1) {
            printf("Value is not prime");
        } else {
            printf("Value is prime");
        }
    } else if (n % 2 == 0) {
        printf("Value is not prime");
    } else {
        // Call upon eldritch forces
        for (int i = 0; i < accuracy; i++) {
            unsigned long long int a = rand() % ((n-2) + 1 - 2) + 2;;
            mpz_set_ui(test_number, a);
            mpz_pow_ui(power, test_number, n - 1);
            mpz_mod(pow_mod_n, power, n_large);
            //Leftover debug script
            //printf("Power: %lu\n", mpz_get_ui(power));
            //printf("Modulus: %lu\n", mpz_get_ui(pow_mod_n));
            if (mpz_get_ui(pow_mod_n) != 1) {
                prime = 0;
                break;
            }
        }
        if (prime) {
            printf("Value is probably prime");
        } else {
            printf("Value is not prime");
        }
    }
}
