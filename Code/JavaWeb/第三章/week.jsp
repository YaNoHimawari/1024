<%@ page language="java" contentType="text/html;charset=GBK"%>
<%@page import="java.util.*"%>
<%
	Date time = new Date();
	int td=time.getDay();
	int th = time.getHours();
	int tm = time.getMinutes();

	String week;
	if(td==0) week="������";
	if(td==1) week="����һ";
	if(td==2) week="���ڶ�";
	if(td==3) week="������";
	if(td==4) week="������";
	if(td==5) week="������";
	if(td==6) week="������";
	
	String d;
	if(th>=0 && th<=12) d="����";
	else {d="����"; th=th-12;}

	out.print("������"+week+"\"+d+"\"+th+"��"+tm+"��");
%>