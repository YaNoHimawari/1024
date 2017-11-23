<%@page import="com.sun.xml.internal.txw2.Document"%>
<%@ page import="java.sql.*"
	 pageEncoding="gb2312"%>
<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://"
			+ request.getServerName() + ":" + request.getServerPort()
			+ path + "/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<base href="<%=basePath%>">

<title>list</title>

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
	<form method="post" action="list.jsp" onsubmit="s1()">
		id:<input type="text" name="id"><br> 
		link:<input type="text" name="link"><br>
		pwd:<input type="text" name="pwd"><br>
		roles:<input type="text" name="roles"><br> 
		uid:<input type="text" name="uid"><br> 
		username:<input type="text" name="username"><br> 
        <input type="submit" value="提交">
	</form>

	<%
		String sql1 = "";
		int id = 0;
		String drivername = "com.microsoft.sqlserver.jdbc.SQLServerDriver";
		String dbURL = "jdbc:sqlserver://localhost:1433;DataBaseName=mydatabase";
		String userName = "sa";
		String userPassword = "15058121";
		try {
			id = Integer.valueOf(request.getParameter("id"));
		} catch (Exception e) {
			e.printStackTrace();
		}
		request.setCharacterEncoding("gb2312");
		String link = String.valueOf(request.getParameter("link"));
		String pwd = String.valueOf(request.getParameter("pwd"));
		String roles = String.valueOf(request.getParameter("roles"));
		String uid = String.valueOf(request.getParameter("uid"));
		String username = String.valueOf(request.getParameter("username"));

		// http://localhost:8080/Homework6/list.jsp
		/*连接数据库*/
		Connection conn;
		try {
			Class.forName(drivername);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		sql1="";
		if (request.getParameter("id") != null){
				sql1 = "select * from students where id=" + id;
		}
		if (!link.isEmpty()) {
			if(sql1=="")
				sql1 = "select * from students where link='" + link + "'";
			else
				sql1+=" and link='" + link + "'";
		}
		if (!pwd.isEmpty()) {
			if(sql1=="")
				sql1 = "select * from students where pwd='" + pwd + "'";
			else
				sql1+=" and pwd='" + pwd + "'";
		}
		if (!roles.isEmpty()) {
			if(sql1=="")
				sql1 = "select * from students where roles='" + roles + "'";
			else
				sql1+=" and roles='" + roles + "'";
		}

 		if (!uid.isEmpty()) {
 			if(sql1=="")
 				sql1 = "select * from students where uid='" + uid + "'";
 			else
				sql1+=" and uid='" + uid + "'";
 		}
		if (!username.isEmpty()) {
			if(sql1=="")
				sql1 = "select * from students where username='" + username+ "'";
			else
				sql1+=" and username='" + username + "'";
		}
		out.println(username);
		conn = DriverManager.getConnection(dbURL, userName, userPassword);
		Statement statement = conn.createStatement();
		ResultSet rs = statement.executeQuery(sql1);
		out.println("<table border=\"1\">");
		while (rs.next()) {
			out.println("<tr>");
			out.println("<td>" + rs.getInt(1) + "</td>");
			out.println("<td>" + rs.getString(2) + "</td>");
			out.println("<td>" + rs.getString(3) + "</td>");
			out.println("<td>" + rs.getString(4) + "</td>");
			out.println("<td>" + rs.getString(5) + "</td>");
			out.println("<td>" + rs.getString(6) + "</td>");
			out.println("</tr>");
		}
		out.println("</table>");

		/*连接数据库*/
	%>
	

	<a href="new.jsp">增加学生</a>
</body>
</html>
