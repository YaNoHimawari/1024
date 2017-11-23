<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>用户注册</title>
    <meta http-equiv="Content-Type" content="text/html; charset=GBK" />
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
	<script type="text/javascript">
	function isEmail(str){
       var reg = /^([a-zA-Z0-9_-])+@([a-zA-Z0-9_-])+((\.[a-zA-Z0-9_-]{2,3}){1,2})$/;
       if(!reg.test(str))
       {
            return false;
        }
        return true;
	}
	
	function checkMobile(sMobile){ 
		if(!(/^1[3|4|5|8][0-9]\d{4,8}$/.test(sMobile)))
		{ 
			return false; 
		}
		return true; 
	}
	
	function subm(){	
	if(document.loginForm.t1.value.length<6||document.loginForm.t1.value.length>10)
	{
		window.alert("用户名长度不符或为空！");
		return false;
	}
	c=document.loginForm.t1.value.charAt(0);
	if(!((c>='a'&&c<='z')||(c>='A'&&c<='Z')))
	{
		window.alert("用户名必须用字母开头！");
		return false;
	}
	else if(document.loginForm.p1.value=="")
	{
		window.alert("密码不能为空！");
		return false;
	}
	else if(document.loginForm.t2_y.value.length!=4||document.loginForm.t2_y.value>2016)
	{
		window.alert("年份格式不正确！");
		return false;
	}
	else if(document.loginForm.t2_m.value>12 || document.loginForm.t2_m.value<1)
	{
		window.alert("月份格式不正确！");
		return false;
	}
	else if(document.loginForm.t2_d.value<1 || document.loginForm.t2_d.value>31)
	{
		window.alert("日期格式不正确！");
		return false;
	}
	else if(document.loginForm.t3.value<100 || document.loginForm.t3.value>250)
	{
		window.alert("身高格式不正确！");
		return false;
	}
	else if(!isEmail(document.loginForm.t4.value))
	{
		window.alert("邮箱格式不正确！");
		return false;
	}
	
	else if(document.loginForm.t5.value.length!=11 || !checkMobile(document.loginForm.t5.value))
	{
		window.alert("手机格式不正确！");
		return false;
	}
	return true;
	}
	
	function clear(){
		document.loginForm.t1.value="";
		document.loginForm.p1.value="";
		document.loginForm.t2_y.value="";
		document.loginForm.t2_m.value="";
		document.loginForm.t2_d.value="";
		document.loginForm.t3.value="";
		document.loginForm.t4.value="";
		document.loginForm.t5.value="";
		document.loginForm.ta1.value="";
		document.loginForm.ta2.value="";
	}
	</script>
	
	<!-- http://localhost:8080/Test3/register.jsp -->
	
	<form name="loginForm" action="post.jsp" onsubmit="return subm()" method="post">
	<title>用户注册</title>
	用户名：<input name="t1" type="text"><br>
	密码：<input name="p1" type="password"><br>
	籍贯：<select name = "s1">
           <option value="北京">北京</option>
           <option value="上海">上海</option>
           <option value="杭州" selected>杭州</option>
         </select><br>
	出生年月：<input name="t2_y" type="text">年
	<input name="t2_m" type="text">月
	<input name="t2_d" type="text">日<br>
	性别：<input name="sex1" type="radio" checked >男
	<input type="radio"name="sex2">女<br>
	身高：<input name="t3" type="text"><br>
	邮箱：<input name="t4" type="text"><br>
	手机：<input name="t5" type="text"><br>
	爱好：<br>
	<textarea rows="2" cols="20" name="ta1"></textarea><br>
	个人简介：<br>
	<textarea rows="5" cols="20" name="ta2"></textarea><br>
	<input type="submit" value="确认">
	<input type="reset" onClick="clear()" value="重置">
	</form>
  </body>
</html>
