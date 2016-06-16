#ifndef PURETEST_H
#define PURETEST_H


class PureTest
{
public:
    PureTest();

    void test1() const;
    void test2() const noexcept;
};

void testPure();

void testVector();

#endif // PURETEST_H
