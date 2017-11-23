package com.szy.test.service.impl;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.List;

import javax.annotation.Resource;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFRichTextString;
import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.springframework.stereotype.Component;

import com.szy.test.dao.UserDao;
import com.szy.test.model.User;
import com.szy.test.service.UserService;

@Component("userService")
public class UserServiceImpl implements UserService {
	
	private UserDao userDao;
	
	public void add(User user) {
		userDao.saveUser(user);
	}

	public void delete(User user) {
		userDao.deleteUser(user);
	}

	public List<User> getAllUsers() {
		return userDao.findAllUsers();
	}

	public User getUserById(int id) {
		return userDao.findUserById(id);
	}

	public void update(User user) {
		userDao.update(user);
	}

	public UserDao getUserDao() {
		return userDao;
	}

	@Resource
	public void setUserDao(UserDao userDao) {
		this.userDao = userDao;
	}

	public InputStream getInputStream() {
		
		HSSFWorkbook wb = new HSSFWorkbook();
		HSSFSheet sheet = wb.createSheet("sheet1");
		HSSFRow row = sheet.createRow(0);
		
		HSSFCell cell = row.createCell((short)0);
		cell.setCellValue(new HSSFRichTextString("ÐòºÅ"));
		
		cell = row.createCell((short)2);
		cell.setCellValue(new HSSFRichTextString("ÐÕ"));
		
		cell = row.createCell((short)3);
		cell.setCellValue(new HSSFRichTextString("Ãû"));
		
		cell = row.createCell((short)4);
		cell.setCellValue(new HSSFRichTextString("ÄêÁä"));
		
		List<User> list = userDao.findAllUsers();
		for(int i=0; i<list.size(); ++i) {
			User user = list.get(i);
			
			row = sheet.createRow(i+1);
			
			cell = row.createCell((short)0);
			cell.setCellValue(new HSSFRichTextString(String.valueOf(user.getId())));
			
			cell = row.createCell((short)2);
			cell.setCellValue(new HSSFRichTextString(user.getFirstname()));
			
			cell = row.createCell((short)3);
			cell.setCellValue(new HSSFRichTextString(user.getLastname()));
			
			cell = row.createCell((short)4);
			cell.setCellValue(new HSSFRichTextString(String .valueOf(user.getAge())));
		}
		
		ByteArrayOutputStream os = new ByteArrayOutputStream();
		
		try {
			wb.write(os);
		} catch (IOException e) {
			e.printStackTrace();
		}
		byte[] content = os.toByteArray();
		
		InputStream is = new ByteArrayInputStream(content);
		
		return is;
	}

}
