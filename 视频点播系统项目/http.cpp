#include "httplib.h"
#include<ofstream>
using namespace httplib;
void helloworld(const Request &req, Response &rsp)
{
rsp.body="<html><body><h1>Hello Bit</h1></body></html>";
rsp.status=200;
rsp.set_header("Content-Type","text/html");
}
bool WriteFile(std::string &name, std::string &content)
{  
  std::ofstream of;
  of.open(name,std::ios::out|std::ios::binary|std::ios::trunc);
  if(!of.is_open())
  {
   std::cout<<"open file failed!\n";
   return false;
  }
  of.write(content.c_str(),content.size());
  if(!of.good())
  {
   std::cout<<"write file failed!\n";
   return false;
  }
 of.close(); 
 return true;
}

void upload(const Request &req, Response &rsp)
{
  auto ret = req.has_file("video_name");//判断是否有某个文件上传
  if(ret==false)
  {
  std::cout<<"have no file!\n";
  return;
  }
  const auto& file = req.get_file_value("video_name");
  std::string vname=file.content;
 
  ret = req.has_file("video_desc");//判断是否有某个文件上传
  if(ret==false)
  {
  std::cout<<"have no file!\n";
  return;
  }
 const auto&file1 = req.get_file_value("video_desc");
  std::string vdesc = file1.content;
 
  ret = req.has_file("video_file");//判断是否有某个文件上传
  if(ret==false)
  {
  std::cout<<"have no file!\n";
  return;
  }
 const auto &file2 = req.get_file_value("video_file");
  std::string vfile=file2.filename;
  std::string vcont=file2.content;

  ret = req.has_file("image_file");//判断是否有某个文件上传
  if(ret==false)
  {
  std::cout<<"have no file!\n";
  return;
  }
 const auto &file3 = req.get_file_value("image_file");
  std::string ifile=file3.filename;
  std::string icont=file3.content;

  std::cout<<"["<<vname<<"]\n";
  std::cout<<"["<<vdesc<<"]\n";
  std::cout<<"["<<vfile<<"]\n";
  std::cout<<"["<<vcont<<"]\n"; 
  std::cout<<"["<<ifile<<"]\n";
  std::cout<<"["<<icont<<"]\n";
}
int main()
{
 httplib::Server srv;
 srv.set_base_dir("./wwwroot");
 srv.Get("/hello", helloworld);
 srv.Post("/video",upload);
 srv.listen("0.0.0.0",9000);
 return 0;
}
