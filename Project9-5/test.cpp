#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../Project9-5/BookingScheduler.cpp"
#include <iostream>
#include <ctime>

using namespace std;
using std::time_t;
using std::time;
using std::cout;

time_t getTime(int year, int mon, int day, int hour, int min, int sec) {
    tm result = { sec, min, hour, day, mon - 1, year - 1900, 0, 0, -1 };
    //mktime = tm_wday, tm_yday를 자동으로 계산 후 time_t 리턴
    return mktime(&result);
}

class BookingItem : public testing::Test {
protected:
    void SetUp() override {
        NOT_ON_THE_HOUR = getTime(2021, 3, 26, 9, 5);
        ON_THE_HOUR = getTime(2021, 3, 26, 9, 0);
    }
public:
    tm getTime(int year, int mon, int day, int hour, int min) {
        tm result = { 0, min, hour, day, mon - 1, year - 1900, 0, 0, -1 };
        mktime(&result);
        return result;
    }

    tm NOT_ON_THE_HOUR;
    tm ON_THE_HOUR;
    Customer CUSTOMER{ "Fake name", "010-1234-5678" };
    const int UNDER_CAPACITY = 1;
    const int CAPACITY_PER_HOUR = 3;

    BookingScheduler bookingScheduler{ CAPACITY_PER_HOUR };
};

TEST_F(BookingItem, 예약은_정시에만_가능하다_정시가_아닌경우_예약불가) {
    // arrange
    Schedule* schedule = new Schedule{ NOT_ON_THE_HOUR, UNDER_CAPACITY, CUSTOMER };

    // act
    EXPECT_THROW({ bookingScheduler.addSchedule(schedule); }, runtime_error);

    // assert
    // expected runtime exception
}


TEST_F(BookingItem, 예약은_정시에만_가능하다_정시인_경우_예약가능) {
    // arrange
    Schedule* schedule = new Schedule{ ON_THE_HOUR, UNDER_CAPACITY, CUSTOMER };

    // act
    bookingScheduler.addSchedule(schedule);

    // assert
    EXPECT_EQ(true, bookingScheduler.hasSchedule(schedule));
}

TEST_F(BookingItem, 시간대별_인원제한이_있다_같은_시간대에_Capacity_초과할_경우_예외발생) {

}

TEST_F(BookingItem, 시간대별_인원제한이_있다_같은_시간대가_다르면_Capacity_차있어도_스케쥴_추가_성공) {

}

TEST_F(BookingItem, 예약완료시_SMS는_무조건_발송) {

}

TEST_F(BookingItem, 이메일이_없는_경우에는_이메일_미발송) {

}

TEST_F(BookingItem, 이메일이_있는_경우에는_이메일_발송) {

}

TEST_F(BookingItem, 현재날짜가_일요일인_경우_예약불가_예외처리) {

}

TEST_F(BookingItem, 현재날짜가_일요일이_아닌경우_예약가능) {

}