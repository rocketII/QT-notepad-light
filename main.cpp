#include "mainwindow.h"
#include <QApplication>
#include<iostream>
using namespace std;
//string& caesarCrypto(string mytxt);
//main(int argc, char *argv[])
int main(int argc, char *argv[])
{
    //cout << "abc"<<endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    //return 0;
}

/*
string& caesarCrypto(string mytxt, int sizeOfArray)
{
    /*
     *caesar crypto: each source letter are moved k positions in the alphabet.
     * To decrypt you move back k positions.
     * This crypto is one of the oldest and one of the easiest to decrypt.
    //*
    string mytxt2Caesar[sizeOfArray];
    int k = 4;
    //char abc[]={a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,å,ä,ö};
    for(int i=0; i < sizeOfArray; i++)
    {
        mytxt2Caesar[i] = mytxt[i];
    }
    return &mytxt2Caesar;


}*/
