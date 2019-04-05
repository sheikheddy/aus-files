#include <iostream>
#include <ctime>

using namespace std;

void prgm_A (int n)
{
    int total=0;
    int j=0;

    while (j<n) {
        total++;
        j++;
    }
}

void prgm_B (int n)
{
    int total=0;
    int i=0, j=0, k=0;

    while (i<n) {
        while (j<n) {
            while (k<j) {
                total++;
                k++;
            }
            k=0;
            j++;
        }
        j=0;
        i++;
    }
}

void prgm_C (int n)
{
    int total=0;
    int i=0, j=0;

    while (j<n) {
        while (i<j) {
            total++;
            i++;
        }
        i=0;
        j++;
    }
}


void prgm_D (int n)
{
    int total=0;
    int i=0, j=0;

    while (j<n) {
        while (i<n){
            total++;
            i++;
        }
        j++;
    }
}


void test_A ()
{
    int n=1250000, m=2;

    for (int i=0; i<10; i++) {
        n*=m;
        clock_t start, finish;  
        start=clock(); finish=clock();
        double clock_delay=(double)(finish - start);
  
        start=clock();

        prgm_A(n);

        finish=clock();

        double elapsed_time=(double)(finish - start) - clock_delay;
        double elapsed_second=elapsed_time / CLOCKS_PER_SEC;
        cout<<"A: n="<<n<<" time="<<(double)elapsed_second<<endl;
    }
}

void test_B ()
{
    int n=125, m=125;

    for (int i=0; i<10; i++) {
        n+=m;
        clock_t start, finish;  
        start=clock(); finish=clock();
        double clock_delay=(double)(finish - start);
  
        start=clock();

        prgm_B(n);

        finish=clock();

        double elapsed_time=(double)(finish - start) - clock_delay;
        double elapsed_second=elapsed_time / CLOCKS_PER_SEC;
        cout<<"B: n="<<n<<" time="<<(double)elapsed_second<<endl;
    }
}

void test_C ()
{
    int n=5000, m=5000;

    for (int i=0; i<10; i++) {
        n+=m;
        clock_t start, finish;  
        start=clock(); finish=clock();
        double clock_delay=(double)(finish - start);
  
        start=clock();

        prgm_C(n);

        finish=clock();

        double elapsed_time=(double)(finish - start) - clock_delay;
        double elapsed_second=elapsed_time / CLOCKS_PER_SEC;
        cout<<"C: n="<<n<<" time="<<(double)elapsed_second<<endl;
    }
}


void test_D ()
{
    int n=1250000, m=2;

    for (int i=0; i<10; i++) {
        n*=m;
        clock_t start, finish;  
        start=clock(); finish=clock();
        double clock_delay=(double)(finish - start);
  
        start=clock();

        prgm_D(n);

        finish=clock();

        double elapsed_time=(double)(finish - start) - clock_delay;
        double elapsed_second=elapsed_time / CLOCKS_PER_SEC;
        cout<<"E: n="<<n<<" time="<<(double)elapsed_second<<endl;
    }
}


int main()
{
    cout<<"testing"<<endl;

  //test_A ();
 //test_B ();
   //test_C ();
 test_D ();

    cout<<"done"<<endl;
    return 0;
}
