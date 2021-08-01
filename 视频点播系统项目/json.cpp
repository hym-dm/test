#include<iostream>
#include<string>
#include<jsoncpp/json/json.h>
std::string seria()
{
    Json::Value val;
    val["学号"]=1001;
    val["姓名"]="张三";
    val["婚否"]=false;
    val["成绩"].append(77);//专用于数组元素添加
    val["成绩"].append(77);//专用于数组元素添加
    val["成绩"].append(77);//专用于数组元素添加
  
    Json::FastWriter writer;
    // Json::StyledWriter writer;
    std::string str = writer.write (val);
    str[str.size()-1] = '\0';
    return str;
}
void unseria(std::string &str)
{
    Json::Value val;
    Json:: Reader reader;
    bool ret = reader.parse(str, val);
    if(ret == false)
    {
        std::cout<<"pase failed!"<<std::endl;
        return;
    }
    std::cout<<val["学号"].asInt()<<std::endl;
    std::cout<<val["姓名"].asString()<<std::endl;
    std::cout<<val["姓名"].asCString()<<std::endl;
    std::cout<<val["婚否"].asBool()<<std::endl;
    int num = val["成绩"].size();
for(int i=0;i<num;i++)
{
    std::cout<<val["成绩"][i].asFloat()<<std::endl;
}
}
int main()
{
    std::string str;
    str = seria();     
    std::cout<< "["<<str<<"]\n";
    unseria(str);
    return 0;
}
