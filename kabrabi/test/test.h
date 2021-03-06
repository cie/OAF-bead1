#ifndef __TEST__TEST_H
#define __TEST__TEST_H

#include <cxxtest/TestSuite.h>
#include <iostream>
#include "../bignum.h"

/**
 * Teszteljünk-e beolvasást és kiírást (inputra vár)
 */
//const bool TEST_IO=true;
const bool TEST_IO=false;

/**
 * Teszteljünk-e destruktort (lassú)
 */
//const bool TEST_DESTRUCTOR=true;
const bool TEST_DESTRUCTOR=false;

class Test : public CxxTest::TestSuite
{
public:

    /**
     * Destruktor tesztelése
     */
    void testDestructor() {
        const long COUNT = 1e6L;
        const long SLEEP = 1e4L;
        if (TEST_DESTRUCTOR) {
            Bignum* p;
            std::cout << "Creating and freeing many bignums...";
            std::cout.flush();
            for (long i=0; i<COUNT; i++) {
                p=new Bignum("12345678123456781234567812345678987654321345678");
                delete p;
                for (long j=0; j<SLEEP; j++); // sleep
                if (i%(COUNT/10) == 0) {
                    std::cout << (i/(COUNT/10));
                    std::cout.flush();
                }
            }
        }
    }
    
    /**
     * Copy konstruktor tesztelése
     */
    void testCopy() { 
        Bignum *a = new Bignum("1234567");
        Bignum b = *a;
        delete a;
        TS_ASSERT_EQUALS((std::string)b, "1234567");
    }
    
    /**
     * Értékadás tesztelése
     */
    void testAssignment() {
        Bignum *a = new Bignum("1234567");
        Bignum b("123");
        b = *a;
        delete a;
        TS_ASSERT_EQUALS((std::string)b, "1234567");
    }


    /**
     * Beolvasás és kiírás tesztelése
     */
    void testIO() {
        if (TEST_IO) {
            Bignum a("0");
            std::cout << "a=";
            std::cin >> a;
            std::cout << "You entered " << a << std::endl;
        }
    }

    /**
     * Próba teszteset
     */
    void test1() {
        std::string s("124");
        Bignum a(s);
        TS_ASSERT_EQUALS(1+1, 2);
    }
    /**
     * Számok összeadása átvitel nélkül
     */
    void testOsszeadas1() 
    {
        Bignum a("1234567");
        Bignum b("7654321");
        TS_ASSERT_EQUALS((std::string)(a+b), std::string("8888888"));
    }
    /**
     * Számok összeadása átvitellel
     */
    void testOsszeadas2() 
    {
        Bignum x("5");
        Bignum y("7");
        TS_ASSERT_EQUALS((std::string)(x+y), std::string("12"));
        Bignum a("1234567");
        Bignum b("9999999");
        TS_ASSERT_EQUALS((std::string)(a+b), std::string("11234566"));
    }
    /**
     * Nulla összeadása más számmal, nullával
     */
    void testOsszeadas0()
    {
        Bignum a("12345");
        Bignum b("0");
        Bignum c("0");
        TS_ASSERT_EQUALS((std::string)(a+b), std::string("12345"));
        TS_ASSERT_EQUALS((std::string)(b+c), std::string("0"));
    }

    /**
     * Számok szorzása
     */
    void testSzorzas()
    {
        Bignum a("12345"), b("67890");
        TS_ASSERT_EQUALS((std::string)(a*b), "838102050");
    }

    /**
     * Számok szorzása 1-gyel
     */
    void testSzorzas1()
    {
        Bignum a("12345"), b("1");
        TS_ASSERT_EQUALS((std::string)(a*b), "12345");
    }

    /**
     * Számok szorzása 0-val
     */
    void testSzorzas0()
    {
        Bignum a("12345"), b("0");
        TS_ASSERT_EQUALS((std::string)(a*b), "0");
    }

    /**
     * Nagyon nagy számok összeadása
     */
    void testOsszeadasNagy()
    {
        Bignum a("1180591620717411303424"), b("1152921504606846976");
        TS_ASSERT_EQUALS((std::string)(a+b), "1181744542222018150400");
    }

    /**
     * Nagyon nagy számok szorzása
     */
    void testSzorzasNagy()
    {
        Bignum a("590295810358705651712"), b("590295810358705651712");
        TS_ASSERT_EQUALS((std::string)(a*b), "348449143727040986586495598010130648530944");
    }


    /**
     * Szorzás kommutativitása
     */
    void testSzorzasKomm() 
    {
        Bignum a("12345"), b("67890");
        TS_ASSERT_EQUALS((std::string)(b*a), "838102050");
        Bignum c("12345"), d("1");
        TS_ASSERT_EQUALS((std::string)(d*c), "12345");
        Bignum e("12345"), f("0");
        TS_ASSERT_EQUALS((std::string)(f*e), "0");
        Bignum g("590295810358705651712"), h("590295810358705651712");
        TS_ASSERT_EQUALS((std::string)(h*g), "348449143727040986586495598010130648530944");
    }

    /**
     * Segéd metódusok tesztelése
     */
    void testSeged() {
        // Tízhatvánnyal való szorzás
        Bignum a("12345");
        TS_ASSERT_EQUALS((std::string)(a<<3), "12345000");
        // Kis számmal való szorzás
        TS_ASSERT_EQUALS((std::string)(a*2), "24690");
        TS_ASSERT_EQUALS((std::string)(a*9), "111105");
    }


};




#endif
