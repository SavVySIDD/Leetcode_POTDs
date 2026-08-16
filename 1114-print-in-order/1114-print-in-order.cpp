#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class Foo {
private:
    mutex mtx;
    condition_variable cv;
    int step;

public:
    Foo() : step(1) {}

    void first(function<void()> printFirst) {
        // printFirst() outputs "first".
        printFirst();

        // Lock, update state to 2, and wake up any waiting threads
        {
            unique_lock<mutex> lock(mtx);
            step = 2;
        }
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        // Wait until step becomes 2
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() { return step == 2; });

        // printSecond() outputs "second".
        printSecond();

        step = 3;
        lock.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        // Wait until step becomes 3
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() { return step == 3; });

        // printThird() outputs "third".
        printThird();
    }
};