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
    
    <title>buy1</title>
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
    	session.setAttribute("b1", goods);	
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
    
 <form name="loginForm" action="buy1.jsp" onsubmit="return subm()" method="post">
      �������˦����һ��ʮ�飺
    <li><input type="checkbox" name="CheckboxGroup1" value="����" id="CheckboxGroup1">����</li>
	<li><input type="checkbox" name="CheckboxGroup1" value="ţ��" id="CheckboxGroup1">ţ��</li>
	<li><input type="checkbox" name="CheckboxGroup1" value="����" id="CheckboxGroup1">����</li>
	<br>
	<input type="submit" value="�ύ">
	<input type="reset" value="ȫ����д" onClick="clear()">
	<a href="buy2.jsp" >�����</a>
	<a href="display.jsp" >�鿴���ﳵ</a>	
</form>
  </body>
</html>
