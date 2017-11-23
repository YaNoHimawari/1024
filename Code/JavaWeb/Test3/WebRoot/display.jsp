<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>display</title>
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
    你选择的结果是：<br>
    <%
    	ArrayList b1=(ArrayList)session.getAttribute("b1");
    	if(b1!=null)
    	for(int i=0;i<b1.size();++i)
    	{
			String t=(String)b1.get(i);
			out.print("<li>"+t+"</li>");    	
    	}
    	ArrayList b2=(ArrayList)session.getAttribute("b2");
    	if(b2!=null)
    	for(int i=0;i<b2.size();++i)
    	{
			String t=(String)b2.get(i);
			out.print("<li>"+t+"</li>");    	
    	}
     %>
  </body>
</html>
