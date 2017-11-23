package com.szy.test.action;

import java.io.InputStream;
import java.util.Map;

import javax.annotation.Resource;

import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;
import com.szy.test.model.User;
import com.szy.test.service.UserService;

@Component("userAction")
@Scope("prototype")
public class UserAction extends ActionSupport{
	private User user;
	private UserService userService;
	
	
	public String addUI() {
		return "addUI";
	}
	
	public String add() {
		userService.add(user);
		return "add";
	}
	
	public String updateP() {
		user = userService.getUserById(user.getId());
		return "updateP";
	}
	
	public String update() {
		userService.update(user);
		return "update";
	}
	
	public String delete() {
		userService.delete(user);
		return "delete";
	}
	
	@SuppressWarnings("unchecked")
	public String list() {
		Map request = (Map)ActionContext.getContext().get("request");
		request.put("list", userService.getAllUsers());
		return "list";
	}
	
	public String download() {
		return "download";
	}
	
	public InputStream getDownloadFile() {
		return userService.getInputStream();
	}
	
	public User getUser() {
		return user;
	}

	public void setUser(User user) {
		this.user = user;
	}


	public UserService getUserService() {
		return userService;
	}


	@Resource
	public void setUserService(UserService userService) {
		this.userService = userService;
	}
}
