#include <boost/program_options.hpp>
#include <string>
#include <iostream>
using namespace std;
namespace BPO=boost::program_options;

int main(int argc,char** argv){
    BPO::options_description bOptions("Test Options");
    bOptions.add_options()("help","Produce help message")("vint",BPO::value<int>(),"int value");
    BPO::variables_map mVMap;
    BPO::store(BPO::parse_command_line(argc,argv,bOptions),mVMap);
    BPO::notify(mVMap);
    if (mVMap.count("help"))
    {
        cout<<bOptions<<endl;
    }
    if(mVMap.count("vint"))
    {
        int iValInt=mVMap["vint"].as<int>();
        cout<<"Int:"<<iValInt<<endl;
    }
}