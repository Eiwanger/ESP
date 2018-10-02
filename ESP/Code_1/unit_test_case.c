#include <gtest/gtest.h>
#include "modbus.h"

TEST(MytestCategory,MyTEst1)
{
    unsigned char MBframe[]=":0103040404";
    unsigned char lrc;

    lrc=MB_count_LRC(MBframe,5);
    EXPECT_EQ(0xF0,lrc);
}

TEST(MytestCategory,MyTEst2)
{
    unsigned char MBframe[]=":0103041404";
    unsigned char lrc;

    lrc=MB_count_LRC(MBframe,5);
    EXPECT_EQ(0xE0,lrc);
}

TEST(MytestCategory,MyTEst3)
{
    unsigned char MBframe[]=":0103B39A055F677";
    unsigned char lrc;

    lrc=MB_count_LRC(MBframe,8);
    EXPECT_EQ(38,lrc);
}



