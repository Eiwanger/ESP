/*
Function will calculate a LRC checksum from a Modbus ASCII message

To calculate the LRC: 
   1.  Add up all the data bytes in the message (after converting two ASCII character into datavalue, All values without the initial colon and final CR/LF).
   2.  Throw away any bits that carry over 8 bits.
   3.  Make the result negative (by twos compliment) to get the LRC byte.

Example:
:12134455

2 cpmplement (12+13+44+55)  


*/

unsigned char MB_count_LRC(unsigned char *mb_data, unsigned char mb_l)
{
    unsigned char lrc,i=0,value = 0;

    for (i=1; i<=mb_l*2; i= i+2)
    {   
        value=(*(mb_data+i)-'0')*16 +(*(mb_data+i+1)-'0');
        lrc+=value;
       }
    lrc=~lrc+1;

    return lrc;
}

