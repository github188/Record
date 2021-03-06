问题记录：
1、子码流 704*576，可实际图片大小640*352。


4: DNS解析失败
5: IPC抓图信息
6: 图片base64转码
7: 获取磁盘信息
8: 开辟内存空间
SBizSearchPara
界面：
1、抓图参数
2、图片回放
3、图片备份

ConfigGetSnapParam
ConfigSetSnapParam   ConfigSetIPCameraParam
bizData_GetIPCExtSensorAlarmDefault( i, &sPIns );


海康NVR
1、设置Agent ID，主菜单-系统配置-通用配置。需要向深广平台申请获得。


界面说明：
1、用户报修。系统故障后，监控人员向深广平台上报故障信息。
2、维保维护。维保维护专业人员向深广平台的反馈。
3、测试保养。测试图片上传：安装人员安装后测试用；保养图片上传：维护专业人员保养后操作。可对所有/部分通道抓图上传。
4、验收管理。设备安装后由警察负责验收。可对所有/部分通道抓图上传。
5、基本设置。运行状态、报警联动设置是否上传；
	报警图片设置：输入端子是 NVR外接的传感器，共计17个，当设置的传感器报警后，启动指定通道的抓图，
		上传报警前m秒后n秒，每间隔p秒的图像（前置时间：n，延录时间：m，间隔时间p）。
	日常图片配置：相当于闹钟功能，可以设置两个闹钟，系统运行到达指定时间后，可对所有/部分通道抓图上传。

消息类型说明
01报警联动图像
02保养上传图像
03日常上传图像
04测试上传图像
05-10 保留
11其他系统故障
12周界报警故障
13联网报警故障
14本地报警故障
15视频监控故障
16楼宇对讲故障
17出入控制故障
18电子巡更故障
19DVR系统启动
20DVR系统退出
21DVR异常退出
22DVR参数设置
23DVR参数保存
24DVR视屏丢失
25DVR移动侦测
26DVR外部触发
27系统报警解除
28DVR非法退出
29系统维修签到
30系统维保签到
31DVR本地回放
32DVR远程回放
33验收上传图像
36报警上传图像（未录像或移动侦测）
37保养上传图像（未录像或移动侦测）
38日常上传图像（当日未录像）
39测试上传图像（未录像或移动侦测）
40验收上传图像（未录像或移动侦测）
41DVR磁盘错误
42系统心跳超时
43系统心跳恢复
44视频其他事件

//yaogang modify 20141209
	//深广平台参数

//yaogang modify 20141209 深广平台参数
ModConfigGetParam
psSensorPara

//yaogang modify 20141209
//深广平台参数
typedef struct
{
	u8 TimeEnable;	//定时上传时间使能
	u8 hour;
	u8 min;
	u8 sec;
} SModSGTime;
typedef struct
{
	u8 PreTimes;		//前置时间
	u8 Interval;		//间隔时间
	u8 StillTimes;		//延录时间
	u8 AlarmInput;	//输入端子
	u32 IpcChn;		//16个IPC通道各占一位，0x1000 0000表示所有通道
} SModAlarmPicCFG;
typedef struct
{
	SModSGTime Time1;		//定时上传时间1 
	SModSGTime Time2;		//定时上传时间2
	u32 IpcChn1;		//16个IPC通道各占一位，0x1000 0000表示所有通道
	u32 IpcChn2;		//16个IPC通道各占一位，0x1000 0000表示所有通道
} SModDailyPicCFG;
typedef struct
{
	char AgentID[100];
	char CenterIP[100];
	u8 RunEnable;//运行状态启用
	u8 AlarmEnable;//报警联动启用
	u8 DailyPicEnable;//日常图像启用
	SModAlarmPicCFG SAlarmPicParam;//报警图片配置参数
	SModDailyPicCFG SDailyPicParam;//日常图片配置参数
} SModConfigSGParam;

//写配置文件时 各个数据段序号

RefreshAlarmList()
CfgPtn.LocalAlarm=本机报警
CfgPtn.Motion
CfgPtn.VideoLoss
CfgPtn.IPCExtAlarm=IPC外部报警
CfgPtn.IPCCoverAlarm=IPC遮挡报警
CfgPtn.485ExtAlarm=485扩展报警
CfgPtn.ExtAlarm=报警扩展
CfgPtn.HDDAlarm=硬盘报警
CfgPtn.DiskLost=硬盘丢失
CfgPtn.DiskErr=硬盘读写错误
CfgPtn.DiskNone=开机无硬盘

消息记录					Note
系统启动
QWCMD: <?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="SSJCyao3gang" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="19" Channel="0" TriggerTime="2014-12-17 19:43:08" Note="5ZCv5Yqo57O757uf77yM6L+b5YWl5bel5L2c54q25oCB" GUID="1060221395">
</OperationCmd>
</Agent>

用户报修  15 视频监控故障 前端故障
QWCMD:<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="abc" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="15" Channel="0" TriggerTime="2014-12-16 13:28:03" Note="5YmN56uv5pWF6Zqc" GUID="1555950586">
</OperationCmd>
</Agent>

用户报修  17 出入控制故障 终端故障
QWCMD:<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="abc" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="17" Channel="0" TriggerTime="2014-12-16 14:15:43" Note="57uI56uv5pWF6Zqc" GUID="943511967">
</OperationCmd>
</Agent>

用户报修  16 楼宇对讲故障 系统故障
QWCMD:<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="abc" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="16" Channel="0" TriggerTime="2014-12-16 14:20:00" Note="57O757uf5pWF6Zqc" GUID="81095966">
</OperationCmd>
</Agent>

30 系统维保签到 异常 已修复
QWCMD:<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="abc" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="30" Channel="0" TriggerTime="2014-12-16 14:36:29" Note="5byC5bi4IOW3suS/ruWkjQ==" GUID="1361512346">
</OperationCmd>
</Agent>

server ack
QWCMD:<?xml version="1.0" encoding="UTF-8"?><Server Ver="1.0"><Ticks Value="5"/><OK NowTime="2014-12-16 14:36:30"/></Server>

29 系统维修签到		不选
QWCMD:<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="abc" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="29" Channel="0" TriggerTime="2014-12-16 14:36:29" Note="5LiN6YCJ" GUID="1185511183">
</OperationCmd>
</Agent>

server ack
QWCMD:<?xml version="1.0" encoding="UTF-8"?><Server Ver="1.0"><Ticks Value="5"/><OK NowTime="2014-12-16 14:36:30"/></Server>

4 测试图片上传，共有3通道，每个通道独立依次按此流程操作 建立连接-->上传数据-->关闭连接
																	Note 测试上传图像
QWCMD:=<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="abc" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="4" Channel="1" TriggerTime="2014-12-16 14:45:14" Note="5rWL6K+V5LiK5Lyg5Zu+5YOP" GUID="1954823277">
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</OperationCmd>
</Agent>

其中base64编码的图片
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

server ack
QWCMD:<?xml version="1.0" encoding="UTF-8"?><Server Ver="1.0"><Ticks Value="5"/><OK NowTime="2014-12-16 14:45:15"/></Server>

2 保养上传图像														Note 保养上传图像
QWCMD:A=<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="abc" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="2" Channel="1" TriggerTime="2014-12-16 15:01:11" Note="5L+d5YW75LiK5Lyg5Zu+5YOP" GUID="152818876">


"&CfgPtn.PoliceID",
"&CfgPtn.KeyWord",
33 验收上传图像														Note 警官号: 9527 密码: 123456
QWCMD:;<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="abc" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="33" Channel="1" TriggerTime="2014-12-16 15:32:27" Note="6K2m5a6Y5Y+3OiA5NTI3IOWvhueggTogMTIzNDU2" GUID="180853964">
/9j/4AAQSkZJRgABAgEAYABgAAD/wAARCAEgAWADASIAAhEBAxEB/8QBogAAAQUBAQEBAQEAAAAAAAAAAAECAwQFBgcICQoLEAACAQMDAgQDBQUEBAAAAX0BAgMABBEFEiExQQYTUWEHInEUMoGRoQgjQrHBFVLR8CQzYnKCCQoWFxgZGiUmJygpKjQ1Njc4OTpDREVGR0hJSlNUVVZXWFlaY2RlZmdoaWpzdHV2d3h5eoOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4eLj5OXm5+jp6vHy8/T19vf4+foBAAMBAQEBAQEBAQEAAAAAAAABAgMEBQYHCAkKCxEAAgECBAQDBAcFBAQAAQJ3AAECAxEEBSExBhJBUQdhcRMiMoEIFEKRobHBCSMzUvAVYnLRChYkNOEl8RcYGRomJygpKjU2Nzg5OkNERUZHSElKU1RVVldYWVpjZGVmZ2hpanN0dXZ3eHl6goOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4uPk5ebn6Onq8vP09fb3+Pn6/9sAhAAFAwQEBAMFBAQEBQUFBgcMCAcHBwcPCwsJDBEPEhIRDxERExYcFxMUGhURERghGBodHR8fHxMXIiQiHiQcHh8eAQUFBQcGBw4ICA4eFBEUHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh4eHh7/2gAMAwEAAhEDEQA/APkyiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKK2/7B/wCnr/yH/wDXp3/CP/8AT3/5D/8Ar0rgYVFb3/CPf9Pf/kP/AOvTW0Hb1u+P+uf/ANei4GHRW6nh/d/y9cf9c/8A69P/AOEc/wCnz/yH/wDXouBz9FdD/wAI3/0+/wDkP/69H/CN/wDT7/5D/wD

心跳
QWCMD:<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="abc" Type="SG" Ver="1.2.0.0">
<DVRHeart State="0" TotalSpace="3000592498688" FreeSpace="2567316701184">
init,hicore,pppoed
</DVRHeart>
<GetTicks/>
</Agent>

系统启动
QWCMD: <?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="SSJCyao3gang" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="19" Channel="0" TriggerTime="2014-12-17 19:43:08" Note="5ZCv5Yqo57O757uf77yM6L+b5YWl5bel5L2c54q25oCB" GUID="1060221395">
</OperationCmd>
</Agent>

server ack
QWCMD:<?xml version="1.0" encoding="UTF-8"?><Server Ver="1.0"><Ticks Value="5"/><OK NowTime="2014-12-16 15:01:13"/></Server>
	
	
	
QWCMD:<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="SSJCWHRZ00HK" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="22" Channel="0" TriggerTime="2015-01-27 14:58:24" Note="6K6+5aSH57u05L+d" GUID="1091801337">
</OperationCmd>
</Agent>





//海康报警抓包
QWCMD:<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="SSJCYYYYYYYH" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="26" Channel="1" TriggerTime="2015-10-23 12:07:52" Note="5aSW6YOo5oql6K2m" GUID="449407651">
</OperationCmd>
</Agent>
/*
<OperationCmd Type="26" Channel="1" TriggerTime="2015-10-23 12:07:52" Note="5aSW6YOo5oql6K2m" GUID="449407651"/>
ID:SSJCYYYYYYYH GUID:449407651 Type:26 Trigger:2015-10-23 12:07:52 Note:外部报警 Size:112
*/
/*服务器回应
QWCMD:<?xml version="1.0" encoding="UTF-8"?><Server Ver="1.0"><Ticks Value="5"/><OK NowTime="2015-10-23 12:07:53"/></Server>
*/


QWCMD:<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="SSJCYYYYYYYH" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="1" Channel="1" TriggerTime="2015-10-23 12:07:52" Note="6YCa6YGTMeaKpeitpuiBlOWKqOWbvuWDj+S4iuS8oA==" GUID="883876640">
</OperationCmd>
</Agent>
/*
<OperationCmd Type="1" Channel="1" TriggerTime="2015-10-23 12:07:52" Note="6YCa6YGTMeaKpeitpuiBlOWKqOWbvuWDj+S4iuS8oA==" GUID="883876640"/>
ID:SSJCYYYYYYYH GUID:883876640 Type:1 Trigger:2015-10-23 12:07:52 Note:通道1报警联动图像上传 Size:139
*/

QWCMD:<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="SSJCYYYYYYYH" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="1" Channel="1" TriggerTime="2015-10-23 12:07:55" Note="6YCa6YGTMeaKpeitpuiBlOWKqOWbvuWDj+S4iuS8oA==" GUID="883876640">
/9j/4AAQSkZJRgABAgEAYABgAAD/wAARCAEgAWADASIAAhEBAxEB/8QBogAAAQUBAQEBAQEAAAAAAAAAAAECAwQFBgcICQoLEAACAQMDAgQDBQUEBAAAAX0BAgMABBEFEiExQQYTUWEHInEUMoGRoQgjQrHBFVLR8CQzYnKCCQoWFxgZGiUmJygpKjQ1Njc4OTpDREVGR0hJSlNUVVZXWFlaY2RlZmdoaWpzdHV2d3h5eoOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4eLj5OXm5+jp6vHy8/T19vf4+foBAAMBAQEBAQEBAQEAAAAAAAABAgMEBQYHCAkKCxEAAgECBAQDBAcFBAQAAQJ3AAECAxEEBSExBhJBUQdhcRMiMoEIFEKRobHBCSMzUvAVYnLRChYkNOEl8RcYGRomJygpKjU2Nzg5OkNERUZHSElKU1RVVldYWVpjZGVmZ2hpanN0dXZ3eHl6goOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4uPk5ebn6Onq8vP09fb3+Pn6/9sAhAANCQoLCggNCwoLDg4NDxMgFRMSEhMnHB4XIC4pMTAuKS0sMzpKPjM2RjcsLUBXQUZMTlJTUjI+WmFaUGBKUVJPAQ4ODhMREyYVFSZPNS01T09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT0//2gAMAwEAAhEDEQA/APO6KKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAorqv8AhDv+n/8A8g//AF6P+EN/6iH/AJB/+vQBytFdX/whv/UQ/wDIP/16P+EM/wCoh/5B/wDr0AcpRXWf8IZ/1EP/ACD/APXo/wCEL/6iH/kH/wCvQBydFdb/AMIV/wBRD/yD/wDXo/4Qr/qIf+Qf/r0AclRXW/8ACFf9RH/yD/8AXpf+EJ/6iP8A5B/+vQByNFdd/wAIT/1Ef/IP/wBej/hCf+oj/wCQf/r0AcjRXXf8IR/1Ef8AyD/9ej/hCP8AqI/+Qf8A69AHI0V13/CEf9RH/wAg/wD16P8AhCP+oj/5B/8Ar0AcjRXXf8IR/wBRH/yD/wDXo/4Qj/qI/wDkH/69AHI0V13/AAhH/UR/8g//AF6P+EI/6iP/AJB/+vQByNFdd/whP/UR/wDIP/16T/hCv+oh/wCQf/r0AclRXWf8IWf+gh/5B/8Ar1XfwlJH966/Hy//AK9AHN0V1cHg5Zf+Yjt/7Y//AF6ur8Pg3/MW/wDJf/7KgDh6K7r/AIVy3/QT/wDIH/2VB+HTf9BT/wAl/wD7KgDhaK7n/hXn/UU/8l//ALKl/wCFd/8AUV/8l/8A7KgDhaK7r/hXX/UV/wDJf/7Kj/hXf/UW/wDJf/7KgDhaK7r/AIV3/wBRb/yX/wDsqP8AhXf/AFFv/Jf/AOyoA4Wiu6/4V3/1Fv8AyX/+yo/4V3j/AJiv/kv/APZUAcLRXdH4d/8AUV/8l/8A7Kk/4V5/1Ff/ACX/APsqAOGoruP+Fe/9RX/yX/8AsqP+Fe/9RX/yX/8AsqAOHoruP+Fe8/8AIU/8l/8A7Kj/AIV7/wBRX/yX/wDsqAucPRXcf8K+/wCor/5L/wD2VH/Cvf8AqKf+S/8A9lQBuUtFLQIMUuP8/pSjt+NKpw6v/EP8c/4/nQAm0+W0n8CAkmlpuzMWw/3Cv5jH9KfQAUUtLQAlLS0tADaWlpaAG0tLRQA2inUUANop1FADaWlooAbRinUUAMxTSualpMUAR29oXnCw9T2ret9NmH3sCsiPKuGU4I6V1NrOLiBZB+P1oAYlrt61J9nj9KlooAg+ypTGtB2q1RRcCg1vUZgrTpCM0XAxWKrkN2owu7bnnO38cZq9Lp6SR7GY7f6+tP8As2GLAnk5P5UAUCnGai4yFz1rQ+zbYRH2C7agNkPMV+6jA/X/ABoArH5etIpzkelTvBlwT/D09qQRY3c5J/wpiK5ZcNz90c/5/CjI9af9mX95/wBNM5/X/Glki3gg9OODQBDuHyejnC/lmnbhtBz9MUog2MDnOECikaPIXk5Hf8/8aAEzyR3HWjPFLt+dm7tSd8imIx6WilqSgpaKWgApaKWgApaKWgApaKWgAopaKACilooASilooASinUUANopaKAEpKdRQA2lpaWgBBWlpc/lz7P4X4rPqVODQB09FMifzIlf1FPoAKKKKACiiigAooooAKaVFOooArtHzURjq7UTLTEU9lNKVZK96jP0pgVylRlatGo2oEVtvY03H51McUzigDCp1JTqkoKWiloAKWiloAKWiloAKWiloAKKWigAopaKACiiloASilooASilooASkp1FACUUtFABTxTadQBuaW+62x/dNXKytJfErJ/eFatABRRRQAUUUUAFFFFABRRRQAUGikzQAxhjmocF6m5pMCmIpyDDdKb1q0wqJloAg20wpU3IppzQBzlOpKdSGFLSU6gApaKWgApaKWgApaKWkAlLRS0wCilooASlopaQCUUtJQAUUtFMBKKWigBKKWigApaKWgCe2k8uVH9DXQVzS1v2j77WM+2KAJqKKSgBaKZupN1AElFNU06gAoopkhoAQmm7qYWpu6gRJupM1FupN1AEpNMzTN9N3UxD2qI0u6mlqAOepaSnUigpaKWgAp1JS0CFoopaBhS0UUgClopaAClpKWmAUUUUgCiiimAUUUUgCloopgFFFFABS0lFADq1NNk/dMvoayqtWUm1z7igDX3Ubqq+bSebQBZ3U3dVczVWmvo4fvmgDSDVZHSuaOuW696UeJYB3pD5WdJVaRqw28Tw+tRHxDbHvRcOVmyXpN1Y/9t2p/iqVNTt36PTuFjS3U3dVYTqeho8wUEk++k31TkuUT7xqudTtx/y0oA099N31lHV7b+/UZ1m1/v0XAKWkpaBi0tJS0ALS0lLQIWlpKWgYtFFFAC0tJS0AFLSUtABRRRQAUtJRQAUUUUALRSUtABRSUUALRSUUALT0bBqOlFAD/tkf9+mm9j/v1ylwHgvZ4dxwrfL9O1N3t/eNQM6o30f96sHUbkyzYB4qnub1NQ5PnU7jg7MsqhJrZs9CmuIwwHFZEZ+au/0Q505Kq5s67Ocn8OTRrnArEubVo3xXpkn+rb6VwWs/8fRouSqzMRkNRxS+XJVhj1rOz89IHVubseqxqPv1KNZj/v1xuoJslB9aiQ0GJ02q6n53EbVlFs9zUNoRv2nvTL0vbTY7UwLFG0elZ4u2pftbUAejU6m06gBaWm0tADqKKKBC0tNp1AC0tJS0DFopKWgBaKSloAWikooAWikooAWiikoA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</OperationCmd>
</Agent>

QWCMD:v<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="SSJCYYYYYYYH" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="1" Channel="1" TriggerTime="2015-10-23 12:07:56" Note="6YCa6YGTMeaKpeitpuiBlOWKqOWbvuWDj+S4iuS8oA==" GUID="883876640">
/9j/4AAQSkZJRgABAgEAYABgAAD/wAARCAEgAWADASIAAhEBAxEB/8QBogAAAQUBAQEBAQEAAAAAAAAAAAECAwQFBgcICQoLEAACAQMDAgQDBQUEBAAAAX0BAgMABBEFEiExQQYTUWEHInEUMoGRoQgjQrHBFVLR8CQzYnKCCQoWFxgZGiUmJygpKjQ1Njc4OTpDREVGR0hJSlNUVVZXWFlaY2RlZmdoaWpzdHV2d3h5eoOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4eLj5OXm5+jp6vHy8/T19vf4+foBAAMBAQEBAQEBAQEAAAAAAAABAgMEBQYHCAkKCxEAAgECBAQDBAcFBAQAAQJ3AAECAxEEBSExBhJBUQdhcRMiMoEIFEKRobHBCSMzUvAVYnLRChYkNOEl8RcYGRomJygpKjU2Nzg5OkNERUZHSElKU1RVVldYWVpjZGVmZ2hpanN0dXZ3eHl6goOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4uPk5ebn6Onq8vP09fb3+Pn6/9sAhAANCQoLCggNCwoLDg4NDxMgFRMSEhMnHB4XIC4pMTAuKS0sMzpKPjM2RjcsLUBXQUZMTlJTUjI+WmFaUGBKUVJPAQ4ODhMREyYVFSZPNS01T09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT09PT0//2gAMAwEAAhEDEQA/APO6KKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAooooAKKKKACiiigAorqv8AhDv+n/8A8g//AF6P+EN/6iH/AJB/+vQBytFdX/whv/UQ/wDIP/16P+EM/wCoh/5B/wDr0AcpRXWf8IZ/1EP/ACD/APXo/wCEL/6iH/kH/wCvQBydFdb/AMIV/wBRD/yD/wDXo/4Qr/qI/wDkH/69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</OperationCmd>
</Agent>

QWCMD:<?xml version="1.0" encoding="UTF-8" ?>
<Agent ID="SSJCYYYYYYYH" Type="SG" Ver="1.2.0.0">
<GetTicks/>
<OperationCmd Type="27" Channel="1" TriggerTime="2015-10-23 12:08:03" Note="5oql6K2m6Kej6Zmk" GUID="449407651">
</OperationCmd>
</Agent>
/*
<OperationCmd Type="27" Channel="1" TriggerTime="2015-10-23 12:08:03" Note="5oql6K2m6Kej6Zmk" GUID="449407651"/>
ID:SSJCYYYYYYYH GUID:449407651 Type:27 Trigger:2015-10-23 12:08:03 Note:报警解除 Size:112
*/

