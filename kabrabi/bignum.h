#ifndef __BIGNUM_H
#define __BIGNUM_H

#include <string>

class Bignum
{
    private:
        int* v;
        int n;
        Bignum(){};
    
    public:
        /**
         * Copy konstruktor
         */
        Bignum(const Bignum& other);
        /**
         * Értékadás operátor
         */
        Bignum& operator = (const Bignum& other);
        /**
         * Destruktor
         */
        ~Bignum();
        /**
         * Egy jegy lekérdezése
         *
         * Visszaadja a szám egy jegyét vagy 0-t, ha a kért jegy nagyobb, mint a
         * számjegyek száma.
         * @param i hányadik jegyet kérjük
         * @returns az i-edik jegy, vagy 0, ha i>n
         */
        int jegy(int i) const { return i<n ? v[i] : 0; }

        /**
         * Összeadás
         *
         * Összead két nagyszámot.
         * @param a az egyik szám
         * @param b a másik szám
         * @returns a két nagyszám összege
         */
        friend Bignum operator+(const Bignum &a, const Bignum &b);

        /**
         * Egész számmal szorzás
         *
         * Megszorozza a nagyszámot egy egyjegyű egész számmal
         * @param a a nagyszám
         * @param x az egész szám. A [0..9] intervallumban kell lennie.
         * @returns a szorzatuk
         */
        friend Bignum operator*(const Bignum &a, int x);

        /**
         * Tízhatvánnyal szorzás ("shiftelés balra")
         *
         * Megszorozza 10^x-nel a nagyszámot.
         * @param a a nagyszám
         * @param x a kitevő
         * @returns a szorzatot, vagyis a*10^x -t.
         */
        friend Bignum operator<<(const Bignum &a, int x);

        /**
         * Szorzás
         *
         * Összeszorozza a két nagyszámot.
         * @param a az egyik nagyszám
         * @param b a másik nagyszám
         * @returns a szorzatuk
         */
        friend Bignum operator*(const Bignum &a, const Bignum &b);
        
        /**
         * Létrehozás sztringből
         *
         * Létrehozza a számot a sztringben lévő tízes számrendszerbeli alak alapján.
         * @param s a szám tízes számrendszerben
         */
        Bignum(const std::string &s);

        /**
         * Sztringgé alakítás
         *
         * Sztringgé alakítja a nagyszámot
         * @returns a tízes számrendszerbeli alakja
         */
        operator std::string() const;

        /**
         * Beolvasás
         *
         * Beolvassa a nagyszámot a bemeneti adatfolyamról.
         * @param os a bemeneti adatfolyam
         * @param a a nagyszám
         */
        friend std::istream& operator>>(std::istream& is, Bignum& a);

        /**
         * Kiírás
         *
         * Kiírja a nagyszámot a megadott kimeneti adatfolyamra.
         * @param os a kimeneti adatfolyam
         * @param a a nagyszám
         */
        friend std::ostream& operator<<(std::ostream& os, const Bignum& a);




};











#endif
