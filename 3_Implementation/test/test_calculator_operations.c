#include<stdio.h>
#include "../unity/unity.h"
#include "../unity/unity_internals.h"
void setUp(){}
void tearDown(){}
char confirm;
void check(void)
{
    TEST_ASSERT_EQUAL('y',confirm);
}

int main(){
    FILE *fp;
	fp=fopen("tickets_reserved.txt","r");
     if(fp == NULL)
    {
        confirm='n';
    }else{
        confirm='y';
    }
    UNITY_BEGIN();
    RUN_TEST(check);
    return UNITY_END();
}
