#include "gtest/gtest.h"

extern "C"{
#include "QARR.h"
#include "QList.h"
#include <stdlib.h>
}

TEST(testQueueArray, addInArraynonfull) {
	QueueARR q;
	q.last = 0;
	AddARR(&q, 5);
	EXPECT_TRUE(q.data[0] == 5);
}
TEST(testQueueArray, addInArrayfull) {
	QueueARR q;
	int flaq = 3;
	q.last = 10;
	flaq = AddARR(&q, 5);
	EXPECT_TRUE(flaq == 0);
}
TEST(testQueueArray, deletefromArraynonempty) {
	QueueARR q;
	int flaq = 3;
	q.last = 3;
	q.data[0] = 3;
	q.data[1] = 2;
	q.data[2] = 1;
	flaq = DeleteARR(&q);
	EXPECT_TRUE(flaq == 1);
}
TEST(testQueueArray, deletefromArrayempty) {
	QueueARR q;
	int flaq = 3;
	q.last = 0;
	flaq = DeleteARR(&q);
	EXPECT_TRUE(flaq == 0);
}
TEST(testQueueArray, TopfromArraynonempty) {
	QueueARR q;
	int flaq = 3;
	q.last = 3;
	q.data[0] = 1;
	q.data[1] = 2;
	q.data[2] = 4;
	flaq = TopARR(&q);
	EXPECT_TRUE(flaq == 1);
}
TEST(testQueueArray, TopfromArrayempty) {
	QueueARR q;
	int flaq = 3;
	q.last = 0;
	q.data[0] = 0;
	flaq = TopARR(&q);
	EXPECT_TRUE(flaq == -1);
}
TEST(testQueueArray, PopfromArraynonempty) {
	QueueARR q;
	int flaq = 3;
	q.last = 3;
	q.data[0] = 13;
	q.data[1] = 2;
	q.data[2] = 4;
	flaq = PopARR(&q);
	EXPECT_TRUE(flaq == 13);
}



TEST(testQueueList, InitArray) {
	Queue q;
	Init(&q);
	EXPECT_TRUE((q.first == NULL) && (q.first == NULL));
}
TEST(testQueueList, addInArrayEmpty) {
	Queue q;
	Init(&q);
	Add(&q, 5);
	EXPECT_TRUE(q.first->data == 5);
}
TEST(testQueueList, addInArrayEmptyMoreThanOneTime) {
	Queue q;
	Init(&q);
	Add(&q, 5);
	Add(&q, 8);
	EXPECT_TRUE(q.first->next->data == 8);
}
TEST(testQueueList, PopfromArraynonempty) {
	Queue q;
	int buf = 0;
	int flaq;
	Init(&q);
	Add(&q, 5);
	flaq = Pop(&q, &buf);
	int buf1 = q.last->data;
	EXPECT_TRUE((buf == 5)&&(buf1!=buf)&&(flaq));
}
TEST(testQueueList, PopfromArrayempty) {
	Queue q;
	Init(&q);
	int buf = 0;
	int flaq = 3;
	flaq = Pop(&q, &buf);
	
	EXPECT_TRUE((buf == 0) && !(flaq));
}
