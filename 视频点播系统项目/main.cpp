#include "db.hpp"
#include "httplib.h"
#include<regex>
#define WWWROOT "./wwwroot"
using namespace httplib;
vod_system::TableVod *tb_video;

void VideoDelete(const Request  &req,Response &rsp)
{
        int video_id=std::stoi(req.matches[1]);
        Json::Value video;
        Json::FastWriter writer;
        Json::Value json_rsp;
        bool ret = tb_video->GetOne(video_id, &video);
        if(ret == false)
        {
                std::cout<<"mysql get viodeo info failed!\n";
                rsp.status = 500;
                json_rsp["result"]=false;
                json_rsp["reason"]="mysql get video info failed!";
                rsp.body=writer.write(json_rsp);
                rsp.set_header("Content-Type","application/json");
                return;
        }
        std::string vpath = WWWROOT + video["video_url"].asString();
        std::string ipath = WWWROOT + video["image_url"].asString();
        unlink(vpath.c_str());
        unlink(ipath.c_str());
        ret = tb_video->Delete(video_id);
        if(ret==false)
        {
                rsp.status=500;
                std::cout<<"mysql delete video failed!\n";
                return;
        }
}
void VideoUpdate(const Request  &req,Response &rsp)
{
        int video_id=std::stoi(req.matches[1]);
        Json::Value video;
        Json::Reader reader;
        bool ret=reader.parse(req.body, video);
        if(ret==false)
        {
                std::cout<<"update video :parse video json failed!\n";
                rsp.status = 400;
                return;
        }
        ret = tb_video->Update(video_id,video);
        if(ret==false)
        {
                std::cout<<"update video:mysql update failed!\n";
                rsp.status =500;
                return;
        }
}
void VideoGetAll(const Request &req,Response &rsp)
{
        Json::Value videos;
        Json::FastWriter writer;
        bool ret=tb_video->GetAll(&videos);
        if(ret==false)
        {
                std::cout<<"getall video:mysql operation failed!\n";
                rsp.status =500;
                return;
        }
        rsp.body=writer.write(videos);
        rsp.set_header("Content-Type","application/json");
}
void VideoGetOne(const Request &req,Response &rsp)
{

        int video_id = std::stoi(req.matches[1]);
        Json::Value video;
        Json::FastWriter writer;
      bool  ret=tb_video->GetOne(video_id,&video);
        if(ret==false)
        {
                std::cout<<"getone video:mysql operation failed!\n";
                rsp.status =500;
                return;
        }
        rsp.body=writer.write(video);
        rsp.set_header("Content-Type","application/json");
}
#define VIDEO_PATH "/video/"
#define IMAGE_PATH "/image/"
void VideoUpload(const Request &req,Response &rsp)
{
        auto ret = req.has_file("video_name");//判断是否有某个文件上传
        if(ret==false)
        {
                std::cout<<"have no video name!\n";
                rsp.status=400;
                return;
        }
        const auto& file = req.get_file_value("video_name");
        std::string vname=file.content;
        ret = req.has_file("video_desc");//判断是否有某个文件上传
        if(ret==false)
        {
                std::cout<<"have no video desc!\n";
                rsp.status=400;
                return;
        }
        const auto&file1 = req.get_file_value("video_desc");
        std::string vdesc = file1.content;
       
       ret=req.has_file("video_file");//判断是否有某个文件上传
        if(ret==false)
        {
                std::cout<<"have no video file!\n";
                rsp.status=400;
                return;
        }
     
        const auto &file2 = req.get_file_value("video_file"); 
        ret = req.has_file("image_file");//判断是否有某个文件上传
        if(ret==false)
       {
         std::cout<<"have no image file!\n";
         rsp.status=400;
         return;
       }
    const auto &file3 = req.get_file_value("image_file");
    const      std::string &vfile=file2.filename;
    const      std::string &vcont=file2.content;
    const      std::string &ifile=file3.filename;
    const      std::string &icont=file3.content;
               std:: string vurl = VIDEO_PATH + file2.filename;
     std::string wwwroot= WWWROOT;
     vod_system::     Util::WriteFile(wwwroot + vurl, file2.content); 
            std::     string iurl = IMAGE_PATH + file3.filename;
     vod_system::     Util::WriteFile(wwwroot + iurl, file3.content);

          Json::Value video;
          video["name"]=vname;
          video["vdesc"]=vdesc;
          video["video_url"]=vurl;
          video["image_url"]=iurl;
          ret=tb_video->Insert(video);
          if(ret==false)
          {
           
           rsp.status = 500;
           std::cout<<"insert video: mysql operation failed!\n";
           return ;
         }
         return;
}

                
int main()
{
        tb_video = new vod_system::TableVod();
         httplib:: Server srv;
        //正则表达式\d匹配一个字符：+匹配一次或多次
        //R”（string）“取出括号中字符串中每个字符的特殊含义
        srv.set_base_dir("./wwwroot");
        srv.Delete(R"(/video/(\d+))",VideoDelete);
        srv.Put(R"(/video/(\d+))",VideoUpdate);
        srv.Get(R"(/video)",VideoGetAll);
        srv.Get(R"(/video/(\d+))",VideoGetOne);
        srv.Post(R"(/video)",VideoUpload);
        srv.listen("0.0.0.0",9000);
}
void test()
{
        vod_system::TableVod tb_vod;
        Json::Value val;
        // val["name"]="云顶天宫";
        // val["vdesc"]="这是一个烂片";
        // val["video_url"]="/video/tianxian.mp4";
        // val["image_url"]="/video/tianxian.jpg";
        //tb_vod.Insert(val);
        // tb_vod.Update(2,val);
        // tb_vod.Delete(3);
        // tb_vod.GetAll(&val);
        tb_vod.GetOne(1,&val);
        Json::StyledWriter writer;
        std::cout<<writer.write(val)<<std::endl;
        return;
}
//int main()
//{

//test();
// return 0;
//}
