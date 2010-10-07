/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_LONGLONG long long
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
    CxxTest::ErrorPrinter tmp;
    return CxxTest::Main<CxxTest::ErrorPrinter>( tmp, argc, argv );
}
bool suite_Test_init = false;
#include "test.h"

static Test suite_Test;

static CxxTest::List Tests_Test = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Test( "test.h", 8, "Test", suite_Test, Tests_Test );

static class TestDescription_suite_Test_test1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_test1() : CxxTest::RealTestDescription( Tests_Test, suiteDescription_Test, 14, "test1" ) {}
 void runTest() { suite_Test.test1(); }
} testDescription_suite_Test_test1;

static class TestDescription_suite_Test_testOsszeadas1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_testOsszeadas1() : CxxTest::RealTestDescription( Tests_Test, suiteDescription_Test, 22, "testOsszeadas1" ) {}
 void runTest() { suite_Test.testOsszeadas1(); }
} testDescription_suite_Test_testOsszeadas1;

static class TestDescription_suite_Test_testOsszeadas2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_testOsszeadas2() : CxxTest::RealTestDescription( Tests_Test, suiteDescription_Test, 31, "testOsszeadas2" ) {}
 void runTest() { suite_Test.testOsszeadas2(); }
} testDescription_suite_Test_testOsszeadas2;

static class TestDescription_suite_Test_testOsszeadas0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_testOsszeadas0() : CxxTest::RealTestDescription( Tests_Test, suiteDescription_Test, 43, "testOsszeadas0" ) {}
 void runTest() { suite_Test.testOsszeadas0(); }
} testDescription_suite_Test_testOsszeadas0;

static class TestDescription_suite_Test_testSzorzas : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_testSzorzas() : CxxTest::RealTestDescription( Tests_Test, suiteDescription_Test, 55, "testSzorzas" ) {}
 void runTest() { suite_Test.testSzorzas(); }
} testDescription_suite_Test_testSzorzas;

static class TestDescription_suite_Test_testSzorzas1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_testSzorzas1() : CxxTest::RealTestDescription( Tests_Test, suiteDescription_Test, 64, "testSzorzas1" ) {}
 void runTest() { suite_Test.testSzorzas1(); }
} testDescription_suite_Test_testSzorzas1;

static class TestDescription_suite_Test_testSzorzas0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_testSzorzas0() : CxxTest::RealTestDescription( Tests_Test, suiteDescription_Test, 73, "testSzorzas0" ) {}
 void runTest() { suite_Test.testSzorzas0(); }
} testDescription_suite_Test_testSzorzas0;

static class TestDescription_suite_Test_testOsszeadasNagy : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_testOsszeadasNagy() : CxxTest::RealTestDescription( Tests_Test, suiteDescription_Test, 82, "testOsszeadasNagy" ) {}
 void runTest() { suite_Test.testOsszeadasNagy(); }
} testDescription_suite_Test_testOsszeadasNagy;

static class TestDescription_suite_Test_testSzorzasNagy : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_testSzorzasNagy() : CxxTest::RealTestDescription( Tests_Test, suiteDescription_Test, 91, "testSzorzasNagy" ) {}
 void runTest() { suite_Test.testSzorzasNagy(); }
} testDescription_suite_Test_testSzorzasNagy;

static class TestDescription_suite_Test_testSzorzasKomm : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_testSzorzasKomm() : CxxTest::RealTestDescription( Tests_Test, suiteDescription_Test, 101, "testSzorzasKomm" ) {}
 void runTest() { suite_Test.testSzorzasKomm(); }
} testDescription_suite_Test_testSzorzasKomm;

static class TestDescription_suite_Test_testSeged : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_testSeged() : CxxTest::RealTestDescription( Tests_Test, suiteDescription_Test, 116, "testSeged" ) {}
 void runTest() { suite_Test.testSeged(); }
} testDescription_suite_Test_testSeged;

static class TestDescription_suite_Test_testCopy : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_testCopy() : CxxTest::RealTestDescription( Tests_Test, suiteDescription_Test, 128, "testCopy" ) {}
 void runTest() { suite_Test.testCopy(); }
} testDescription_suite_Test_testCopy;

static class TestDescription_suite_Test_testAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_testAssignment() : CxxTest::RealTestDescription( Tests_Test, suiteDescription_Test, 137, "testAssignment" ) {}
 void runTest() { suite_Test.testAssignment(); }
} testDescription_suite_Test_testAssignment;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
