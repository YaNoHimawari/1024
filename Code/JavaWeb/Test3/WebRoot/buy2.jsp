<%@page import="com.sun.xml.internal.txw2.Document"%>
<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>buy2</title>
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
    function subm()
    {
    <%
    	request.setCharacterEncoding("gb2312");
    	String[]	s=request.getParameterValues("CheckboxGroup1");
    	ArrayList goods =new ArrayList();
    	if(s!=null)
    		for(int i=0;i<s.length;++i)
    			if(s[i]!=null)
    				goods.add(s[i]);
    	session.setAttribute("b2", goods);	
    %> 
    }
    
	function clear()
	{
		var cb=document.all["CheckboxGroup1"];
		if(cb.length!=0)
			for(i=0;i<cb.length;++i)
				cb[i].checked=false;
	
	}
    </script>
    
 <form name="loginForm" action="buy2.jsp" onsubmit="return subm()" method="post">
      各类球大甩卖，一律八块：
    <li><input type="checkbox" name="CheckboxGroup1" value="篮球" id="CheckboxGroup1">篮球</li>
	<li><input type="checkbox" name="CheckboxGroup1" value="足球" id="CheckboxGroup1">足球</li>
	<li><input type="checkbox" name="CheckboxGroup1" value="排球" id="CheckboxGroup1">排球</li>
	<br>
	<input type="submit" value="提交">
	<input type="reset" value="全部重写" onClick="clear()">
	<a href="buy1.jsp" >买点别的</a>
	<a href="display.jsp" >查看购物车</a>	
</form>
  </body>
</html>
