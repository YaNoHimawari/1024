<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>�û�ע��</title>
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
	function isEmail(str){
       var reg = /^([a-zA-Z0-9_-])+@([a-zA-Z0-9_-])+((\.[a-zA-Z0-9_-]{2,3}){1,2})$/;
       if(!reg.test(str))
       {
            return false;
        }
        return true;
	}
	
	function checkMobile(sMobile){ 
		if(!(/^1[3|4|5|8][0-9]\d{4,8}$/.test(sMobile)))
		{ 
			return false; 
		}
		return true; 
	}
	
	function subm(){	
	if(document.loginForm.t1.value.length<6||document.loginForm.t1.value.length>10)
	{
		window.alert("�û������Ȳ�����Ϊ�գ�");
		return false;
	}
	c=document.loginForm.t1.value.charAt(0);
	if(!((c>='a'&&c<='z')||(c>='A'&&c<='Z')))
	{
		window.alert("�û�����������ĸ��ͷ��");
		return false;
	}
	else if(document.loginForm.p1.value=="")
	{
		window.alert("���벻��Ϊ�գ�");
		return false;
	}
	else if(document.loginForm.t2_y.value.length!=4||document.loginForm.t2_y.value>2016)
	{
		window.alert("��ݸ�ʽ����ȷ��");
		return false;
	}
	else if(document.loginForm.t2_m.value>12 || document.loginForm.t2_m.value<1)
	{
		window.alert("�·ݸ�ʽ����ȷ��");
		return false;
	}
	else if(document.loginForm.t2_d.value<1 || document.loginForm.t2_d.value>31)
	{
		window.alert("���ڸ�ʽ����ȷ��");
		return false;
	}
	else if(document.loginForm.t3.value<100 || document.loginForm.t3.value>250)
	{
		window.alert("��߸�ʽ����ȷ��");
		return false;
	}
	else if(!isEmail(document.loginForm.t4.value))
	{
		window.alert("�����ʽ����ȷ��");
		return false;
	}
	
	else if(document.loginForm.t5.value.length!=11 || !checkMobile(document.loginForm.t5.value))
	{
		window.alert("�ֻ���ʽ����ȷ��");
		return false;
	}
	return true;
	}
	
	function clear(){
		document.loginForm.t1.value="";
		document.loginForm.p1.value="";
		document.loginForm.t2_y.value="";
		document.loginForm.t2_m.value="";
		document.loginForm.t2_d.value="";
		document.loginForm.t3.value="";
		document.loginForm.t4.value="";
		document.loginForm.t5.value="";
		document.loginForm.ta1.value="";
		document.loginForm.ta2.value="";
	}
	</script>
	
	<!-- http://localhost:8080/Test3/register.jsp -->
	
	<form name="loginForm" action="post.jsp" onsubmit="return subm()" method="post">
	<title>�û�ע��</title>
	�û�����<input name="t1" type="text"><br>
	���룺<input name="p1" type="password"><br>
	���᣺<select name = "s1">
           <option value="����">����</option>
           <option value="�Ϻ�">�Ϻ�</option>
           <option value="����" selected>����</option>
         </select><br>
	�������£�<input name="t2_y" type="text">��
	<input name="t2_m" type="text">��
	<input name="t2_d" type="text">��<br>
	�Ա�<input name="sex1" type="radio" checked >��
	<input type="radio"name="sex2">Ů<br>
	��ߣ�<input name="t3" type="text"><br>
	���䣺<input name="t4" type="text"><br>
	�ֻ���<input name="t5" type="text"><br>
	���ã�<br>
	<textarea rows="2" cols="20" name="ta1"></textarea><br>
	���˼�飺<br>
	<textarea rows="5" cols="20" name="ta2"></textarea><br>
	<input type="submit" value="ȷ��">
	<input type="reset" onClick="clear()" value="����">
	</form>
  </body>
</html>
