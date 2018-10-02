#include <stdio.h>

struct time_t{
	int hours;
	int minutes;
	int seconds;
};


int time_diff(struct time_t time1, struct time_t time2)
{
	unsigned int hours;
	unsigned int minutes; 
	unsigned int seconds; 
		hours = time1.hours - time2.hours;
		minutes = time1.minutes - time2.minutes;
		seconds = time1.seconds - time2.seconds;

	return hours*3600 + minutes * 60 + seconds;
}














int main()
{

	struct time_t time1={12,12,12};
	struct time_t time2={12,12,12};
	struct time_t time3={18,10,1};
	struct time_t time4={1, 59,45};
	struct time_t time5={0, 0, 0};
	struct time_t time6={0, 1, 0};
	struct time_t time7={1,8,2};
	struct time_t time8={16,1,4};

	printf("%d    Expected: 0 \n",time_diff(time1,time2));
	printf("%d    Expected: 21731\n",time_diff(time1,time3));
	printf("%d    Expected: 42453\n",time_diff(time1,time4));

	printf("%d    Expected: 21731\n",time_diff(time2,time3));
	printf("%d    Expected: 42453\n",time_diff(time2,time4));
	printf("%d    Expected: 64184\n",time_diff(time3,time4));
	printf("%d    Expected: 64184\n",time_diff(time5,time6));
	printf("%d    Expected: 64184\n",time_diff(time7,time8));

	return 0;
}
