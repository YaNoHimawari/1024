<%@ page language="java" contentType="text/html;charset=GBK"%>
<%@page import="java.util.*"%>
<%
	Date time = new Date();
	int td=time.getDay();
	int th = time.getHours();
	int tm = time.getMinutes();

	String week;
	if(td==0) week="星期日";
	if(td==1) week="星期一";
	if(td==2) week="星期二";
	if(td==3) week="星期三";
	if(td==4) week="星期四";
	if(td==5) week="星期五";
	if(td==6) week="星期六";
	
	String d;
	if(th>=0 && th<=12) d="上午";
	else {d="下午"; th=th-12;}

	out.print("今天是"+week+"\"+d+"\"+th+"点"+tm+"分");
%>