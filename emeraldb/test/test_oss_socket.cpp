//
// Created by xiehui02 on 2019-07-15.
//

#include "test_oss_socket.h"


void test_oss_socket::SetUpTestCase() {
   printf("setup test case");
}

void test_oss_socket::TearDownTestCase() {
    printf("tear down test case");
}

TEST_F(test_oss_socket, CheckTrue) {
    ossSocket _ossSocket;
    int ret = _ossSocket.initSocket();
    ASSERT_EQ(ret, 8);
}