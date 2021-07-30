create database if not exists vod_system;

use vod_system;

create table if not exists tb_video(
    id int primary key auto_increment,
    name varchar(32),
    vdesc text,
    video_url varchar(255),
    image_url varchar(255),
    ctime datetime

);
insert tb_video values(null,"让子弹飞","非物质文化遗产","/video/plane.mp4","/image/plane.jpg",now());
