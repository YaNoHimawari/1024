<%@ page language="java" import="java.util.*" contentType="text/html;charset=GBK"%>
<%@page import="java.util.*"%>
<%
	Date time = new Date();
	int th = time.getHours();
	int tm = time.getMinutes();
	int ts = time.getSeconds();
out.print("������ʱ��Ϊ" + th + ":" + tm + ":" + ts);
%>

<SCRIPT LANGUAGE="JavaScript">
	var time = new Date();
	th = time.getHours();
	tm = time.getMinutes();
	td = time.getSeconds();
	document.write("<br>�ͻ���ʱ��Ϊ" + th + ":" + tm + ":" + ts);
</SCRIPT>
