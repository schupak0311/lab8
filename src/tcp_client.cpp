#include <progbase-cpp/net.h>
#include <iostream>
#include "tcp_client.h"

using namespace std;
using namespace progbase::net;

int tcpClient(void) {
//    int main(void){
    TcpClient client;
    NetMessage message(1000);
    try {
        client.connect(IpAddress("127.0.0.1", 8080));
        message.setDataString("GET /favorites HTTP/1.1\r\nHost: Localhost \r\n\r\n");
        client.send(message);
        cout << ">> Request sent" << endl;
        do {
            client.receive(message);
            std::string str = message.dataAsString();
            cout << ">> Received " << str.length() << " bytes: " << endl << str << endl;
        } while (!message.isEmpty());
    } catch(NetException const & exc) {
        cerr << exc.what() << endl;
    }
    return 0;
}