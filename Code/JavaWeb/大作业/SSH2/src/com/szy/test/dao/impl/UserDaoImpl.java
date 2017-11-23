package com.szy.test.dao.impl;

import java.util.List;

import javax.annotation.Resource;

import org.springframework.orm.hibernate3.HibernateTemplate;
import org.springframework.stereotype.Component;

import com.szy.test.dao.UserDao;
import com.szy.test.model.User;

@Component("userDao")
public class UserDaoImpl implements UserDao {
	
	private HibernateTemplate hibernateTemplate;
	
	public void deleteUser(User user) {
		hibernateTemplate.delete(user);
	}

	public List<User> findAllUsers() {
		String hql = "from User user order by user.id";
		return (List<User>)hibernateTemplate.find(hql);
	}

	public User findUserById(int id) {
		User user = (User)hibernateTemplate.get(User.class, id);
		return user;
	}

	public void saveUser(User user) {
		hibernateTemplate.save(user);
	}

	public void update(User user) {
		hibernateTemplate.update(user);
	}

	public HibernateTemplate getHibernateTemplate() {
		return hibernateTemplate;
	}

	@Resource
	public void setHibernateTemplate(HibernateTemplate hibernateTemplate) {
		this.hibernateTemplate = hibernateTemplate;
	}
	
}
