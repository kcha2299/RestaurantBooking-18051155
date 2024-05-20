#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "MailSender.cpp"

class TestableMailSender : public MailSender {
public:
	void sendMail(Schedule* schedule) {
		countSendMailMethodIsCalled++;
	}

	int getCountSendMailMethodIsCalled() {
		return countSendMailMethodIsCalled;
	}

private:
	int countSendMailMethodIsCalled = 0;
};