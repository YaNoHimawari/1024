<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>表单内容</title>
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
  
     <%
        request.setCharacterEncoding("gb2312");
        String t1 = request.getParameter("t1");
        String p1=request.getParameter("p1");
        String s=request.getParameter("s1");
        String t2_y = request.getParameter("t2_y");
        String t2_m = request.getParameter("t2_m");
        String t2_d = request.getParameter("t2_d");
        String t3 = request.getParameter("t3");
        String t4 = request.getParameter("t4");
        String t5 = request.getParameter("t5");
        String ta1 = request.getParameter("ta1");
        String ta2 = request.getParameter("ta2");
     %>
     <ol>
     <li>用户名：<%out.print(t1);%></li>
     <li> 密码：<%out.print(p1);%></li>
     <li> 籍贯：<%=s%></li>
     <li>出生年月：<%out.print(t2_y+"年"+t2_m+"月"+t2_d+"日");%></li>
     <li>身高：<%out.print(t3);%></li>
     <li>邮箱名称：<%out.print(t4);%></li>
     <li> 手机：<%out.print(t5);%></li>
     <li> 爱好：<%out.print(ta1);%></li>
     <li>个人介绍：<%out.print(ta2);%></li>
     </ol>
    
  </body>
</html>
