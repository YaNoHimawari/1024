<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>new</title>
    
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

  //     http://localhost:8080/Homework6/new.jsp
  function sub()
{
	if((document.form1.text1.value=="")||(document.form1.text2.value=="")||(document.form1.text3.value=="")||(document.form1.text4.value=="")||(document.form1.text5.value=="")||(document.form1.text6.value==""))
    {
      window.alert("输入框不允许为空");
      return false;
    }
    else if(document.form1.text2.value.length!=11)
    {
      window.alert("手机号码必须为11位的");
      return false;
    }
    return true;
}

  
  </script>
  <form name = "form1" action="newConfirm.jsp" onsubmit="return sub()" method="post">
  id:<input type = "text" name = "text1"><br>
  link:<input type = "text" name = "text2"><br>
  pwd:<input type = "text" name = "text3"><br>
  roles:<input type = "text" name = "text4"><br>
  uid:<input type = "text" name = "text5"><br>
  username:<input type = "text" name = "text6"><br>
  <input type = "submit" value="提交">
  </form>
  </body>
</html>
