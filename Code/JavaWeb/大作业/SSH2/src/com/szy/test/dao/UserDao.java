package com.szy.test.dao;

import java.util.List;

import com.szy.test.model.User;

public interface UserDao {
	
	public void saveUser(User user);
	
	public void deleteUser(User user);
	
	public User findUserById(int id);
	
	public List<User> findAllUsers();
	
	public void update(User user);
}
