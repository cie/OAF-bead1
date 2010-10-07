#include "bignum.h"
#include <iostream>


/**
 * Copy konstruktor
 */
Bignum::Bignum(const Bignum& other)
{
    n = other.n;
    v = new int[n];
    for (int i=0; i<n; i++) {
        v[i] = other.v[i];
    }
}

/**
 * Értékadás operátor
 */
Bignum& Bignum::operator = (const Bignum& other) {
    delete[] v;
    n = other.n;
    v = new int[n];
    for (int i=0; i<n; i++) {
        v[i] = other.v[i];
    }
}

/**
 * Destruktor
 */
Bignum::~Bignum() {
    delete[] v;
}

/**
 * Összeadás
 *
 * Összead két nagyszámot.
 * @param a az egyik szám
 * @param b a másik szám
 * @returns a két nagyszám összege
 */
Bignum operator+(const Bignum &a, const Bignum &b) {
    int maxn = a.n > b.n ? a.n : b.n;
    Bignum e;
    e.v = new int[maxn+1];
    int k = a.jegy(0) + b.jegy(0);
    int i = 0;
    while (i<maxn || k > 0)
    {
        e.v[i] = k % 10;
        i++;
        k = k/10 + a.jegy(i) + b.jegy(i);
    }
    e.n = i;
    return e;
}

/**
 * Egész számmal szorzás
 *
 * Megszorozza a nagyszámot egy egyjegyű egész számmal
 * @param a a nagyszám
 * @param x az egész szám. A [0..9] intervallumban kell lennie.
 * @returns a szorzatuk
 */

Bignum operator*(const Bignum &a, int x) 
{
    if (0==x) return Bignum("0");
    Bignum e;
    e.v = new int[a.n + 1];
    int k = a.jegy(0) * x;
    int i = 0;
    while (i<a.n || k>0)
    {
        e.v[i] = k % 10;
        i++;
        k = k/10 + a.jegy(i)*x;
    }
    e.n = i;
    return e;
}


/**
 * Tízhatvánnyal szorzás ("shiftelés balra")
 *
 * Megszorozza 10^x-nel a nagyszámot.
 * @param a a nagyszám
 * @param x a kitevő
 * @returns a szorzatot, vagyis a*10^x -t.
 */
Bignum operator<<(const Bignum &a, int x)
{
    if (0 == a.n) return a;
    Bignum e;
    e.v = new int[a.n+x];
    for (int i = 0; i<x; i++)
    {
        e.v[i] = 0;
    }
    for (int i = x; i<a.n+x; i++) 
    {
        e.v[i] = a.v[i-x];
    }
    e.n = a.n + x;
    return e;
}



/**
 * Szorzás
 *
 * Összeszorozza a két nagyszámot.
 * @param a az egyik nagyszám
 * @param b a másik nagyszám
 * @returns a szorzatuk
 */
Bignum operator*(const Bignum &a, const Bignum &b)
{
    Bignum e("0");
    for (int i=0; i<b.n; i++) {
        Bignum p = a*b.jegy(i);
        p = p << i;
        e = e + p;
    }
    return e;
}

/**
 * Létrehozás sztringből
 *
 * Létrehozza a számot a sztringben lévő tízes számrendszerbeli alak alapján.
 * @param s a szám tízes számrendszerben
 */
Bignum::Bignum(const std::string &s) {
    if (s == "0") 
    {
        n = 0;
        v = new int[0];
    } 
    else 
    {
        n = s.length();
        v = new int[n];
        for (int i=0; i<n; i++) {
            v[i] = s[n-i-1]-'0';
        }
    }
}

/**
 * Sztringgé alakítás
 *
 * Sztringgé alakítja a nagyszámot
 * @returns a tízes számrendszerbeli alakja
 */
Bignum::operator std::string() const {
    if (0 == n)
    {
        return "0";
    }
    else 
    {
        std::string s(n, ' ');
        for (int i=0; i<n; i++) {
            s[n-i-1]=v[i]+'0';
        }
        return s;
    }
}

/**
 * Beolvasás
 *
 * Beolvassa a nagyszámot a bemeneti adatfolyamról.
 * @param os a bemeneti adatfolyam
 * @param a a nagyszám
 */
std::istream& operator>>(std::istream& is, Bignum& a) {
    std::string s;
    is >> s;
    a = (Bignum) s;
    return is;
}


/**
 * Kiírás
 *
 * Kiírja a nagyszámot a megadott kimeneti adatfolyamra.
 * @param os a kimeneti adatfolyam
 * @param a a nagyszám
 */
std::ostream& operator<<(std::ostream& os, const Bignum& a)
{
    return os << (std::string) a;
}

