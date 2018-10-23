#include <gtest/gtest.h>
#include "modbus.h"
#include "ringbuffer.h"

/*******************************************/

TEST(RingCategory, RingTEst1)
{
  unsigned char recive_buffer[MAX_BUFFER];
  unsigned char rx_buffer[1024];
  struct buffer_type r;

  init_buffer(&r,rx_buffer);

  EXPECT_EQ(r.head,rx_buffer);
  EXPECT_EQ(r.tail,rx_buffer);
  EXPECT_EQ(r.buffer,rx_buffer);

}

/*******************************************/

TEST(ErrorCategory, ErrTEst)
{
  unsigned char recive_buffer[MAX_BUFFER];
  struct buffer_type b;

  empty_buffer(&b);

  EXPECT_EQ(0, empty_buffer(&b));
  EXPECT_EQ(0, empty_buffer(&b));
  EXPECT_EQ(0, empty_buffer(&b));
}

/******************************************/

TEST(StateCategory, StTEst)
{
  unsigned char recive_buffer[MAX_BUFFER];
  struct buffer_type b;
  error_type err;

  b.head=&recive_buffer[5];
  b.tail=&recive_buffer[3];
  b.buffer=&recive_buffer[0];

  EXPECT_EQ(2,get_buffer_state(&b,&err));
}

/*****************************************/

TEST(AddCategory, AddTEst)
{
  unsigned char recive_buffer[MAX_BUFFER];
  unsigned int c;
  struct buffer_type b;
  error_type err;

  b.head=&recive_buffer[5];
  b.tail=&recive_buffer[5];
  b.buffer=&recive_buffer[0];

   EXPECT_EQ(-57,add_char_to_buffer(&b,c,&err));
}

/******************************************/

  TEST(GetCategory, GtTest)
  {
  unsigned char recive_buffer[MAX_BUFFER];
  unsigned char c='a';

  recive_buffer[3]=c;
  struct buffer_type b;
  error_type err;
  b.head=&recive_buffer[5];
  b.tail=&recive_buffer[3];
  b.buffer=&recive_buffer[0];

  EXPECT_EQ('a', get_char_from_buffer(&b,&err));
}

/********************************************/

  TEST(PrintCategory, PrintTEst)
  {
  unsigned char recive_buffer[MAX_BUFFER]="jesjesjes";
  struct buffer_type b;

  error_type err;
  b.head=&recive_buffer[6];
  b.tail=&recive_buffer[3];
  b.buffer=&recive_buffer[0];

  EXPECT_EQ(3, print_buffer(b,&err));
  EXPECT_EQ('j', recive_buffer[3]);
  EXPECT_EQ('e', recive_buffer[4]);
  EXPECT_EQ('s', recive_buffer[5]);
}

/********************************************/
