#include <bits/stdc++.h>
#define ll long long
#define x real()
#define y imag()
#define angel(a)                    (atan2((a).imag , (a).real()))
#define vec(a , b)                  ((b) - (a))
#define length(a)                   (hypot((a).imag() , (a).real()))
#define normalize(a)                (a) / length(a)
#define dp(a , b)                   ( (conj(a) * (b)).real() )
#define cp(a , b)                   ( (conj(a) * (b)).imag() )

#define rotate0(p , ang)            ((p) * exp(point(0 , ang)) )
#define rotateA(p , ang , about)    (rotate0(vec(about , p) , ang ) + about)
typedef complex <double> point;

using namespace std;
int const MAXN = 1e6 + 5;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
ll d, a, b;
complex <double> a(1 , 2), b(3 , 4);
int main()
{
   cout << a.real(); // 1
   cout << a.imag() // 2
   cout << a + b; // (4 , 6)
   cout << a * b; //(-5 , 10)
   complex <double> i = -1;
   cout << sqrt(i); // (0 , 1)
   cout << conj(b); // المرافق (3 , -4);
   return 0;
}
