<%@ page language="java" import="java.util.*" import="java.sql.*" import="javax.swing.*" import="java.awt.*" pageEncoding="gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>newConfirm</title>
    
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
  
  function s1()
  {
    <%
    String drivername = "com.microsoft.sqlserver.jdbc.SQLServerDriver";
    String dbURL = "jdbc:sqlserver://localhost:1433;DataBaseName=mydatabase";
    String userName = "moliang";
    String userPassword = "15058118";
    
//     http://localhost:8080/Homework6/list.jsp
    /*连接数据库*/
    Connection conn;
			try{
	    		   Class.forName(drivername);
	    	   }catch(ClassNotFoundException e){
	    		   e.printStackTrace();
	    	   }
	    	   try{
	    		   conn = DriverManager.getConnection(dbURL,userName,userPassword);
	    		   request.setCharacterEncoding("gb2312");
	    		   String id = request.getParameter("text1");
	    		   String link = request.getParameter("text2");
	    		   String pwd = request.getParameter("text3");
	    		   String roles = request.getParameter("text4");
	    		   String uid = request.getParameter("text5");
	    		   String username = request.getParameter("text6");
	    		   String sql = "insert into students(id,link,pwd,roles,uid,username)values(?,?,?,?,?,?)";
	    		   PreparedStatement ps = conn.prepareStatement(sql);
	    		   ps.setString(1, id);
	    		   ps.setString(2, link);
	    		   ps.setString(3, pwd);
	    		   ps.setString(4, roles);
	    		   ps.setString(5, uid);
	    		   ps.setString(6, username);
	    		   ps.executeUpdate();
	    		   ps.close();
	    		   conn.close();
	    	   }  
	    	   catch(Exception e){
	    		   e.printStackTrace();
	    	   }
	    	   /*连接数据库*/
  %>
  	alert("新建学生成功");
    window.location.href = "list.jsp";
  }
  window.setTimeout("s1()","5000");
  </script>
  </body>
</html>
