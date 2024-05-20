#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "SmsSender.cpp"
#include <iostream>

using namespace std;

class TestableSmsSender : public SmsSender {
public:
    void send(Schedule* schedule) override {
        cout << "테스트용 SmsSender class의 send 메서드 실행됨" << endl;
        sendMethodIsCalled = true;
    }

    bool isSendMethodIsCalled() {
        return sendMethodIsCalled;
    }

private:
    bool sendMethodIsCalled;
};