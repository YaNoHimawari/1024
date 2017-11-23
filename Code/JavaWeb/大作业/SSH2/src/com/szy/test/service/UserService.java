package com.szy.test.service;

import java.io.InputStream;
import java.util.List;

import com.szy.test.model.User;

public interface UserService {
	
	public void add(User user);
	
	public void delete(User user);
	
	public void update(User user);
	
	public User getUserById(int id);
	
	public List<User> getAllUsers();
	
	public InputStream getInputStream();
}
