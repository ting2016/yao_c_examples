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

#endif // PURETEST_H
