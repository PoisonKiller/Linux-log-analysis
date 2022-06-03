#include <stdio.h>
#include "include/IPLocator.hpp"
using namespace std;

int main()
{
  IPLocator ipl("QQWry.dat");
  string ip("202.200.225.52");
    cout << ipl.getVersion() << endl ;
    cout << ipl.getIpAddr(ip) << endl;
    cout << ipl.getIpRange(ip) << endl;
    return 0;
}

